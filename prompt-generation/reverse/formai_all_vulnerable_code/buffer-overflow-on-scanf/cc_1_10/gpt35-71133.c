//FormAI DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_PATH 1024
#define MAX_CMD  512

// Function to list all the running processes and their PIDs
void list_processes() {
    DIR *dp;
    struct dirent *dirp;

    // Open the "/proc" directory
    if ((dp = opendir("/proc")) == NULL) {
        perror("Error: could not open /proc directory");
        return;
    }
    
    // Traverse through all the directories in "/proc" and print their PIDs and names
    while ((dirp = readdir(dp)) != NULL) {
        if (dirp->d_type == DT_DIR) {
            char path[MAX_PATH];
            int pid = atoi(dirp->d_name);
            if (pid != 0) {
                sprintf(path, "/proc/%d/cmdline", pid);
                FILE *fp = fopen(path, "r");
                if (fp) {
                    char cmd[MAX_CMD];
                    fgets(cmd, MAX_CMD, fp);
                    fclose(fp);
                    printf("PID: %d\tCommand: %s\n", pid, cmd);
                }
            }
        }
    }
    
    closedir(dp);
}

// Function to terminate a process given its PID
void kill_process(int pid) {
    if (kill(pid, SIGTERM) == -1) {
        perror("Error: could not terminate process");
        return;
    }
    printf("Process with PID %d terminated successfully.\n", pid);
}

int main() {
    // List all running processes
    printf("Listing all running processes...\n");
    list_processes();
    
    // Ask user to specify a PID to terminate
    int pid;
    printf("Enter the PID of the process you wish to terminate: ");
    scanf("%d", &pid);
    
    // Terminate the specified process
    printf("Terminating process with PID %d...\n", pid);
    kill_process(pid);
    
    return 0;
}