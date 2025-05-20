//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: optimized
// Website Uptime Monitor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 256

int main(int argc, char *argv[]) {
  char url[MAX_LINE];
  int port;
  int sockfd;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[MAX_LINE];
  int n;

  // Check if the URL is provided as a command-line argument
  if (argc < 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }
  strcpy(url, argv[1]);

  // Extract the hostname and port from the URL
  char *hostname = strtok(url, ":");
  char *port_str = strtok(NULL, ":");
  port = atoi(port_str);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Get the address of the server
  server = gethostbyname(hostname);
  if (server == NULL) {
    perror("Error getting server address");
    return 1;
  }

  // Connect to the server
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(port);
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    return 1;
  }

  // Send the request to the server
  char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
  send(sockfd, request, strlen(request), 0);

  // Receive the response from the server
  bzero(buffer, MAX_LINE);
  n = recv(sockfd, buffer, MAX_LINE, 0);
  if (n < 0) {
    perror("Error receiving response");
    return 1;
  }

  // Print the response
  printf("Response: %s\n", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}