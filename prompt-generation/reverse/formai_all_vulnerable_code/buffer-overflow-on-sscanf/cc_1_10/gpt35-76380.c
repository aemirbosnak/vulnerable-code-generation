//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080
#define ADDR "127.0.0.1" // Localhost
#define BACKLOG 10
#define BUFSIZE 4096

void handle_client(int client_socket) {
  char buffer[BUFSIZE];
  int bytes_recv, bytes_send;
  struct sockaddr_in endpoint;
  socklen_t len = sizeof(endpoint);
  
  if ((bytes_recv = recv(client_socket, buffer, BUFSIZE, 0)) == -1) {
    perror("Error receiving");
    exit(1);
  }
  
  // Parse the request
  char method[10], path[256], version[20];
  sscanf(buffer, "%s %s %s", method, path, version);
  
  // Only http requests supported
  if (strncmp(method, "GET", 3) != 0 || strncmp(version, "HTTP/1.1", 8) != 0) {
    char* error_msg = "HTTP/1.1 400 Bad Request\r\n\r\n";
    send(client_socket, error_msg, strlen(error_msg), 0);
    exit(1);
  }
  
  // Strip the initial slash from the path
  memmove(path, path+1, strlen(path));
  
  // Get the IP address of the requested site
  struct hostent* site = gethostbyname(path);
  if (site == NULL) {
    char* error_msg = "HTTP/1.1 404 Not Found\r\n\r\n";
    send(client_socket, error_msg, strlen(error_msg), 0);
    exit(1);
  }
  char ip[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, site->h_addr, ip, INET_ADDRSTRLEN);
  
  // Connect to the site
  int site_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (site_socket == -1) {
    perror("Error creating socket");
    exit(1);
  }
  bzero(&endpoint, sizeof(endpoint));
  endpoint.sin_family = AF_INET	;
  endpoint.sin_port = htons(80);
  endpoint.sin_addr = *((struct in_addr *)site->h_addr);
  if (connect(site_socket, (struct sockaddr *)&endpoint, sizeof(endpoint)) == -1) {
    perror("Error connecting");
    exit(1);
  }
  
  // Construct the request for the site
  char url[256];
  snprintf(url, 256, "GET / HTTP/1.1\r\nhost: %s\r\nConnection: close\r\n\r\n", path);
  
  // Send the request to the site
  send(site_socket, url, strlen(url), 0);
  
  // Forward the response from the site to the client
  int total_bytes = 0;
  while ((bytes_recv = recv(site_socket, buffer, BUFSIZE, 0)) > 0) {
    bytes_send = send(client_socket, buffer, bytes_recv, 0);
    total_bytes += bytes_send;
  }
  printf("Sent %d bytes to client\n", total_bytes);
  
  // Clean up
  close(site_socket);
  close(client_socket);
  exit(0);
}

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  socklen_t len = sizeof(struct sockaddr_in);
  
  // Create a listening socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error creating socket");
    exit(1);
  }
  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr(ADDR);
  if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error binding");
    exit(1);
  }
  if (listen(server_socket, BACKLOG) == -1) {
    perror("Error listening");
    exit(1);
  }
  
  while (1) {
    // Accept a client connection
    printf("Waiting for connection...\n");
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &len);
    if (client_socket == -1) {
      perror("Error accepting");
      continue;
    }
    printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    // Handle the client request in a new process
    pid_t pid;
    if ((pid = fork()) == -1) {
      perror("Error forking");
      exit(1);
    } else if (pid == 0) { // child process
      close(server_socket);
      handle_client(client_socket);
      exit(0);
    } else { // parent process
      close(client_socket);
    }
  }
  return 0;
}