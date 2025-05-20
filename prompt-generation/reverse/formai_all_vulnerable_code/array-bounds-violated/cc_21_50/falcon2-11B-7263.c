//Falcon2-11B DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

typedef struct {
    int pid;
    char name[256];
    int status;
} Process;

typedef struct {
    char path[256];
    int permissions;
    int owner_uid;
    int group_gid;
    int num_files;
} File;

typedef struct {
    char filename[256];
    char log_level[256];
} Log;

int main() {
    // Initialize processes
    Process processes[10];
    int num_processes = 0;

    // Initialize files
    File files[10];
    int num_files = 0;

    // Initialize logs
    Log logs[10];
    int num_logs = 0;

    while (1) {
        char command[256];
        printf("sysadmin > ");
        fgets(command, sizeof(command), stdin);

        // Process command
        int command_len = strlen(command);
        if (command[command_len - 1] == '\n') {
            command[command_len - 1] = '\0';
        }

        // Execute command
        if (strncmp(command, "process", command_len) == 0) {
            if (processes[num_processes].pid!= 0) {
                printf("Error: Process already running\n");
            } else {
                strcpy(processes[num_processes].name, command + strlen("process"));
                int status = fork();
                if (status == 0) {
                    // Child process
                    printf("Child process started with PID %d\n", getpid());
                    // Do child process tasks
                    exit(0);
                } else if (status > 0) {
                    // Parent process
                    processes[num_processes].pid = status;
                    processes[num_processes].status = 0;
                    num_processes++;
                } else {
                    printf("Error: Failed to start child process\n");
                }
            }
        } else if (strncmp(command, "file", command_len) == 0) {
            if (files[num_files].permissions!= 0) {
                printf("Error: File already exists\n");
            } else {
                strcpy(files[num_files].path, command + strlen("file"));
                struct stat file_info;
                int status = stat(files[num_files].path, &file_info);
                if (status == 0) {
                    files[num_files].permissions = file_info.st_mode & S_IRWXU;
                    files[num_files].owner_uid = file_info.st_uid;
                    files[num_files].group_gid = file_info.st_gid;
                    files[num_files].num_files = 0;
                    num_files++;
                } else {
                    printf("Error: Failed to stat file\n");
                }
            }
        } else if (strncmp(command, "log", command_len) == 0) {
            if (logs[num_logs].filename[0]!= '\0') {
                printf("Error: Log already exists\n");
            } else {
                strcpy(logs[num_logs].filename, command + strlen("log"));
                struct stat file_info;
                int status = stat(logs[num_logs].filename, &file_info);
                if (status == 0) {
                    logs[num_logs].log_level[0] = '\0';
                    num_logs++;
                } else {
                    printf("Error: Failed to stat log file\n");
                }
            }
        } else if (strncmp(command, "processes", command_len) == 0) {
            if (num_processes == 0) {
                printf("No processes running\n");
            } else {
                for (int i = 0; i < num_processes; i++) {
                    printf("PID: %d, Name: %s, Status: %d\n",
                            processes[i].pid, processes[i].name, processes[i].status);
                }
            }
        } else if (strncmp(command, "files", command_len) == 0) {
            if (num_files == 0) {
                printf("No files created\n");
            } else {
                for (int i = 0; i < num_files; i++) {
                    printf("Path: %s, Permissions: %d, Owner: %d, Group: %d, Num Files: %d\n",
                            files[i].path, files[i].permissions, files[i].owner_uid,
                            files[i].group_gid, files[i].num_files);
                }
            }
        } else if (strncmp(command, "logs", command_len) == 0) {
            if (num_logs == 0) {
                printf("No logs created\n");
            } else {
                for (int i = 0; i < num_logs; i++) {
                    printf("Filename: %s, Log Level: %s\n", logs[i].filename, logs[i].log_level);
                }
            }
        } else {
            printf("Unknown command\n");
        }
    }

    return 0;
}