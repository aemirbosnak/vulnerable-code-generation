//FormAI DATASET v1.0 Category: System process viewer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_DIRECTORY_LENGTH 512

int main() {
    char cwd[MAX_DIRECTORY_LENGTH];
    
    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
      perror("Could not get current working directory");
      exit(EXIT_FAILURE);
    }

    printf("Process Viewer in %s:\n", cwd);
    
    // Open the /proc directory
    DIR *dir = opendir("/proc");

    if (dir == NULL) {
        perror("Could not open /proc directory");
        exit(EXIT_FAILURE);
    }

    // Read the contents of the /proc directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory and its name consists of only digits
        if (entry->d_type == DT_DIR && strspn(entry->d_name, "0123456789") == strlen(entry->d_name)) {
            // Open the /proc/[pid]/stat file for this process
            int pid = atoi(entry->d_name);
            char path[MAX_DIRECTORY_LENGTH];
            sprintf(path, "/proc/%d/stat", pid);

            FILE *file = fopen(path, "r");
            if (file) {
                // Read the information from the /proc/[pid]/stat file
                int ppid;
                char comm[MAX_DIRECTORY_LENGTH];
                char state;
                fscanf(file, "%d %s %c", &ppid, comm, &state);

                // Display the process information
                printf("%d  %d  %c  %s\n", pid, ppid, state, comm);
                
                fclose(file);
            }
        }
    }

    closedir(dir);
    return 0;
}