//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  // Get ready to party! Let's get the user's input for the port where we'll be listening.
  printf("Yo, what port should I set up shop on? (1024 to 65535): ");
  int port;
  scanf("%d", &port);

  // Create a socket! This is how we'll chat with the world.
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Set up the address where we'll be listening for requests.
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);

  // Bind the socket to the address. This is like putting up a sign saying "HTTP Proxy over here!"
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Bind failed");
    return 1;
  }

  // Listen for incoming connections. This is like opening the door to our virtual party.
  if (listen(server_socket, 5) == -1) {
    perror("Listen failed");
    return 1;
  }

  printf("Alright, party's on! I'm listening for requests on port %d.\n", port);

  // Let's boogie! We'll keep looping, waiting for requests.
  while (1) {
    // We got a connection! Let's get ready to rock.
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);

    // Read the request from the client. This is like opening a letter from a secret admirer.
    char request[1024];
    memset(request, 0, sizeof(request));
    recv(client_socket, request, sizeof(request) - 1, 0);

    // Parse the request. Let's figure out where this request wants to go.
    char hostname[256];
    char path[256];
    sscanf(request, "GET %s %s", hostname, path);

    // Connect to the remote server. This is like calling the secret admirer on the phone.
    struct sockaddr_in remote_address;
    memset(&remote_address, 0, sizeof(remote_address));
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(80);
    remote_address.sin_addr.s_addr = inet_addr(hostname);

    int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(remote_socket, (struct sockaddr *)&remote_address, sizeof(remote_address)) == -1) {
      // Oh no, the secret admirer hung up! Let's tell the client.
      char error_message[] = "HTTP/1.1 502 Bad Gateway\r\n\r\n";
      send(client_socket, error_message, sizeof(error_message) - 1, 0);
      close(client_socket);
      continue;
    }

    // Forward the request to the remote server. This is like passing the phone to the secret admirer.
    send(remote_socket, request, strlen(request), 0);

    // Read the response from the remote server. This is like listening to the secret admirer's sweet voice.
    char response[1024];
    memset(response, 0, sizeof(response));
    recv(remote_socket, response, sizeof(response) - 1, 0);

    // Send the response back to the client. This is like giving the secret admirer a kiss on the cheek.
    send(client_socket, response, strlen(response), 0);

    // Close the sockets. This is like hanging up the phone after a great conversation.
    close(client_socket);
    close(remote_socket);
  }

  // If we ever got here, it means something went wrong. Let's pack up and go home.
  close(server_socket);
  return 0;
}