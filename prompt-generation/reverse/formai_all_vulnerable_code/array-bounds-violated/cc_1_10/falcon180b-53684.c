//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PROCESSES 100

typedef struct {
    pid_t pid;
    char name[MAX_LINE_LENGTH];
} process_t;

void print_processes(process_t processes[], int count) {
    printf("PID\tName\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }
}

int get_processes(process_t processes[], int max_count) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int count = 0;

    fp = fopen("/proc/self/task", "r");
    if (fp == NULL) {
        printf("Error opening /proc/self/task\n");
        return -1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (count >= max_count) {
            break;
        }

        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        processes[count].pid = atoi(line);
        strcpy(processes[count].name, line + strlen(line) - 1);
        count++;
    }

    fclose(fp);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <process name>\n", argv[0]);
        return -1;
    }

    char process_name[MAX_LINE_LENGTH];
    strcpy(process_name, argv[1]);

    process_t processes[MAX_PROCESSES];
    int count = get_processes(processes, MAX_PROCESSES);

    if (count == -1) {
        return -1;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(processes[i].name, process_name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Process %s not found\n", process_name);
        return -1;
    }

    printf("Process %s found\n", process_name);
    print_processes(processes, count);

    return 0;
}