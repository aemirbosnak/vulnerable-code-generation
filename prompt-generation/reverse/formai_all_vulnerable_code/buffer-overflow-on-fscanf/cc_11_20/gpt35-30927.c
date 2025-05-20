//FormAI DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define PROC_DIRECTORY "/proc"

int main() {
    DIR *directory;
    struct dirent *entry;
    char stat_file_path[256];
    char process_name[256];
    int pid;
    int ppid;
    int state;
    char state_desc[256];

    printf("%-10s %-10s %-20s %s\n", "PID", "PPID", "Process Name", "State");

    // Open the /proc directory
    if ((directory = opendir(PROC_DIRECTORY)) == NULL) {
        perror("opendir() error");
        return 1;
    }

    // Iterate over all directory entries
    while ((entry = readdir(directory)) != NULL) {
        // Ignore non-numeric directory entries
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        // Construct the path to the process' stat file
        snprintf(stat_file_path, sizeof(stat_file_path), "%s/%s/stat", PROC_DIRECTORY, entry->d_name);

        // Try to open the stat file
        FILE *stat_file;
        if ((stat_file = fopen(stat_file_path, "r")) == NULL) {
            continue;
        }

        // Parse the values from the stat file
        fscanf(stat_file, "%d %s %c %d", &pid, process_name, &state, &ppid);

        // Close the stat file
        fclose(stat_file);

        // Determine the process' state
        switch (state) {
            case 'R':
                strncpy(state_desc, "Running", sizeof(state_desc));
                break;
            case 'S':
                strncpy(state_desc, "Sleeping", sizeof(state_desc));
                break;
            case 'D':
                strncpy(state_desc, "Disk Sleep", sizeof(state_desc));
                break;
            case 'Z':
                strncpy(state_desc, "Zombie", sizeof(state_desc));
                break;
            case 'T':
                strncpy(state_desc, "Stopped", sizeof(state_desc));
                break;
            case 't':
                strncpy(state_desc, "Tracing Stop", sizeof(state_desc));
                break;
            case 'X':
                strncpy(state_desc, "Dead", sizeof(state_desc));
                break;
            case 'K':
                strncpy(state_desc, "Wakekill", sizeof(state_desc));
                break;
            case 'W':
                strncpy(state_desc, "Waking", sizeof(state_desc));
                break;
            case 'P':
                strncpy(state_desc, "Parked", sizeof(state_desc));
                break;
            default:
                strncpy(state_desc, "Unknown", sizeof(state_desc));
                break;
        }

        printf("%-10d %-10d %-20s %s\n", pid, ppid, process_name, state_desc);
    }

    // Close the /proc directory
    closedir(directory);

    return 0;
}