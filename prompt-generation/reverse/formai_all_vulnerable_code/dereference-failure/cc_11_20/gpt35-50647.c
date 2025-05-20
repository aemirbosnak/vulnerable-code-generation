//FormAI DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define BUFFER_SIZE 512

int main() {
    DIR* proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    struct dirent* entry;
    int pid;
    char stat_path[BUFFER_SIZE], stat_buffer[BUFFER_SIZE], comm[BUFFER_SIZE];
    int utime, stime;

    printf("%-10s %-20s %-20s %-10s %-10s\n", "PID", "COMMAND", "USER", "UTIME", "STIME");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_type != DT_DIR) {
            continue;
        }

        pid = atoi(entry->d_name);
        if (pid == 0) {
            continue;
        }

        sprintf(stat_path, "/proc/%d/stat", pid);
        FILE* stat_file = fopen(stat_path, "r");
        if (!stat_file) {
            continue;
        }

        fgets(stat_buffer, BUFFER_SIZE, stat_file);
        fclose(stat_file);

        sscanf(stat_buffer, "%d %s", &pid, comm);
        strtok(comm, ")");
        strtok(NULL, "(");
        char* command = strtok(NULL, ")");

        sprintf(stat_path, "/proc/%d/status", pid);
        FILE* status_file = fopen(stat_path, "r");
        if (!status_file) {
            continue;
        }

        char line[BUFFER_SIZE];
        char user[BUFFER_SIZE];
        while (fgets(line, BUFFER_SIZE, status_file)) {
            if (strncmp(line, "Uid:", 4) == 0) {
                int uid;
                sscanf(line, "Uid:\t%d", &uid);
                sprintf(stat_path, "/proc/%d/cmdline", pid);
                FILE* cmdline_file = fopen(stat_path, "r");         

                fgets(comm, BUFFER_SIZE, cmdline_file);
                fclose(cmdline_file);

                sprintf(stat_path, "/etc/passwd");
                FILE* passwd_file = fopen(stat_path, "r");         

                char passwd_line[BUFFER_SIZE];
                while (fgets(passwd_line, BUFFER_SIZE, passwd_file)) {
                    sscanf(passwd_line, "%[^:]:x:%d", user, &uid);
                    if (uid == uid) {
                        break;
                    }
                }

                fclose(passwd_file);
                break;
            }
        }

        sprintf(stat_path, "/proc/%d/stat", pid);
        stat_file = fopen(stat_path, "r");
        fgets(stat_buffer, BUFFER_SIZE, stat_file);
        fclose(stat_file);

        sscanf(stat_buffer, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %d %d", &utime, &stime);

        printf("%-10d %-20s %-20s %-10d %-10d\n", pid, command, user, utime, stime);
    }

    closedir(proc_dir);
    return 0;
}