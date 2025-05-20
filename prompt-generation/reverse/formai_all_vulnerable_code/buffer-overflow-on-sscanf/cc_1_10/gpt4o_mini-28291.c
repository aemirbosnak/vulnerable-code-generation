//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void trim_whitespace(char *str) {
    // A utility function to trim whitespace from interface
    char *end;

    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return;
    
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

void display_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    FILE *fp;
    char line[BUFFER_SIZE];
    char name[BUFFER_SIZE] = {0};
    int ppid = -1, p_status = 0;

    // Construct the path to the process status file
    snprintf(path, sizeof(path), "/proc/%s/status", pid);

    // Now we read the file
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Could not open process status file");
        return;
    }

    // Read the lines of the file
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "Name:\t%s", name) == 1) {
            trim_whitespace(name);
        } else if (sscanf(line, "PPid:\t%d", &ppid) == 1) {
            // PPid found
        } else if (sscanf(line, "State:\t%d", &p_status) == 1) {
            // State found
        }
    }
    
    // Display relevant process information
    printf("PID: %s | Name: %s | PPID: %d | State: %d\n", pid, name, ppid, p_status);
    fclose(fp);
}

void list_processes() {
    struct dirent *entry;
    DIR *proc_dir = opendir("/proc");

    if (proc_dir == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    while ((entry = readdir(proc_dir))) {
        if (isdigit(*entry->d_name)) {
            display_process_info(entry->d_name);
        }
    }
    closedir(proc_dir);
}

int main() {
    printf("Simple Process Viewer\n");
    printf("======================\n");
    
    list_processes();
    
    printf("\nEnd of Process List.\n");
    return 0;
}