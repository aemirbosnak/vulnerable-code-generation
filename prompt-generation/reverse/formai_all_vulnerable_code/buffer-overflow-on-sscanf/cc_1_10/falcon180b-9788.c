//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/time.h>

#define MAX_TASKS 100

typedef struct {
    char name[16];
    int pid;
    int mem_usage;
} Task;

int task_count = 0;
Task tasks[MAX_TASKS];

void update_task_mem_usage(int pid) {
    FILE *fp;
    char path[20];
    sprintf(path, "/proc/%d/statm", pid);

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", path);
        return;
    }

    int mem_usage = 0;
    fscanf(fp, "%d", &mem_usage);
    fclose(fp);

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].pid == pid) {
            tasks[i].mem_usage = mem_usage;
            break;
        }
    }
}

void print_tasks() {
    printf("PID\tName\tMemory Usage\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d\t%s\t%d\n", tasks[i].pid, tasks[i].name, tasks[i].mem_usage);
    }
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    char line[100];
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "add", 3) == 0) {
            int pid;
            sscanf(line, "add %d", &pid);
            strcpy(tasks[task_count].name, "Unknown");
            tasks[task_count].pid = pid;
            task_count++;
        } else if (strncmp(line, "del", 3) == 0) {
            int pid;
            sscanf(line, "del %d", &pid);
            for (int i = 0; i < task_count; i++) {
                if (tasks[i].pid == pid) {
                    task_count--;
                    memmove(&tasks[i], &tasks[i+1], (task_count - i - 1) * sizeof(Task));
                    break;
                }
            }
        } else if (strncmp(line, "update", 6) == 0) {
            update_task_mem_usage(atoi(line + 7));
        } else if (strncmp(line, "print", 5) == 0) {
            print_tasks();
        }
    }

    return 0;
}