//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
// Embark on a celestial voyage through the digital ethereal realm with this visionary TCP/IP tapestry.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the celestial bodies involved in this cosmic dance.
#define PORT 8080
#define IP_ADDRESS "127.0.0.1"
#define BUFFER_SIZE 1024

// Begin the celestial transmission by creating a socket.
int main() {
  int client_socket;
  struct sockaddr_in server_address;

  // Establish a connection to the celestial server.
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    perror("Socket creation failed");
    return -1;
  }

  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  if (inet_pton(AF_INET, IP_ADDRESS, &server_address.sin_addr) <= 0) {
    perror("Invalid IP address");
    return -1;
  }

  // Initiate the cosmic handshake with the celestial server.
  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Connection failed");
    return -1;
  }

  // Prepare the message to be transmitted into the ethereal void.
  char message[] = "Greetings from the celestial realm!";

  // Send the message, embarking it on its journey through the astral plane.
  send(client_socket, message, strlen(message), 0);

  // Receive the celestial response from the server, a whisper from the cosmic abyss.
  char buffer[BUFFER_SIZE];
  int received_bytes;
  received_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
  if (received_bytes < 0) {
    perror("Message reception failed");
    return -1;
  }

  // Translate the celestial response into the mortal tongue.
  buffer[received_bytes] = '\0';

  // Echo the cosmic wisdom received from the depths of the ethereal expanse.
  printf("Message received from the celestial realm: %s\n", buffer);

  // Conclude the cosmic transmission, severing the celestial bond.
  close(client_socket);

  return 0;
}