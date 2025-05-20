//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_SIZE 4096

int main() {
  // Welcome the user to the application
  printf("Welcome to the Sherlock Holmes Internet Speed Test Application!\n");

  // Prompt the user for the IP address of the server to test
  char server_ip[MAX_SIZE];
  printf("Enter the IP address of the server to test: ");
  scanf("%s", server_ip);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return EXIT_FAILURE;
  }

  // Resolve the server's address
  struct hostent *server = gethostbyname(server_ip);
  if (server == NULL) {
    perror("Error resolving server address");
    return EXIT_FAILURE;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  server_addr.sin_addr = *((struct in_addr *)server->h_addr);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    return EXIT_FAILURE;
  }

  // Send a request to the server
  char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("Error sending request to server");
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  char response[MAX_SIZE];
  int bytes_received = recv(sockfd, response, MAX_SIZE, 0);
  if (bytes_received < 0) {
    perror("Error receiving response from server");
    return EXIT_FAILURE;
  }

  // Parse the response to get the content length
  char *content_length_str = strstr(response, "Content-Length:");
  if (content_length_str == NULL) {
    printf("Error finding Content-Length header in response\n");
    return EXIT_FAILURE;
  }
  content_length_str += strlen("Content-Length:");
  int content_length = atoi(content_length_str);

  // Calculate the download speed
  double download_speed = (double)content_length / bytes_received;

  // Print the download speed to the user
  printf("Download speed: %.2f MB/s\n", download_speed);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}