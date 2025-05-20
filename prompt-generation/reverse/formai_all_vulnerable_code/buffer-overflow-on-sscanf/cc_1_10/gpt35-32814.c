//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS_NAME 50
#define MAX_NUM_PROCESSES 100

typedef struct process {
    char name[MAX_PROCESS_NAME];
    int pid;
    float cpu_percentage;
} Process;

int num_processes = 0;
Process processes[MAX_NUM_PROCESSES];

// Function to parse the output of the 'ps' command to get cpu usage info for each process
void parse_ps_output(char* ps_output) {
    char* token = strtok(ps_output, "\n"); // Split output by line
    while(token != NULL) {
        char process_name[MAX_PROCESS_NAME];
        int pid;
        float cpu_percentage;
        // Parse output to get process name, pid and cpu %
        sscanf(token, "%s %d %f", process_name, &pid, &cpu_percentage);
        if(strlen(process_name) > 0) { // Ignore empty lines
            // Add process to array
            strcpy(processes[num_processes].name, process_name);
            processes[num_processes].pid = pid;
            processes[num_processes].cpu_percentage = cpu_percentage;
            num_processes++;
        }
        token = strtok(NULL, "\n");
    }
}

// Function to get CPU usage for each process
void get_process_cpu_usage() {
    char ps_command[50];
    // Run 'ps' command to get CPU usage info
    sprintf(ps_command, "ps -Ao comm,pid,pcpu --sort=-pcpu | head -n %d", MAX_NUM_PROCESSES);
    FILE* pipe = popen(ps_command, "r");
    if(pipe == NULL) {
        perror("Error running ps command");
        exit(1);
    }
    char ps_output[1000];
    fread(ps_output, sizeof(char), sizeof(ps_output), pipe);
    parse_ps_output(ps_output);
    pclose(pipe);
}

int main() {
    while(1) {
        // Clear array of processes
        num_processes = 0;
        memset(processes, 0, sizeof(processes));
        // Get CPU usage for each process
        get_process_cpu_usage();
        printf("---------------------------------------------------------------------------\n");
        printf("| %-20s | %-10s | %-15s |\n", "Process Name", "PID", "CPU Usage (%)");
        printf("---------------------------------------------------------------------------\n");
        for(int i=0; i<num_processes; i++) {
            printf("| %-20s | %-10d | %-15.2f |\n", processes[i].name, processes[i].pid, processes[i].cpu_percentage);
        }
        printf("---------------------------------------------------------------------------\n");
        // Wait for one second before getting CPU usage info again
        sleep(1);
    }
    return 0;
}