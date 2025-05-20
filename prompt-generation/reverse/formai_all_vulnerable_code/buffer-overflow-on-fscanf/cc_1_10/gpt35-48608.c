//FormAI DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

// Define constants for maximum length of file names, process names and paths
#define MAX_FILE_NAME_LEN 256
#define MAX_PROC_NAME_LEN 256
#define MAX_PROC_PATH_LEN 1024

// Define a struct for the process information
typedef struct {
    char name[MAX_PROC_NAME_LEN];
    int pid;
    int ppid;
    long rss; // Resident Set Size: number of pages the process has in real memory
    char state; // R: Running, S: Sleeping, D: I/O Wait, Z: Zombie, T: Stopped
} proc_info;

// Function to parse the /proc/[pid]/stat file to extract the process information
proc_info parse_stat_file(char *filename) {
    proc_info info;
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        // Read the first field from the stat file, which is the process ID
        fscanf(file, "%d", &info.pid);
        // Read the second field, which is the process name (in parentheses)
        fscanf(file, " (%[^)]s", info.name);
        // Skip the next 10 fields, which we don't need
        for (int i = 0; i < 10; i++) {
            fscanf(file, "%*s");
        }
        // Read the next field, which is the process state
        fscanf(file, "%c", &info.state);
        // Skip the next 19 fields, which we don't need
        for (int i = 0; i < 19; i++) {
            fscanf(file, "%*s");
        }
        // Read the next field, which is the parent process ID
        fscanf(file, "%d", &info.ppid);
        // Skip the next 21 fields, which we don't need
        for (int i = 0; i < 21; i++) {
            fscanf(file, "%*s");
        }
        // Read the next field, which is the resident set size
        fscanf(file, "%ld", &info.rss);
        // Close the file
        fclose(file);
    }
    return info;
}

// Function to print the process information in a table format
void print_proc_info(proc_info info) {
    printf("| %5d | %5d | %12ld | %c | %-32s |\n",
           info.pid, info.ppid, info.rss, info.state, info.name);
}

int main() {

    // Print the header row of the process table
    printf("+-------+-------+--------------+-----+----------------------------------+\n");
    printf("| PID   | PPID  | RSS          | S   | NAME                             |\n");
    printf("+-------+-------+--------------+-----+----------------------------------+\n");

    // Open the /proc directory
    DIR *dir = opendir("/proc");
    if (dir != NULL) {
        // Loop through all the files in the /proc directory
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            // Check if the filename is a directory and made up of digits only
            if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
                // Get the full path of the stat file for this process
                char stat_path[MAX_PROC_PATH_LEN];
                sprintf(stat_path, "/proc/%s/stat", entry->d_name);
                // Parse the stat file and print the process information
                proc_info info = parse_stat_file(stat_path);
                if (strlen(info.name) > 0) {
                    print_proc_info(info);
                }
            }
        }
        // Close the /proc directory
        closedir(dir);
    }

    // Print the footer row of the process table
    printf("+-------+-------+--------------+-----+----------------------------------+\n");

    return 0;
}