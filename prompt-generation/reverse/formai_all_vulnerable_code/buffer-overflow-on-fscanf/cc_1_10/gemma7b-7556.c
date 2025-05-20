//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PROC_NUM 10

typedef struct PROC_INFO {
    char name[20];
    int pid;
    long uptime;
    struct PROC_INFO* next;
} PROC_INFO;

PROC_INFO* gProcHead = NULL;

void updateProcInfo(char* procName, int pid) {
    PROC_INFO* newProc = malloc(sizeof(PROC_INFO));
    strcpy(newProc->name, procName);
    newProc->pid = pid;
    newProc->uptime = time(NULL);
    newProc->next = NULL;

    if (gProcHead == NULL) {
        gProcHead = newProc;
    } else {
        PROC_INFO* tempProc = gProcHead;
        while (tempProc->next) {
            tempProc = tempProc->next;
        }
        tempProc->next = newProc;
    }
}

int main() {
    int i, j;
    char procName[20];
    FILE* fp;
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (1) {
        for (i = 0; i < MAX_PROC_NUM; i++) {
            fscanf(fp, "%s %d ", procName, &j);
            updateProcInfo(procName, j);
        }

        sleep(1);
    }

    fclose(fp);
    return 0;
}