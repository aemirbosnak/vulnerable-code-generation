//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_BUFFER 256

// Function to extract process information
void fetch_processes() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_BUFFER];
    FILE *status_file;

    // Open the directory containing process IDs
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    printf("O, gentle gait, the processes do rise,\n");
    printf("In this fair realm of Linux, life does thrive.\n");
    
    while ((entry = readdir(dir)) != NULL) {
        // Only look for directories that are numbers (i.e., process IDs)
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
            status_file = fopen(path, "r");

            if (status_file) {
                char line[MAX_BUFFER];
                char name[MAX_BUFFER] = "Unknown";

                // Reading the process name and state
                while (fgets(line, sizeof(line), status_file)) {
                    if (sscanf(line, "Name:\t %s", name) == 1) {
                        printf("Ah, what light through yonder process breaks?\n");
                        printf("The process's name: %s\n", name);
                    } else if (strstr(line, "State:")) {
                        printf("Its state, alas, is: %s", line + 7); // Skip "State:" and the tab
                        printf("Thus, it dances 'neath the processor's sky,\n\n");
                    }
                }
                fclose(status_file);
            }
        }
    }
    closedir(dir);
    printf("So many processes in this spirited play,\n");
    printf("Each a tale of fleeting time, a breath away.\n");
}

int main() {
    printf("Welcome to the realm of Processes, dear friend.\n");
    printf("Let us embark on a quest to see the lives that blend.\n\n");

    fetch_processes();

    printf("The curtain falls, yet life must ever go on,\n");
    printf("In the great theater of bytes, we bid you warm dawn.\n");

    return 0;
}