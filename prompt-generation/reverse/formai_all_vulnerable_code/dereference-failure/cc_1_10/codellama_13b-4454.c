//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
/*
 * A POP3 client example program in C
 *
 * This program demonstrates how to use the POP3 protocol to retrieve
 * emails from a POP3 server.
 *
 * Usage: ./pop3_client <host> <port> <username> <password>
 *
 * Example: ./pop3_client pop.example.com 110 user@example.com mypassword
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define POP3_TIMEOUT 60

int main(int argc, char *argv[]) {
  if (argc < 5) {
    printf("Usage: %s <host> <port> <username> <password>\n", argv[0]);
    return 1;
  }

  const char *host = argv[1];
  int port = atoi(argv[2]);
  const char *username = argv[3];
  const char *password = argv[4];

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send the USER command
  char user_cmd[100];
  snprintf(user_cmd, sizeof(user_cmd), "USER %s\r\n", username);
  if (send(sock, user_cmd, strlen(user_cmd), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send the PASS command
  char pass_cmd[100];
  snprintf(pass_cmd, sizeof(pass_cmd), "PASS %s\r\n", password);
  if (send(sock, pass_cmd, strlen(pass_cmd), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send the STAT command
  char stat_cmd[100];
  snprintf(stat_cmd, sizeof(stat_cmd), "STAT\r\n");
  if (send(sock, stat_cmd, strlen(stat_cmd), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  char response[100];
  if (recv(sock, response, sizeof(response), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Print the response
  printf("Response: %s\n", response);

  // Close the socket
  close(sock);

  return 0;
}