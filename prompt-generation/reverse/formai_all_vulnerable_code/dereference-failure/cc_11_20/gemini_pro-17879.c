//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 21
#define BUFLEN 256

int main(int argc, char **argv) {
  // Check if the user provided the hostname and filename
  if (argc < 3) {
    printf("Usage: %s <hostname> <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the hostname and filename from the command line arguments
  char *hostname = argv[1];
  char *filename = argv[2];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Get the IP address of the hostname
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Connect to the FTP server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the username and password to the FTP server
  char *username = "username";
  char *password = "password";
  char buf[BUFLEN];
  snprintf(buf, BUFLEN, "USER %s\n", username);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }
  if (recv(sockfd, buf, BUFLEN, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  snprintf(buf, BUFLEN, "PASS %s\n", password);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }
  if (recv(sockfd, buf, BUFLEN, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send the RETR command to the FTP server to retrieve the file
  snprintf(buf, BUFLEN, "RETR %s\n", filename);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the file from the FTP server
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }
  while (1) {
    int n = recv(sockfd, buf, BUFLEN, 0);
    if (n == -1) {
      perror("recv");
      return EXIT_FAILURE;
    } else if (n == 0) {
      break;
    }
    fwrite(buf, 1, n, fp);
  }

  // Close the file and the socket
  fclose(fp);
  close(sockfd);

  return EXIT_SUCCESS;
}