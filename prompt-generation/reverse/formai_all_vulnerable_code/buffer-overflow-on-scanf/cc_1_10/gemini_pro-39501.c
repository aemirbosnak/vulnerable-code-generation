//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DRONE_PORT 5555
#define DRONE_IP "192.168.1.1"
#define COMMAND_LENGTH 1024

int main()
{
  int sockfd;
  struct sockaddr_in servaddr;
  char command[COMMAND_LENGTH];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Set the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(DRONE_PORT);
  servaddr.sin_addr.s_addr = inet_addr(DRONE_IP);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return 1;
  }

  // Get the user input
  while (1) {
    printf("Enter a command: ");
    scanf("%s", command);

    // Send the command to the drone
    if (sendto(sockfd, command, strlen(command), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
      perror("sendto");
      return 1;
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}