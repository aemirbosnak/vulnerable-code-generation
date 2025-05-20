//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
  int sock;
  struct sockaddr_in server_address;
  char buffer[BUFFER_SIZE];
  char username[BUFFER_SIZE];
  char password[BUFFER_SIZE];
  char command[BUFFER_SIZE];
  int response_code = 0;

  if (argc != 3) {
    printf("Usage: ./pop3_client <server_address> <port>\n");
    exit(1);
  }

  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(atoi(argv[2]));

  if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
    perror("Invalid address or address not supported");
    exit(1);
  }

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Connection failed");
    exit(1);
  }

  read(sock, buffer, BUFFER_SIZE);
  printf("%s", buffer);
  memset(buffer, 0, BUFFER_SIZE);

  printf("Username: ");
  fgets(username, BUFFER_SIZE, stdin);
  username[strcspn(username, "\n")] = 0;
  printf("Password: ");
  fgets(password, BUFFER_SIZE, stdin);
  password[strcspn(password, "\n")] = 0;

  sprintf(command, "USER %s\r\n", username);
  write(sock, command, strlen(command));
  memset(command, 0, BUFFER_SIZE);
  read(sock, buffer, BUFFER_SIZE);
  printf("%s", buffer);
  sscanf(buffer, "%d", &response_code);
  memset(buffer, 0, BUFFER_SIZE);

  if (response_code == 331) {
    sprintf(command, "PASS %s\r\n", password);
    write(sock, command, strlen(command));
    memset(command, 0, BUFFER_SIZE);
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    sscanf(buffer, "%d", &response_code);
    memset(buffer, 0, BUFFER_SIZE);
  }

  if (response_code == 230) {
    sprintf(command, "LIST\r\n");
    write(sock, command, strlen(command));
    memset(command, 0, BUFFER_SIZE);
    read(sock, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    sscanf(buffer, "%d", &response_code);

    while (response_code == 110 || response_code == 120) {
      memset(buffer, 0, BUFFER_SIZE);
      read(sock, buffer, BUFFER_SIZE);
      printf("%s", buffer);
      sscanf(buffer, "%d", &response_code);
    }
  }

  if (response_code == 172 || response_code == 173) {
    perror("Authentication failed");
    exit(1);
  }

  close(sock);
  
  return 0;
}