//FormAI DATASET v1.0 Category: System process viewer ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>

/* function to check if string is a number */
int isNumber(char* str) {
    for(int i=0; str[i]!='\0'; i++) {
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

/* function to get process name from pid */
char* getProcName(char* pid) {
    char* procName = (char*)malloc(sizeof(char)*100);
    char* path = (char*)malloc(sizeof(char)*100);
    strcpy(path, "/proc/");
    strcat(path, pid);
    strcat(path, "/comm");
    int fd = open(path, O_RDONLY);
    if(fd==-1) {
        strcpy(procName, "N/A");
        close(fd);
        return procName;
    }
    read(fd, procName, 100);
    close(fd);
    return procName;
}

/* function to print the process table */
void printProcessTable(int* pidArr, int* ppidArr, int* utimeArr, int* stimeArr, int* vsizeArr, int length) {
    printf("%5s %10s %10s %10s %10s %10s\n", "PID", "PPID", "PROCESS", "UTIME", "STIME", "VSIZE");
    for(int i=0; i<length; i++) {
        char* procName = getProcName((char*)pidArr[i]);
        printf("%5d %10d %10s %10d %10d %10d\n", pidArr[i], ppidArr[i], procName, utimeArr[i], stimeArr[i], vsizeArr[i]);
    }
}

/* function to get process info */
void getProcessInfo(int* pidArr, int* ppidArr, int* utimeArr, int* stimeArr, int* vsizeArr, int length) {
    DIR* dp;
    struct dirent* de;

    /* traverse the /proc directory */
    dp = opendir("/proc");
    while((de=readdir(dp)) != NULL) {
        if(isNumber(de->d_name)) {
            /* get the pid */
            int pid = atoi(de->d_name);

            /* get the process status */
            char* path = (char*)malloc(sizeof(char)*100);
            strcpy(path, "/proc/");
            strcat(path, de->d_name);
            strcat(path, "/stat");
            int fd = open(path, O_RDONLY);
            char buffer[1001];
            read(fd, buffer, 1000);
            close(fd);

            /* parse the process status */
            char* token = strtok(buffer, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            int ppid = atoi(token);
            token = strtok(NULL, " ");
            int pgrp = atoi(token);
            token = strtok(NULL, " ");
            int session = atoi(token);
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            int utime = atoi(token);
            token = strtok(NULL, " ");
            int stime = atoi(token);
            token = strtok(NULL, " ");
            int cutime = atoi(token);
            token = strtok(NULL, " ");
            int cstime = atoi(token);
            token = strtok(NULL, " ");
            int priority = atoi(token);
            token = strtok(NULL, " ");
            int nice = atoi(token);
            token = strtok(NULL, " ");
            int numThreads = atoi(token);
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            int vsize = atoi(token);

            /* check if pid is in the array for display */
            for(int i=0; i<length; i++) {
                if(pid==pidArr[i]) {
                    /* update the arrays */
                    ppidArr[i] = ppid;
                    utimeArr[i] = utime;
                    stimeArr[i] = stime;
                    vsizeArr[i] = vsize;
                }
            }
        }
    }
    closedir(dp);
}

int main() {
    int pidArr[10], ppidArr[10], utimeArr[10], stimeArr[10], vsizeArr[10];
    int length = 0;
    int input = 0;
    while(1) {
        system("clear");
        printf("1. Add PID\n");
        printf("2. Print Process Table\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &input);
        switch(input) {
            case 1:
                if(length==10) {
                    printf("Cannot add more than 10 processes!\n");
                    sleep(2);
                }
                else {
                    printf("Enter PID of process: ");
                    scanf("%d", &pidArr[length]);
                    ppidArr[length] = -1;
                    utimeArr[length] = -1;
                    stimeArr[length] = -1;
                    vsizeArr[length] = -1;
                    length++;
                }
                break;
            case 2:
                if(length==0) {
                    printf("No PIDs added!\n");
                    sleep(2);
                }
                else {
                    /* get process information */
                    getProcessInfo(pidArr, ppidArr, utimeArr, stimeArr, vsizeArr, length);
                    /* print process table */
                    printProcessTable(pidArr, ppidArr, utimeArr, stimeArr, vsizeArr, length);
                    printf("Press Enter to continue...\n");
                    getchar();
                    getchar();
                }
                break;
            case 3:
                printf("Exiting...\n");
                sleep(1);
                exit(0);
            default:
                printf("Invalid choice!\n");
                sleep(1);
        }
    }
    return 0;
}