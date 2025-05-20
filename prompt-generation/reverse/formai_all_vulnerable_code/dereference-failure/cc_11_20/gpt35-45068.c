//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 4096 // Maximum buffer size for incoming messages

int main(int argc, char *argv[]) {

  // Parse command line arguments
  if (argc < 4) {
    printf("Usage: %s <server-ip> <username> <password>\n", argv[0]);
    return 1;
  }

  char *server_ip = argv[1];
  char *username = argv[2];
  char *password = argv[3];

  // Connect to server
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Failed to create socket");
    return 1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(server_ip);
  server_addr.sin_port = htons(110);

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to connect to server");
    return 1;
  }

  // Receive greeting message from server
  char buf[BUFSIZE];
  memset(buf, 0, BUFSIZE);
  if (recv(sock, buf, BUFSIZE, 0) < 0) {
    perror("Failed to receive greeting");
    return 1;
  }
  printf("%s", buf);

  // Authenticate with server
  memset(buf, 0, BUFSIZE);
  sprintf(buf, "USER %s\r\n", username);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("Failed to send username");
    return 1;
  }

  memset(buf, 0, BUFSIZE);
  if (recv(sock, buf, BUFSIZE, 0) < 0) {
    perror("Failed to receive username confirmation");
    return 1;
  }
  printf("%s", buf);

  memset(buf, 0, BUFSIZE);
  sprintf(buf, "PASS %s\r\n", password);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("Failed to send password");
    return 1;
  }

  memset(buf, 0, BUFSIZE);
  if (recv(sock, buf, BUFSIZE, 0) < 0) {
    perror("Failed to receive password confirmation");
    return 1;
  }
  printf("%s", buf);

  // Retrieve number of messages and their sizes
  memset(buf, 0, BUFSIZE);
  sprintf(buf, "STAT\r\n");
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("Failed to send STAT");
    return 1;
  }

  memset(buf, 0, BUFSIZE);
  if (recv(sock, buf, BUFSIZE, 0) < 0) {
    perror("Failed to receive STAT response");
    return 1;
  }
  printf("%s", buf);

  // Retrieve message headers
  memset(buf, 0, BUFSIZE);
  sprintf(buf, "LIST\r\n");
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("Failed to send LIST");
    return 1;
  }

  // Parse response and retrieve number of messages
  memset(buf, 0, BUFSIZE);
  if (recv(sock, buf, BUFSIZE, 0) < 0) {
    perror("Failed to receive LIST response");
    return 1;
  }
  printf("%s", buf);

  char *num_messages_str = strtok(buf, " ");
  int num_messages = atoi(num_messages_str);

  // Retrieve headers for each message
  for (int i = 1; i <= num_messages; i++) {
    memset(buf, 0, BUFSIZE);
    sprintf(buf, "TOP %d 0\r\n", i);
    if (send(sock, buf, strlen(buf), 0) < 0) {
      perror("Failed to send TOP");
      return 1;
    }

    printf("Message %d:\n", i);

    // Print message headers
    while (1) {
      memset(buf, 0, BUFSIZE);
      if (recv(sock, buf, BUFSIZE, 0) < 0) {
        perror("Failed to receive header");
        return 1;
      }

      if (strcmp(buf, "\r\n") == 0) {
        printf("\n");
        break;
      }

      printf("%s", buf);
    }
  }

  // Disconnect from server
  if (send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
    perror("Failed to send QUIT command");
    return 1;
  }

  close(sock);

  return 0;
}