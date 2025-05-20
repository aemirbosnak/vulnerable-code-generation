//FormAI DATASET v1.0 Category: System process viewer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 256

int main() {
    // Get process id of this program
    int pid = getpid();

    // Create a directory stream for /proc directory
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error opening directory /proc\n");
        exit(1);
    }

    // Loop through all subdirectories in /proc directory
    struct dirent* entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        char* name = entry->d_name;

        // Check if the subdirectory's name is a number; if not, skip it
        if (name[0] < '0' || name[0] > '9') {
            continue;
        }

        // Open the subdirectory for reading
        char proc_path[BUF_SIZE];
        snprintf(proc_path, BUF_SIZE, "/proc/%s", name);
        DIR* proc = opendir(proc_path);
        if (proc == NULL) {
            continue;
        }

        // Read the process's PID from the cmdline file
        char cmdline_path[BUF_SIZE];
        snprintf(cmdline_path, BUF_SIZE, "%s/cmdline", proc_path);
        FILE* cmdline_file = fopen(cmdline_path, "r");
        if (cmdline_file == NULL) {
            continue;
        }
        char cmdline[BUF_SIZE];
        fgets(cmdline, BUF_SIZE, cmdline_file);

        // Read the process's status from the status file
        char status_path[BUF_SIZE];
        snprintf(status_path, BUF_SIZE, "%s/status", proc_path);
        FILE* status_file = fopen(status_path, "r");
        if (status_file == NULL) {
            continue;
        }
        char status[BUF_SIZE];
        while (fgets(status, BUF_SIZE, status_file)) {
            if (strncmp(status, "State:", 6) == 0) {
                break;
            }
        }

        // Get the process's memory usage from the statm file
        char statm_path[BUF_SIZE];
        snprintf(statm_path, BUF_SIZE, "%s/statm", proc_path);
        FILE* statm_file = fopen(statm_path, "r");
        if (statm_file == NULL) {
            continue;
        }
        int size;
        fscanf(statm_file, "%d", &size);

        // Determine if the process is running or idle
        char* state;
        if (strcmp(status + 7, "running\n") == 0) {
            state = "running";
        } else {
            state = "idle";
        }

        // Determine if the process is this program or not
        char* same;
        if (atoi(name) == pid) {
            same = "Yes";
        } else {
            same = "No";
        }

        // Output the process information
        printf("PID: %s\n", name);
        printf("Command: %s\n", cmdline);
        printf("Status: %s", status + 7);
        printf("Memory usage: %d KB\n", size);
        printf("State: %s\n", state);
        printf("This program? %s\n", same);
        printf("---------------------------------------------------------\n");

        // Cleanup
        fclose(cmdline_file);
        fclose(status_file);
        fclose(statm_file);
        closedir(proc);
    }

    // Cleanup
    closedir(proc_dir);
    return 0;
}