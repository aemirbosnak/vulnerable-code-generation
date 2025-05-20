//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MAX_CPU_USAGE 100

struct process {
    pid_t pid;
    char name[64];
    int cpu_usage;
};

void print_usage() {
    printf("Usage:./cpu_monitor [interval_in_seconds]\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    int interval = atoi(argv[1]);

    if (interval <= 0) {
        printf("Invalid interval\n");
        return 1;
    }

    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    FILE *proc_file = fopen("/proc/self/status", "r");
    if (!proc_file) {
        printf("Error opening /proc/self/status\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), proc_file)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strcpy(processes[num_processes].name, line + 6);
        } else if (strncmp(line, "Pid:", 4) == 0) {
            processes[num_processes].pid = atoi(line + 5);
        }
    }

    fclose(proc_file);

    printf("Monitoring CPU usage of process %s (PID %d)\n", processes[0].name, processes[0].pid);

    while (1) {
        sleep(interval);

        for (int i = 0; i < num_processes; i++) {
            sprintf(line, "/proc/%d/stat", processes[i].pid);

            FILE *stat_file = fopen(line, "r");
            if (!stat_file) {
                continue;
            }

            char *token = NULL;
            while ((token = strtok(NULL, " "))!= NULL) {
                if (strncmp(token, "utime", 5) == 0) {
                    processes[i].cpu_usage = atoi(token + 5);
                    break;
                }
            }

            fclose(stat_file);
        }

        for (int i = 0; i < num_processes; i++) {
            printf("%s (PID %d) CPU usage: %d%%\n", processes[i].name, processes[i].pid, processes[i].cpu_usage);
        }
    }

    return 0;
}