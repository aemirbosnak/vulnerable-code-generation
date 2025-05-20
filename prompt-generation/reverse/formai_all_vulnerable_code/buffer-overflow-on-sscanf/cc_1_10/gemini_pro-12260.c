//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/utsname.h>
#include <pwd.h>
#include <grp.h>

#define MAX_SIZE 1024

int main() {
    // A tale of curious process explorer begins...

    // Let's ask the kernel for a list of all the processes.
    DIR *proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("Failed to open /proc");
        return EXIT_FAILURE;
    }

    // A loop to explore each process's mysteries.
    struct dirent *dir_entry;
    while ((dir_entry = readdir(proc_dir)) != NULL) {
        // Check if it's a directory, for we seek the process's details.
        if (!strcmp(dir_entry->d_name, ".") || !strcmp(dir_entry->d_name, "..")) {
            continue;
        }
        int pid = atoi(dir_entry->d_name);

        // A trip to the status file to unfold its secrets.
        char status_path[MAX_SIZE];
        snprintf(status_path, MAX_SIZE, "/proc/%d/status", pid);
        FILE *status_file = fopen(status_path, "r");
        if (!status_file) {
            perror("Failed to open status file");
            continue;
        }

        // A charlatan to hold the process's story.
        char buffer[MAX_SIZE];

        // Unraveling the process's name.
        fgets(buffer, MAX_SIZE, status_file);
        char *name = strchr(buffer, ':') + 2;
        name[strlen(name) - 1] = '\0';

        // A glimpse into the process's lineage.
        int ppid;
        fgets(buffer, MAX_SIZE, status_file);
        sscanf(buffer, "PPid: %d", &ppid);

        // Uncovering its username and group.
        fgets(buffer, MAX_SIZE, status_file);
        char *username = getpwuid(atoi(buffer + 9))->pw_name;
        fgets(buffer, MAX_SIZE, status_file);
        char *groupname = getgrgid(atoi(buffer + 6))->gr_name;

        // The time this process has been alive.
        long uptime;
        fgets(buffer, MAX_SIZE, status_file);
        sscanf(buffer, "Uptime: %ld", &uptime);

        // Wrapping it all in a neat package.
        printf("Process %d:\n", pid);
        printf("  Name: %s\n", name);
        printf("  Parent: %d\n", ppid);
        printf("  Username: %s\n", username);
        printf("  Group: %s\n", groupname);
        printf("  Uptime: %ld seconds\n", uptime);
        printf("=====================\n");

        fclose(status_file);
    }

    closedir(proc_dir);
    return EXIT_SUCCESS;
}