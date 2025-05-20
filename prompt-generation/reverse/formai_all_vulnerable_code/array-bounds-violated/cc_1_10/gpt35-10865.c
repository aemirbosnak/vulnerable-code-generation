//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
// Romeo and Juliet POP3 Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

void die(char *s) {
  perror(s);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sock;
  char server_addr[MAXSIZE], username[MAXSIZE], password[MAXSIZE];
  struct sockaddr_in server;

  printf("Romeo: Oh, wherefore art thou POP3 client?\n");
  printf("Juliet: I am here, my Romeo. What troubles thee?\n");
  printf("Romeo: I need to access my email, but my client doth not work.\n");
  printf("Juliet: Fear not, my love. I shall help thee.\n");
  printf("Juliet: Pray, tell me thy email server address.\n");
  fgets(server_addr, MAXSIZE, stdin);
  strtok(server_addr, "\n");

  // Create socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    die("socket");

  // Configure server address
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(110);

  // Convert server address from text to binary form
  if (inet_pton(AF_INET, server_addr, &server.sin_addr) == -1)
    die("inet_pton");

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
    die("connect");

  // Receive server greeting
  char response[MAXSIZE];
  if (recv(sock, response, MAXSIZE, 0) == -1)
    die("recv");
  printf("Server: %s", response);

  printf("Juliet: Now, tell me thy username and password.\n");
  fgets(username, MAXSIZE, stdin);
  strtok(username, "\n");
  fgets(password, MAXSIZE, stdin);
  strtok(password, "\n");

  // Send login command
  char command[MAXSIZE];
  sprintf(command, "USER %s\r\n", username);
  if (send(sock, command, strlen(command), 0) == -1)
    die("send");
  if (recv(sock, response, MAXSIZE, 0) == -1)
    die("recv");
  printf("Server: %s", response);

  sprintf(command, "PASS %s\r\n", password);
  if (send(sock, command, strlen(command), 0) == -1)
    die("send");
  if (recv(sock, response, MAXSIZE, 0) == -1)
    die("recv");
  printf("Server: %s", response);

  // Send list command
  sprintf(command, "LIST\r\n");
  if (send(sock, command, strlen(command), 0) == -1)
    die("send");
  if (recv(sock, response, MAXSIZE, 0) == -1)
    die("recv");
  printf("Server: %s", response);

  // Send retrieve command
  printf("Juliet: Which email would you like me to retrieve?\n");
  char email_num[MAXSIZE];
  fgets(email_num, MAXSIZE, stdin);
  strtok(email_num, "\n");
  sprintf(command, "RETR %s\r\n", email_num);
  if (send(sock, command, strlen(command), 0) == -1)
    die("send");
  
  // Receive email contents
  int bytes_received;
  printf("\n");
  while ((bytes_received = recv(sock, response, MAXSIZE, 0)) > 0) {
    response[bytes_received] = '\0';
    printf("%s", response);
    if (strstr(response, "\r\n.\r\n") != NULL)
      break;
  }

  // Close socket
  close(sock);

  printf("\nJuliet: Is there anything else you need, my love?\n");
  printf("Romeo: No, Juliet. Thou art my only need.\n");

  return 0;
}