//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_PORT_NUM 65535
     
int main(int argc, char *argv[])
{
   int sockfd;
   struct hostent *host;
   struct sockaddr_in target_addr;
   int port, scan_range_start, scan_range_end, i;
   
   if(argc != 4){
      printf("Usage: %s <Host> <Start port> <End port>\n", argv[0]);
      return -1;
   }
   
   scan_range_start = atoi(argv[2]);
   scan_range_end = atoi(argv[3]);
   
   if(scan_range_start < 0 || scan_range_start > MAX_PORT_NUM) {
      printf("Invalid port number!\n");
      return -1;
   }
   
   if(scan_range_end < 0 || scan_range_end > MAX_PORT_NUM) {
      printf("Invalid port number!\n");
      return -1;
   }
   
   if(scan_range_start > scan_range_end) {
      printf("Invalid port range!\n");
      return -1;
   }
   
   host = gethostbyname(argv[1]);
   
   if(!host) {
      printf("Error: %s\n", strerror(errno));
      return -1;
   }
   
   for(port = scan_range_start; port <= scan_range_end; port++) {
   
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
      if(sockfd < 0) {
         printf("Error: %s\n", strerror(errno));
         return -1;
      }
      
      target_addr.sin_family = AF_INET;
      target_addr.sin_port = htons(port);
      memcpy(&target_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
      
      if(connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
         printf("Port %d is open\n", port);
      }
   
      close(sockfd);
   
   }
   
   printf("Scan complete\n");
   
   return 0;
}