//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

#define PORT 8080

typedef struct {
  char *name;
  int value;
} setting_t;

setting_t settings[] = {
  {"speed", 0},
  {"yaw", 0},
  {"pitch", 0},
  {"roll", 0},
};

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in servaddr;
  char buffer[1024];
  int n;
  int i;

  // Check command line arguments.
  if (argc != 3) {
    fprintf(stderr, "usage: %s <ip address> <drone name>\n", argv[0]);
    return 1;
  }

  // Open socket.
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return 1;
  }

  // Set socket address.
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(PORT);

  // Connect to server.
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send drone name.
  n = send(sockfd, argv[2], strlen(argv[2]), 0);
  if (n < 0) {
    perror("send");
    return 1;
  }

  // Read welcome message.
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }

  // Print welcome message.
  printf("%s\n", buffer);

  // Main loop.
  while (1) {
    // Print settings.
    printf("Settings:\n");
    for (i = 0; i < sizeof(settings) / sizeof(settings[0]); i++) {
      printf("  %s: %d\n", settings[i].name, settings[i].value);
    }

    // Prompt for input.
    printf("Enter command: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Parse command.
    char *command = strtok(buffer, " ");
    if (strcmp(command, "quit") == 0) {
      break;
    } else if (strcmp(command, "speed") == 0) {
      settings[0].value = atoi(strtok(NULL, " "));
    } else if (strcmp(command, "yaw") == 0) {
      settings[1].value = atoi(strtok(NULL, " "));
    } else if (strcmp(command, "pitch") == 0) {
      settings[2].value = atoi(strtok(NULL, " "));
    } else if (strcmp(command, "roll") == 0) {
      settings[3].value = atoi(strtok(NULL, " "));
    } else {
      printf("Invalid command\n");
    }

    // Send settings to drone.
    n = send(sockfd, &settings, sizeof(settings), 0);
    if (n < 0) {
      perror("send");
      return 1;
    }
  }

  // Close socket.
  close(sockfd);

  return 0;
}