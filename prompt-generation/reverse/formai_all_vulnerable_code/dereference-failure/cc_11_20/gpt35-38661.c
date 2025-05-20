//FormAI DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

int main() {
    pid_t pids[MAX_PROCESSES];
    DIR *proc_dir;
    struct dirent *dir_entry;
    char proc_path[1024], status_path[1024];
    char process_name[256], state;
    int utime, stime, rss, pid_count = 0;

    printf("=== Post-Apocalyptic System Process Viewer ===\n\n");

    // Open the proc directory
    if ((proc_dir = opendir("/proc")) != NULL) {
        // Read each directory entry
        while ((dir_entry = readdir(proc_dir)) != NULL) {
            // Check if the entry name is a number (that could be a pid)
            if (isdigit(dir_entry->d_name[0])) {
                // Convert the directory name to a pid
                pids[pid_count++] = atoi(dir_entry->d_name);
                // Break if we reached the maximum number of processes
                if (pid_count >= MAX_PROCESSES) {
                    break;
                }
            }
        }
        closedir(proc_dir);
    } else {
        printf("Error: Could not open /proc directory\n");
        return 1;
    }

    // Print the table header
    printf("%-10s%-20s%-10s%-20s%-7s%-7s%-10s\n", 
        "PID", "Process name", "State", "Memory usage", "Utime", 
        "Stime", "Path");
    printf("=================================================================\n");

    // Read the status information for each process
    for (int i = 0; i < pid_count; i++) {
        // Construct the path to the process status file
        sprintf(status_path, "/proc/%d/status", pids[i]);
        // Open the process status file
        FILE *status_file = fopen(status_path, "r");
        if (status_file != NULL) {
            // Read each line of the file and extract the information we need
            while (fgets(proc_path, sizeof(proc_path), status_file) != NULL) {
                if (strstr(proc_path, "Name:") != NULL) {
                    sscanf(proc_path + strlen("Name:"), " %s", process_name);
                } else if (strstr(proc_path, "State:") != NULL) {
                    sscanf(proc_path + strlen("State:"), " %c", &state);
                } else if (strstr(proc_path, "VmRSS:") != NULL) {
                    sscanf(proc_path + strlen("VmRSS:"), " %d", &rss);
                } else if (strstr(proc_path, "Utime:") != NULL) {
                    sscanf(proc_path + strlen("Utime:"), " %d", &utime);
                } else if (strstr(proc_path, "Stime:") != NULL) {
                    sscanf(proc_path + strlen("Stime:"), " %d", &stime);
                }
            }
            fclose(status_file);
        }

        // If we have all the information we need, print it in the table
        if (strlen(process_name) > 0 && state != '\0' && rss > 0) {
            // Get the path to the executable
            sprintf(proc_path, "/proc/%d/exe", pids[i]);
            char exe_path[1024];
            int path_size = readlink(proc_path, exe_path, sizeof(exe_path) - 1);
            exe_path[path_size] = '\0';
            // Print the process information in the table
            printf("%-10d%-20s%-10c%-20d%-7d%-7d%-10s\n",
                pids[i], process_name, state, rss, utime, stime, exe_path);
        }

        // Reset the variables for the next process
        memset(process_name, 0, sizeof(process_name));
        state = '\0';
        rss = 0;
        utime = 0;
        stime = 0;
    }

    return 0;
}