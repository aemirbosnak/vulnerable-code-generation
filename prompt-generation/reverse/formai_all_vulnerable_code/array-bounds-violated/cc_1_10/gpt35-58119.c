//FormAI DATASET v1.0 Category: Socket programming ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main()
{
  int server_socket, client_socket, bytes_received, bytes_sent;
  struct sockaddr_in server_address, client_address;
  char buffer[BUFFER_SIZE];

  // create server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1)
  {
    perror("Error creating server socket");
    exit(EXIT_FAILURE);
  }

  // set server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(12345);

  // bind server socket to address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
  {
    perror("Error binding server socket");
    exit(EXIT_FAILURE);
  }

  // listen for incoming connections
  if (listen(server_socket, 5) == -1)
  {
    perror("Error listening on server socket");
    exit(EXIT_FAILURE);
  }
  
  printf("Server is listening on port 12345...\n");

  // accept incoming connections
  socklen_t client_address_size = sizeof(client_address);
  client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
  if (client_socket == -1)
  {
    perror("Error accepting incoming connection");
    exit(EXIT_FAILURE);
  }

  printf("Received connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

  // receive data from client
  bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
  if (bytes_received == -1)
  {
    perror("Error receiving data from client");
    exit(EXIT_FAILURE);
  }
  
  buffer[bytes_received] = '\0'; // add null terminator

  printf("Received message from client: %s\n", buffer);

  // send response back to client
  char response[] = "Hello from server!";
  bytes_sent = send(client_socket, response, strlen(response), 0);
  if (bytes_sent == -1)
  {
    perror("Error sending response to client");
    exit(EXIT_FAILURE);
  }

  printf("Response sent to client: %s\n", response);

  // close sockets
  close(client_socket);
  close(server_socket);

  return 0;
}