//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 4096

/* 
 * error - wrapper for perror
 */
void error(char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char **argv) {
  int parentfd; /* parent socket */
  int childfd; /* child socket */
  int portno; /* port to listen on */
  int clientlen; /* byte size of client's address */
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct hostent *hostp; /* client host info */
  char buf[BUFSIZE]; /* message buf */
  char *hostaddrp; /* dotted decimal host addr string */
  int optval; /* flag value for setsockopt */
  int n; /* message byte size */

  /* check command line arguments */
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[1]);

  /* socket: create the parent socket */
  parentfd = socket(AF_INET, SOCK_STREAM, 0);
  if (parentfd < 0)
    error("ERROR opening socket");

  /* setsockopt: Handy debugging trick that lets 
   * us rerun the server immediately after we kill it; 
   * otherwise we have to wait about 20 secs. 
   * Eliminates "ERROR on binding: Address already in use" error. 
   */
  optval = 1;
  setsockopt(parentfd, SOL_SOCKET, SO_REUSEADDR, 
	     (const void *)&optval , sizeof(int));

  /* build the server's Internet address */
  bzero((char *) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET; /* we are using the Internet */
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); /* accept reqs to any IP addr */
  serveraddr.sin_port = htons((unsigned short)portno); /* port to listen on */

  /* bind: associate the parent socket with a port */
  if (bind(parentfd, (struct sockaddr *) &serveraddr, 
	   sizeof(serveraddr)) < 0)
    error("ERROR on binding");

  /* listen: make it a listening socket ready to accept connection requests */
  if (listen(parentfd, 5) < 0) /* allow 5 requests to queue up */ 
    error("ERROR on listen");

  /* main loop: wait for a connection request, echo input line, 
     then close connection. */
  clientlen = sizeof(clientaddr);
  while (1) {

    /* wait for a connection request */
    childfd = accept(parentfd, (struct sockaddr *) &clientaddr, &clientlen);
    if (childfd < 0)
      error("ERROR on accept");

    /* gethostbyaddr: determine who sent the message */
    hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
			  sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      error("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
      error("ERROR on inet_ntoa\n");
    printf("server established connection with %s (%s)\n", 
	   hostp->h_name, hostaddrp);

    /* read: read input string from the client */
    bzero(buf, BUFSIZE);
    n = read(childfd, buf, BUFSIZE);
    if (n < 0)
      error("ERROR reading from socket");
    printf("server received %d bytes: %s", n, buf);

    /* parse the GET request for target host and port */
    char *p = strstr(buf, "HTTP/");
    if (p == NULL)
      error("ERROR malformed request");
    *p = 0;
    if (strncmp(buf, "GET http://", 11) != 0)
      error("ERROR only GET method is supported and URL must start with http://");
    char *p1 = strstr(buf+11, ":");
    if (p1 == NULL)
      error("ERROR malformed request");
    *p1++ = 0;
    char *p2 = strstr(p1, "/");
    if (p2 == NULL)
      error("ERROR malformed request");
    *p2 = 0;
    printf("proxy serving %s:%s\n", p1, p2+1);
    int port = atoi(p1+1);

    /* open a socket to the target server */
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
      error("ERROR opening socket");
    struct hostent *server = gethostbyname(p1);
    if (server == NULL)
      error("ERROR no such host");
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
	  (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(port);
    if (connect(serverfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
      error("ERROR connecting to server");

    /* forward the GET request to the target server */
    n = write(serverfd, buf, strlen(buf));
    if (n < 0)
      error("ERROR writing to server");

    /* read the response from the target server */
    bzero(buf, BUFSIZE);
    while (n = read(serverfd, buf, BUFSIZE)) {
      if (n < 0)
        error("ERROR reading from server");
      /* forward the response to the client */
      int m = write(childfd, buf, n);
      if (m < 0)
        error("ERROR writing to socket");
      if (n < BUFSIZE)
        break;
      bzero(buf, BUFSIZE);
    }

    /* close the sockets */
    close(childfd);
    close(serverfd);
  }
  return 0;
}