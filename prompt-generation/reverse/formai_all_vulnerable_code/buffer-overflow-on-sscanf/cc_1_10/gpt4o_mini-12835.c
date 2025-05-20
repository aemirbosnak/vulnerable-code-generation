//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define PROC_DIR "/proc"

void display_process_info(const char *pid) {
    char path[MAX_LINE_LENGTH];
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char comm[MAX_LINE_LENGTH];
    char state;
    int ppid;

    // Construct the path to the status file.
    snprintf(path, sizeof(path), "%s/%s/status", PROC_DIR, pid);
    
    file = fopen(path, "r");
    if (!file) {
        return; // Couldn't open the file, return early.
    }

    // Read information from the status file.
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "Name:\t%s", comm) == 1) {
            // Successfully read the command name.
            continue;
        }
        if (sscanf(line, "State:\t%c", &state) == 1) {
            // Successfully read the process state.
            continue;
        }
        if (sscanf(line, "PPid:\t%d", &ppid) == 1) {
            // Successfully read the parent process ID.
            continue;
        }
    }

    fclose(file);

    // Display the collected process information.
    printf("PID: %s\t Name: %s\t State: %c\t PPID: %d\n", pid, comm, state, ppid);
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    // Open the directory containing process information.
    if ((proc_dir = opendir(PROC_DIR)) == NULL) {
        perror("opendir");
        return;
    }

    // Read the directory entries.
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a numeric directory (representing a PID).
        if (isdigit(entry->d_name[0])) {
            // Display process information for this PID.
            display_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

int main(int argc, char *argv[]) {
    printf("Simple Process Viewer:\n");
    printf("--------------------------------------------------\n");
    list_processes();
    printf("--------------------------------------------------\n");
    return 0;
}