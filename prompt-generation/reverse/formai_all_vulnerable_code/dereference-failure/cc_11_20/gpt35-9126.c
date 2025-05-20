//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID_LEN 6
#define MAX_CMDLINE_LEN 1024

int main(){
    DIR *dp;
    struct dirent *entry;
    char pid[MAX_PID_LEN], cmdline[MAX_CMDLINE_LEN], state;
    int uid, ppid, vm_size;
    long int utime, stime;
    float cpu_usage;
    float total_cpu_time_1 = 0, total_cpu_time_2 = 0;
    char *endptr;
    char *subdir = "/proc/";

    dp = opendir(subdir);
    if (dp == NULL) {
        perror("Unable to open /proc directory!\n");
        return 1;
    }

    printf("%-6s %-10s %-10s %-6s %-8s %-8s %-8s\n", "PID", "USER", "STATE", "PPID", "VM SIZE", "CPU TIME", "CMDLINE");

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            if (!isdigit(entry->d_name[0])) continue;
            strncpy(pid, entry->d_name, MAX_PID_LEN);
            pid[MAX_PID_LEN - 1] = '\0';

            sprintf(cmdline, "%s%s/stat", subdir, pid);
            FILE *fp = fopen(cmdline, "r");
            if (fp == NULL) {
                printf("Unable to open stat file for PID=%s\n", pid);
                continue;
            }

            fscanf(fp, "%*s %*s %c %*d %*d %*d %*d %*d %*u %*u %*u %*u %ld %ld %ld %ld", &state, &utime, &stime, &ppid);
            fclose(fp);

            sprintf(cmdline, "%s%s/status", subdir, pid);
            fp = fopen(cmdline, "r");
            if (fp == NULL) {
                printf("Unable to open status file for PID=%s\n", pid);
                continue;
            }

            char line[256];
            while (fgets(line, sizeof(line), fp)) {
                if (strncmp(line, "Uid:", 4) == 0) {
                    uid = strtol(line + 4, &endptr, 10);
                    if (endptr == (line + 4)) {
                        printf("Unable to parse UID for PID=%s\n", pid);
                        continue;
                    }

                    // ignore other UIDs
                    if (uid != getuid()) break;
                }
                if (strncmp(line, "VmSize:", 7) == 0) {
                    vm_size = strtol(line + 7, &endptr, 10);
                    if (endptr == (line + 7)) {
                        printf("Unable to parse VmSize for PID=%s\n", pid);
                        continue;
                    }
                }
            }
            fclose(fp);

            // calculate total CPU time across all processes
            total_cpu_time_1 += (float)(utime + stime);

            sprintf(cmdline, "%s%s/cmdline", subdir, pid);
            fp = fopen(cmdline, "r");
            if (fp == NULL) {
                printf("Unable to open cmdline file for PID=%s\n", pid);
                continue;
            }

            fgets(cmdline, MAX_CMDLINE_LEN, fp);
            fclose(fp);

            // calculate CPU usage
            cpu_usage = (float)(utime + stime) / (float)total_cpu_time_1;

            // print process details
            printf("%-6s %-10d %-10c %-6d %-8d %-8.2f %s\n",
                    pid, uid, state, ppid, vm_size, cpu_usage, cmdline);
        }
    }

    closedir(dp);

    return 0;
}