//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PATH_LENGTH 256

void check_disk_usage(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("statvfs failed");
        return;
    }

    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;
    double percentage_used = (double)used / (double)total * 100;

    printf("Disk Usage for %s:\n", path);
    printf("Total: %.2f GiB\n", total / (1024.0 * 1024.0 * 1024.0));
    printf("Used: %.2f GiB (%.2f%%)\n", used / (1024.0 * 1024.0 * 1024.0), percentage_used);
    printf("Free: %.2f GiB\n", free / (1024.0 * 1024.0 * 1024.0));
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH_LENGTH];
    FILE *status_file;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("PID\t\tCOMMAND\n");
    printf("-----------------------------------\n");
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                snprintf(path, sizeof(path), "/proc/%d/status", pid);
                status_file = fopen(path, "r");
                if (status_file) {
                    char comm[256];
                    while (fgets(path, sizeof(path), status_file)) {
                        if (sscanf(path, "Name:\t%s", comm) == 1) {
                            printf("%d\t\t%s\n", pid, comm);
                            break;
                        }
                    }
                    fclose(status_file);
                }
            }
        }
    }
    closedir(dir);
}

void kill_process(int pid) {
    if (kill(pid, SIGTERM) == 0) {
        printf("Process %d has been terminated.\n", pid);
    } else {
        printf("Failed to terminate process %d: %s\n", pid, strerror(errno));
    }
}

int main() {
    int choice;
    int pid;
    char path[MAX_PATH_LENGTH];

    while (1) {
        printf("\n*** System Administration Menu ***\n");
        printf("1. Check Disk Usage\n");
        printf("2. List Running Processes\n");
        printf("3. Kill a Process\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the path to check disk usage (default is /): ");
                scanf("%s", path);
                check_disk_usage(strlen(path) > 0 ? path : "/");
                break;

            case 2:
                list_processes();
                break;

            case 3:
                printf("Enter the PID of the process to kill: ");
                if (scanf("%d", &pid) != 1) {
                    printf("Invalid PID.\n");
                    while(getchar() != '\n'); // Clear input buffer
                    break;
                }
                kill_process(pid);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please enter again.\n");
                break;
        }
    }
    
    return 0;
}