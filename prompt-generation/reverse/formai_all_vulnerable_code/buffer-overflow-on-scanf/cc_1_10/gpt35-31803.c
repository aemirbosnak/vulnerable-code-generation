//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOG_ENTRIES 1000 // max entries in log file
#define MAX_FILE_NAME_LENGTH 100 // max length of log filename

typedef struct{
    char timestamp[20];
    char source_ip[20];
    char destination_ip[20];
    char message[100];
} LogEntry;

int readLog(char *filename, LogEntry *log){
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL){
        printf("Error: Could not read the log file\n");
        return 0;
    }

    int count = 0;
    while(!feof(fptr) && count < MAX_LOG_ENTRIES){
        fscanf(fptr, "%[^,],%[^,],%[^,],%[^\n]%*c", log[count].timestamp, log[count].source_ip, log[count].destination_ip, log[count].message);
        count++;
    }
    fclose(fptr);
    return count;
}

void printLog(LogEntry *log, int count){
    printf("Timestamp\tSource IP\tDestination IP\tMessage\n");
    for(int i=0; i<count; i++){
        printf("%s\t%s\t%s\t%s\n", log[i].timestamp, log[i].source_ip, log[i].destination_ip, log[i].message);
    }
}

int detectIntrusion(LogEntry *log, int count){
    int intrusion_count = 0;
    for(int i=0; i<count; i++){
        if(strcmp(log[i].message, "Invalid login attempt") == 0){
            for(int j=i+1; j<count; j++){
                if(strcmp(log[j].source_ip, log[i].source_ip) == 0 && strcmp(log[j].message, "Repeat invalid login attempt") == 0){
                    intrusion_count++;
                    printf("Intrusion detected: Source IP: %s\n", log[j].source_ip);
                    break;
                }
            }
        }
    }
    return intrusion_count;
}

int main(){
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    LogEntry *log = (LogEntry*) malloc(sizeof(LogEntry) * MAX_LOG_ENTRIES);
    int count = readLog(filename, log);
    if(count > 0){
        printLog(log, count);
        int intrusion_count = detectIntrusion(log, count);
        printf("Total number of intrusions detected: %d\n", intrusion_count);
    }
    free(log);
    return 0;
}