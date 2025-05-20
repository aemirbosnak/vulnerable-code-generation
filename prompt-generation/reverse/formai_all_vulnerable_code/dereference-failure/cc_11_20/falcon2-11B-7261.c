//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CONNECTIONS 5

int main(int argc, char *argv[]) {
  int sockfd, portno, newsockfd, pid, status;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[1024];
  struct hostent *server;

  if (argc < 2) {
    printf("Usage: %s [port number]\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);
  if (portno <= 0 || portno > 65535) {
    printf("Invalid port number\n");
    exit(1);
  }

  server = gethostbyname("localhost");
  if (server == NULL) {
    printf("Hostname not found\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error creating socket\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error binding socket\n");
    exit(1);
  }

  listen(sockfd, MAX_CONNECTIONS);

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &status);
    if (newsockfd < 0) {
      perror("accept");
      continue;
    }

    pid = fork();
    if (pid < 0) {
      perror("fork");
      close(newsockfd);
      continue;
    } else if (pid == 0) {
      close(sockfd);
      close(newsockfd);
      printf("Child process: Connection established with client\n");

      while (1) {
        bzero(buffer, sizeof(buffer));
        recv(newsockfd, buffer, sizeof(buffer), 0);
        printf("Received message: %s\n", buffer);
        bzero(buffer, sizeof(buffer));
        printf("Enter message to send: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(newsockfd, buffer, strlen(buffer), 0);
        printf("Sent message: %s\n", buffer);
        break;
      }

      close(newsockfd);
      exit(0);
    } else {
      close(newsockfd);
    }
  }

  close(sockfd);
  return 0;
}