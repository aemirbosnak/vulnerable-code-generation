//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 80
#define BUFSIZE 1024

int main(int argc, char **argv) {
  int sockfd, clientfd, remotefd;
  struct sockaddr_in serveraddr, clientaddr, remoteaddr;
  socklen_t addrlen;
  char buf[BUFSIZE];
  int nbytes;
  char *hostname;
  struct hostent *remotehost;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  hostname = argv[1];
  remotehost = gethostbyname(hostname);
  if (remotehost == NULL) {
    fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error: could not create socket");
    exit(1);
  }

  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
    perror("Error: could not bind socket");
    exit(1);
  }

  if (listen(sockfd, 5) == -1) {
    perror("Error: could not listen on socket");
    exit(1);
  }

  while (1) {
    addrlen = sizeof(clientaddr);
    clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen);
    if (clientfd == -1) {
      perror("Error: could not accept client connection");
      continue;
    }

    memset(&remoteaddr, 0, sizeof(remoteaddr));
    remoteaddr.sin_family = AF_INET;
    remoteaddr.sin_addr.s_addr = remotehost->h_addr;
    remoteaddr.sin_port = htons(atoi(argv[2]));

    remotefd = socket(AF_INET, SOCK_STREAM, 0);
    if (remotefd == -1) {
      perror("Error: could not create remote socket");
      close(clientfd);
      continue;
    }

    if (connect(remotefd, (struct sockaddr *)&remoteaddr, sizeof(remoteaddr)) == -1) {
      perror("Error: could not connect to remote host");
      close(clientfd);
      close(remotefd);
      continue;
    }

    while ((nbytes = read(clientfd, buf, BUFSIZE)) > 0) {
      if (write(remotefd, buf, nbytes) == -1) {
        perror("Error: could not write to remote host");
        close(clientfd);
        close(remotefd);
        break;
      }
    }

    close(clientfd);
    close(remotefd);
  }

  close(sockfd);

  return 0;
}