//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024

struct process_info {
    pid_t pid;
    char name[32];
    float cpu_usage;
};

int get_process_info(struct process_info *processes, int num_processes) {
    FILE *fp;
    char filename[128], line[1024];
    int count = 0;

    sprintf(filename, "/proc/stat");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        return -1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= num_processes) {
            break;
        }

        if (sscanf(line, "cpu %d %s", &processes[count].pid, processes[count].name)!= 2) {
            continue;
        }

        processes[count].cpu_usage = 0.0;
        count++;
    }

    fclose(fp);
    return count;
}

void print_process_info(struct process_info *processes, int num_processes) {
    int i;

    printf("PID\tName\tCPU Usage\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }
}

int main() {
    int num_processes = 0;
    struct process_info processes[MAX_PROCESSES];

    while (num_processes == 0 || num_processes == MAX_PROCESSES) {
        printf("Enter the number of processes you want to monitor (1 to %d): ", MAX_PROCESSES - 1);
        scanf("%d", &num_processes);
    }

    int num_found = get_process_info(processes, num_processes);

    if (num_found == -1) {
        return 1;
    }

    while (1) {
        usleep(500000); // Sleep for 0.5 seconds

        int num_updated = get_process_info(processes, num_processes);

        if (num_updated!= num_found) {
            num_found = num_updated;
            print_process_info(processes, num_found);
        }
    }

    return 0;
}