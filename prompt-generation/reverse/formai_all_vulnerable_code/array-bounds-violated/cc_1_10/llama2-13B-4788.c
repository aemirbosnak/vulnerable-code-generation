//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 256

// Global variables
int sock; // Socket handle
struct sockaddr_in server_address; // Server address
char message[MAX_MESSAGE_LENGTH]; // User's message

// Function declarations
void init_socket(); // Initialize the socket
void connect_to_server(); // Connect to the server
void send_message(); // Send the user's message to the server
void receive_message(); // Receive a message from the server
void print_message(char *message); // Print the received message

int main() {
  // Initialize the socket
  init_socket();

  // Connect to the server
  connect_to_server();

  // Send a message to the server
  send_message();

  // Receive a message from the server
  receive_message();

  // Print the received message
  print_message(message);

  return 0;
}

// Function: init_socket()
void init_socket() {
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }
}

// Function: connect_to_server()
void connect_to_server() {
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

  if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Connection failed");
    exit(EXIT_FAILURE);
  }
}

// Function: send_message()
void send_message() {
  int len = strlen(message);
  if (send(sock, message, len, 0) < len) {
    perror("Message sending failed");
    exit(EXIT_FAILURE);
  }
}

// Function: receive_message()
void receive_message() {
  int len = recv(sock, message, MAX_MESSAGE_LENGTH, 0);
  if (len < 0) {
    perror("Message receiving failed");
    exit(EXIT_FAILURE);
  }
  message[len] = '\0'; // Null-terminate the message
}

// Function: print_message(char *message)
void print_message(char *message) {
  printf("%s\n", message);
}