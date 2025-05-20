//FormAI DATASET v1.0 Category: System process viewer ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<ctype.h>

#define DESC_SIZE 1024

typedef struct process {
    pid_t pid; // Process ID
    char name[DESC_SIZE]; // Process name
    char state; // Process status 
} process;

// Function to retrieve and parse process data from procfs
process* getProcesses(int *n)
{
    DIR *dir;
    struct dirent *ent;
    process *processes = NULL;
    *n = 0;

    // Open /proc directory
    if ((dir = opendir("/proc")) != NULL) {
        // Loop through all directories in /proc directory
        while ((ent = readdir(dir)) != NULL) {
            // Check if the directory name is a number (representing a process ID)
            if(isdigit(ent->d_name[0])) {
                // Open the cmdline file for this process to retrieve the process name
                char path[DESC_SIZE];
                sprintf(path, "/proc/%s/cmdline", ent->d_name);
                FILE *fp = fopen(path, "r");
                if(fp != NULL) {
                    // Read the first string (process name) from cmdline
                    fscanf(fp, "%s", path);
                    fclose(fp);
                    // Allocate memory for a new process structure
                    process *newProcess = realloc(processes, (*n+1) * sizeof(process));
                    // Assign process attributes
                    newProcess[*n].pid = atoi(ent->d_name);
                    strncpy(newProcess[*n].name, path, DESC_SIZE);
                    newProcess[*n].state = 'N'; // Set process state as 'Not Running'
                    // Increase process count
                    *n += 1;
                    processes = newProcess;
                }
            }
        }
        closedir(dir);
    }
    // Return the array of process structures
    return processes;
}

// Function to display process information in a table
void showProcesses(process *processes, int n)
{
    printf("%-10s %-30s %-10s\n", "PID", "Process Name", "State");
    for(int i=0; i<n; i++) {
        printf("%-10d %-30s %-10c\n", processes[i].pid, processes[i].name, processes[i].state);
    }
    printf("\n");
}

// Function to set process states
void setProcessStates(process *processes, int n)
{
    DIR *dir;
    struct dirent *ent;
    char path[DESC_SIZE];

    // Open /proc directory
    if ((dir = opendir("/proc")) != NULL) {
        // Loop through all directories in /proc directory
        while ((ent = readdir(dir)) != NULL) {
            // Check if the directory name is a number (representing a process ID)
            if(isdigit(ent->d_name[0])) {
                // Form the status filepath for this process
                sprintf(path, "/proc/%s/status", ent->d_name);
                FILE *fp = fopen(path, "r");
                if(fp != NULL) {
                    char line[DESC_SIZE];
                    // Loop through all lines in the status file
                    while(fgets(line, sizeof line, fp) != NULL) {
                        // Check for the "State:" line
                        if(strncmp(line, "State:", 6) == 0) {
                            // Read the 3rd character of this line (process state character)
                            sscanf(line+7,"%c", &processes->state);
                        }
                    }
                    fclose(fp);
                }
            }
        }
        closedir(dir);
    }
}

int main()
{
    int n;
    process *processes = getProcesses(&n);
    if(processes != NULL) {
        // Display initial process information
        printf("Initial Process Information:\n");
        showProcesses(processes, n);
        // Wait for 5 seconds
        sleep(5);
        // Retrieve and set process states
        setProcessStates(processes, n);
        // Display updated process information
        printf("Updated Process Information:\n");
        showProcesses(processes, n);
        // Free the dynamically allocated process array
        free(processes);
    }
    return 0;
}