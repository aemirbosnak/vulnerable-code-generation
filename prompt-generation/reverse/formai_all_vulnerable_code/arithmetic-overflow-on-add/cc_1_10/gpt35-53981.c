//FormAI DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define LOG_FILE "event.log" // change this to your preferred log file name

// function to create log file if it doesn't already exist
void createLogFile(){
    FILE *logFile;
    logFile = fopen(LOG_FILE,"a+");
    if (logFile == NULL){
        printf("Error creating log file!");
        exit(1);
    }
    fclose(logFile);
}

// function to get current date and time
void getCurrentDateTime(char *dateTime){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateTime,"%d-%02d-%02d %02d:%02d:%02d",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
}

// function to log the event to the log file
void logEvent(char *event){
    char dateTime[20];
    getCurrentDateTime(dateTime);
    FILE *logFile;
    logFile = fopen(LOG_FILE,"a+");
    fprintf(logFile,"%s %s\n",dateTime,event);
    fclose(logFile);
}

// function to log a system event
void logSystemEvent(char *msg, int errorCode){
    char event[100];
    sprintf(event,"%s %d",msg,errorCode);
    logEvent(event);
}

int main(){
    createLogFile();
    char msg[50];
    int errorCode;
    printf("Please enter a system event followed by an error code (separated by a space):\n");
    scanf("%[^\n]%*c%d",msg,&errorCode);
    logSystemEvent(msg,errorCode);
    printf("Event logged successfully to %s\n",LOG_FILE);
    return 0;
}