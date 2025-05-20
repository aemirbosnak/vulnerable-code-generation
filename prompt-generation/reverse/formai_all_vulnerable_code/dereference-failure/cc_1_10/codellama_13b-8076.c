//Code Llama-13B DATASET v1.0 Category: Robot movement control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PI 3.14159265358979323846

// Robot movement control
struct movement_control {
  float x;
  float y;
  float theta;
};

// Socket connection
int socket_connection(char* host, char* port) {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Socket creation error");
    exit(EXIT_FAILURE);
  }

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  struct addrinfo* server_info;
  if (getaddrinfo(host, port, &hints, &server_info) != 0) {
    perror("getaddrinfo error");
    exit(EXIT_FAILURE);
  }

  if (connect(sock, server_info->ai_addr, server_info->ai_addrlen) == -1) {
    perror("Socket connection error");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(server_info);

  return sock;
}

// Movement control functions
void forward(struct movement_control* move, float distance) {
  move->x += distance * cos(move->theta);
  move->y += distance * sin(move->theta);
}

void backward(struct movement_control* move, float distance) {
  move->x -= distance * cos(move->theta);
  move->y -= distance * sin(move->theta);
}

void left(struct movement_control* move, float angle) {
  move->theta += angle;
}

void right(struct movement_control* move, float angle) {
  move->theta -= angle;
}

// Main program
int main() {
  // Socket connection
  int sock = socket_connection("localhost", "3000");

  // Robot movement control
  struct movement_control move;
  move.x = 0;
  move.y = 0;
  move.theta = 0;

  // Movement control loop
  while (1) {
    // Read movement commands from socket
    char buf[1024];
    int n = read(sock, buf, sizeof(buf));
    if (n < 0) {
      perror("Socket read error");
      exit(EXIT_FAILURE);
    } else if (n == 0) {
      break;
    }

    // Parse movement commands
    char* cmd = strtok(buf, " ");
    if (strcmp(cmd, "forward") == 0) {
      float distance = atof(strtok(NULL, " "));
      forward(&move, distance);
    } else if (strcmp(cmd, "backward") == 0) {
      float distance = atof(strtok(NULL, " "));
      backward(&move, distance);
    } else if (strcmp(cmd, "left") == 0) {
      float angle = atof(strtok(NULL, " "));
      left(&move, angle);
    } else if (strcmp(cmd, "right") == 0) {
      float angle = atof(strtok(NULL, " "));
      right(&move, angle);
    } else {
      printf("Invalid movement command: %s\n", cmd);
    }

    // Print robot position
    printf("Robot position: (%.2f, %.2f, %.2f)\n", move.x, move.y, move.theta);
  }

  // Close socket connection
  close(sock);

  return 0;
}