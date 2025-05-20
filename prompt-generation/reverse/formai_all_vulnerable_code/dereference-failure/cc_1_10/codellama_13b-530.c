//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: lively
// Building a SMTP Client example program in a lively style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to send an email
void send_email(char *to, char *from, char *subject, char *body) {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Failed to create socket\n");
    return;
  }

  // Get the address info
  struct addrinfo hints, *server_info;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  int status = getaddrinfo("smtp.gmail.com", "587", &hints, &server_info);
  if (status != 0) {
    printf("Failed to get address info\n");
    return;
  }

  // Connect to the server
  status = connect(sock, server_info->ai_addr, server_info->ai_addrlen);
  if (status < 0) {
    printf("Failed to connect to the server\n");
    return;
  }

  // Send the email
  char buf[1024];
  sprintf(buf, "HELO\r\n");
  send(sock, buf, strlen(buf), 0);
  sprintf(buf, "MAIL FROM:<%s>\r\n", from);
  send(sock, buf, strlen(buf), 0);
  sprintf(buf, "RCPT TO:<%s>\r\n", to);
  send(sock, buf, strlen(buf), 0);
  sprintf(buf, "DATA\r\n");
  send(sock, buf, strlen(buf), 0);
  sprintf(buf, "Subject: %s\r\n\r\n", subject);
  send(sock, buf, strlen(buf), 0);
  sprintf(buf, "%s\r\n", body);
  send(sock, buf, strlen(buf), 0);
  sprintf(buf, ".\r\n");
  send(sock, buf, strlen(buf), 0);
  sprintf(buf, "QUIT\r\n");
  send(sock, buf, strlen(buf), 0);

  // Close the socket
  close(sock);
}

int main() {
  // Send an email
  send_email("to@example.com", "from@example.com", "Subject", "Body");

  return 0;
}