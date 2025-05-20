//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PATH_LEN 128
#define MAX_PID_LEN 16

typedef enum {false, true} bool;

int main(int argc, char *argv[]) {
    DIR *proc_dir;
    int pid_len = MAX_PID_LEN, path_len = MAX_PATH_LEN;
    char pid_buff[MAX_PID_LEN], path_buff[MAX_PATH_LEN];
    struct dirent *proc_entry;
    int pid;
    char status_path[MAX_PATH_LEN];
    FILE *status_fp;
    char line_buff[MAX_PATH_LEN];
    char *name, *ppid_str, *rss_str, *vms_str;
    int ppid, rss, vms;
    char *endptr;
    bool is_number;
    int selection;
    char c;

    printf("C System Process Viewer\n");
    printf("Select a mode:\n");
    printf("1. View all processes\n");
    printf("2. View specific process by PID\n");
    printf("> ");
    scanf("%d", &selection);
    if (selection == 2) {
        printf("Enter PID: ");
        scanf("%d", &pid);
        sprintf(status_path, "/proc/%d/status", pid);
        status_fp = fopen(status_path, "r");
        if (status_fp == NULL) {
            perror("Failed to open status file");
            return EXIT_FAILURE;
        }
        printf("PID\tName\tPPID\tRSS\tVMS\n");
        while (fgets(line_buff, MAX_PATH_LEN, status_fp) != NULL) {
            if (strncmp(line_buff, "Name:", 5) == 0) {
                name = line_buff + 6;
                printf("%d\t%s", pid, name);
            } else if(strncmp(line_buff, "PPid:", 5) == 0) {
                ppid_str = line_buff + 6;
                ppid = strtol(ppid_str, &endptr, 10);
                printf("\t%d", ppid);
            } else if(strncmp(line_buff, "VmRSS:", 6) == 0) {
                rss_str = line_buff + 7;
                rss = strtol(rss_str, &endptr, 10);
                printf("\t%d", rss);
            } else if(strncmp(line_buff, "VmSize:", 7) == 0) {
                vms_str = line_buff + 8;
                vms = strtol(vms_str, &endptr, 10);
                printf("\t%d\n", vms);
            }
        }
    } else if (selection == 1) {
        printf("PID\tName\tPPID\tRSS\tVMS\n");
        proc_dir = opendir("/proc");
        while ((proc_entry = readdir(proc_dir)) != NULL) {
            pid_len = strlen(proc_entry->d_name);
            is_number = true;
            for (int i = 0; i < pid_len; i++) {
                if (!isdigit(proc_entry->d_name[i])) {
                    is_number = false;
                    break;
                }
            }
            if (is_number) {
                pid = strtol(proc_entry->d_name, &endptr, 10);
                if (pid != getpid() && strcmp(proc_entry->d_name, "1") != 0) {
                    sprintf(status_path, "/proc/%d/status", pid);
                    status_fp = fopen(status_path, "r");
                    if (status_fp == NULL) {
                        perror("Failed to open status file");
                        return EXIT_FAILURE;
                    }
                    while (fgets(line_buff, MAX_PATH_LEN, status_fp) != NULL) {
                        if (strncmp(line_buff, "Name:", 5) == 0) {
                            name = line_buff + 6;
                            printf("%d\t%s", pid, name);
                        } else if(strncmp(line_buff, "PPid:", 5) == 0) {
                            ppid_str = line_buff + 6;
                            ppid = strtol(ppid_str, &endptr, 10);
                            printf("\t%d", ppid);
                        } else if(strncmp(line_buff, "VmRSS:", 6) == 0) {
                            rss_str = line_buff + 7;
                            rss = strtol(rss_str, &endptr, 10);
                            printf("\t%d", rss);
                        } else if(strncmp(line_buff, "VmSize:", 7) == 0) {
                            vms_str = line_buff + 8;
                            vms = strtol(vms_str, &endptr, 10);
                            printf("\t%d\n", vms);
                        }
                    }
                    fclose(status_fp);
                }
            }
        }
        closedir(proc_dir);
    } else {
        printf("Invalid selection. Exiting.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}