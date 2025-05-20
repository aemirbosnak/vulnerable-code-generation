//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HOSTS 10
#define MAX_PACKETS 20

typedef struct {
   char source[16];
   char target[16];
   int length;
} packet;

typedef struct {
   char ip[16];
   int num_packets;
   packet packets[MAX_PACKETS];
} host;

void print_packet(packet p) {
   printf("Source: %s\n", p.source);
   printf("Target: %s\n", p.target);
   printf("Length: %d\n", p.length);
}

void print_host(host h) {
   printf("Host: %s\n", h.ip);
   printf("Num_packets: %d\n", h.num_packets);
   for(int i=0;i<h.num_packets;i++) {
      print_packet(h.packets[i]);
   }
}

int main() {
   host hosts[MAX_HOSTS];
   int num_hosts = 0;
   char input[50];

   while(num_hosts < MAX_HOSTS) {
      printf("Enter IP address of host %d: ", num_hosts+1);
      fgets(input, 50, stdin);
      input[strcspn(input, "\n")] = 0;
      
      int exists = 0;
      for(int i=0;i<num_hosts;i++) {
         if(strcmp(input, hosts[i].ip) == 0) {
            exists = 1;
            printf("Host already exists.\n");
            break;
         }
      }

      if(exists) continue;

      strcpy(hosts[num_hosts].ip, input);
      hosts[num_hosts].num_packets = 0;
      num_hosts++;

      if(num_hosts == MAX_HOSTS) break;

      printf("Add another host? (Y/N): ");
      fgets(input, 50, stdin);
      input[strcspn(input, "\n")] = 0;

      if(strcmp(input, "N") == 0) break;
   }

   printf("\nStarting monitoring...\n\n");

   while(1) {
      printf("Enter packet information (src ip, dst ip, length): ");
      fgets(input, 50, stdin);
      input[strcspn(input, "\n")] = 0;
      
      packet p;
      sscanf(input, "%s %s %d", p.source, p.target, &p.length);
      int host_index = -1;

      for(int i=0;i<num_hosts;i++) {
         if(strcmp(hosts[i].ip, p.source) == 0) {
            host_index = i;
            break;
         }
      }

      if(host_index == -1) {
         printf("Unknown source IP, discarding packet.\n");
         continue;
      }

      int pack_index = hosts[host_index].num_packets;
      hosts[host_index].packets[pack_index] = p;
      hosts[host_index].num_packets++;

      if(hosts[host_index].num_packets == MAX_PACKETS) {
         printf("Host %s has reached the maximum number of packets, possible intrusion detected!\n", hosts[host_index].ip);
         print_host(hosts[host_index]);
         break;
      }      
   }

   return 0;
}