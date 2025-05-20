//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

int main() {
  int client_socket, bytes, sent, received;
  char hostname[MAXSIZE], username[MAXSIZE], password[MAXSIZE], filename[MAXSIZE], command[MAXSIZE], buffer[MAXSIZE];
  struct sockaddr_in server_address;

  // Prompt user for hostname, username and password
  printf("Enter the hostname: ");
  scanf("%s", hostname);
  printf("Enter the username: ");
  scanf("%s", username);
  printf("Enter the password: ");
  scanf("%s", password);

  // Establish connection with server
  if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Error: Could not create socket");
    return 1;
  }

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(21);
  inet_pton(AF_INET, hostname, &server_address.sin_addr);

  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("\n Connection Failed");
    return 1;
  }

  // Receive and print server welcome message
  received = recv(client_socket, buffer, MAXSIZE, 0);
  buffer[received] = '\0';
  printf("%s\n",buffer);

  // Send username
  sprintf(command, "USER %s\r\n", username);
  sent = send(client_socket, command, strlen(command), 0);
  received = recv(client_socket, buffer, MAXSIZE, 0);
  buffer[received] = '\0';
  printf("%s\n", buffer);

  // Send password
  sprintf(command, "PASS %s\r\n", password);
  sent = send(client_socket, command, strlen(command), 0);
  received = recv(client_socket, buffer, MAXSIZE, 0);
  buffer[received] = '\0';
  printf("%s\n", buffer);

  // Prompt user for filename to download and send request
  printf("Enter filename to download: ");
  scanf("%s", filename);

  sprintf(command, "RETR %s\r\n", filename);
  sent = send(client_socket, command, strlen(command), 0);

  // Receive file
  FILE *fp = fopen(filename, "w");
  while ((received = read(client_socket, buffer, MAXSIZE)) > 0) {
    fwrite(buffer, 1, received, fp);
  }
  fclose(fp);

  // Close connection
  sprintf(command, "QUIT\r\n");
  sent = send(client_socket, command, strlen(command), 0);
  received = recv(client_socket, buffer, MAXSIZE, 0);
  buffer[received] = '\0';
  printf("%s\n", buffer);
  close(client_socket);

  return 0;
}