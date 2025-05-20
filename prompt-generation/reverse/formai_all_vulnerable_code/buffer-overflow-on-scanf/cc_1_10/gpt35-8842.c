//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

  char username[MAX_BUFFER_SIZE], password[MAX_BUFFER_SIZE], response[MAX_BUFFER_SIZE], buffer[MAX_BUFFER_SIZE];
  int sock, n, port;
  struct sockaddr_in server;

  // Ask the user for their login credentials
  printf("Enter your email username: ");
  scanf("%s", username);
  printf("Enter your email password: ");
  scanf("%s", password);

  // Create a socket for connecting to the IMAP server
  sock = socket(AF_INET, SOCK_STREAM, 0);

  if (sock < 0) {
    perror("Failed to create socket");
    return 1;
  }

  // Set up the server address
  port = 143;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(port);

  // Connect to the server
  if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
    perror("Failed to connect to server");
    return 1;
  }

  // Receive the IMAP server greeting
  memset(response, 0, sizeof(response));
  n = recv(sock, response, MAX_BUFFER_SIZE, 0);

  if (n < 0) {
    perror("Failed to receive response from server");
    return 1;
  }

  printf("%s", response);

  // Send the username to the server
  snprintf(buffer, MAX_BUFFER_SIZE, "a001 LOGIN %s %s\r\n", username, password);

  if (send(sock, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send message to server");
    return 1;
  }

  // Receive the response to the username command
  memset(response, 0, sizeof(response));
  n = recv(sock, response, MAX_BUFFER_SIZE, 0);

  if (n < 0) {
    perror("Failed to receive response from server");
    return 1;
  }

  printf("%s", response);

  // Send the logout command to the server
  snprintf(buffer, MAX_BUFFER_SIZE, "a002 LOGOUT\r\n");

  if (send(sock, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send message to server");
    return 1;
  }

  // Receive the response to the logout command
  memset(response, 0, sizeof(response));
  n = recv(sock, response, MAX_BUFFER_SIZE, 0);

  if (n < 0) {
    perror("Failed to receive response from server");
    return 1;
  }

  printf("%s", response);

  // Close the socket
  close(sock);

  return 0;
}