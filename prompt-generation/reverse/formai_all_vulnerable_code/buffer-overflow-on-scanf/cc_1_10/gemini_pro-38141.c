//GEMINI-pro DATASET v1.0 Category: Networking ; Style: irregular
// Enter the mysterious realm of network programming with this enigmatic C program!

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Delve into the twilight of sockets and uncover their secrets...
int create_socket(void) {
  int sockfd;

  // Begin the incantation to summon a pristine socket.
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    // Alas! The socket failed to materialize from the ether.
    perror("Socket creation failed!");
    return -1;
  }

  return sockfd;
}

// Embark on a celestial voyage to a specific destination.
int connect_socket(int sockfd, const char *ip_address, unsigned short port) {
  struct sockaddr_in socket_address;

  // Craft a celestial beacon that points towards our destination.
  socket_address.sin_family = AF_INET;
  socket_address.sin_addr.s_addr = inet_addr(ip_address);
  socket_address.sin_port = htons(port);

  // Embark on the ethereal journey, connecting to the distant server.
  if (connect(sockfd, (struct sockaddr *)&socket_address, sizeof(socket_address)) == -1) {
    // Alas! The connection was lost amidst the cosmic void.
    perror("Connection failed!");
    return -1;
  }

  return 0;
}

// Transmit our ethereal whispers to the far reaches of the network.
int send_message(int sockfd, const char *message) {
  int bytes_sent;

  // Encode our message in ethereal runes and send it forth.
  bytes_sent = send(sockfd, message, strlen(message), 0);

  if (bytes_sent == -1) {
    // Alas! Our message was lost in the celestial expanse.
    perror("Message transmission failed!");
    return -1;
  }

  return bytes_sent;
}

// Unveil the celestial whispers that reach our shores.
int receive_message(int sockfd, char *buffer, size_t buffer_size) {
  int bytes_received;

  // Prepare a celestial vessel to receive the incoming message.
  bytes_received = recv(sockfd, buffer, buffer_size, 0);

  if (bytes_received == -1) {
    // Alas! The celestial whispers were lost in the cosmic void.
    perror("Message reception failed!");
    return -1;
  }

  return bytes_received;
}

// Close the ethereal portal, severing our connection to the distant realm.
int close_socket(int sockfd) {
  // Seal the gateway to the celestial dimension, releasing the socket to the void.
  if (close(sockfd) == -1) {
    // Alas! The socket could not be closed, leaving a rift in the fabric of the universe.
    perror("Socket closure failed!");
    return -1;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int sockfd;
  char buffer[1024];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
    return 1;
  }

  // Embark on a cosmic adventure! First, conjure a socket.
  sockfd = create_socket();
  if (sockfd == -1) {
    return 1;
  }

  // Now, traverse the ethereal void and connect to the celestial destination.
  if (connect_socket(sockfd, argv[1], atoi(argv[2])) == -1) {
    close_socket(sockfd);
    return 1;
  }

  // Send our celestial whispers to the far reaches of the universe.
  printf("Enter a message to send to the celestial realm (or type \"exit\" to depart): ");
  while (1) {
    scanf("%s", buffer);

    if (strcmp(buffer, "exit") == 0) {
      break;
    }

    send_message(sockfd, buffer);

    // Prepare to receive celestial echoes from the distant realm.
    receive_message(sockfd, buffer, sizeof(buffer));

    // Decipher the celestial echoes and unveil their ethereal secrets.
    printf("Celestial echo: %s\n", buffer);
  }

  // Our cosmic journey draws to a close. Sever the connection to the celestial realm.
  close_socket(sockfd);

  return 0;
}