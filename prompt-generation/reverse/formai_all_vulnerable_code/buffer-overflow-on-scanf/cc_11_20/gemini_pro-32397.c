//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

int main() {
  // Let's start by getting the address of the FTP server.
  printf("Yo! What's the address of the FTP server you wanna connect to?\n");
  char server_address[100];
  scanf("%s", server_address);
  
  // Now let's create a socket.
  // Don't worry, it's like a virtual connection between us and the server.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed!");
    exit(1);
  }
  
  // Time to specify the server's address where we want to connect.
  struct sockaddr_in server_info;
  memset(&server_info, 0, sizeof(server_info));
  server_info.sin_family = AF_INET;
  server_info.sin_addr.s_addr = inet_addr(server_address);
  server_info.sin_port = htons(21); // FTP's default port
  
  // Let's try to connect to the server.
  if (connect(sockfd, (struct sockaddr *)&server_info, sizeof(server_info)) < 0) {
    perror("Connection failed!");
    exit(1);
  }

  // Woohoo! We're connected. Let's send a login command.
  char login_command[100] = "USER anonymous\r\n";
  if (send(sockfd, login_command, strlen(login_command), 0) < 0) {
    perror("Login command sending failed!");
    exit(1);
  }

  // Now let's send the password (it's usually "anonymous" for anonymous FTP).
  char password_command[100] = "PASS anonymous\r\n";
  if (send(sockfd, password_command, strlen(password_command), 0) < 0) {
    perror("Password command sending failed!");
    exit(1);
  }
  
  // Let's list the files on the server.
  char list_command[100] = "LIST\r\n";
  if (send(sockfd, list_command, strlen(list_command), 0) < 0) {
    perror("LIST command sending failed!");
    exit(1);
  }
  
  // Okay! Let's receive the file list now.
  char file_list[1024];
  int received_bytes = recv(sockfd, file_list, sizeof(file_list), 0);
  if (received_bytes < 0) {
    perror("File list receiving failed!");
    exit(1);
  }
  
  // Boom! We've got the file list. Let's print it!
  printf("Here's the list of files on the FTP server:\n");
  printf("%s", file_list);
  
  // Now let's download a file from the server.
  printf("Which file do you want to download, my friend?\n");
  char file_name[100];
  scanf("%s", file_name);
  
  // Let's send the download command.
  char download_command[100] = "RETR ";
  strcat(download_command, file_name);
  strcat(download_command, "\r\n");
  if (send(sockfd, download_command, strlen(download_command), 0) < 0) {
    perror("RETR command sending failed!");
    exit(1);
  }
  
  // Awesome! Now let's receive the file.
  FILE *fp = fopen(file_name, "wb");
  if (fp == NULL) {
    perror("File opening failed!");
    exit(1);
  }
  
  char buffer[1024];
  while ((received_bytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
    fwrite(buffer, 1, received_bytes, fp);
  }
  
  if (received_bytes < 0) {
    perror("File receiving failed!");
    exit(1);
  }
  
  // Ta-da! We've successfully downloaded the file!
  fclose(fp);
  
  // Now let's close the connection and say goodbye to the server.
  close(sockfd);
  printf("Mission accomplished, buddy! File downloaded and connection closed.\n");
  
  return 0;
}