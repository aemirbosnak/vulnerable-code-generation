//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

   int sockfd, portno, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   char buffer[256];
   if (argc < 3) {
      fprintf(stderr,"usage %s hostname port\n", argv[0]);
      exit(0);
   }

   portno = atoi(argv[2]);
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      printf("Error: could not create SMTP socket");
      exit(1);
   }

   server = gethostbyname(argv[1]);

   if (server == NULL) {
      printf("Error: could not resolve SMTP server hostname");
      exit(1);
   }

   memset((char *) &serv_addr,0,sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   memcpy((char *)&serv_addr.sin_addr.s_addr,(char *)server->h_addr, server->h_length);
   serv_addr.sin_port = htons(portno);

   if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
      printf("Error: could not connect to SMTP server");
      exit(1);
   }

   if (read(sockfd, buffer, 255) < 0) {
      printf("Error: could not read SMTP server response");
      exit(1);
   }

   printf("%s\n",buffer);

   char *hello = "EHLO client\r\n";
   n = write(sockfd, hello, strlen(hello));
   if (n < 0) {
      printf("Error: could not write SMTP command");
      exit(1);
   }

   if (read(sockfd, buffer, 255) < 0) {
      printf("Error: could not read SMTP server response");
      exit(1);
   }

   printf("%s\n",buffer);

   char *mail_from = "MAIL FROM:<user@example.com>\r\n";
   n = write(sockfd, mail_from, strlen(mail_from));
   if (n < 0) {
      printf("Error: could not write SMTP command");
      exit(1);
   }

   if (read(sockfd, buffer, 255) < 0) {
      printf("Error: could not read SMTP server response");
      exit(1);
   }

   printf("%s\n",buffer);

   char *rcpt_to = "RCPT TO:<user@example.com>\r\n";
   n = write(sockfd, rcpt_to, strlen(rcpt_to));
   if (n < 0) {
      printf("Error: could not write SMTP command");
      exit(1);
   }

   if (read(sockfd, buffer, 255) < 0) {
      printf("Error: could not read SMTP server response");
      exit(1);
   }

   printf("%s\n",buffer);

   char *data = "DATA\r\n";
   n = write(sockfd, data, strlen(data));
   if (n < 0) {
      printf("Error: could not write SMTP command");
      exit(1);
   }

   if (read(sockfd, buffer, 255) < 0) {
      printf("Error: could not read SMTP server response");
      exit(1);
   }

   printf("%s\n",buffer);

   char *msg_body = "From: user@example.com\r\nTo: user@example.com\r\nSubject: Test\r\n\r\nThis is a test email";
   n = write(sockfd, msg_body, strlen(msg_body));
   if (n < 0) {
      printf("Error: could not write SMTP message body");
      exit(1);
   }

   char *end_msg = "\r\n.\r\n";
   n = write(sockfd, end_msg, strlen(end_msg));
   if (n < 0) {
      printf("Error: could not end SMTP message");
      exit(1);
   }

   if (read(sockfd, buffer, 255) < 0) {
      printf("Error: could not read SMTP server response");
      exit(1);
   }

   printf("%s\n",buffer);

   char *quit = "QUIT\r\n";
   n = write(sockfd, quit, strlen(quit));
   if (n < 0) {
      printf("Error: could not write SMTP command");
      exit(1);
   }

   if (read(sockfd, buffer, 255) < 0) {
      printf("Error: could not read SMTP server response");
      exit(1);
   }

   printf("%s\n",buffer);

   close(sockfd);
   return 0;
}