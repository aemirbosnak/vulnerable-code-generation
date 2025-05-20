//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
 
#define MAX_SIZE 1024
 
int main(int argc, char *argv[]) {
   char *ip, *username, *password, *filename, command[MAX_SIZE];
   int sockfd, port;
   struct sockaddr_in serverAddr;
   socklen_t addr_size;
 
   // Get user inputs
   printf("Enter server IP address:\n");
   scanf("%s", ip);
   printf("Enter server port number:\n");
   scanf("%d", &port);
   printf("Enter your username:\n");
   scanf("%s", username);
   printf("Enter your password:\n");
   scanf("%s", password);
   printf("Enter filename to download:\n");
   scanf("%s", filename);
 
   // Create socket
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   memset(&serverAddr, 0, sizeof(serverAddr)); 
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_port = htons(port);  
   serverAddr.sin_addr.s_addr = inet_addr(ip);
   addr_size = sizeof serverAddr;
 
   // Connect to server
   connect(sockfd, (struct sockaddr *) &serverAddr, addr_size);
 
   // Send login details
   sprintf(command, "USER %s\r\n", username);
   send(sockfd, command, strlen(command), 0);
   sprintf(command, "PASS %s\r\n", password);
   send(sockfd, command, strlen(command), 0);
 
   // Download file
   sprintf(command, "RETR %s\r\n", filename);
   send(sockfd, command, strlen(command), 0);
 
   // Read data from server
   char buffer[MAX_SIZE];
   FILE *file = fopen(filename, "w");
   while(recv(sockfd, buffer, MAX_SIZE, 0)) {
     fprintf(file, "%s", buffer);
     memset(buffer, 0, MAX_SIZE);
   }
   fclose(file);
 
   // Logout
   sprintf(command, "QUIT\r\n");
   send(sockfd, command, strlen(command), 0);
   close(sockfd);
 
   printf("File downloaded successfully.\n");
 
   return 0;
}