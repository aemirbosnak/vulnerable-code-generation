//FormAI DATASET v1.0 Category: System process viewer ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILES 1024
#define MAX_LEN 50

typedef struct proc {
    int pid;
    char name[MAX_LEN];
    char state[MAX_LEN];
    int threads;
    struct proc *next;
} proc_t;

void displayHeader() {
    printf("%-6s %-25s %-10s %s\n", "PID", "NAME", "STATE", "THREADS");
}

int isNumeric(char *s) {
    while (*s) {
        if (!isdigit(*s++)) {
            return 0;
        }
    }
    return 1;
}

int cmpNums(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void displayProcesses(proc_t *head, int numProcs) {
    proc_t *current = head;
    int pids[numProcs];
    int i = 0;
    while (current != NULL) {
        pids[i++] = current->pid;
        current = current->next;
    }
    qsort(pids, numProcs, sizeof(int), cmpNums);
    for (int i = 0; i < numProcs; i++) {
        current = head;
        while (current != NULL) {
            if (current->pid == pids[i]) {
                printf("%-6d %-25s %-10s %d\n", current->pid, current->name, current->state, current->threads);
                break;
            }
            current = current->next;
        }
    }
}

void addProcess(proc_t **head, int pid, char *name, char *state, int threads) {
    proc_t *newNode = (proc_t*)malloc(sizeof(proc_t));
    newNode->pid = pid;
    strcpy(newNode->name, name);
    strcpy(newNode->state, state);
    newNode->threads = threads;
    newNode->next = *head;
    *head = newNode;
}

void freeList(proc_t *head) {
    proc_t *current = head;
    while (current != NULL) {
        proc_t *temp = current;
        current = current->next;
        free(temp);
    }
}

void parseStatFile(char *filePath, proc_t **head) {
    char *line = NULL;
    char filename[MAX_LEN];
    char state[MAX_LEN];
    int pid, ppid, pgrp, session, tty_nr, tpgid, num_threads;
    unsigned int flags;
    long unsigned int minflt, cminflt, majflt, cmajflt, utime, stime, cutime, cstime, priority, nice, num_context_switches;
    long int starttime;
    size_t len = 0;
    ssize_t read;

    FILE *fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filePath);
        return;
    }

    fscanf(fp, "%d ", &pid); // read the pid from the file path
    sprintf(filename, "/proc/%d/stat", pid);
    FILE *fp1 = fopen(filename, "r");
    if (fp1 == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // read fields from the stat file using fscanf
    fscanf(fp1, "%d %s %s %d %d %d %d %d %u %lu %lu %lu %lu %lu %ld %ld %ld %ld \
        %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %u %u %lu %ld",
        &pid,                            // %d
        filename,                       // %s
        state,                          // %c
        &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt, &cminflt,
        &majflt, &cmajflt, &utime, &stime, &cutime, &cstime, &priority, &nice,
        &num_threads, &num_context_switches, &starttime);

    // close file pointers
    fclose(fp1);
    fclose(fp);

    addProcess(head, pid, filename, state, num_threads);
}

void readProcFiles(proc_t **head) {
    DIR *d;
    struct dirent *dir;
    d = opendir("/proc/");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (isNumeric(dir->d_name)) {
                char filePath[MAX_LEN];
                sprintf(filePath, "/proc/%s/stat", dir->d_name);
                parseStatFile(filePath, head);
            }
        }
        closedir(d);
    }
}

int main(int argc, char **argv) {
    proc_t *head = NULL;
    printf("System Process Viewer\n\n");
    readProcFiles(&head);
    int numProcs = 0;
    proc_t *current = head;
    while (current != NULL) {
        numProcs++;
        current = current->next;
    }
    displayHeader();
    displayProcesses(head, numProcs);
    freeList(head);
    return 0;
}