//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_SIZE 4096

int main(int argc, char *argv[]) {
  int socket_desc;
  struct sockaddr_in server;
  char username[50], password[50], email[MAX_SIZE];
  char recv_buffer[MAX_SIZE], send_buffer[MAX_SIZE];

  // Create socket
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  
  if(socket_desc == -1) {
    printf("Could not create socket");
    return 1;
  }

  printf("Socket created\n");

  // Prepare the sockaddr_in structure
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(110);

  // Connect to remote server
  if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Connection error\n");
    return 1;
  }

  printf("Connected\n");

  // Retrieve the banner message from the server
  if(recv(socket_desc, recv_buffer, MAX_SIZE, 0) < 0) {
    printf("Could not receive banner\n");
    return 1;
  }
  
  printf("Banner: %s", recv_buffer);
  
  // Send the user credentials to the server
  printf("Username: ");
  scanf("%s", username);
  
  printf("Password: ");
  scanf("%s", password);

  sprintf(send_buffer, "USER %s\r\n", username);

  if(send(socket_desc, send_buffer, strlen(send_buffer), 0) < 0) {
    printf("Send failed\n");
    return 1;
  }
  
  memset(recv_buffer, 0, sizeof(recv_buffer));

  if(recv(socket_desc, recv_buffer, MAX_SIZE, 0) < 0) {
    printf("Could not receive username acknowledge\n");
    return 1;
  }
  
  printf("%s", recv_buffer);

  sprintf(send_buffer, "PASS %s\r\n", password);

  if(send(socket_desc, send_buffer, strlen(send_buffer), 0) < 0) {
    printf("Send failed\n");
    return 1;
  }

  memset(recv_buffer, 0, sizeof(recv_buffer));

  if(recv(socket_desc, recv_buffer, MAX_SIZE, 0) < 0) {
    printf("Could not receive password acknowledge\n");
    return 1;
  }

  printf("%s", recv_buffer);

  // Send the RETR command to retrieve the email
  printf("Which email would you like to retrieve? ");
  scanf("%s", email);

  sprintf(send_buffer, "RETR %s\r\n", email);

  if(send(socket_desc, send_buffer, strlen(send_buffer), 0) < 0) {
    printf("Send failed\n");
    return 1;
  }

  // Receive the email from the server
  while(recv(socket_desc, recv_buffer, MAX_SIZE, 0) > 0) {
    printf("%s", recv_buffer);
    
    if(strstr(recv_buffer, "\r\n.\r\n") != NULL) {
      break;
    }

    memset(recv_buffer, 0, sizeof(recv_buffer));
  }

  printf("Email retrieved\n");

  // Send the QUIT command to disconnect from the server
  sprintf(send_buffer, "QUIT\r\n");

  if(send(socket_desc, send_buffer, strlen(send_buffer), 0) < 0) {
    printf("Send failed\n");
    return 1;
  }

  printf("Disconnected\n");

  close(socket_desc);

  return 0;
}