//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SA struct sockaddr

int main(int argc, char const *argv[]) {
  int sockfd, connfd;
  struct sockaddr_in servaddr, cli;

  if(argc != 3) {
    printf("Usage: smtp_client <IP> <port>\n");
    exit(1);
  }

  // Create socket file descriptor
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1) {
    printf("Socket creation failed...\n");
    exit(1);
  } else {
    printf("Socket created successfully!\n");
  }

  // Clear and set server address structure
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(atoi(argv[2]));

  // Connect the client socket to server socket
  if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
    printf("Connection with server failed...\n");
    exit(1);
  } else {
    printf("Connected with server successfully!\n");
  }

  // Start SMTP client
  char buffer[1024];
  int n;

  n = read(sockfd, buffer, sizeof(buffer));
  buffer[n] = 0;

  if(strstr(buffer, "220") == NULL) {
    printf("Error: %s", buffer);
    exit(1);
  }

  snprintf(buffer, sizeof(buffer), "HELO %s\r\n", argv[1]);
  write(sockfd, buffer, strlen(buffer));
  n = read(sockfd, buffer, sizeof(buffer));
  buffer[n] = 0;

  if(strstr(buffer, "250") == NULL) {
    printf("Error: %s", buffer);
    exit(1);
  }

  printf("\nSMTP Commands:\n");
  printf("1. MAIL FROM:<address>\n");
  printf("2. RCPT TO:<address>\n");
  printf("3. DATA\n");
  printf("4. QUIT\n\n");

  while(1) {
    printf("Enter command: ");
    fgets(buffer, sizeof(buffer), stdin);

    if(strncmp(buffer, "MAIL", 4) == 0) {
      write(sockfd, buffer, strlen(buffer));
      n = read(sockfd, buffer, sizeof(buffer));
      buffer[n] = 0;

      if(strstr(buffer, "250") == NULL) {
        printf("Error: %s", buffer);
        exit(1);
      }
    } else if(strncmp(buffer, "RCPT", 4) == 0) {
      write(sockfd, buffer, strlen(buffer));
      n = read(sockfd, buffer, sizeof(buffer));
      buffer[n] = 0;

      if(strstr(buffer, "250") == NULL) {
        printf("Error: %s", buffer);
        exit(1);
      }
    } else if(strncmp(buffer, "DATA", 4) == 0) {
      write(sockfd, buffer, strlen(buffer));
      n = read(sockfd, buffer, sizeof(buffer));
      buffer[n] = 0;

      if(strstr(buffer, "354") == NULL) {
        printf("Error: %s", buffer);
        exit(1);
      }

      printf("Enter message (terminate with a single dot on a new line):\n");
      while(1) {
        fgets(buffer, sizeof(buffer), stdin);
        write(sockfd, buffer, strlen(buffer));
        if(strncmp(buffer, ".\n", 2) == 0) {
          break;
        }
      }

      n = read(sockfd, buffer, sizeof(buffer));
      buffer[n] = 0;

      if(strstr(buffer, "250") == NULL) {
        printf("Error: %s", buffer);
        exit(1);
      }
    } else if(strncmp(buffer, "QUIT", 4) == 0) {
      write(sockfd, buffer, strlen(buffer));
      n = read(sockfd, buffer, sizeof(buffer));
      buffer[n] = 0;

      if(strstr(buffer, "221") == NULL) {
        printf("Error: %s", buffer);
        exit(1);
      }

      printf("Connection closed by server.");
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}