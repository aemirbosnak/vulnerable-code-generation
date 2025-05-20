//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

  // Check for correct usage
  if (argc != 3) {
    printf("Usage: %s <port_number> <proxy_server>\n", argv[0]);
    exit(1);
  }

  // Initialize socket variables
  int clientSocket, serverSocket;
  int clientPort = atoi(argv[1]);  // Port number for client
  int serverPort = 80;             // Port number for server
  struct hostent *server;
  struct sockaddr_in clientAddr, serverAddr;
  char buffer[BUFFER_SIZE];

  // Create client socket and bind to port
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  bzero((char *) &clientAddr, sizeof(clientAddr));
  clientAddr.sin_family = AF_INET;
  clientAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  clientAddr.sin_port = htons(clientPort);

  // Bind client socket
  if (bind(clientSocket, (struct sockaddr *) &clientAddr, sizeof(clientAddr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  // Listen for incoming connections
  listen(clientSocket,1);
  printf("Proxy server listening on port %d...\n", clientPort);

  // Loop endlessly to accept connections
  while (1) {

    // Accept client connection
    socklen_t clientLen = sizeof(clientAddr);
    int clientConnection = accept(clientSocket, (struct sockaddr *) &clientAddr, &clientLen);
    if (clientConnection < 0) {
      perror("ERROR on accept");
      exit(1);
    }

    // Create server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
      perror("ERROR opening socket");
      exit(1);
    }

    // Convert server IP to hostent struct
    server = gethostbyname(argv[2]);
    if (server == NULL) {
      fprintf(stderr,"ERROR, no such host\n");
      exit(1);
    }

    // Initialize server socket variables
    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serverAddr.sin_addr.s_addr, server->h_length);
    serverAddr.sin_port = htons(serverPort);

    // Connect to server
    if (connect(serverSocket,(struct sockaddr *) &serverAddr,sizeof(serverAddr)) < 0) {
      perror("ERROR connecting");
      exit(1);
    }

    // Loop to read and forward incoming data from client
    while (1) {

      // Clear buffers
      bzero(buffer,BUFFER_SIZE);

      // Read data from client
      int numBytes = read(clientConnection, buffer, BUFFER_SIZE);
      if (numBytes <= 0) {
        break;
      }

      // Write data to server
      write(serverSocket, buffer, numBytes);

      // Loop to read and forward incoming data from server
      while (1) {

        // Clear buffers
        bzero(buffer,BUFFER_SIZE);

        // Read data from server
        numBytes = read(serverSocket, buffer, BUFFER_SIZE);
        if (numBytes <= 0) {
          break;
        }

        // Write data to client
        write(clientConnection, buffer, numBytes);

      }

      // Close server socket
      close(serverSocket);

      // Close client socket
      close(clientConnection);

    }
  }
  return 0;
}