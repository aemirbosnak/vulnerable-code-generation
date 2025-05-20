//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define BASE_PATH "/proc/"
#define BUFFER_SIZE 256

// Function prototypes
void print_process_info(const char *pid);
void display_processes();

int main() {
    printf("=================================\n");
    printf("   Simple Process Viewer v1.0   \n");
    printf("=================================\n");
    display_processes();
    return 0;
}

void display_processes() {
    struct dirent *entry;
    DIR *proc_dir = opendir(BASE_PATH);
    if (!proc_dir) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-25s %-10s\n", "PID", "COMMAND", "STATUS");
    printf("-------------------------------------------------------------\n");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name);
        }
    }
    closedir(proc_dir);
}

void print_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), BASE_PATH "%s/stat", pid);
    
    FILE *stat_file = fopen(path, "r");
    if (stat_file == NULL) {
        perror("Failed to open stat file");
        return;
    }

    int pid_num;
    char comm[BUFFER_SIZE];
    char state;
    
    // Reading the stat file
    fscanf(stat_file, "%d %s %c", &pid_num, comm, &state);
    fclose(stat_file);

    // Removing the parentheses from command
    if (comm[0] == '(') {
        char *end = strchr(comm, ')');
        if (end != NULL) {
            *end = '\0';
            memmove(comm, comm + 1, strlen(comm)); // Remove the opening parenthesis
        }
    }

    printf("%-10s %-25s %-10c\n", pid, comm, state);
}