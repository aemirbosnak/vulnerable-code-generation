//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 50007

int main() {
   int sockfd, newsockfd;
   struct sockaddr_in server_addr;
   char buffer[1024];
   int n;
   int sum;

   if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      perror("Error in socket");
      exit(EXIT_FAILURE);
   }

   // server address structure
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // replace with actual server address
   server_addr.sin_port = htons(PORT);

   if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("Error in connect");
      exit(EXIT_FAILURE);
   }

   while (1) {
      printf("Enter first number: ");
      scanf("%d", &n);

      if (n == 0) {
         break;
      }

      send(sockfd, &n, sizeof(n), 0);

      if (recv(sockfd, &n, sizeof(n), 0) < 0) {
         perror("Error in recv");
         exit(EXIT_FAILURE);
      }

      sum = n + n;
      send(sockfd, &sum, sizeof(sum), 0);

      if (recv(sockfd, &sum, sizeof(sum), 0) < 0) {
         perror("Error in recv");
         exit(EXIT_FAILURE);
      }

      printf("Sum of %d and %d is %d\n", n, sum, sum);
   }

   close(sockfd);
   return 0;
}