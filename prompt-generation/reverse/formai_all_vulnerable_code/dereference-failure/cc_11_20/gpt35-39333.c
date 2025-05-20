//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
   int sockfd, portno, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   char buffer[MAX_SIZE];
   char user_email[MAX_SIZE];
   char user_pass[MAX_SIZE];

   printf("POP3 Client\n");

   printf("Enter the server name: ");
   scanf("%s", buffer);
   server = gethostbyname(buffer);
   if (server == NULL) {
      fprintf(stderr,"Error: no such host\n");
      exit(0);
   }

   printf("Enter the server port number: ");
   scanf("%d", &portno);

   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      fprintf(stderr, "Error: opening socket\n");
      exit(0);
   }

   memset(&serv_addr,0,sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
   serv_addr.sin_port = htons(portno);

   if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
      fprintf(stderr,"Error: connecting\n");
      exit(0);
   }

   printf("Enter your email: ");
   scanf("%s", user_email);

   printf("Enter your password: ");
   scanf("%s", user_pass);

   /* Login */
   snprintf(buffer, sizeof(buffer), "USER %s\r\n", user_email);
   n = write(sockfd, buffer, strlen(buffer));
   if (n < 0) {
      fprintf(stderr,"Error: writing to pop3 server\n");
      exit(0);
   }

   snprintf(buffer, sizeof(buffer), "PASS %s\r\n", user_pass);
   n = write(sockfd, buffer, strlen(buffer));
   if (n < 0) {
      fprintf(stderr,"Error: writing to pop3 server\n");
      exit(0);
   }

   /* Get number of emails */
   snprintf(buffer, sizeof(buffer), "STAT\r\n");
   n = write(sockfd, buffer, strlen(buffer));
   if (n < 0) {
      fprintf(stderr,"Error: writing to pop3 server\n");
      exit(0);
   }

   memset(buffer, 0, MAX_SIZE);
   n = read(sockfd, buffer, MAX_SIZE);
   if (n < 0) {
      fprintf(stderr,"Error: reading from pop3 server\n");
      exit(0);
   }
   printf("%s", buffer);

   /* List all emails */
   snprintf(buffer, sizeof(buffer), "LIST\r\n");
   n = write(sockfd, buffer, strlen(buffer));
   if (n < 0) {
      fprintf(stderr,"Error: writing to pop3 server\n");
      exit(0);
   }

   memset(buffer, 0, MAX_SIZE);
   n = read(sockfd, buffer, MAX_SIZE);
   if (n < 0) {
      fprintf(stderr,"Error: reading from pop3 server\n");
      exit(0);
   }
   printf("%s", buffer);

   /* Quit */
   snprintf(buffer, sizeof(buffer), "QUIT\r\n");
   n = write(sockfd, buffer, strlen(buffer));
   if (n < 0) {
      fprintf(stderr,"Error: writing to pop3 server\n");
      exit(0);
   }

   close(sockfd);
   return 0;
}