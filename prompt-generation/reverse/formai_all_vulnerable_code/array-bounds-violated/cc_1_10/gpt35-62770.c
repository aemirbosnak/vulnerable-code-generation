//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define MAX_BUFFER 512
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 25

int main(int argc, char const *argv[]) {

  //Create socket
  int socket_desc;
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);

  if (socket_desc == -1) {
    printf("Could not create socket\n");
  }

  // Define the server address
  struct sockaddr_in server;
  server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
  server.sin_family = AF_INET;
  server.sin_port = htons(SERVER_PORT);

  // Connect to remote server
  if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Could not connect");
    return 1;
  }

  char server_reply[MAX_BUFFER];
  int reply_len;

  // Send the HELO message
  char helo_msg[MAX_BUFFER] = "HELO example.com\n";
  send(socket_desc, helo_msg, strlen(helo_msg), 0);
  reply_len = recv(socket_desc, server_reply, MAX_BUFFER, 0);
  server_reply[reply_len] = '\0';
  printf("%s", server_reply);

  // Send the MAIL FROM message
  char mail_from[MAX_BUFFER] = "MAIL FROM:<sender@example.com>\n";
  send(socket_desc, mail_from, strlen(mail_from), 0);
  reply_len = recv(socket_desc, server_reply, MAX_BUFFER, 0);
  server_reply[reply_len] = '\0';
  printf("%s", server_reply);

  // Send the RCPT TO message
  char rcpt_to[MAX_BUFFER] = "RCPT TO:<recipient@example.com>\n";
  send(socket_desc, rcpt_to, strlen(rcpt_to), 0);
  reply_len = recv(socket_desc, server_reply, MAX_BUFFER, 0);
  server_reply[reply_len] = '\0';
  printf("%s", server_reply);

  // Send the DATA message
  char data_msg[MAX_BUFFER] = "DATA\n";
  send(socket_desc, data_msg, strlen(data_msg), 0);
  reply_len = recv(socket_desc, server_reply, MAX_BUFFER, 0);
  server_reply[reply_len] = '\0';
  printf("%s", server_reply);

  // Send the message body
  char message[MAX_BUFFER] = "From: sender@example.com\nTo: recipient@example.com\nSubject: Test email\n\nThis is a test email.\n";
  send(socket_desc, message, strlen(message), 0);

  // Send the QUIT message
  char quit_msg[MAX_BUFFER] = "QUIT\n";
  send(socket_desc, quit_msg, strlen(quit_msg), 0);

  // Close the socket
  close(socket_desc);

  return 0;

}