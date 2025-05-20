//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Define the message structure
struct message {
  int type;
  char data[256];
};

// Define the message types
#define MESSAGE_TYPE_TEXT 1
#define MESSAGE_TYPE_EXIT 2

// Create a new socket
int create_socket() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  return sockfd;
}

// Bind the socket to an address
void bind_socket(int sockfd, struct sockaddr_in *addr) {
  if (bind(sockfd, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }
}

// Listen for connections on the socket
void listen_socket(int sockfd) {
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
}

// Accept a connection on the socket
int accept_connection(int sockfd) {
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (clientfd == -1) {
    perror("accept");
    exit(EXIT_FAILURE);
  }
  return clientfd;
}

// Send a message to a client
void send_message(int sockfd, struct message *msg) {
  if (send(sockfd, msg, sizeof(*msg), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }
}

// Receive a message from a client
void receive_message(int sockfd, struct message *msg) {
  if (recv(sockfd, msg, sizeof(*msg), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
}

// Handle a client connection
void handle_client(int sockfd) {
  struct message msg;
  while (1) {
    // Receive a message from the client
    receive_message(sockfd, &msg);

    // Check the message type
    switch (msg.type) {
      case MESSAGE_TYPE_TEXT:
        // Print the message data
        printf("Received message: %s\n", msg.data);

        // Send a response message
        strcpy(msg.data, "Hello from the server!");
        send_message(sockfd, &msg);
        break;
      case MESSAGE_TYPE_EXIT:
        // Close the client connection
        close(sockfd);
        break;
      default:
        // Ignore unknown message types
        break;
    }
  }
}

// Start the server
void start_server() {
  // Create a socket
  int sockfd = create_socket();

  // Bind the socket to an address
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;
  bind_socket(sockfd, &addr);

  // Listen for connections on the socket
  listen_socket(sockfd);

  // Accept connections and handle clients
  while (1) {
    int clientfd = accept_connection(sockfd);
    handle_client(clientfd);
  }
}

// Start the client
void start_client() {
  // Create a socket
  int sockfd = create_socket();

  // Connect to the server
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send a message to the server
  struct message msg;
  strcpy(msg.data, "Hello from the client!");
  send_message(sockfd, &msg);

  // Receive a message from the server
  receive_message(sockfd, &msg);
  printf("Received message: %s\n", msg.data);

  // Close the client connection
  close(sockfd);
}

// Main function
int main() {
  // Start the server or client
  int mode;
  printf("Enter 1 for server or 2 for client: ");
  scanf("%d", &mode);
  if (mode == 1) {
    start_server();
  } else if (mode == 2) {
    start_client();
  } else {
    printf("Invalid mode\n");
  }

  return 0;
}