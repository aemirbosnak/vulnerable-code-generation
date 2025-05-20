//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: all-encompassing
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 1024

int main() {
  int sockfd, port, i, numPings, bytesRead, flags;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in servAddr;

  printf("Enter the port number: ");
  scanf("%d", &port);

  numPings = 0;
  while (numPings < MAX_PINGS) {
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0) {
      perror("Error creating socket");
      exit(1);
    }

    servAddr.sin_port = htons(port);
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr("localhost");

    flags = sendto(sockfd, "PING", 5, 0, (struct sockaddr *)&servAddr, sizeof(servAddr));
    if (flags < 0) {
      perror("Error sending message");
      close(sockfd);
      exit(1);
    }

    bytesRead = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&servAddr, NULL);
    if (bytesRead < 0) {
      perror("Error receiving message");
      close(sockfd);
      exit(1);
    }

    printf("Ping: %s\n", buffer);

    close(sockfd);
    numPings++;
  }

  return 0;
}