//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>

#define BUFFER_SIZE 256
#define DPROCESSES "/proc"

void print_process_info(const char *pid) {
    char path[BUFFER_SIZE], buffer[BUFFER_SIZE];
    FILE *fp;
    
    // Construct the path to the status file
    snprintf(path, sizeof(path), "%s/%s/status", DPROCESSES, pid);
    
    if ((fp = fopen(path, "r")) == NULL) {
        return; // Unable to open status file, exit the function
    }
    
    char user[BUFFER_SIZE] = "unknown";
    char command[BUFFER_SIZE] = "unknown";
    int utid = 0;

    // Read the status file and extract relevant information
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "Uid:\t%d", &utid) == 1) {
            struct passwd *pw = getpwuid(utid);
            if (pw) {
                strncpy(user, pw->pw_name, sizeof(user) - 1);
            }
        } else if (strncmp(buffer, "Name:", 5) == 0) {
            sscanf(buffer + 6, "%s", command);
        }
    }
    fclose(fp);
    
    printf("%-10s %-20s %-30s\n", pid, user, command);
}

void list_processes() {
    struct dirent *entry;
    DIR *dp;

    // Open the /proc directory
    if ((dp = opendir(DPROCESSES)) == NULL) {
        perror("opendir");
        return;
    }

    printf("\n%-10s %-20s %-30s\n", "PID", "USER", "COMMAND");
    printf("---------------------------------------------------------------\n");

    // Iterate over each item in the /proc directory
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Only process directories that contain digits (PIDs)
            if (isdigit(entry->d_name[0])) {
                print_process_info(entry->d_name);
            }
        }
    }

    closedir(dp);
}

int main(void) {
    printf("Simple Process Viewer\n");
    printf("======================\n");

    while (1) {
        list_processes();
        
        printf("\nPress (q) to quit or any other key to refresh: ");
        char ch = getchar();
        while (getchar() != '\n'); // Clear input buffer

        if (ch == 'q' || ch == 'Q') {
            break;
        }
        // Clear screen for refresh effect
        printf("\e[1;1H\e[2J");
    }
    
    return 0;
}