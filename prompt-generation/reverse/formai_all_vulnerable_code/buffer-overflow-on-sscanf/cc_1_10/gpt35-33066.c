//FormAI DATASET v1.0 Category: System process viewer ; Style: rigorous
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PATH 1024

// Function to check if a given string is a numeric value
int is_numeric(const char *str)
{
    while (*str) {
        if (!isdigit(*str++))
            return 0;
    }
    return 1;
}

// Function to parse the given process id and get information about it
int parse_process_info(char *pid)
{
    char file_path[MAX_PATH], buffer[MAX_PATH];
    FILE *file;
    int process_id;

    // Check if the given pid is numeric
    if (!is_numeric(pid)) {
        printf("Invalid process id provided.\n");
        return 1;
    }

    // Build the path to the process info file
    sprintf(file_path, "/proc/%s/status", pid);

    // Open the process info file
    file = fopen(file_path, "r");
    if (!file) {
        printf("Could not open process info file: %s\n", file_path);
        return 1;
    }

    // Read the process id from the file
    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "Pid: %d", &process_id);

    printf("Process ID: %d\n", process_id);

    // Read the rest of the process info from the file
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}

// Function to list all running processes on the system
void list_processes(void)
{
    DIR *dir;
    struct dirent *entry;

    // Open the directory containing the processes
    dir = opendir("/proc");
    if (!dir) {
        printf("Could not open directory: /proc\n");
        return;
    }

    // Iterate through each entry in the directory
    while ((entry = readdir(dir))) {
        // Check if the entry is a directory and its name is a numeric value (which is a process id)
        if (entry->d_type == DT_DIR && is_numeric(entry->d_name)) {
            printf("%s\n", entry->d_name);
        }
    }

    // Close the directory
    closedir(dir);
}

int main(int argc, char *argv[])
{
    // Check if a process id was provided as an argument
    if (argc >= 2) {
        return parse_process_info(argv[1]);
    }

    // List all running processes on the system
    list_processes();

    return 0;
}