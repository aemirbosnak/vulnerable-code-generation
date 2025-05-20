//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: careful
#include<stdio.h>
#include<string.h>

#define MAX_LOGS 1000
#define MAX_IP_LEN 20

struct LogEntry {
   char ip[MAX_IP_LEN];
   char timestamp[40];
   char message[200];
};

int main() {
   struct LogEntry logs[MAX_LOGS];
   int num_logs = 0;
   int suspicious_count = 0;
   
   FILE *fp;
   fp = fopen("log.txt", "r");

   if(fp == NULL) {
       printf("Failed to open log file\n");
       return -1;
   }

   char line[150];
   while(fgets(line, 150, fp) != NULL) {
       sscanf(line, "%s %s %[^\n]s", logs[num_logs].ip, logs[num_logs].timestamp, logs[num_logs].message);
       num_logs++;
   }

   int i, j;
   for(i=0; i<num_logs; i++) {
       int count = 1;
       for(j=i+1; j<num_logs; j++) {
           if(strcmp(logs[i].ip, logs[j].ip) == 0 && strcmp(logs[i].message, logs[j].message) == 0) {
               count++;

               // Check if a single IP address is responsible for too many logs
               if(count > 10) {
                   printf("Suspicious activity detected from IP address %s\n", logs[i].ip);
                   suspicious_count++;
               }
           }
       }
   }

   if(suspicious_count == 0) {
       printf("No suspicious activity detected\n");
   }

   fclose(fp);

   return 0;
}