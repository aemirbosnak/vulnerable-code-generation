//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 100
#define MAX_SIZE 1024

typedef struct {
    char ip[16];
    char date[20];
    char time[10];
    char method[10];
    char url[1024];
    char user_agent[1024];
} log_entry;

void parse_log(char* log, log_entry* entry) {
    char* token;
    int i = 0;

    // Extract IP address
    token = strtok(log, " ");
    strncpy(entry->ip, token, sizeof(entry->ip));

    // Extract date and time
    token = strtok(NULL, " ");
    strncpy(entry->date, token, sizeof(entry->date));
    token = strtok(NULL, " ");
    strncpy(entry->time, token, sizeof(entry->time));

    // Extract HTTP method and URL
    token = strtok(NULL, " ");
    strncpy(entry->method, token, sizeof(entry->method));
    token = strtok(NULL, " ");
    strncpy(entry->url, token, sizeof(entry->url));

    // Extract user agent
    token = strtok(NULL, " ");
    strncpy(entry->user_agent, token, sizeof(entry->user_agent));
}

void analyze_logs(log_entry logs[], int num_logs) {
    int i;
    for(i=0; i<num_logs; i++) {
        if(strstr(logs[i].url, "admin")!= NULL || strstr(logs[i].url, "login")!= NULL) {
            printf("Possible intrusion attempt from IP %s at %s:%s\n", logs[i].ip, logs[i].date, logs[i].time);
        }
    }
}

int main() {
    FILE* fp;
    char log[MAX_SIZE];
    log_entry logs[MAX_LOGS];
    int num_logs = 0;

    fp = fopen("access.log", "r");
    if(fp == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    while(fgets(log, sizeof(log), fp)!= NULL) {
        parse_log(log, &logs[num_logs]);
        num_logs++;
    }

    fclose(fp);

    analyze_logs(logs, num_logs);

    return 0;
}