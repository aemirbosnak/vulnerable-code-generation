//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
  // Check for valid command line arguments
  if (argc != 4) {
    printf("Usage: %s <pop3_server_address> <username> <password>\n", argv[0]);
    return 1;
  }

  // Get server information
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("Error: Could not resolve server address.\n");
    return 1;
  }

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: Could not create socket.\n");
    return 1;
  }

  // Set server address
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(110);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error: Could not connect to server.\n");
    return 1;
  }

  // Receive server response
  char buffer[MAX_BUFFER_SIZE];
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Error: Could not receive server response.\n");
    return 1;
  }
  printf("Server response: %s", buffer);

  // Send username
  char user[100];
  sprintf(user, "USER %s\r\n", argv[2]);
  if (send(sockfd, user, strlen(user), 0) < 0) {
    printf("Error: Could not send username.\n");
    return 1;
  }

  // Receive server response
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Error: Could not receive server response.\n");
    return 1;
  }
  printf("Server response: %s", buffer);

  // Send password
  char pass[100];
  sprintf(pass, "PASS %s\r\n", argv[3]);
  if (send(sockfd, pass, strlen(pass), 0) < 0) {
    printf("Error: Could not send password.\n");
    return 1;
  }

  // Receive server response
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Error: Could not receive server response.\n");
    return 1;
  }
  printf("Server response: %s", buffer);

  // Send command to list emails
  if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) < 0) {
    printf("Error: Could not send command to list emails.\n");
    return 1;
  }

  // Receive server response
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    printf("Error: Could not receive server response.\n");
    return 1;
  }
  printf("Server response: %s", buffer);

  // Close connection
  if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
    printf("Error: Could not send quit command.\n");
    return 1;
  }
  close(sockfd);

  return 0;
}