//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  int sockfd, portno;
  char *host;
  struct hostent *server;
  struct sockaddr_in serv_addr;

  printf("Enter the FTP server hostname: ");
  scanf("%s", host);

  portno = 21;

  if ((server = gethostbyname(host)) == NULL) {
    printf("Error: Host not found\n");
    return -1;
  }

  if (server->h_addrtype == AF_INET) {
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
  } else {
    printf("Error: Unknown address type\n");
    return -1;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: Socket creation failed\n");
    return -1;
  }

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error: Connection failed\n");
    return -1;
  }

  printf("Connected to FTP server\n");

  char *username = "anonymous";
  char *password = "anonymous@example.com";

  send(sockfd, username, strlen(username), 0);
  send(sockfd, password, strlen(password), 0);

  char response[1024];
  recv(sockfd, response, sizeof(response), 0);
  printf("Server response: %s\n", response);

  char *command = "LIST";
  send(sockfd, command, strlen(command), 0);

  recv(sockfd, response, sizeof(response), 0);
  printf("Server response: %s\n", response);

  close(sockfd);
  return 0;
}