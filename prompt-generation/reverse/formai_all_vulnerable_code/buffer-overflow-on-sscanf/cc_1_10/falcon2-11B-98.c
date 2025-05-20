//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define PORT 8080

void error(const char *msg) { perror(msg); exit(1); }

int main(int argc, char *argv[])
{
  if (argc!= 2)
  {
    fprintf(stderr, "usage: %s <message>\n", argv[0]);
    exit(1);
  }

  int sockfd, newsockfd;
  struct sockaddr_in serv_addr, cli_addr;
  int n;
  char buf[1024];
  char message[1024];
  FILE *fp;

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    error("ERROR opening socket");

  // Prepare the server's address struct
  memset((char *) &serv_addr, '\0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Bind the socket to the server's address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");

  // Listen for incoming connections
  if (listen(sockfd, 3) < 0)
    error("ERROR on listen");

  printf("Listening for connections...\n");

  // Accept a connection
  while ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &n)) >= 0)
  {
    printf("Connected with %s\n", inet_ntoa(cli_addr.sin_addr));

    // Get the message from the client
    bzero(buf, sizeof(buf));
    n = recv(newsockfd, buf, sizeof(buf), 0);
    if (n <= 0)
    {
      printf("ERROR reading from socket\n");
      close(newsockfd);
      continue;
    }
    buf[n] = '\0';
    printf("Received: %s\n", buf);

    // Process the message
    sscanf(buf, "%s %s", message, buf);

    // Send the message back to the client
    n = send(newsockfd, message, strlen(message), 0);
    if (n <= 0)
    {
      printf("ERROR sending to socket\n");
      close(newsockfd);
      continue;
    }

    // Close the connection
    close(newsockfd);
  }

  // Cleanup
  close(sockfd);

  return 0;
}