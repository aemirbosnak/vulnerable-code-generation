//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <dirent.h>
#include <string.h>

#define PROC_PATH "/proc"

// Function to print process information
void print_process_info(struct dirent *dir) {
    char path[256];
    FILE *file;

    // Check if the file is a directory
    if (!dir->d_type == DT_DIR) {
        return;
    }

    // Check if the directory name is numeric
    if (!isdigit(dir->d_name[0])) {
        return;
    }

    // Get the process ID
    int pid = atoi(dir->d_name);

    // Get the process status file path
    snprintf(path, sizeof(path), "%s/%d/status", PROC_PATH, pid);

    // Open the process status file
    file = fopen(path, "r");
    if (file == NULL) {
        return;
    }

    // Read the process name
    char name[256];
    fscanf(file, "Name: %s", name);

    // Read the process state
    char state[2];
    fscanf(file, "State: %s", state);

    // Read the process memory usage
    long rss;
    fscanf(file, "VmRSS: %ld kB", &rss);

    // Print the process information
    printf("%d %s %s %ld\n", pid, name, state, rss);

    // Close the process status file
    fclose(file);
}

int main() {
    // Get the directory stream for the "/proc" directory
    DIR *proc_dir = opendir(PROC_PATH);
    if (proc_dir == NULL) {
        return -1;
    }

    // Iterate over the files in the "/proc" directory
    struct dirent *dir;
    while ((dir = readdir(proc_dir)) != NULL) {
        // Print the process information
        print_process_info(dir);
    }

    // Close the directory stream
    closedir(proc_dir);

    return 0;
}