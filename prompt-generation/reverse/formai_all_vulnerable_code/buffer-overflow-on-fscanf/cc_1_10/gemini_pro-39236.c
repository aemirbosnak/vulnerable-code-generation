//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <math.h>

int main() {
    // Define the set of processes
    DIR *proc_dir = opendir("/proc");
    struct dirent *proc_entry;

    // Define the set of process attributes
    int pid;
    char name[256];
    long int state;
    int ppid;
    long int utime;
    long int stime;

    // Enumerate the processes
    while ((proc_entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a directory
        if (proc_entry->d_type != DT_DIR) {
            continue;
        }

        // Extract the process ID
        pid = atoi(proc_entry->d_name);

        // Define the path to the process status file
        char status_file[256];
        sprintf(status_file, "/proc/%d/status", pid);

        // Open the process status file
        FILE *status_fp = fopen(status_file, "r");
        if (status_fp == NULL) {
            perror("fopen");
            continue;
        }

        // Read the process attributes
        fscanf(status_fp, "Name: %s\n", name);
        fscanf(status_fp, "State: %ld\n", &state);
        fscanf(status_fp, "PPid: %d\n", &ppid);
        fscanf(status_fp, "Utime: %ld\n", &utime);
        fscanf(status_fp, "Stime: %ld\n", &stime);

        // Close the process status file
        fclose(status_fp);

        // Print the process attributes
        printf("%d %s %ld %d %ld %ld\n", pid, name, state, ppid, utime, stime);
    }

    // Close the process directory
    closedir(proc_dir);

    return 0;
}