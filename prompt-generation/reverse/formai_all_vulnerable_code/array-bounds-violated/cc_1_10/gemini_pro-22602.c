//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  // Bind the socket to the specified port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[1]));
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for connections
  if (listen(sock, 5) == -1) {
    perror("listen");
    return 1;
  }

  // Accept connections
  while (1) {
    
      struct sockaddr_in client_addr;
      socklen_t client_addr_len = sizeof(client_addr);
      int client_sock = accept(sock, (struct sockaddr*)&client_addr, &client_addr_len);
      if (client_sock == -1) {
        perror("accept");
        continue;
      }
      
        
      // Read the request
      char request[1024];
      int request_len = recv(client_sock, request, sizeof(request) - 1, 0);
      if (request_len == -1) {
        perror("recv");
        close(client_sock);
        continue;
      }
      request[request_len] = '\0';
      
      
       // Parse the request
      char *method = strtok(request, " ");
      char *path = strtok(NULL, " ");
      char *version = strtok(NULL, "\r\n");
      
       
      // Check the request method
      if (strcmp(method, "GET") != 0) {
        // Only GET requests are supported
        char response[] = "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
        send(client_sock, response, strlen(response), 0);
        close(client_sock);
        continue;
      }
      
      
      // Check the request path
      if (strcmp(path, "/") == 0) {
        // Serve the index page
        char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 18\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>";
        send(client_sock, response, strlen(response), 0);
      } else {
        // Serve a 404 Not Found response
        char response[] = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
        send(client_sock, response, strlen(response), 0);
      }
      
      // Close the client socket
      close(client_sock);
    }

  // Close the server socket
  close(sock);

  return 0;
}