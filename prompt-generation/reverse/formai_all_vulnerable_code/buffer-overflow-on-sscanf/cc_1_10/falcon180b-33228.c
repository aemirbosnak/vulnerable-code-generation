//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESS_NUM 1024
#define MAX_LINE_NUM 1024

typedef struct {
    int pid;
    char name[32];
    int status;
    int ppid;
    int cpu_time;
    int priority;
} Process;

int main() {
    int fd;
    char path[64];
    char buf[1024];
    char line[MAX_LINE_NUM];
    Process processes[MAX_PROCESS_NUM];
    int num_processes = 0;
    int i;

    // Open the /proc directory
    sprintf(path, "/proc");
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    // Read the directory contents
    while (readdir(fd, buf)!= 0) {
        // Skip non-numeric directories
        if (buf[0] < '0' || buf[0] > '9') {
            continue;
        }

        // Get the PID from the directory name
        sscanf(buf, "%d", &processes[num_processes].pid);

        // Read the process information
        sprintf(path, "/proc/%d/stat", processes[num_processes].pid);
        fd = open(path, O_RDONLY);
        if (fd == -1) {
            printf("Error opening stat file for PID %d\n", processes[num_processes].pid);
            exit(1);
        }

        if (read(fd, buf, sizeof(buf))!= sizeof(buf)) {
            printf("Error reading stat file for PID %d\n", processes[num_processes].pid);
            exit(1);
        }

        close(fd);

        // Extract the process name
        char *name_ptr = strtok(buf, " ");
        strcpy(processes[num_processes].name, name_ptr);

        // Extract the process status
        name_ptr = strtok(NULL, " ");
        processes[num_processes].status = atoi(name_ptr);

        // Extract the process PPID
        name_ptr = strtok(NULL, " ");
        processes[num_processes].ppid = atoi(name_ptr);

        // Extract the process CPU time
        name_ptr = strtok(NULL, " ");
        processes[num_processes].cpu_time = atoi(name_ptr);

        // Extract the process priority
        name_ptr = strtok(NULL, " ");
        processes[num_processes].priority = atoi(name_ptr);

        // Increment the number of processes
        num_processes++;
    }

    closedir(fd);

    // Print the process information
    printf("PID\tName\tStatus\tPPID\tCPU Time\tPriority\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].name, processes[i].status, processes[i].ppid, processes[i].cpu_time, processes[i].priority);
    }

    return 0;
}