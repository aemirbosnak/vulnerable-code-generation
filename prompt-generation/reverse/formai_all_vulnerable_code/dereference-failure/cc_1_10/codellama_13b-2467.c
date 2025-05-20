//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: safe
/*
 * imap-client.c
 *
 * A safe IMAP client example program in C
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s hostname port\n", argv[0]);
    return 1;
  }

  // Get the hostname and port from the command line arguments
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set up the address structure
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = inet_addr(hostname);

  // Connect to the server
  if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
    perror("connect");
    return 1;
  }

  // Send the IMAP command
  char *command = "LOGIN username password\r\n";
  send(sock, command, strlen(command), 0);

  // Receive the response
  char buf[MAX_BUF];
  int bytes_recv = recv(sock, buf, MAX_BUF, 0);
  if (bytes_recv < 0) {
    perror("recv");
    return 1;
  }

  // Print the response
  printf("Received %d bytes\n", bytes_recv);
  printf("Response: %s\n", buf);

  // Close the socket
  close(sock);

  return 0;
}