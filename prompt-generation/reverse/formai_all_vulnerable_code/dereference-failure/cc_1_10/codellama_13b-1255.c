//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
/*
 * Building a FTP Client in C
 *
 * This program demonstrates how to build a FTP client in C.
 *
 * Usage: ./ftp_client [username] [password] [host] [port]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define PORT 21

int main(int argc, char **argv) {
  // Check if the number of arguments is correct
  if (argc != 5) {
    fprintf(stderr, "Usage: %s [username] [password] [host] [port]\n", argv[0]);
    return 1;
  }

  // Get the username, password, host, and port from the arguments
  char *username = argv[1];
  char *password = argv[2];
  char *host = argv[3];
  int port = atoi(argv[4]);

  // Create a socket for the FTP client
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  // Set up the address structure for the FTP server
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(host);

  // Connect to the FTP server
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Send the username and password to the FTP server
  char buf[BUF_SIZE];
  sprintf(buf, "USER %s\r\n", username);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }
  sprintf(buf, "PASS %s\r\n", password);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the welcome message from the FTP server
  char welcome[BUF_SIZE];
  if (recv(sock, welcome, BUF_SIZE, 0) == -1) {
    perror("recv");
    return 1;
  }
  printf("%s\n", welcome);

  // Send the LIST command to the FTP server
  sprintf(buf, "LIST\r\n");
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the file list from the FTP server
  char file_list[BUF_SIZE];
  if (recv(sock, file_list, BUF_SIZE, 0) == -1) {
    perror("recv");
    return 1;
  }
  printf("%s\n", file_list);

  // Send the QUIT command to the FTP server
  sprintf(buf, "QUIT\r\n");
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  // Close the socket
  close(sock);

  return 0;
}