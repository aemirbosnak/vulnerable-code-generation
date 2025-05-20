//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCESSES 50

typedef struct Proc {
    pid_t pid;
    char name[256];
    int ram_usage;
} Proc;

Proc processes[MAX_PROCESSES];

int num_processes = 0;

int get_ram_usage(pid_t pid) {
    char filename[256];
    sprintf(filename, "/proc/%d/statm", pid);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file\n");
        exit(1);
    }

    int ram_usage;
    fscanf(fp, "%d", &ram_usage);

    fclose(fp);

    return ram_usage;
}

void init_processes() {
    FILE *pids_file = popen("pidof -x monitor", "r");
    if (pids_file == NULL) {
        perror("Error opening PID file\n");
        exit(1);
    }

    char pids_str[1024];
    fgets(pids_str, sizeof(pids_str), pids_file);
    pclose(pids_file);

    char *pid_str = strtok(pids_str, " ");
    while (pid_str != NULL) {
        int pid = atoi(pid_str);
        char cmd_filename[256];
        sprintf(cmd_filename, "/proc/%d/cmdline", pid);

        FILE *cmd_file = fopen(cmd_filename, "r");
        if (cmd_file == NULL) {
            perror("Error opening command file\n");
            exit(1);
        }

        char cmd[1024];
        fgets(cmd, sizeof(cmd), cmd_file);
        fclose(cmd_file);

        Proc process = {
            .pid = pid,
            .ram_usage = get_ram_usage(pid)
        };
        strcpy(process.name, cmd);
        processes[num_processes++] = process;
        
        pid_str = strtok(NULL, " ");
    }
}

void print_processes() {
    printf("%-10s %-30s %-15s\n", "PID", "COMMAND", "RAM USAGE");
    for (int i = 0; i < num_processes; i++) {
        printf("%-10d %-30s %-15d\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
}

void update_ram_usage() {
    for (int i = 0; i < num_processes; i++) {
        int ram_usage = get_ram_usage(processes[i].pid);
        processes[i].ram_usage = ram_usage;
    }
}

int main() {
    init_processes();
    print_processes();

    while (1) {
        sleep(1);
        update_ram_usage();
        system("clear");
        print_processes();
    }

    return 0;
}