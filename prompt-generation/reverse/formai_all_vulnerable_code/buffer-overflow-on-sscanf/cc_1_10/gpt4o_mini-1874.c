//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PROC 1024
#define MAX_PATH 256

void display_system_info() {
    printf("======= System Information =======\n");
    printf("Operating System: %s\n", "Linux");
    // More information can be gathered using specific system calls or files
    printf("User: %s\n", getlogin());
    printf("Current Directory: %s\n", getcwd(NULL, 0));
    printf("==================================\n");
}

void list_files(const char *dir) {
    struct dirent *entry;
    DIR *dp = opendir(dir);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Listing files in directory: %s\n", dir);
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            printf("  - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void display_processes() {
    struct stat statbuf;
    printf("======= Running Processes =======\n");

    for (int i = 1; i < MAX_PROC; i++) {
        char path[MAX_PATH];
        sprintf(path, "/proc/%d", i);

        if (stat(path, &statbuf) == 0) {
            FILE *cmdfile;
            char cmdline[256];

            sprintf(path, "/proc/%d/cmdline", i);
            cmdfile = fopen(path, "r");
            if (cmdfile) {
                fgets(cmdline, sizeof(cmdline), cmdfile);
                printf("PID: %d, Command: %s\n", i, cmdline);
                fclose(cmdfile);
            }
        }
    }

    printf("==================================\n");
}

void change_directory(const char *path) {
    if (chdir(path) == 0) {
        printf("Successfully changed directory to: %s\n", path);
    } else {
        perror("chdir failed");
    }
}

int main() {
    char command[256];
    char path[MAX_PATH];

    display_system_info();

    while (1) {
        printf("Enter command (ls, ps, cd <path>, exit): ");
        
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break; // EOF or error
        }

        // Remove newline character
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "ls", 2) == 0) {
            list_files(".");
        } else if (strncmp(command, "ps", 2) == 0) {
            display_processes();
        } else if (strncmp(command, "cd", 2) == 0) {
            sscanf(command, "cd %s", path);
            change_directory(path);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting system administration program...\n");
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}