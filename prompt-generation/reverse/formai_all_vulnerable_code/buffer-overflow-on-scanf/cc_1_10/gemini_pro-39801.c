//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Let's fire up the engines and get ready for an unforgettable networking adventure!

// The server - a majestic lighthouse, guiding ships through treacherous waters:
int main_server() {
  // Declare our communication beacon:
  int server_socket;
  
  // Set up the socket, like a sturdy ship preparing for its voyage:
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Socket creation failed! Oh no, our ship can't set sail!");
    exit(EXIT_FAILURE);
  }
  
  // Define the port, like a predetermined destination:
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  // Bind the socket to the port, like anchoring our ship in the harbor:
  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    perror("Bind failed! Our ship can't leave the dock!");
    exit(EXIT_FAILURE);
  }
  
  // Listen up for incoming connections, like a lookout scanning the horizon:
  if (listen(server_socket, 5) == -1) {
    perror("Listen failed! No ships on the horizon!");
    exit(EXIT_FAILURE);
  }
  
  printf("Server is up and running! Ready to welcome ships from afar.\n");
  
  // Accept incoming connections, like welcoming ships into the harbor:
  int client_socket;
  socklen_t client_address_length;
  struct sockaddr_in client_address;
  while (1) {
    client_address_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
    if (client_socket == -1) {
      perror("Accept failed! No ships approaching!");
      continue;
    }
    
    char message[] = "Welcome aboard, shipmate! Your message is received loud and clear.\n";
    
    // Send the message to the client, like delivering a treasure map:
    if (send(client_socket, message, strlen(message), 0) == -1) {
      perror("Send failed! The treasure map couldn't reach the ship!");
      close(client_socket);
      continue;
    }
    
    printf("Message sent! Bon voyage, shipmate.\n");
    
    // Close the connection, like waving goodbye to the departing ship:
    close(client_socket);
  }
  
  // Close the server socket, like bidding farewell to the last ship in the harbor:
  close(server_socket);
  
  return 0;
}

// The client - a daring ship, venturing into the vast ocean:
int main_client() {
  // Declare our trusty ship:
  int client_socket;
  
  // Set up the ship, like a skilled captain preparing for the journey:
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("Socket creation failed! Our ship can't leave port!");
    exit(EXIT_FAILURE);
  }
  
  // Define the destination, like charting a course across the sea:
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  // Connect to the server, like setting sail for adventure:
  if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    perror("Connect failed! Our ship can't reach the horizon!");
    exit(EXIT_FAILURE);
  }
  
  // Send a message to the server, like shouting "Ahoy!" across the waves:
  char message[] = "Ahoy there, mateys! We've come from afar with a message in our sails.\n";
  if (send(client_socket, message, strlen(message), 0) == -1) {
    perror("Send failed! Our message got lost in the storm!");
    close(client_socket);
    exit(EXIT_FAILURE);
  }
  
  // Receive a response from the server, like listening for the sound of distant drums:
  char buffer[1024];
  int received_bytes = recv(client_socket, buffer, sizeof(buffer), 0);
  if (received_bytes == -1) {
    perror("Receive failed! No drums in sight!");
    close(client_socket);
    exit(EXIT_FAILURE);
  }
  
  // Print the response, like deciphering the ancient runes on a treasure map:
  printf("Message received: %s\n", buffer);
  
  // Close the connection, like dropping anchor in a safe harbor:
  close(client_socket);
  
  return 0;
}

int main() {
  // The main function - the captain's quarters, where the journey begins:
  
  // Let's choose our adventure - server or client?
  printf("Avast there, matey! Choose your destiny:\n1. Be the majestic lighthouse, guiding ships through the night (Server)\n2. Embark on a daring voyage, seeking treasure (Client)\n");
  int choice;
  scanf("%d", &choice);
  
  switch (choice) {
    // Server - guiding the way:
    case 1:
      printf("Prepare your lighthouse, matey! Let's welcome ships from distant lands.\n");
      return main_server();
    
    // Client - setting sail for adventure:
    case 2:
      printf("Hoist the sails, shipmate! Let's sail the seas and seek our fortune.\n");
      return main_client();
    
    // Invalid choice - lost at sea:
    default:
      printf("Arrr, ye be lost at sea, matey! Choose wisely next time.\n");
      return EXIT_FAILURE;
  }
  
  return 0;
}