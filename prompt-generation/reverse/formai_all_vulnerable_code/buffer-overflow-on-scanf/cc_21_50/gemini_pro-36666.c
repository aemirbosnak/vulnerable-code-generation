//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
// Enter the ethereal realm of mail retrieval with this visionary POP3 client!

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define POP3_PORT 110

// Step into the server's digital sanctuary
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <server-ip> <username>\n", argv[0]);
    return 1;
  }

  // Invoke the mystical power of sockets
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Failed to open a socket to the server.\n");
    return 2;
  }

  // Embark on a journey to the server's celestial address
  struct sockaddr_in server;
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(POP3_PORT);
  if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
    printf("Invalid server IP address.\n");
    return 3;
  }

  // Send a gentle knock on the server's virtual door
  if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Failed to connect to the server.\n");
    return 4;
  }

  // Unravel the server's initial greeting
  char buffer[256];
  memset(buffer, 0, sizeof(buffer));
  if (recv(sock, buffer, sizeof(buffer), 0) <= 0) {
    printf("Failed to receive the server's greeting.\n");
    return 5;
  }
  printf("Server: %s\n", buffer);

  // Reveal your earthly identity to the server
  snprintf(buffer, sizeof(buffer), "USER %s\r\n", argv[2]);
  if (send(sock, buffer, strlen(buffer), 0) <= 0) {
    printf("Failed to send username to the server.\n");
    return 6;
  }
  if (recv(sock, buffer, sizeof(buffer), 0) <= 0) {
    printf("Failed to receive the server's response to username.\n");
    return 7;
  }
  printf("Server: %s\n", buffer);

  // Summon the password gatekeeper
  snprintf(buffer, sizeof(buffer), "PASS %s\r\n", argv[2]);
  if (send(sock, buffer, strlen(buffer), 0) <= 0) {
    printf("Failed to send password to the server.\n");
    return 8;
  }
  if (recv(sock, buffer, sizeof(buffer), 0) <= 0) {
    printf("Failed to receive the server's response to password.\n");
    return 9;
  }
  printf("Server: %s\n", buffer);

  // Prepare for the impending mail deluge
  printf("Messages:\n");
  snprintf(buffer, sizeof(buffer), "LIST\r\n");
  if (send(sock, buffer, strlen(buffer), 0) <= 0) {
    printf("Failed to send LIST command to the server.\n");
    return 10;
  }
  int messageCount = 0;
  while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
    if (strncmp(buffer, "+OK", 3) == 0) {
      break;
    } else if (strncmp(buffer, "-ERR", 4) == 0) {
      printf("Server: %s\n", buffer);
      return 11;
    } else {
      printf("%s", buffer);
      messageCount++;
    }
  }

  // Retrieve the chosen message
  if (messageCount > 0) {
    printf("Enter message number to retrieve (1-%d): ", messageCount);
    int messageNumber;
    scanf("%d", &messageNumber);
    if (messageNumber < 1 || messageNumber > messageCount) {
      printf("Invalid message number.\n");
      return 12;
    }

    // Embark on a perilous journey to the heart of a single mail
    snprintf(buffer, sizeof(buffer), "RETR %d\r\n", messageNumber);
    if (send(sock, buffer, strlen(buffer), 0) <= 0) {
      printf("Failed to send RETR command to the server.\n");
      return 13;
    }
    while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
      if (strncmp(buffer, "+OK", 3) == 0) {
        break;
      } else if (strncmp(buffer, "-ERR", 4) == 0) {
        printf("Server: %s\n", buffer);
        return 14;
      } else {
        printf("%s", buffer);
      }
    }
  }

  // Close the ethereal portal
  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  if (send(sock, buffer, strlen(buffer), 0) <= 0) {
    printf("Failed to send QUIT command to the server.\n");
    return 15;
  }
  if (recv(sock, buffer, sizeof(buffer), 0) <= 0) {
    printf("Failed to receive the server's response to QUIT.\n");
    return 16;
  }
  printf("Server: %s\n", buffer);

  close(sock);

  return 0;
}