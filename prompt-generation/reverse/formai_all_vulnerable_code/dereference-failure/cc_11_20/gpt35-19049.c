//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *proc_directory;
    struct dirent *proc_file;
    char path[80];
    char buffer[1024];
    FILE *fp;
    int pid;

    // Open the /proc directory
    proc_directory = opendir("/proc");

    // Check if directory exists
    if(proc_directory == NULL) {
        printf("Error: could not open /proc directory\n");
        return 1;
    }

    // Print header
    printf("|-----------------------------------------------------|\n");
    printf("|           Futuristic System Process Viewer          |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|   PID   |    NAME    |   STATE   |   MEM USAGE(KB)  |\n");
    printf("|-----------------------------------------------------|\n");

    // Loop through each file in /proc directory
    while((proc_file = readdir(proc_directory)) != NULL) {
        // Check if it is a directory and if the name is all digits (meaning it is a process)
        if(proc_file->d_type == DT_DIR && isdigit(proc_file->d_name[0])) {
            // Get the process ID
            pid = atoi(proc_file->d_name);

            // Generate file path for status file
            sprintf(path, "/proc/%d/status", pid);

            // Open the status file
            fp = fopen(path, "r");

            // Check if file exists
            if(fp == NULL) {
                printf("Error: could not open status file for PID %d\n", pid);
            } else {
                // Read the file line by line
                while(fgets(buffer, sizeof(buffer), fp)) {
                    // Look for the Name and State lines
                    if(strncmp(buffer, "Name:", 5) == 0) {
                        // Parse the process name
                        char *name = buffer + 6;

                        // Remove any trailing whitespace
                        int length = strlen(name);
                        if(name[length-1] == '\n') {
                            name[length-1] = '\0';
                        }

                        // Generate file path for statm file
                        sprintf(path, "/proc/%d/statm", pid);

                        // Open the statm file
                        fp = fopen(path, "r");

                        // Check if file exists
                        if(fp == NULL) {
                            printf("Error: could not open statm file for PID %d\n", pid);
                        } else {
                            // Read the first line (contains memory usage)
                            fgets(buffer, sizeof(buffer), fp);
                            int memory_usage = atoi(buffer);

                            // Close the file
                            fclose(fp);

                            // Print the process information
                            printf("|%8d|%12s|%11s|%19d|\n", pid, name, "RUNNING", memory_usage);
                        }
                    }
                    else if(strncmp(buffer, "State:", 6) == 0) {
                        // Get the state of the process
                        char state = buffer[7];

                        // Print the process information
                        printf("|%8d|%12s|%11c|%19s|\n", pid, "", state, "");
                    }
                }

                // Close the file
                fclose(fp);
            }
        }
    }

    // Close the /proc directory
    closedir(proc_directory);

    // Print footer
    printf("|-----------------------------------------------------|\n");
    
    return 0;
}