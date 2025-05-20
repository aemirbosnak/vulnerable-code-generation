//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
   int sock_fd, n;
   char buffer[MAX_BUF_SIZE];
   struct sockaddr_in server_addr;
   struct hostent *server;

   if (argc < 3) {
      printf("Usage: %s hostname port\n", argv[0]);
      exit(1);
   }

   sock_fd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sock_fd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }

   server = gethostbyname(argv[1]);

   if (server == NULL) {
      printf("ERROR, no such host\n");
      exit(1);
   }

   bzero((char *) &server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
   server_addr.sin_port = htons(atoi(argv[2]));

   if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
      perror("ERROR connecting");
      exit(1);
   }

   // Connection successful
   printf("Connected to server.\n");

   // Send IMAP login request
   char login_request[] = "01 LOGIN username password\n";
   n = write(sock_fd, login_request, strlen(login_request));
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }

   // Receive response from server
   bzero(buffer, MAX_BUF_SIZE);
   n = read(sock_fd, buffer, MAX_BUF_SIZE-1);
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }

   printf("%s", buffer);

   // Send IMAP select mailbox request
   char select_mailbox_request[] = "02 SELECT INBOX\n";
   n = write(sock_fd, select_mailbox_request, strlen(select_mailbox_request));
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }

   // Receive response from server
   bzero(buffer, MAX_BUF_SIZE);
   n = read(sock_fd, buffer, MAX_BUF_SIZE-1);
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }

   printf("%s", buffer);

   // Send IMAP list mailbox request
   char list_mailbox_request[] = "03 LIST \"\" *\n";
   n = write(sock_fd, list_mailbox_request, strlen(list_mailbox_request));
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }

   // Receive response from server
   bzero(buffer, MAX_BUF_SIZE);
   n = read(sock_fd, buffer, MAX_BUF_SIZE-1);
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }

   printf("%s", buffer);

   close(sock_fd);
   return 0;
}