//GEMINI-pro DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  char buffer[1024];
  while (1) {
    printf("> ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    if (strcmp(buffer, "exit") == 0) {
      break;
    }
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      perror("send");
      exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      perror("recv");
      exit(EXIT_FAILURE);
    }
    printf("< %s\n", buffer);
  }

  close(sockfd);
  return EXIT_SUCCESS;
}