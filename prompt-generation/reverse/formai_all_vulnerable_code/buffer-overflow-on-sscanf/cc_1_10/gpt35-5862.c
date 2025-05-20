//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

void processPacket(char *packet);
void processHeader(char *header);
void processData(char *data);

int main(void) {
   char packet[MAX_BUF_SIZE];

   printf("Enter packet data:\n");
   fgets(packet, MAX_BUF_SIZE, stdin);

   processPacket(packet);

   return 0;
}

void processPacket(char *packet) {
   char header[MAX_BUF_SIZE];
   char data[MAX_BUF_SIZE];

   sscanf(packet, "%[^|]|%s", header, data);

   processHeader(header);
   processData(data);
}

void processHeader(char *header) {
   char *token;

   token = strtok(header, ",");
   while (token != NULL) {
       printf("Header: %s\n", token);
       token = strtok(NULL, ",");
   }
}

void processData(char *data) {
   if (strstr(data, "SELECT")) {
      printf("Possible SQL injection detected!\n");
   }
   else if (strstr(data, "DROP")) {
      printf("Possible SQL injection detected!\n");
   }
   else if (strstr(data, "UNION")) {
      printf("Possible SQL injection detected!\n");
   }
   else {
      printf("Packet data: %s\n", data);
   }
}