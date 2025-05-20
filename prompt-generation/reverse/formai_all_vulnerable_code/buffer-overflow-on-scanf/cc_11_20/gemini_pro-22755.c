//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {
  int sockfd, port;
  struct sockaddr_in serv_addr;
  char buffer[1024];

  // Get the port number from the user.
  printf("Enter the port number: ");
  scanf("%d", &port);

  // Create a socket.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the server address.
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the USER command to the server.
  strcpy(buffer, "USER user@example.com\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the server's response.
  printf("%s", buffer);

  // Send the PASS command to the server.
  strcpy(buffer, "PASS password\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the server's response.
  printf("%s", buffer);

  // Send the STAT command to the server.
  strcpy(buffer, "STAT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the server's response.
  printf("%s", buffer);

  // Send the LIST command to the server.
  strcpy(buffer, "LIST\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  while (1) {
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      perror("recv");
      return EXIT_FAILURE;
    }

    // Print the server's response.
    printf("%s", buffer);

    // Check if the server has sent the end of the list.
    if (strstr(buffer, ".\r\n") != NULL) {
      break;
    }
  }

  // Send the QUIT command to the server.
  strcpy(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the server's response.
  printf("%s", buffer);

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}