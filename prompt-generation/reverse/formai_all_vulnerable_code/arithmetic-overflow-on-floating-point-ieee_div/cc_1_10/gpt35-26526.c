//FormAI DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#define MAX_BUF 1024

int isNumber(char* s){
    for (int i = 0; i < strlen(s); i++){
        if(!isdigit(*(s+i))){
            return 0;
        }
    }
    return 1;
}

void displayProcessInfo(char* pid){
    char* filePath = (char*) malloc(sizeof(char)*MAX_BUF);
    snprintf(filePath, MAX_BUF, "/proc/%s/status", pid);
    FILE* fp = fopen(filePath, "r");
    char buf[MAX_BUF];
    if(fp == NULL){
        printf("\nProcess %s does not exist.\n", pid);
        return;
    }
    printf("\nProcess %s:\n", pid);
    int counter = 0, utime = 0, stime = 0;
    while(fgets(buf, MAX_BUF, fp) != NULL){
        if(counter == 1){
            printf("- Name: %s", buf+6);
        }else if(counter == 12){
            printf("- State: %s", buf+7);
        }else if(counter == 14){
            printf("- User Time: %s", buf+6);
            utime = atoi(buf+6);
        }else if(counter == 15){
            printf("- System Time: %s", buf+6);
            stime = atoi(buf+6);
        }
        counter++;
    }
    fclose(fp); 
    free(filePath);
}

int main(){
    DIR* directory;
    struct dirent* filePtr;
    char fullPath[MAX_BUF], path[MAX_BUF];
    directory = opendir("/proc/");
    if(directory == NULL){
        printf("Could not open /proc/.");
        exit(EXIT_FAILURE);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("                                   POST-APOCALYPTIC TASK MANAGER\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("       PID |          Name | State |  CPU Usage (%%)\n");
    printf("-------------------------------------------------------------------------------------------\n");
    while((filePtr=readdir(directory)) != NULL){
        if(!isNumber(filePtr->d_name)){
            continue;
        }
        snprintf(fullPath, MAX_BUF, "/proc/%s/stat", filePtr->d_name);
        FILE* fp = fopen(fullPath, "r");
        if(fp == NULL){
            printf("Could not open file %s", fullPath);
            exit(EXIT_FAILURE);
        }
        fscanf(fp, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*d %*d %*d %*d %*d %*d %*u %*u %*d %*d %*d %*d %*d %*d %*d %*u %*u %*d");
        int utime, stime;
        fscanf(fp, "%d %d", &utime, &stime);
        fclose(fp); 
        snprintf(path, MAX_BUF, "/proc/%s/cmdline", filePtr->d_name);
        fp = fopen(path, "r");
        char cmd[MAX_BUF];
        if(fp == NULL){
            strcpy(cmd, "[unknown]");
        }else{
            fgets(cmd, MAX_BUF, fp);
            fclose(fp);
        }
        displayProcessInfo(filePtr->d_name);
        printf(" %7s | %13s | %5s | %8.2lf\n", filePtr->d_name, cmd, "running", ((float)(utime+stime)/(float)sysconf(_SC_CLK_TCK)) * 100);
    }
    closedir(directory);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return 0;
}