//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

// Define the maximum number of bytes to be sent or received at a time
#define MAX_BYTES 1024

// Define the port number to connect to
#define PORT 21

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments passed to the program
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
    return 1;
  }

  // Get the hostname and filename from the command line arguments
  char *hostname = argv[1];
  char *filename = argv[2];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Get the IP address of the hostname
  struct hostent *hostinfo = gethostbyname(hostname);
  if (hostinfo == NULL) {
    fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
    return 1;
  }

  // Create the socket address structure
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr = *(struct in_addr *)hostinfo->h_addr;

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Send the username and password to the server
  char *username = "user";
  char *password = "password";
  char buffer[MAX_BYTES];
  snprintf(buffer, MAX_BYTES, "USER %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return 1;
  }

  snprintf(buffer, MAX_BYTES, "PASS %s\r\n", password);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the response from the server
  if (recv(sockfd, buffer, MAX_BYTES, 0) == -1) {
    perror("recv");
    return 1;
  }

  // Check if the login was successful
  if (strncmp(buffer, "230", 3) != 0) {
    fprintf(stderr, "%s\n", buffer);
    return 1;
  }

  // Send the RETR command to the server
  snprintf(buffer, MAX_BYTES, "RETR %s\r\n", filename);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the file from the server
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  while (1) {
    int n = recv(sockfd, buffer, MAX_BYTES, 0);
    if (n == -1) {
      perror("recv");
      return 1;
    } else if (n == 0) {
      break;
    }

    fwrite(buffer, 1, n, fp);
  }

  fclose(fp);

  // Send the QUIT command to the server
  snprintf(buffer, MAX_BYTES, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the response from the server
  if (recv(sockfd, buffer, MAX_BYTES, 0) == -1) {
    perror("recv");
    return 1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}