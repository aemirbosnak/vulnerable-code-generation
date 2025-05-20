//FormAI DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024
#define MAX_PID_LENGTH 10

/*
 * Function: getProcessInfo
 * ------------------------
 * Retrieves process information, such as process ID, name, and status, from a specified /proc/[pid] directory.
 *
 *  pid     : Process ID to retrieve information for
 *  name    : Memory location to store process name
 *  status  : Memory location to store process status
 *
 *  returns : void
 */
void getProcessInfo(char* pid, char* name, char* status) {
    char path[MAX_PATH_LENGTH];
    FILE *fp;

    // Construct path to /proc/[pid]/cmdline file
    snprintf(path, MAX_PATH_LENGTH, "/proc/%s/cmdline", pid);

    // Open /proc/[pid]/cmdline file for reading
    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", path);
        return;
    }

    // Retrieve process name from /proc/[pid]/cmdline file
    if (fgets(name, MAX_PATH_LENGTH, fp) != NULL) {
        // Remove the newline character from the end of the string
        name[strcspn(name, "\n")] = 0;
    }

    // Close /proc/[pid]/cmdline file
    fclose(fp);

    // Construct path to /proc/[pid]/status file
    snprintf(path, MAX_PATH_LENGTH, "/proc/%s/status", pid);

    // Open /proc/[pid]/status file for reading
    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", path);
        return;
    }

    // Retrieve process status from /proc/[pid]/status file
    while (fgets(path, MAX_PATH_LENGTH, fp) != NULL) {
        if (strncmp(path, "State:", 6) == 0) {
            // Remove leading whitespace and the 'State:' string from the status line
            char* ptr = path + 6;
            while (*ptr == ' ' || *ptr == '\t') ptr++;
            strncpy(status, ptr, MAX_PATH_LENGTH);
            break;
        }
    }

    // Close /proc/[pid]/status file
    fclose(fp);
}

int main(int argc, char** argv) {
    DIR* dirp;
    struct dirent *dp;

    // Open /proc directory for reading
    dirp = opendir("/proc");
    if (dirp == NULL) {
        printf("Could not open directory /proc\n");
        return 1;
    }

    // Print header row for process information table
    printf("%-10s%-20s%s\n", "PID", "Name", "Status");

    // Loop over all files in /proc directory and retrieve process information for each process
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_type == DT_DIR) {
            char pid[MAX_PID_LENGTH];
            char name[MAX_PATH_LENGTH];
            char status[MAX_PATH_LENGTH];

            // Check if current directory name represents a process ID
            if (sscanf(dp->d_name, "%s", pid) == 1) {
                // Retrieve process information for current process ID
                getProcessInfo(pid, name, status);

                // If process name and status were successfully retrieved, print them in table format
                if (strlen(name) > 0 && strlen(status) > 0) {
                    printf("%-10s%-20s%s\n", pid, name, status);
                }
            }
        }
    }

    // Close /proc directory
    closedir(dirp);

    return 0;
}