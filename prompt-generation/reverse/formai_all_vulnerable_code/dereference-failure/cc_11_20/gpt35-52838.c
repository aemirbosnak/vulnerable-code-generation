//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024 // Maximum path length
#define MAX_LINE 512 // Maximum line length

// Convert all characters in a string to uppercase
void to_upper(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

// Print a row of dashes to separate sections
void print_dashes(int num) {
    for (int i = 0; i < num; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    DIR *proc_dir; // Pointer to directory structure
    struct dirent *entry; // Directory entry
    char path[MAX_PATH]; // Path to /proc directory
    char line[MAX_LINE]; // Buffer for reading line from /proc/PID/status file
    char name[MAX_LINE]; // Process name
    char state[MAX_LINE]; // Process state
    char pid[MAX_LINE]; // Process ID
    char uid[MAX_LINE]; // User ID
    char mem[MAX_LINE]; // Memory usage
    char cmd[MAX_LINE]; // Command line
    int num_procs = 0; // Number of processes found
    int total_mem = 0; // Total memory usage
    int longest_name = 0; // Length of longest process name
    int longest_cmd = 0; // Length of longest command line

    // Open /proc directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Could not open /proc directory");
        exit(EXIT_FAILURE);
    }

    // Iterate through directory entries
    while ((entry = readdir(proc_dir))) {
        // Check if directory entry is a directory
        if (entry->d_type == DT_DIR) {
            // Check if directory name is a valid PID
            if (isdigit(*entry->d_name)) {
                // Construct path to /proc/PID/status file
                sprintf(path, "/proc/%s/status", entry->d_name);

                // Open /proc/PID/status file
                FILE *status_file = fopen(path, "r");
                if (status_file == NULL) {
                    // Could not open file, process probably ended
                    continue;
                }

                // Read process information from /proc/PID/status file
                while (fgets(line, sizeof(line), status_file)) {
                    // Process name
                    if (sscanf(line, "Name:\t%s", name) == 1) {
                        to_upper(name);
                        // Update length of longest process name
                        int name_len = strlen(name);
                        if (name_len > longest_name) {
                            longest_name = name_len;
                        }
                    }
                    // Process state
                    else if (sscanf(line, "State:\t%s", state) == 1) {
                        to_upper(state);
                    }
                    // Process ID
                    else if (sscanf(line, "Pid:\t%s", pid) == 1) {
                        to_upper(pid);
                    }
                    // User ID
                    else if (sscanf(line, "Uid:\t%s", uid) == 1) {
                        to_upper(uid);
                    }
                    // Memory usage
                    else if (sscanf(line, "VmSize:\t%s", mem) == 1) {
                        // Remove units from memory size
                        strtok(mem, " ");
                        // Convert memory size from string to integer
                        int mem_int = atoi(mem);
                        // Add memory usage to total memory usage
                        total_mem += mem_int;
                    }
                }

                // Close /proc/PID/status file
                fclose(status_file);

                // Construct path to /proc/PID/cmdline file
                sprintf(path, "/proc/%s/cmdline", entry->d_name);

                // Open /proc/PID/cmdline file
                FILE *cmdline_file = fopen(path, "r");
                if (cmdline_file == NULL) {
                    // Could not open file, process probably ended
                    continue;
                }

                // Read command line from /proc/PID/cmdline file
                fgets(cmd, sizeof(cmd), cmdline_file);

                // Close /proc/PID/cmdline file
                fclose(cmdline_file);

                // Update length of longest command line
                int cmd_len = strlen(cmd);
                if (cmd_len > longest_cmd) {
                    longest_cmd = cmd_len;
                }

                // Increment number of processes found
                num_procs++;
            }
        }
    }

    // Close /proc directory
    closedir(proc_dir);

    // Print process viewer
    printf("+-");
    print_dashes(longest_name);
    printf("| Process");
    for (int i = 0; i < longest_name - 7; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("+-");
    print_dashes(longest_name);
    printf("| State");
    for (int i = 0; i < longest_name - 5; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("+-");
    print_dashes(longest_name);
    printf("| PID");
    for (int i = 0; i < longest_name - 3; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("+-");
    print_dashes(longest_name);
    printf("| UID");
    for (int i = 0; i < longest_name - 3; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("+-");
    print_dashes(longest_name);
    printf("| Memory");
    for (int i = 0; i < longest_name - 6; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("+-");
    print_dashes(longest_name);
    printf("| Command");
    for (int i = 0; i < longest_cmd - 7; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("+-");
    print_dashes(longest_name);

    // Print process information
    proc_dir = opendir("/proc");
    while ((entry = readdir(proc_dir))) {
        if (entry->d_type == DT_DIR && isdigit(*entry->d_name)) {
            sprintf(path, "/proc/%s/status", entry->d_name);
            FILE *status_file = fopen(path, "r");
            if (status_file == NULL) {
                continue;
            }
            while (fgets(line, sizeof(line), status_file)) {
                if (sscanf(line, "Name:\t%s", name) == 1) {
                    to_upper(name);
                    printf("| %-*s", longest_name, name);
                    break;
                }
            }
            fclose(status_file);
            sprintf(path, "/proc/%s/status", entry->d_name);
            FILE *cmdline_file = fopen(path, "r");
            if (cmdline_file == NULL) {
                continue;
            }
            while (fgets(line, sizeof(line), cmdline_file)) {
                if (sscanf(line, "%s", cmd) == 1) {
                    printf("| %s", cmd);
                    break;
                }
            }
            fclose(cmdline_file);
            printf("|\n");
            printf("+-");
            print_dashes(longest_name);
        }
    }
    closedir(proc_dir);

    // Print total number of processes and total memory usage
    printf("Total processes: %d\n", num_procs);
    printf("Total memory usage: %d KB\n", total_mem);

    return 0;
}