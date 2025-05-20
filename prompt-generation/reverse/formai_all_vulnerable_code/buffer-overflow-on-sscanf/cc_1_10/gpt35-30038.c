//FormAI DATASET v1.0 Category: Log analysis ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_SIZE 1000

//Function to parse a line of the log file and store relevant information
void parseLogLine(char* line, char* date, char* time, char* ip, char* method, char* path, char* protocol, int* status, int* bytes){
    sscanf(line, "%s %s %s %s %s %d %d", date, time, ip, method, path, status, bytes);
    if(strcmp(protocol, "HTTP/1.0")==0 || strcmp(protocol, "HTTP/1.1")==0 || strcmp(protocol, "")==0){
        //Protocol accepted
    }
    else{
        *status = -1; //Invalid protocol
    }
}

//Function to read the log file line by line and parse each line using the parseLogLine function
void readLogFile(char* filename){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }
    char line[MAX_LINE_SIZE];
    char date[MAX_LINE_SIZE];
    char time[MAX_LINE_SIZE];
    char ip[MAX_LINE_SIZE];
    char method[MAX_LINE_SIZE];
    char path[MAX_LINE_SIZE];
    char protocol[MAX_LINE_SIZE];
    int status;
    int bytes;
    int lineNum = 0;
    int errorLines = 0;
    int successfulRequests = 0;
    int totalBytes = 0;
    while(fgets(line, MAX_LINE_SIZE, file) != NULL){
        lineNum++;
        parseLogLine(line, date, time, ip, method, path, protocol, &status, &bytes);
        if(status==-1){
            printf("Error: Invalid protocol at line %d\n%s\n", lineNum, line);
            errorLines++;
        }
        else if(status>=400 && status<=499){
            printf("Warning: Client error at line %d\n%s\n", lineNum, line);
            errorLines++;
        }
        else if(status>=500 && status<=599){
            printf("Warning: Server error at line %d\n%s\n", line);
            errorLines++;
        }
        else{
            successfulRequests++;
            totalBytes += bytes;
        }
    }
    printf("Processed %d lines of log file %s\n", lineNum, filename);
    printf("%d successful requests with total of %d bytes\n", successfulRequests, totalBytes);
    printf("%d errors detected\n", errorLines);
    fclose(file);
}

int main(){
    char* filename = "access.log";
    readLogFile(filename);
    return 0;
}