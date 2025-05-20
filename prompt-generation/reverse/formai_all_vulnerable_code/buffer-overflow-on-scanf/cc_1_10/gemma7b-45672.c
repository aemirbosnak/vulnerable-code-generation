//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define MAX_SERVERS 5

int main() {
  int server_fd[MAX_SERVERS];
  char server_ip[MAX_SERVERS][20];
  int i, j;

  // Get the server IP addresses from the user
  for (i = 0; i < MAX_SERVERS; i++) {
    printf("Enter the IP address of server %d: ", i + 1);
    scanf("%s", server_ip[i]);
  }

  // Create a socket for each server
  for (i = 0; i < MAX_SERVERS; i++) {
    server_fd[i] = socket(AF_INET, SOCK_STREAM, htons(80));
    if (server_fd[i] < 0) {
      perror("Error creating socket");
      exit(1);
    }
  }

  // Ping each server
  for (i = 0; i < MAX_SERVERS; i++) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(server_ip[i]);

    if (connect(server_fd[i], (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("Error connecting to server");
      exit(1);
    }

    send(server_fd[i], "Ping", 5, 0);
    char resp[1024];
    recv(server_fd[i], resp, 1024, 0);

    printf("Server %d is alive: %s\n", i + 1, resp);
  }

  return 0;
}