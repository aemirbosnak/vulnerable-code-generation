//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// The surrealist muse whispers in our ear
#define GOLDEN_RATIO 1.618033988749895
#define PI 3.141592653589793
#define E 2.718281828459045
#define SQRT_OF_2 1.414213562373095

// The socket, our portal to the ethereal network
int socket_descriptor;

// The server's address, a celestial coordinate
struct sockaddr_in server_address;

// The command buffer, where our ethereal whispers are stored
char command_buffer[1024];

// The response buffer, where the server's celestial echoes reverberate
char response_buffer[1024];

// The port number, a gateway to the digital ether
int port_number;

// The hostname, a celestial beacon guiding our journey
char hostname[1024];

// The username, a celestial key unlocking the secrets of the network
char username[1024];

// The password, a celestial cipher protecting our ethereal treasures
char password[1024];

// The path, a labyrinthine thread winding through the digital realm
char path[1024];

// The filename, a celestial artifact we seek to download
char filename[1024];

// The surrealist function, our guide through the labyrinth of possibilities
int surrealist_function(int n) {
  if (n == 0) {
    return GOLDEN_RATIO;
  } else if (n == 1) {
    return PI;
  } else if (n == 2) {
    return E;
  } else if (n == 3) {
    return SQRT_OF_2;
  } else {
    return surrealist_function(n - 1) + surrealist_function(n - 2);
  }
}

// The main function, our cosmic adventure begins
int main(int argc, char **argv) {
  // Parse the surrealist incantations from the command line
  if (argc != 7) {
    printf("Usage: %s <hostname> <port> <username> <password> <path> <filename>\n", argv[0]);
    return 1;
  }
  strcpy(hostname, argv[1]);
  port_number = atoi(argv[2]);
  strcpy(username, argv[3]);
  strcpy(password, argv[4]);
  strcpy(path, argv[5]);
  strcpy(filename, argv[6]);

  // Create a celestial socket, a portal to the ethereal network
  socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_descriptor == -1) {
    perror("Could not create socket");
    return 1;
  }

  // Resolve the hostname, a celestial beacon guiding our journey
  struct hostent *host_entry = gethostbyname(hostname);
  if (host_entry == NULL) {
    perror("Could not resolve hostname");
    return 1;
  }

  // Initialize the server's address, a celestial coordinate
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port_number);
  memcpy(&server_address.sin_addr, host_entry->h_addr, host_entry->h_length);

  // Connect to the server, a celestial encounter
  if (connect(socket_descriptor, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Could not connect to server");
    return 1;
  }

  // Send the username, a celestial key unlocking the secrets of the network
  sprintf(command_buffer, "USER %s\r\n", username);
  if (send(socket_descriptor, command_buffer, strlen(command_buffer), 0) == -1) {
    perror("Could not send username");
    return 1;
  }

  // Receive the server's response, a celestial echo reverberating through the void
  if (recv(socket_descriptor, response_buffer, sizeof(response_buffer), 0) == -1) {
    perror("Could not receive server response");
    return 1;
  }

  // Send the password, a celestial cipher protecting our ethereal treasures
  sprintf(command_buffer, "PASS %s\r\n", password);
  if (send(socket_descriptor, command_buffer, strlen(command_buffer), 0) == -1) {
    perror("Could not send password");
    return 1;
  }

  // Receive the server's response, a celestial echo reverberating through the void
  if (recv(socket_descriptor, response_buffer, sizeof(response_buffer), 0) == -1) {
    perror("Could not receive server response");
    return 1;
  }

  // Change to the specified path, a labyrinthine thread winding through the digital realm
  sprintf(command_buffer, "CWD %s\r\n", path);
  if (send(socket_descriptor, command_buffer, strlen(command_buffer), 0) == -1) {
    perror("Could not change directory");
    return 1;
  }

  // Receive the server's response, a celestial echo reverberating through the void
  if (recv(socket_descriptor, response_buffer, sizeof(response_buffer), 0) == -1) {
    perror("Could not receive server response");
    return 1;
  }

  // Set the surrealist binary mode, a celestial dance of bits and bytes
  sprintf(command_buffer, "TYPE I\r\n");
  if (send(socket_descriptor, command_buffer, strlen(command_buffer), 0) == -1) {
    perror("Could not set binary mode");
    return 1;
  }

  // Receive the server's response, a celestial echo reverberating through the void
  if (recv(socket_descriptor, response_buffer, sizeof(response_buffer), 0) == -1) {
    perror("Could not receive server response");
    return 1;
  }

  // Open the file for writing, a celestial canvas where the digital artifact will be painted
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("Could not open file");
    return 1;
  }

  // Send the RETR command, a celestial incantation summoning the digital artifact
  sprintf(command_buffer, "RETR %s\r\n", filename);
  if (send(socket_descriptor, command_buffer, strlen(command_buffer), 0) == -1) {
    perror("Could not send RETR command");
    return 1;
  }

  // Receive the server's response, a celestial echo reverberating through the void
  if (recv(socket_descriptor, response_buffer, sizeof(response_buffer), 0) == -1) {
    perror("Could not receive server response");
    return 1;
  }

  // Read the data from the socket, a celestial stream of bits and bytes
  int bytes_received;
  while (bytes_received = recv(socket_descriptor, response_buffer, sizeof(response_buffer), 0)) {
    if (bytes_received == -1) {
      perror("Could not receive data from server");
      return 1;
    } else if (bytes_received == 0) {
      break;
    } else {
      fwrite(response_buffer, 1, bytes_received, file);
    }
  }

  // Close the file, a celestial portal sealed shut
  fclose(file);

  // Send the QUIT command, a celestial farewell to the server
  sprintf(command_buffer, "QUIT\r\n");
  if (send(socket_descriptor, command_buffer, strlen(command_buffer), 0) == -1) {
    perror("Could not send QUIT command");
    return 1;
  }

  // Close the socket, a celestial gateway closed
  close(socket_descriptor);

  // The surrealist journey ends, the digital artifact safely downloaded
  return 0;
}