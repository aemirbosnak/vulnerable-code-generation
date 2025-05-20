//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){

  printf("Welcome to the IMAP Client Program, where we make your mailbox a happy place!\n");

  // Initializing necessary variables
  char username[30], password[30];
  int server_socket, client_socket, port_no, server_len, i;
  char buffer[256];
  struct sockaddr_in server_address, client_address;

  printf("Please enter your username: ");
  scanf("%s", username);
  printf("Please enter your password: ");
  scanf("%s", password);

  printf("Trying to connect to the server...\n");

  // Opening the IMAP server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    printf("Oh no! Looks like the server socket opening failed.\n");
    exit(1);
  }

  // Setting up the server address
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_address.sin_port = htons(5000);
  server_len = sizeof(server_address);

  // Attempting to connect to the server
  if(connect(server_socket, (struct sockaddr *)&server_address, server_len) < 0){
    printf("Oops! Connection to the server failed.\n");
    exit(1);
  }

  printf("Connection to the IMAP server established!\n");

  // Sending the login details to the server
  sprintf(buffer, "USER %s\r\n", username);
  send(server_socket, buffer, strlen(buffer), 0);
  sleep(2);

  sprintf(buffer, "PASS %s\r\n", password);
  send(server_socket, buffer, strlen(buffer), 0);
  sleep(2);

  // Reading server responses
  recv(server_socket, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);
  recv(server_socket, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);
  recv(server_socket, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  printf("Logged in successfully!\n");

  // Now that we are logged in, let's make our mailbox a happy place and fetch some emails!
  send(server_socket, "LIST \r\n", strlen("LIST \r\n"), 0);
  sleep(2);
  recv(server_socket, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  printf("Fetching details of all emails in your mailbox...\n");

  send(server_socket, "RETR 1 \r\n", strlen("RETR 1 \r\n"), 0);
  sleep(2);
  recv(server_socket, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);
  recv(server_socket, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  printf("That's all the emails we have for you! Thank you for using the IMAP Client Program!\n");
  
  return 0;
}