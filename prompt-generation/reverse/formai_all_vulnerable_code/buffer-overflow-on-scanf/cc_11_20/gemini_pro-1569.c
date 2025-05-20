//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  // Get the FTP server's IP address and port number.
  char server_ip[16];
  int server_port;
  printf("Enter the FTP server's IP address: ");
  scanf("%s", server_ip);
  printf("Enter the FTP server's port number: ");
  scanf("%d", &server_port);

  // Create a socket for connecting to the FTP server.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set up the server address.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  server_addr.sin_addr.s_addr = inet_addr(server_ip);

  // Connect to the FTP server.
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the USER command to the FTP server.
  char username[16];
  printf("Enter your username: ");
  scanf("%s", username);
  char user_command[32];
  sprintf(user_command, "USER %s\r\n", username);
  if (send(sockfd, user_command, strlen(user_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the FTP server.
  char response[1024];
  if (recv(sockfd, response, sizeof(response), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the user was successfully authenticated.
  if (strncmp(response, "230 User logged in, proceed.", strlen("230 User logged in, proceed.")) != 0) {
    printf("Login failed.\n");
    return EXIT_FAILURE;
  }

  // Send the PASS command to the FTP server.
  char password[16];
  printf("Enter your password: ");
  scanf("%s", password);
  sprintf(user_command, "PASS %s\r\n", password);
  if (send(sockfd, user_command, strlen(user_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the FTP server.
  if (recv(sockfd, response, sizeof(response), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the user was successfully authenticated.
  if (strncmp(response, "230 User logged in, proceed.", strlen("230 User logged in, proceed.")) != 0) {
    printf("Login failed.\n");
    return EXIT_FAILURE;
  }

  // Send the CWD command to the FTP server.
  char directory[1024];
  printf("Enter the directory you want to change to: ");
  scanf("%s", directory);
  sprintf(user_command, "CWD %s\r\n", directory);
  if (send(sockfd, user_command, strlen(user_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the FTP server.
  if (recv(sockfd, response, sizeof(response), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the directory was successfully changed.
  if (strncmp(response, "250 Directory successfully changed.", strlen("250 Directory successfully changed.")) != 0) {
    printf("Directory change failed.\n");
    return EXIT_FAILURE;
  }

  // Send the LIST command to the FTP server.
  char list_command[] = "LIST\r\n";
  if (send(sockfd, list_command, strlen(list_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the FTP server.
  while (1) {
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }

    // Check if the end of the file list has been reached.
    if (strncmp(response, "226 Transfer complete.", strlen("226 Transfer complete.")) == 0) {
      break;
    }

    // Print the file list.
    printf("%s", response);
  }

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}