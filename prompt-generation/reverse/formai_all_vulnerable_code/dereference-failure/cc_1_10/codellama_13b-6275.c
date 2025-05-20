//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FTP_PORT 21
#define FTP_BUF_SIZE 1024
#define FTP_USER "user"
#define FTP_PASS "pass"

int main(int argc, char *argv[]) {
  int sock, n;
  char buf[FTP_BUF_SIZE];
  struct sockaddr_in server_addr;
  struct hostent *server;

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set up the server address
  server = gethostbyname("ftp.example.com");
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  memset((char *) &server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(FTP_PORT);
  server_addr.sin_addr = *((struct in_addr *) server->h_addr);

  // Connect to the server
  if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send the username and password
  n = write(sock, "USER " FTP_USER "\r\n", strlen("USER " FTP_USER "\r\n"));
  if (n < 0) {
    perror("ERROR writing username");
    exit(1);
  }

  n = write(sock, "PASS " FTP_PASS "\r\n", strlen("PASS " FTP_PASS "\r\n"));
  if (n < 0) {
    perror("ERROR writing password");
    exit(1);
  }

  // Send the command to list files
  n = write(sock, "LIST\r\n", strlen("LIST\r\n"));
  if (n < 0) {
    perror("ERROR writing LIST command");
    exit(1);
  }

  // Read the response
  n = read(sock, buf, FTP_BUF_SIZE - 1);
  if (n < 0) {
    perror("ERROR reading response");
    exit(1);
  }
  buf[n] = '\0';

  // Print the response
  printf("%s\n", buf);

  // Close the socket
  close(sock);

  return 0;
}