//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char const *argv[]) {
  int sock = 0, bytes_sent = 0, bytes_recv = 0;
  struct sockaddr_in server;
  char buffer[BUFFER_SIZE] = {0};
  char username[BUFFER_SIZE] = {0};
  char password[BUFFER_SIZE] = {0};

  // Create a socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Could not create socket.\n");
    return -1;
  }

  // Set server properties
  server.sin_family = AF_INET;
  server.sin_port = htons(POP3_PORT);

  // Convert IP address to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
    printf("Invalid address.\n");
    return -1;
  }

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Connection failed.\n");
    return -1;
  } else {
    printf("Connected to server.\n");
  }

  // Receive banner from server
  bytes_recv = recv(sock, buffer, BUFFER_SIZE, 0);
  buffer[bytes_recv] = '\0';
  printf("%s", buffer);

  // Send username to server
  printf("Username: ");
  fgets(username, BUFFER_SIZE, stdin);
  bytes_sent = send(sock, username, strlen(username), 0);

  // Receive response from server
  bytes_recv = recv(sock, buffer, BUFFER_SIZE, 0);
  buffer[bytes_recv] = '\0';
  printf("%s", buffer);

  // Send password to server
  printf("Password: ");
  fgets(password, BUFFER_SIZE, stdin);
  bytes_sent = send(sock, password, strlen(password), 0);

  // Receive response from server
  bytes_recv = recv(sock, buffer, BUFFER_SIZE, 0);
  buffer[bytes_recv] = '\0';
  printf("%s", buffer);

  // Quit session with server
  bytes_sent = send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);

  // Receive response from server
  bytes_recv = recv(sock, buffer, BUFFER_SIZE, 0);
  buffer[bytes_recv] = '\0';
  printf("%s", buffer);

  // Close socket
  close(sock);

  return 0;
}