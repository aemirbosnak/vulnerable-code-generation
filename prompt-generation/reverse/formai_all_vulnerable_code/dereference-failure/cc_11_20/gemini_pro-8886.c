//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s <recipient> <sender> <message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *recipient = argv[1];
  char *sender = argv[2];
  char *message = argv[3];

  struct hostent *host = gethostbyname("smtp.example.com");
  if (!host) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(25);
  addr.sin_addr = *((struct in_addr *) host->h_addr);

  if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
    perror("connect");
    close(sock);
    return EXIT_FAILURE;
  }

  char buffer[1024];

  // Receive banner
  if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    close(sock);
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send HELO
  sprintf(buffer, "HELO %s\r\n", host->h_name);
  if (send(sock, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    close(sock);
    return EXIT_FAILURE;
  }
  if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    close(sock);
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send MAIL FROM
  sprintf(buffer, "MAIL FROM: <%s>\r\n", sender);
  if (send(sock, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    close(sock);
    return EXIT_FAILURE;
  }
  if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    close(sock);
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send RCPT TO
  sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
  if (send(sock, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    close(sock);
    return EXIT_FAILURE;
  }
  if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    close(sock);
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send DATA
  if (send(sock, "DATA\r\n", 5, 0) == -1) {
    perror("send");
    close(sock);
    return EXIT_FAILURE;
  }
  if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    close(sock);
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send message
  if (send(sock, message, strlen(message), 0) == -1) {
    perror("send");
    close(sock);
    return EXIT_FAILURE;
  }
  if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    close(sock);
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send QUIT
  if (send(sock, "QUIT\r\n", 5, 0) == -1) {
    perror("send");
    close(sock);
    return EXIT_FAILURE;
  }
  if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    close(sock);
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  close(sock);

  return EXIT_SUCCESS;
}