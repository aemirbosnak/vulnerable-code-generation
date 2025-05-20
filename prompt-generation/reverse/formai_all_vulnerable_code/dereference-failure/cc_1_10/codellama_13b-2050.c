//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
// ftp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv) {
  // Check command-line arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(1);
  }

  // Resolve hostname
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    herror("gethostbyname");
    exit(1);
  }

  // Connect to host
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(21);
  addr.sin_addr.s_addr = *(uint32_t *)host->h_addr_list[0];
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Send FTP command
  char cmd[256];
  sprintf(cmd, "USER %s\r\n", argv[2]);
  send(sock, cmd, strlen(cmd), 0);
  sprintf(cmd, "PASS %s\r\n", argv[3]);
  send(sock, cmd, strlen(cmd), 0);
  sprintf(cmd, "CWD /\r\n");
  send(sock, cmd, strlen(cmd), 0);
  sprintf(cmd, "PASV\r\n");
  send(sock, cmd, strlen(cmd), 0);

  // Read response
  char buf[256];
  recv(sock, buf, sizeof(buf), 0);
  printf("Response: %s\n", buf);

  // Close socket
  close(sock);
  return 0;
}