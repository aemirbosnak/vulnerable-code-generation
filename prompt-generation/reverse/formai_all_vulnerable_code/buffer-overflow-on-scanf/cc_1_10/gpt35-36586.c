//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "log.txt"
#define THRESHOLD 3
#define SUSPICIOUS_IPS_FILE "suspicious_ips.txt"

typedef struct{
    char ip_address[16];
    time_t timestamp;
} Log;

void log_activity(Log *logs, int *log_count, const char *ip_address){
    time_t current_time = time(NULL);
    logs[*log_count].timestamp = current_time;
    strcpy(logs[*log_count].ip_address, ip_address);

    FILE *fp = fopen(LOG_FILE, "a");
    if(fp == NULL){
        printf("Error: Unable to open %s\n", LOG_FILE);
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%ld: %s\n", current_time, ip_address);
    fclose(fp);

    *log_count += 1;
}

int is_ip_suspicious(const Log *logs, int log_count, const char *ip_address){
    int count = 0;
    for(int i=0; i < log_count; ++i){
        if(strcmp(logs[i].ip_address, ip_address) == 0){
            count++;
        }
    }

    if(count >= THRESHOLD){
        FILE *fp = fopen(SUSPICIOUS_IPS_FILE, "a");
        if(fp == NULL){
            printf("Error: Unable to open %s\n", SUSPICIOUS_IPS_FILE);
            exit(EXIT_FAILURE);
        }
        fprintf(fp, "%s\n", ip_address);
        fclose(fp);
        return 1;
    }

    return 0;
}

int main(){
    Log logs[1000];
    int log_count = 0;
    char ip_address[16];

    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    log_activity(logs, &log_count, ip_address);

    if(is_ip_suspicious(logs, log_count, ip_address)){
        printf("Suspicious IP Address: %s\n", ip_address);
    }

    return 0;
}