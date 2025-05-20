//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 100
#define MAX_PROC_NAME_LENGTH 50

typedef struct {
    int pid;
    char name[MAX_PROC_NAME_LENGTH];
    int memory_usage;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void update_processes() {
    FILE* fp;
    char buffer[1024];
    char cmd[1024];
    int pid;
    char name[MAX_PROC_NAME_LENGTH];
    int memory_usage;

    // Clear previous processes
    memset(processes, 0, sizeof(processes));
    num_processes = 0;

    // Read list of processes from /proc
    fp = popen("ps -e -o pid,comm,%mem --no-headers", "r");
    if (fp == NULL) {
        printf("Error reading processes\n");
        exit(1);
    }
    while (fgets(buffer, sizeof(buffer), fp)) {
        sscanf(buffer, "%d %s %d", &pid, name, &memory_usage);
        Process process = {pid, name, memory_usage};
        processes[num_processes++] = process;
    }
    pclose(fp);
}

void print_processes() {
    printf("%-10s %-20s %-10s\n", "PID", "NAME", "RAM USAGE");
    for (int i = 0; i < num_processes; i++) {
        Process process = processes[i];
        printf("%-10d %-20s %-10d\n", process.pid, process.name, process.memory_usage);
    }
}

void scale_up() {
    int pid;
    printf("Enter PID to increase RAM usage: ");
    scanf("%d", &pid);
    for (int i = 0; i < num_processes; i++) {
        Process process = processes[i];
        if (process.pid == pid) {
            system("yes > /dev/null &");
            printf("Scaled up RAM usage of process %d (%s)\n", process.pid, process.name);
            return;
        }
    }
    printf("PID not found\n");
}

void scale_down() {
    int pid;
    printf("Enter PID to decrease RAM usage: ");
    scanf("%d", &pid);
    for (int i = 0; i < num_processes; i++) {
        Process process = processes[i];
        if (process.pid == pid) {
            system("killall yes");
            printf("Scaled down RAM usage of process %d (%s)\n", process.pid, process.name);
            return;
        }
    }
    printf("PID not found\n");
}

int main() {
    while (1) {
        update_processes();
        print_processes();

        printf("\nEnter 1 to scale up RAM usage, 2 to scale down, or 0 to quit: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scale_up();
                break;
            case 2:
                scale_down();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}