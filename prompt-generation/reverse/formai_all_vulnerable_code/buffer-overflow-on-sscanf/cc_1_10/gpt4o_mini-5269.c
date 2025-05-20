//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

void showProcesses(const char *style) {
    DIR *procDir;
    struct dirent *entry;
    char buffer[BUFFER_SIZE];
    
    procDir = opendir("/proc");
    if (!procDir) {
        perror("opendir");
        return;
    }
    
    printf("PID\tCMD\t\t\t\t\t\tState\n");
    printf("---------------------------------------------------------\n");
    
    while ((entry = readdir(procDir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            // Construct path to cmdline
            snprintf(buffer, sizeof(buffer), "/proc/%s/cmdline", entry->d_name);
            FILE *cmdFile = fopen(buffer, "r");
            if (cmdFile) {
                char cmd[BUFFER_SIZE];
                fgets(cmd, sizeof(cmd), cmdFile);
                fclose(cmdFile);
                
                // Trim spaces and format the command for output
                for (int i = 0; cmd[i] != '\0'; i++) {
                    if (cmd[i] == '\0') {
                        cmd[i] = ' ';
                    }
                }
                
                // Construct path to status
                snprintf(buffer, sizeof(buffer), "/proc/%s/status", entry->d_name);
                FILE *statusFile = fopen(buffer, "r");
                char state[16];
                if (statusFile) {
                    // Fetch the state of the process
                    while (fgets(buffer, sizeof(buffer), statusFile)) {
                        if (sscanf(buffer, "State:\t%s", state) == 1) {
                            break;
                        }
                    }
                    fclose(statusFile);
                }
                
                // Display processes in a shape-shifting style
                if (strcmp(style, "simple") == 0) {
                    printf("%s\t%s\n", entry->d_name, cmd);
                }
                else if (strcmp(style, "detailed") == 0) {
                    printf("PID: %s, CMD: %s, State: %s\n", entry->d_name, cmd, state);
                }
                else { // elegant style
                    printf("| PID: %s | Command: %s | State: %s |\n", entry->d_name, cmd, state);
                }
            }
        }
    }
    
    closedir(procDir);
}

int main() {
    char style[16];
    
    printf("Process Viewer - Shape Shifting Style!\n");
    printf("Choose a style for viewing processes (simple/detailed/elegant): ");
    
    // Get user input for style
    scanf("%15s", style);
    
    // Process the request
    showProcesses(style);
    
    return 0;
}