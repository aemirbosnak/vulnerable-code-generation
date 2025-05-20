//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define DEFAULT_PORT 21
#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
  int sockfd, port;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUF_SIZE];
  char command[BUF_SIZE];
  char response[BUF_SIZE];
  int n;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: No such host\n");
    exit(EXIT_FAILURE);
  }

  port = atoi(argv[2]);
  if (port < 0) {
    fprintf(stderr, "Error: Invalid port number\n");
    exit(EXIT_FAILURE);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: Could not create socket");
    exit(EXIT_FAILURE);
  }

  // Set up the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error: Could not connect to server");
    exit(EXIT_FAILURE);
  }

  // Receive the welcome message from the server
  memset(response, 0, BUF_SIZE);
  n = recv(sockfd, response, BUF_SIZE - 1, 0);
  if (n < 0) {
    perror("Error: Could not receive welcome message");
    exit(EXIT_FAILURE);
  }
  printf("%s", response);

  // Enter the FTP command loop
  while (1) {
    // Get the command from the user
    printf("FTP> ");
    memset(command, 0, BUF_SIZE);
    fgets(command, BUF_SIZE - 1, stdin);

    // Send the command to the server
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
      perror("Error: Could not send command to server");
      exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    memset(response, 0, BUF_SIZE);
    n = recv(sockfd, response, BUF_SIZE - 1, 0);
    if (n < 0) {
      perror("Error: Could not receive response from server");
      exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Check if the command was QUIT
    if (strcmp(command, "QUIT\r\n") == 0) {
      break;
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}