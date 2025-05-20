//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define COMMAND_SIZE 128

void ftp_client(){
  int sockfd, n;
  struct sockaddr_in server_addr;
  struct hostent *server;
  char buffer[BUFFER_SIZE];
  char cmd[COMMAND_SIZE];

  //Create a new socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0){
    printf("Error: Socket creation failed\n");
    return;
  }

  //Set server details
  server = gethostbyname("ftp.server.com");
  if(server == NULL){
    printf("Error: Host not found\n");
    return;
  }
  memset((char*)&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(21);
  memcpy((char*)&server_addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

  //Connect to server
  if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
    printf("Error: Connection failed\n");
    return;
  }
  printf("Connected to ftp.server.com\n");

  //Read response from server
  memset(buffer, 0, BUFFER_SIZE);
  n = read(sockfd, buffer, BUFFER_SIZE-1);
  if(n < 0){
    printf("Error: Could not read response\n");
    close(sockfd);
    return;
  }
  printf("%s\n", buffer);

  //Send username
  printf("Username: ");
  memset(cmd, 0, COMMAND_SIZE);
  fgets(cmd, COMMAND_SIZE, stdin);
  sprintf(buffer, "USER %s\r\n", cmd);
  n = write(sockfd, buffer, strlen(buffer));
  if(n < 0){
    printf("Error: Could not send username\n");
    close(sockfd);
    return;
  }

  //Read response from server
  memset(buffer, 0, BUFFER_SIZE);
  n = read(sockfd, buffer, BUFFER_SIZE-1);
  if(n < 0){
    printf("Error: Could not read response\n");
    close(sockfd);
    return;
  }
  printf("%s\n", buffer);

  //Send password
  printf("Password: ");
  memset(cmd, 0, COMMAND_SIZE);
  fgets(cmd, COMMAND_SIZE, stdin);
  sprintf(buffer, "PASS %s\r\n", cmd);
  n = write(sockfd, buffer, strlen(buffer));
  if(n < 0){
    printf("Error: Could not send password\n");
    close(sockfd);
    return;
  }

  //Read response from server
  memset(buffer, 0, BUFFER_SIZE);
  n = read(sockfd, buffer, BUFFER_SIZE-1);
  if(n < 0){
    printf("Error: Could not read response\n");
    close(sockfd);
    return;
  }
  printf("%s\n", buffer);

  //Enter passive mode
  sprintf(buffer, "PASV\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if(n < 0){
    printf("Error: Could not enter passive mode\n");
    close(sockfd);
    return;
  }

  //Read response from server
  memset(buffer, 0, BUFFER_SIZE);
  n = read(sockfd, buffer, BUFFER_SIZE-1);
  if(n < 0){
    printf("Error: Could not read response\n");
    close(sockfd);
    return;
  }
  printf("%s\n", buffer);

  //Extract port to connect to
  char *p1, *p2;
  int port;
  p1 = strchr(buffer, '(');
  p2 = strchr(buffer, ')');
  if(p1 == NULL || p2 == NULL){
    printf("Error: Could not extract port number\n");
    close(sockfd);
    return;
  }
  char port_string[12];
  memset(port_string, 0, 12);
  int i = 0;
  for(char *p = p1+1; p < p2; p++){
    if(*p == ','){
      port_string[i] = '.';
    }else{
      port_string[i] = *p;
    }
    i++;
  }
  port = atoi(port_string+20);

  //Create new socket for data transfer
  int datafd;
  struct sockaddr_in data_addr;
  datafd = socket(AF_INET, SOCK_STREAM, 0);
  if(datafd < 0){
    printf("Error: Socket creation failed\n");
    close(sockfd);
    return;
  }
  memset((char*)&data_addr, 0, sizeof(data_addr));
  data_addr.sin_family = AF_INET;
  data_addr.sin_port = htons(port);
  memcpy((char*)&data_addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

  //Connect to data port
  if(connect(datafd, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0){
    printf("Error: Connection failed\n");
    close(sockfd);
    return;
  }

  //Send list command
  sprintf(buffer, "LIST\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if(n < 0){
    printf("Error: Could not send command\n");
    close(sockfd);
    close(datafd);
    return;
  }

  //Read response from server
  memset(buffer, 0, BUFFER_SIZE);
  n = read(sockfd, buffer, BUFFER_SIZE-1);
  if(n < 0){
    printf("Error: Could not read response\n");
    close(sockfd);
    close(datafd);
    return;
  }
  printf("%s\n", buffer);

  //Read data from data port
  memset(buffer, 0, BUFFER_SIZE);
  while((n = read(datafd, buffer, BUFFER_SIZE-1)) > 0){
    printf("%s", buffer);
    memset(buffer, 0, BUFFER_SIZE);
  }
  if(n < 0){
    printf("Error: Could not read data\n");
    close(sockfd);
    close(datafd);
    return;
  }

  //Close sockets
  close(sockfd);
  close(datafd);
  printf("Disconnected from ftp.server.com\n");
}

int main(){
  ftp_client();
  return 0;
}