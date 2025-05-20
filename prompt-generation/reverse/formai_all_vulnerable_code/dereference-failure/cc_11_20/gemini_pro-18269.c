//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define FTP_PORT 21

int main(int argc, char *argv[]) {
  // Check for correct usage
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse hostname and port
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Resolve hostname
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Error: Could not resolve hostname %s\n", hostname);
    return EXIT_FAILURE;
  }

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: Could not create socket");
    return EXIT_FAILURE;
  }

  // Connect to server
  struct sockaddr_in serveraddr;
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(port);
  serveraddr.sin_addr.s_addr = ((struct in_addr *)host->h_addr)->s_addr;
  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
    perror("Error: Could not connect to server");
    return EXIT_FAILURE;
  }

  // Receive welcome message
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error: Could not receive welcome message");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send username
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "USER anonymous\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error: Could not send username");
    return EXIT_FAILURE;
  }

  // Receive username response
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error: Could not receive username response");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send password
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "PASS anonymous@example.com\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error: Could not send password");
    return EXIT_FAILURE;
  }

  // Receive password response
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error: Could not receive password response");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send CWD command
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "CWD /pub\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error: Could not send CWD command");
    return EXIT_FAILURE;
  }

  // Receive CWD response
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error: Could not receive CWD response");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send LIST command
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "LIST\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error: Could not send LIST command");
    return EXIT_FAILURE;
  }

  // Receive LIST response
  memset(buffer, 0, sizeof(buffer));
  while (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
    printf("%s", buffer);
  }

  // Close socket
  close(sockfd);

  return EXIT_SUCCESS;
}