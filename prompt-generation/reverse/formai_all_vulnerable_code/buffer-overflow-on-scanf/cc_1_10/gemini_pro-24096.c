//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

// Robot control commands
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

// Robot state variables
int x = 0;  // X-coordinate of the robot
int y = 0;  // Y-coordinate of the robot
int direction = FORWARD;  // Current direction of the robot

// Socket communication variables
int sockfd;  // Socket file descriptor
struct sockaddr_in servaddr;  // Server address structure

// Thread function to handle robot movement
void *robot_movement(void *arg) {
  while (1) {
    // Receive command from server
    int command;
    recv(sockfd, &command, sizeof(int), 0);

    // Execute command
    switch (command) {
      case FORWARD:
        y++;
        break;
      case BACKWARD:
        y--;
        break;
      case LEFT:
        direction = (direction + 3) % 4;
        break;
      case RIGHT:
        direction = (direction + 1) % 4;
        break;
      case STOP:
        break;
    }

    // Print robot state
    printf("Robot state: x = %d, y = %d, direction = %d\n", x, y, direction);
  }

  return NULL;
}

int main() {
  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Initialize server address structure
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(5000);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error connecting to server");
    exit(EXIT_FAILURE);
  }

  // Create a thread to handle robot movement
  pthread_t tid;
  pthread_create(&tid, NULL, robot_movement, NULL);

  // Main loop to send commands to robot
  while (1) {
    // Get command from user
    int command;
    printf("Enter command (1 - forward, 2 - backward, 3 - left, 4 - right, 5 - stop): ");
    scanf("%d", &command);

    // Send command to server
    send(sockfd, &command, sizeof(int), 0);
  }

  // Close socket
  close(sockfd);

  return 0;
}