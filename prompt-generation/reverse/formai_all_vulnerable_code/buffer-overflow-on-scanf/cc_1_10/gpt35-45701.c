//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int sock = 0;
  struct sockaddr_in serv_addr;
  char buffer[1024] = {0};

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket creation error");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    perror("Invalid address/ Address not supported");
    return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connection Failed");
    return -1;
  }

  printf("Connected to server.\n");
  
  while (1) {
    printf("Enter command: ");
    scanf("%s", buffer);
    if (strcmp(buffer, "exit") == 0) {
      break;
    }

    send(sock, buffer, strlen(buffer), 0);
    printf("Waiting for response...\n");
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = read(sock, buffer, 1024);
    printf("Response: %s\n", buffer);
    memset(buffer, 0, sizeof(buffer));
  }

  close(sock);

  return 0;
}