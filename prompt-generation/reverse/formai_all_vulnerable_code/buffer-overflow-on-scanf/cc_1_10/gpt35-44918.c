//FormAI DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID_LEN 6
#define MAX_BUFF_SIZE 512

int is_number(char *str) {
    // Function to check if a string is a number
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void view_process_info(char *pid) {
    // Function to display information of a process with provided PID
    char proc_file_path[MAX_BUFF_SIZE];
    sprintf(proc_file_path, "/proc/%s/status", pid);

    FILE *fp = fopen(proc_file_path, "r");
    if (fp != NULL) {
        char buffer[MAX_BUFF_SIZE];
        while (fgets(buffer, MAX_BUFF_SIZE, fp)) {
            printf("%s", buffer);
        }
        fclose(fp);
    } else {
        printf("Process with PID %s does not exist\n", pid);
    }
}

void display_processes() {
    // Function to display list of active processes
    printf("%-8s %-30s %-15s\n", "PID", "Name", "Status");
    DIR *d;
    struct dirent *dir;
    d = opendir("/proc/");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (is_number(dir->d_name)) {
                char proc_file_path[MAX_BUFF_SIZE];
                sprintf(proc_file_path, "/proc/%s/stat", dir->d_name);

                FILE *fp = fopen(proc_file_path, "r");
                if (fp != NULL) {
                    char buffer[MAX_BUFF_SIZE];
                    if (fgets(buffer, MAX_BUFF_SIZE, fp)) {
                        char *name_start = strchr(buffer, '(');
                        char *name_end = strchr(buffer, ')');
                        if (name_start && name_end) {
                            char *status = strrchr(buffer, ')');
                            int pid_len = strlen(dir->d_name);
                            printf("%-8s %-30.*s %-15s\n", dir->d_name, name_end - name_start - 1, name_start + 1, status + 2);
                        }
                    }
                    fclose(fp);
                }
            }
        }
        closedir(d);
    } else {
        printf("Error opening directory /proc/\n");
    }
}

int main() {
    int choice;
    char pid[MAX_PID_LEN];
    do {
        printf("\n");
        printf("*** Process Viewer ***\n");
        printf("1. View Active Processes\n");
        printf("2. View Process Info\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_processes();
                break;
            case 2:
                printf("Enter PID of process to view info: ");
                scanf("%s", pid);
                view_process_info(pid);
                break;
            case 3:
                printf("Exiting Process Viewer\n");
                break;
            default:
                printf("Invalid choice. Please try again\n");
        }
    } while (choice != 3);

    return 0;
}