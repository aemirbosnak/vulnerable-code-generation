//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORT 80
#define BUF_SIZE 1024

void display_networks(char *ssid);
void recursive_scan(int start, int end);

int main() {
   int start, end;
   printf("Enter the range to scan (start and end IP addresses): ");
   scanf("%d %d", &start, &end);

    recursive_scan(start, end);

    return 0;
}

void display_networks(char *ssid) {
   printf("Wireless network found: %s\n", ssid);
}

void recursive_scan(int start, int end) {
   int i;
   char ip[20], ssid[50];
   struct sockaddr_in socketaddr;
   struct hostent *host;
   
   for(i=start; i<=end; i++) {
      sprintf(ip, "192.168.1.%d", i);

      memset(&socketaddr, 0, sizeof(socketaddr));
      socketaddr.sin_family = AF_INET;
      socketaddr.sin_port = htons(PORT);

      host = gethostbyname(ip);
      if(host == NULL) {
          continue;
      }

      memcpy(&socketaddr.sin_addr, host->h_addr, host->h_length);

      int sock = socket(AF_INET, SOCK_STREAM, 0);
      if(sock < 0) {
          continue;
      }

      if(connect(sock, (struct sockaddr *)&socketaddr, sizeof(socketaddr)) == 0) {
         sprintf(ssid, "Network-%d", i);
         display_networks(ssid);

         close(sock);
      } else {
         close(sock);
      }

   }
    return recursive_scan(start + 1, end);
}