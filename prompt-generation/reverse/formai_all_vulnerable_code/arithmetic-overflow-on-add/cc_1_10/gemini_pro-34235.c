//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Server port
#define PORT 8080

// Maximum number of clients
#define MAX_CLIENTS 10

// Client structure
typedef struct client {
  int sockfd;
  char name[256];
  int score;
} client;

// Global variables
client clients[MAX_CLIENTS];
int num_clients = 0;

// Function to handle client connections
void handle_client(int sockfd) {
  // Receive client name
  char name[256];
  recv(sockfd, name, sizeof(name), 0);

  // Add client to list of clients
  clients[num_clients].sockfd = sockfd;
  strcpy(clients[num_clients].name, name);
  clients[num_clients].score = 0;
  num_clients++;

  // Send welcome message
  char welcome_msg[256];
  sprintf(welcome_msg, "Welcome to the Wi-Fi Signal Strength Analyzer, %s!", name);
  send(sockfd, welcome_msg, strlen(welcome_msg), 0);

  // Receive client signal strength
  int signal_strength;
  while (recv(sockfd, &signal_strength, sizeof(signal_strength), 0) > 0) {
    // Update client score
    clients[num_clients].score += signal_strength;

    // Send updated score to client
    char score_msg[256];
    sprintf(score_msg, "Your score is now %d", clients[num_clients].score);
    send(sockfd, score_msg, strlen(score_msg), 0);
  }

  // Client disconnected
  close(sockfd);
  num_clients--;
}

// Function to start the server
void start_server() {
  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Set socket options
  int opt = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
    perror("setsockopt");
    exit(1);
  }

  // Bind socket to port
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for connections
  if (listen(sockfd, MAX_CLIENTS) == -1) {
    perror("listen");
    exit(1);
  }

  // Accept connections
  while (1) {
    struct sockaddr_in client_addr;
    int client_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (client_sockfd == -1) {
      perror("accept");
      exit(1);
    }

    // Create thread to handle client
    pthread_t thread;
    if (pthread_create(&thread, NULL, (void *)handle_client, (void *)client_sockfd) != 0) {
      perror("pthread_create");
      exit(1);
    }
  }

  // Close socket
  close(sockfd);
}

// Main function
int main() {
  start_server();
  return 0;
}