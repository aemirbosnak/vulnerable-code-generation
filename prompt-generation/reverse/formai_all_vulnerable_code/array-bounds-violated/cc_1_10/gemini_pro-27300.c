//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 10

struct client {
  int sockfd;
  struct sockaddr_in addr;
};

struct sensor {
  int id;
  float temperature;
  time_t timestamp;
};

int main() {
  int server_sockfd, client_sockfd, i;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len;
  struct client clients[MAX_CLIENTS];
  struct sensor sensors[MAX_CLIENTS];

  // Create a server socket
  if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind the server socket to the server address
  if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_sockfd, MAX_CLIENTS) < 0) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept incoming connections
  while (1) {
    client_addr_len = sizeof(client_addr);

    if ((client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_addr_len)) < 0) {
      perror("accept");
      continue;
    }

    // Add the client to the list of clients
    for (i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i].sockfd == 0) {
        clients[i].sockfd = client_sockfd;
        clients[i].addr = client_addr;
        break;
      }
    }

    // Create a new sensor for the client
    struct sensor sensor;
    sensor.id = i;
    sensor.temperature = 0.0;
    sensor.timestamp = time(NULL);

    // Add the sensor to the list of sensors
    sensors[i] = sensor;

    // Send a welcome message to the client
    char welcome[] = "Welcome to the temperature monitoring system!";
    if (send(client_sockfd, welcome, sizeof(welcome), 0) < 0) {
      perror("send");
      continue;
    }
  }

  // Close the server socket
  close(server_sockfd);

  return EXIT_SUCCESS;
}