//Code Llama-13B DATASET v1.0 Category: System process viewer ; Style: rigorous
/*
 * Unique C System Process Viewer Example Program
 *
 * This program displays information about the currently running system processes
 * using the Linux procfs interface.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

// Structure to store information about a process
struct Process {
    int pid;
    char name[1024];
    char state;
    int priority;
    int cpu_time;
};

// Function to display a process's information
void display_process(struct Process process) {
    printf("PID: %d\n", process.pid);
    printf("Name: %s\n", process.name);
    printf("State: %c\n", process.state);
    printf("Priority: %d\n", process.priority);
    printf("CPU Time: %d\n", process.cpu_time);
    printf("\n");
}

int main() {
    // Open the procfs directory
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Iterate over each directory entry
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip over non-process directories
        if (entry->d_type != DT_DIR) {
            continue;
        }

        // Read the process's information
        char path[1024];
        sprintf(path, "/proc/%s/stat", entry->d_name);
        FILE* file = fopen(path, "r");
        if (file == NULL) {
            perror("fopen");
            continue;
        }

        // Read the process's name
        char name[1024];
        fscanf(file, "%s", name);

        // Read the process's state
        char state;
        fscanf(file, "%c", &state);

        // Read the process's priority
        int priority;
        fscanf(file, "%d", &priority);

        // Read the process's CPU time
        int cpu_time;
        fscanf(file, "%d", &cpu_time);

        // Create a process structure and display its information
        struct Process process;
        process.pid = atoi(entry->d_name);
        strcpy(process.name, name);
        process.state = state;
        process.priority = priority;
        process.cpu_time = cpu_time;
        display_process(process);

        // Close the file
        fclose(file);
    }

    // Close the directory
    closedir(dir);

    return 0;
}