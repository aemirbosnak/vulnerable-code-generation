//FormAI DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
/* Program to display a list of currently running processes along with their process IDs and memory usages */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define PROCESS_DIR "/proc/"
#define NAME_LENGTH 20

int main(void) 
{
    DIR *directory;
    struct dirent *entry;
    char processName[NAME_LENGTH], fileName[NAME_LENGTH + 6], lineBuffer[256];
    FILE *statusFile;
    long int pid;
    int rss;
 
    printf("********** CURRENT SYSTEM PROCESSES **********\n\n");
    printf("%-20s %10s\n", "PROCESS NAME", "PID");
    printf("---------------------------------------------\n");

    if ((directory = opendir(PROCESS_DIR)) != NULL) {
        
        /* Loop through the directory and find directories with numeric names - these are process directories */
        while ((entry = readdir(directory)) != NULL) {
            if (isdigit(entry->d_name[0])) {
                pid = strtol(entry->d_name, NULL, 10);
                
                /* Open the status file for the current process and read the resident set size */
                sprintf(fileName, "%s%s/status", PROCESS_DIR, entry->d_name);
                statusFile = fopen(fileName, "r");
                if (statusFile != NULL) {
                    while (fgets(lineBuffer, sizeof(lineBuffer), statusFile)) {
                        if (strncmp(lineBuffer, "Name:", 5) == 0) {
                            sscanf(lineBuffer + 5, "%s", processName);
                        }
                        if (strncmp(lineBuffer, "VmRSS:", 6) == 0) {
                            sscanf(lineBuffer + 6, "%d", &rss);
                        }
                    }
                    fclose(statusFile);

                    /* Print out the process information */
                    printf("%-20s %10ld %10d KB\n", processName, pid, rss);
                }
            }
        }
        closedir(directory);
    } 
    else {
        perror("Error opening /proc");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}