//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Watson, fetch me the system's processes!
int main(int argc, char *argv[]) {
    // Declare our variables
    DIR *dir;
    struct dirent *ent;
    struct stat fileStat;
    char path[256];
    int pid, ppid, state, found = 0;

    // Check if we have the necessary permissions
    if (geteuid() != 0) {
        printf("Elementary, my dear reader! You must be root to run this program.");
        return 1;
    }

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        printf("My word, Watson! It seems /proc is out of reach.");
        return 2;
    }

    // Iterate through the files in /proc
    while ((ent = readdir(dir)) != NULL) {
        // Skip entries that are not directories
        if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
            continue;
        }

        // Check if the entry represents a process
        sprintf(path, "/proc/%s", ent->d_name);
        if (stat(path, &fileStat) == -1) {
            continue;
        }

        if (!S_ISDIR(fileStat.st_mode)) {
            continue;
        }

        // Fetch the process information
        pid = atoi(ent->d_name);
        sprintf(path, "/proc/%d/stat", pid);
        FILE *fp = fopen(path, "r");
        if (fp == NULL) {
            continue;
        }

        fscanf(fp, "%d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %d", &pid, &ppid);
        fclose(fp);

        sprintf(path, "/proc/%d/status", pid);
        fp = fopen(path, "r");
        if (fp == NULL) {
            continue;
        }

        while (fscanf(fp, "%*s %c", &state) != EOF) {
            if (state == 'R') {
                state = 'running';
            } else if (state == 'S') {
                state = 'sleeping';
            } else if (state == 'D') {
                state = 'disk sleep';
            } else if (state == 'Z') {
                state = 'zombie';
            }
            break;
        }
        fclose(fp);

        // Display the process information
        printf("PID: %d\n", pid);
        printf("PPID: %d\n", ppid);
        printf("State: %c\n", state);
        found = 1;
    }

    closedir(dir);

    // Report our findings
    if (!found) {
        printf("It appears the system is devoid of processes. A most curious case, indeed.");
    } else {
        printf("Elementary, my dear reader! I have deduced the following processes:");
    }

    return 0;
}