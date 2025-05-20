//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
/* FTP Client example program in Claude Shannon style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Failed to create socket");
    return EXIT_FAILURE;
  }

  // Set server address
  struct sockaddr_in serveraddr;
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serveraddr.sin_port = htons(PORT);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
    perror("Failed to connect to server");
    return EXIT_FAILURE;
  }

  // Receive server response
  char buffer[BUFFER_SIZE];
  memset(&buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Failed to receive server response");
    return EXIT_FAILURE;
  }

  // Display server response
  printf("%s\n", buffer);

  // Send username
  char *username = "USER anonymous\r\n";
  if (send(sockfd, username, strlen(username), 0) == -1) {
    perror("Failed to send username");
    return EXIT_FAILURE;
  }

  // Receive server response
  memset(&buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Failed to receive server response");
    return EXIT_FAILURE;
  }

  // Display server response
  printf("%s\n", buffer);

  // Send password
  char *password = "PASS email@example.com\r\n";
  if (send(sockfd, password, strlen(password), 0) == -1) {
    perror("Failed to send password");
    return EXIT_FAILURE;
  }

  // Receive server response
  memset(&buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Failed to receive server response");
    return EXIT_FAILURE;
  }

  // Display server response
  printf("%s\n", buffer);

  // Change working directory
  char *cwd = "CWD /upload\r\n";
  if (send(sockfd, cwd, strlen(cwd), 0) == -1) {
    perror("Failed to change working directory");
    return EXIT_FAILURE;
  }

  // Receive server response
  memset(&buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Failed to receive server response");
    return EXIT_FAILURE;
  }

  // Display server response
  printf("%s\n", buffer);

  // Set transfer mode to binary
  char *type = "TYPE I\r\n";
  if (send(sockfd, type, strlen(type), 0) == -1) {
    perror("Failed to set transfer mode");
    return EXIT_FAILURE;
  }

  // Receive server response
  memset(&buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Failed to receive server response");
    return EXIT_FAILURE;
  }

  // Display server response
  printf("%s\n", buffer);

  // Open file for reading
  FILE *file = fopen("example.txt", "rb");
  if (file == NULL) {
    perror("Failed to open file");
    return EXIT_FAILURE;
  }

  // Send file
  int bytes_sent = 0;
  while (!feof(file)) {
    memset(&buffer, 0, sizeof(buffer));
    int bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (send(sockfd, buffer, bytes_read, 0) == -1) {
      perror("Failed to send file");
      return EXIT_FAILURE;
    }
    bytes_sent += bytes_read;
  }

  // Close file
  fclose(file);

  // Receive server response
  memset(&buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("Failed to receive server response");
    return EXIT_FAILURE;
  }

  // Display server response
  printf("%s\n", buffer);

  // Close socket
  if (close(sockfd) == -1) {
    perror("Failed to close socket");
    return EXIT_FAILURE;
  }

  // Display success message
  printf("File upload successful. %d bytes sent.\n", bytes_sent);

  return EXIT_SUCCESS;
}