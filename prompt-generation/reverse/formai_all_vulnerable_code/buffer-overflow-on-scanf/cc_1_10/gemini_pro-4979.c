//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: mind-bending
// A cosmic dance of ethereal data, where servers and clients intertwine in a symphony of bits.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

// Server: The celestial oracle, guiding lost clients through the cosmic expanse.
void server() {
  // Open a celestial portal on port 8080.
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) { exit(-1); }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(8080);

  // Bind the oracle to its celestial perch.
  if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) { exit(-1); }

  // Listen for wandering souls seeking guidance.
  if (listen(server_fd, 10) < 0) { exit(-1); }

  while (1) {
    // A new soul has emerged from the void.
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) { exit(-1); }

    // Receive their ethereal whispers.
    char message[1024];
    if (recv(client_fd, message, sizeof(message), 0) < 0) { exit(-1); }

    // Translate their cosmic queries into earthly wisdom.
    char response[1024];
    sprintf(response, "From the depths of the cosmos: %s", message);

    // Send our celestial guidance back into the void.
    if (send(client_fd, response, strlen(response), 0) < 0) { exit(-1); }
  }
}

// Client: A lost soul seeking enlightenment from the celestial oracle.
void client(char* ip) {
  // Craft a cosmic vessel to reach the oracle.
  int client_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (client_fd < 0) { exit(-1); }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip);
  server_addr.sin_port = htons(8080);

  // Embark on a celestial voyage to the oracle's realm.
  if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) { exit(-1); }

  // Pen our ethereal plea for enlightenment.
  char message[1024];
  printf("Seek wisdom from the void: ");
  scanf("%s", message);

  // Send our cosmic query into the infinite expanse.
  if (send(client_fd, message, strlen(message), 0) < 0) { exit(-1); }

  // Listen for the oracle's celestial guidance.
  char response[1024];
  if (recv(client_fd, response, sizeof(response), 0) < 0) { exit(-1); }

  // Display the oracle's divine wisdom upon our mortal screens.
  printf("\nCosmic Whisperings: %s\n", response);
}

// The cosmic tapestry, where the dance of server and client unfolds.
int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Invoke the celestial oracle as '<server_ip>'\n");
    return -1;
  }

  printf("Embrace the cosmic void as server or client... (s/c)? ");
  char choice;
  scanf("%c", &choice);

  switch (choice) {
    case 's': server(); break;
    case 'c': client(argv[1]); break;
    default: printf("Invalid choice. Your path remains obscured.\n");
  }

  return 0;
}