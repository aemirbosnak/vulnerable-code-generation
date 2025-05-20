//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define MAX_BUFFER 256

// Function prototypes
void list_processes();
void get_process_info(const char *pid);
void print_process_info(const char *pid, const char *name, const char *state, const char *memory, const char *cpu);

int main() {
    printf("Welcome to the Process Viewer!\n");
    printf("Listing all running processes...\n\n");
    list_processes();
    return 0;
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    // Open the /proc directory
    if ((proc_dir = opendir(PROC_PATH)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Iterate over directory entries
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a directory and is a number (possible PID)
        if (isdigit(*entry->d_name)) {
            get_process_info(entry->d_name);
        }
    }

    // Close the directory
    closedir(proc_dir);
}

void get_process_info(const char *pid) {
    char path[MAX_BUFFER];
    snprintf(path, sizeof(path), "%s/%s/stat", PROC_PATH, pid);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("file open");
        return;
    }

    // Read fields from the stat file
    char name[MAX_BUFFER];
    char state;
    int ppid;
    long int rss; 

    fscanf(file, "%s %s %c %d %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %ld", pid, name, &state, &ppid, &rss);
    fclose(file);

    // Calculate memory usage in Kilobytes
    long int memory_usage_kb = rss * sysconf(_SC_PAGESIZE) / 1024; 

    // Read CPU usage (for simplicity, this could be improved)
    snprintf(path, sizeof(path), "%s/%s/statm", PROC_PATH, pid);
    file = fopen(path, "r");
    long int total_memory;
    fscanf(file, "%ld", &total_memory);
    fclose(file);
    
    // Converting to percentage (not accurate without the proper times)
    char cpu_usage[MAX_BUFFER];
    snprintf(cpu_usage, sizeof(cpu_usage), "%.1f%%", (float)(rss * 100) / total_memory);

    print_process_info(pid, name, (char[]){state, '\0'}, 
                       (char[]) {memory_usage_kb, 'K', '\0'}, cpu_usage);
}

void print_process_info(const char *pid, const char *name, const char *state, 
                        const char *memory, const char *cpu) {
    printf("PID: %s | Name: %s | State: %s | Memory: %s | CPU: %s\n", 
           pid, name, state, memory, cpu);
}