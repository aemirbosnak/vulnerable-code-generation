//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
  int sockfd, n;
  struct sockaddr_in serv_addr;
  char buffer[256];

  if (argc < 3) {
    fprintf(stderr,"Usage: %s <server_ip> <port>\n", argv[0]);
    exit(1);
  }

  // Create a socket point.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set up the server address struct.
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  if (inet_aton(argv[1], &serv_addr.sin_addr) == 0) {
    perror("ERROR invalid server IP address");
    exit(1);
  }

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Receive the welcome message from the server.
  memset(buffer, 0, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send the USER command to the server.
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "USER %s\r\n", argv[3]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Receive the response from the server.
  memset(buffer, 0, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send the PASS command to the server.
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "PASS %s\r\n", argv[4]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Receive the response from the server.
  memset(buffer, 0, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send the STAT command to the server.
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "STAT\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Receive the response from the server.
  memset(buffer, 0, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send the LIST command to the server.
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "LIST\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Receive the response from the server.
  memset(buffer, 0, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send the RETR command to the server.
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "RETR %s\r\n", argv[5]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Receive the response from the server.
  memset(buffer, 0, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  printf("%s", buffer);

  // Send the QUIT command to the server.
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "QUIT\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Close the socket.
  close(sockfd);

  return 0;
}