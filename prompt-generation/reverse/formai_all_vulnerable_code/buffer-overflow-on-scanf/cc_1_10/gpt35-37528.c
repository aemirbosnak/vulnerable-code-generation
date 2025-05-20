//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 10000 // maximum number of logs
#define MAX_LINE_LENGTH 200 // maximum length of each log


typedef struct{
    char date[11];
    char time[6];
    char ip[16];
    char action[10];
} Log;

int readLogs(FILE *fp, Log logs[]){
    // function to read logs from file
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while(fgets(line,MAX_LINE_LENGTH,fp)){
        sscanf(line,"%s %s %s %s", logs[count].date, logs[count].time, logs[count].ip, logs[count].action);
        count++;
    }
    return count;
}

int main(){
    FILE *fp;
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    Log logs[MAX_LOGS];
    int log_count = readLogs(fp, logs);

    // start intrusion detection system
    char offending_ip[16];
    int count = 0;
    printf("[ ALARM SYSTEM ACTIVATED ]\n");
    printf("Potential Intruders: \n");
    for(int i=0; i<log_count; i++){
        int flag = 0;
        for(int j=0; j<i; j++){
            if(strcmp(logs[i].ip, logs[j].ip) == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            // new IP address found
            count = 1;
            strcpy(offending_ip,logs[i].ip);
            for(int k=i+1; k<log_count; k++){
                if(strcmp(logs[k].ip, offending_ip) == 0){
                    count++;
                }
            }
            if(count >= 10){
                printf("%s has made %d failed login attempts.\n", offending_ip, count);
            }
        }
    }

    if(count == 0){
        printf("No potential intruders found.\n");
    }

    fclose(fp);

    return 0;
}