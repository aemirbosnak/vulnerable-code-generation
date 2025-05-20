//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

// Function declarations
void list_processes();
void display_process_info(char *pid);
void print_usage();
int is_number(const char *str);

int main(int argc, char *argv[]) {
    if (argc > 2) {
        print_usage();
        return 1;
    } else if (argc == 2) {
        if (is_number(argv[1])) {
            display_process_info(argv[1]);
        } else {
            print_usage();
        }
    } else {
        list_processes();
    }
    return 0;
}

// Function to print usage information
void print_usage() {
    printf("Usage: ./process_viewer [PID]\n");
    printf("If PID is provided, detailed information about the process will be displayed.\n");
    printf("If no PID is given, a list of current processes will be shown.\n");
}

// Function to check if a string is a number
int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to list all current processes
void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;
    char path[256];
    FILE *status_file;
    char name[256];
    
    printf("Listing all current processes:\n");
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Failed to open /proc");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(proc_dir))) {
        // Check if the entry is a number (which indicates a PID)
        if (is_number(entry->d_name)) {
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
            status_file = fopen(path, "r");
            if (status_file) {
                fscanf(status_file, "Name:\t%s\n", name);
                printf("PID: %s, Name: %s\n", entry->d_name, name);
                fclose(status_file);
            }
        }
    }
    closedir(proc_dir);
}

// Function to display detailed information of a specific process
void display_process_info(char *pid) {
    char path[256];
    FILE *status_file;
    char line[256];

    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    status_file = fopen(path, "r");
    if (!status_file) {
        perror("Failed to open process status file");
        exit(EXIT_FAILURE);
    }

    printf("Displaying information for PID: %s\n", pid);
    while (fgets(line, sizeof(line), status_file)) {
        // Display relevant process information
        if (strncmp(line, "Name:", 5) == 0 ||
            strncmp(line, "State:", 6) == 0 ||
            strncmp(line, "Pid:", 4) == 0 ||
            strncmp(line, "Uid:", 4) == 0 ||
            strncmp(line, "Gid:", 4) == 0 ||
            strncmp(line, "PPid:", 5) == 0 ||
            strncmp(line, "Threads:", 8) == 0) {
            printf("%s", line);
        }
    }

    fclose(status_file);
    printf("End of information for PID: %s\n", pid);
}