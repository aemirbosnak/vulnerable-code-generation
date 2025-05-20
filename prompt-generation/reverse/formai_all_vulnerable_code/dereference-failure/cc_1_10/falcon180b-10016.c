//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100

// Define a structure to store process information
typedef struct process_info {
    int pid;
    char name[20];
    int status;
} ProcessInfo;

// Function to compare two process structures by PID
int compare_processes(const void* a, const void* b) {
    const ProcessInfo* p1 = a;
    const ProcessInfo* p2 = b;
    return p1->pid - p2->pid;
}

// Function to print a list of process structures
void print_processes(ProcessInfo* processes, int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

// Function to wait for a child process to exit and return its status
int wait_for_child(int pid) {
    int status;
    waitpid(pid, &status, 0);
    return status;
}

// Function to signal a child process to terminate
void signal_child(int pid) {
    kill(pid, SIGTERM);
}

// Function to launch a new child process
int launch_child(char* command) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        execlp(command, command, NULL);
        perror("execlp");
        exit(1);
    } else {
        return pid;
    }
}

// Function to monitor a list of child processes
void monitor_processes(ProcessInfo* processes, int num_processes) {
    while (1) {
        printf("Enter a command to launch a new process or 'q' to quit:\n");
        char command[50];
        scanf("%s", command);
        if (strcmp(command, "q") == 0) {
            break;
        }
        int pid = launch_child(command);
        if (pid!= -1) {
            strcpy(processes[num_processes].name, command);
            processes[num_processes].pid = pid;
            processes[num_processes].status = 0;
            num_processes++;
        }
    }
}

// Main function to initialize and run the process viewer
int main() {
    ProcessInfo* processes = malloc(MAX_PROCESSES * sizeof(ProcessInfo));
    int num_processes = 0;

    // Initialize the process list
    for (int i = 0; i < MAX_PROCESSES; i++) {
        strcpy(processes[i].name, "");
        processes[i].pid = 0;
        processes[i].status = 0;
    }

    // Monitor the processes
    monitor_processes(processes, num_processes);

    // Print the final list of processes
    print_processes(processes, num_processes);

    // Terminate all child processes
    for (int i = 0; i < num_processes; i++) {
        signal_child(processes[i].pid);
        wait_for_child(processes[i].pid);
    }

    return 0;
}