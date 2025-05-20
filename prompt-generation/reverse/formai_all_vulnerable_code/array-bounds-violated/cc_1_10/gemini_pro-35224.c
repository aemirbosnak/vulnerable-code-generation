//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// A spaceship is traveling through the vastness of space, seeking knowledge and adventure.
// It encounters a distant star system, and decides to make contact with a planet orbiting one of the stars.
// The spaceship sends a message to the planet, hoping to establish communication.

int main() {
  // The spaceship creates a socket, a gateway to the cosmic network.
  int spaceship_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (spaceship_socket == -1) {
    perror("Failed to create socket");
    return EXIT_FAILURE;
  }

  // The spaceship sets its course for the planet.
  struct sockaddr_in planet_address;
  memset(&planet_address, 0, sizeof(planet_address));
  planet_address.sin_family = AF_INET;
  planet_address.sin_port = htons(8080);
  inet_pton(AF_INET, "192.168.1.100", &planet_address.sin_addr);

  // The spaceship initiates contact with the planet.
  if (connect(spaceship_socket, (struct sockaddr*) &planet_address, sizeof(planet_address)) == -1) {
    perror("Failed to connect");
    return EXIT_FAILURE;
  }

  // The spaceship sends a message to the planet, eager to share knowledge and learn.
  char message[] = "Greetings from the stars! We come in peace.";
  if (send(spaceship_socket, message, strlen(message), 0) == -1) {
    perror("Failed to send message");
    return EXIT_FAILURE;
  }

  // The spaceship waits for a response from the planet, its sensors scanning for any signs of communication.
  char response[1024];
  int response_length = recv(spaceship_socket, response, sizeof(response), 0);
  if (response_length == -1) {
    perror("Failed to receive response");
    return EXIT_FAILURE;
  }

  // The spaceship translates the response from the planet, its systems deciphering the alien language.
  response[response_length] = '\0';
  printf("Response from planet: %s\n", response);

  // The spaceship bids farewell to the planet, its journey continuing through the cosmos.
  close(spaceship_socket);
  return EXIT_SUCCESS;
}