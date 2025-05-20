//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFF_SIZE 1024

// Handles error message printing and exits the program
void print_error(char* error_message) {
  fprintf(stderr, "%s", error_message);
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  // Check if the input arguments are correct
  if (argc != 3) {
    print_error("Usage: ./pop3client hostname port\n");
  }
  
  // Parse the command line arguments
  char* hostname = argv[1];
  int port = atoi(argv[2]);
  char buffer[MAX_BUFF_SIZE];
  
  // Initialize the socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    print_error("Failed to create the socket\n");
  }

  // Look up the address of the host
  struct hostent* host = gethostbyname(hostname);
  if (!host) {
    print_error("Could not get host IP address\n");
  }

  // Initiate the connect to the server
  struct sockaddr_in server_address;
  bzero((char *)&server_address, sizeof(server_address));
  server_address.sin_family = AF_INET;
  bcopy((char *)host->h_addr, (char *)&server_address.sin_addr.s_addr, host->h_length);
  server_address.sin_port = htons(port);
  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    print_error("Failed to connect to the server\n");
  }

  // Read the server welcome message
  int received_bytes = recv(client_socket, buffer, MAX_BUFF_SIZE, 0);
  if (received_bytes < 0) {
    print_error("Failed to receive data from the server\n");
  }
  printf("Received: %s\n", buffer);

  // Send the username
  printf("Enter the username: ");
  scanf("%s", buffer);
  snprintf(buffer, MAX_BUFF_SIZE, "USER %s\n", buffer);
  send(client_socket, buffer, strlen(buffer), 0);

  // Read the server response and check if it was successful
  received_bytes = recv(client_socket, buffer, MAX_BUFF_SIZE, 0);
  if (received_bytes < 0) {
    print_error("Failed to receive data from the server\n");
  }
  buffer[received_bytes] = '\0';
  if (buffer[0] == '-') {
    print_error("Failed to log in, incorrect username\n");
  }
  printf("Received: %s\n", buffer);

  // Send the password
  printf("Enter the password: ");
  scanf("%s", buffer);
  snprintf(buffer, MAX_BUFF_SIZE, "PASS %s\n", buffer);
  send(client_socket, buffer, strlen(buffer), 0);

  // Read the server response and check if it was successful
  received_bytes = recv(client_socket, buffer, MAX_BUFF_SIZE, 0);
  if (received_bytes < 0) {
    print_error("Failed to receive data from the server\n");
  }
  buffer[received_bytes] = '\0';
  if (buffer[0] == '-') {
    print_error("Failed to log in, incorrect password\n");
  }
  printf("Received: %s\n", buffer);

  // Send the LIST command to get the number of messages and their sizes
  snprintf(buffer, MAX_BUFF_SIZE, "LIST\n");
  send(client_socket, buffer, strlen(buffer), 0);

  // Read the server response and print the message sizes
  received_bytes = recv(client_socket, buffer, MAX_BUFF_SIZE, 0);
  if (received_bytes < 0) {
    print_error("Failed to receive data from the server\n");
  }
  buffer[received_bytes] = '\0';
  printf("Received: %s\n", buffer);
  char* end_of_sizes = strchr(buffer, '\n');
  if (!end_of_sizes) {
    print_error("Failed to parse message sizes\n");
  }
  int num_sizes = strtol(&buffer[4], NULL, 10);
  printf("Found %d messages\n", num_sizes);
  while (num_sizes-- > 0) {
    int size = 0;
    sscanf(end_of_sizes, "%d", &size);
    printf("Message size: %d\n", size);
    end_of_sizes = strchr(end_of_sizes + 1, '\n');
    if (!end_of_sizes) {
      break;
    }
  }

  // Select the message to download
  int message_id = 0;
  printf("Enter the message number to download: ");
  scanf("%d", &message_id);
  snprintf(buffer, MAX_BUFF_SIZE, "RETR %d\n", message_id);
  send(client_socket, buffer, strlen(buffer), 0);

  // Read the message from the server
  int total_received = 0;
  FILE* message_file = fopen("message.txt", "w");
  while ((received_bytes = recv(client_socket, buffer, MAX_BUFF_SIZE, 0)) > 0) {
    fwrite(buffer, 1, received_bytes, message_file);
    total_received += received_bytes;
  }
  fclose(message_file);
  printf("Received %d bytes\n", total_received);

  // Quit
  snprintf(buffer, MAX_BUFF_SIZE, "QUIT\n");
  send(client_socket, buffer, strlen(buffer), 0);

  // Close the socket
  close(client_socket);

  return 0;
}