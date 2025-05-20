//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_VALUE 1024

// function to check if a given process is running or not
bool isProcessRunning(pid_t pid) {
    char cmd[MAX_VALUE];
    sprintf(cmd, "ps -p %ld | tail -n +2 | awk '{print $1}'", (long)pid);
    FILE* fp = popen(cmd, "r");
    if (fp == NULL) {
        return false;
    }
    char buf[MAX_VALUE];
    if (fgets(buf, MAX_VALUE, fp) == NULL) {
        pclose(fp);
        return false;
    }
    long int process_id = atol(buf);
    if (process_id == pid) {
        pclose(fp);
        return true;
    }
    pclose(fp);
    return false;
}

int main() {
    pid_t pid;
    printf("Enter process ID to monitor: ");
    scanf("%d", &pid);
    while (true) {
        struct sysinfo info;
        if (sysinfo(&info) != 0) {
            printf("Error occurred!\n");
            continue;
        }
        int total_ram = info.totalram / (1024 * 1024);
        int used_ram = (info.totalram - info.freeram) / (1024 * 1024);
        bool process_running = isProcessRunning(pid);
        printf("Total RAM: %d MB\n", total_ram);
        printf("Used RAM: %d MB\n", used_ram);
        if (process_running) {
            long int resident_set_size = 0;
            char path[MAX_VALUE];
            sprintf(path, "/proc/%ld/statm", (long)pid);
            FILE* fp = fopen(path, "r");
            if (fp != NULL) {
                fscanf(fp, "%ld", &resident_set_size);
                fclose(fp);
            }
            printf("Process with PID %d is running.\n", pid);
            printf("Resident set size: %ld KB\n", resident_set_size * sysconf(_SC_PAGESIZE) / 1024);
        } else {
            printf("Process with PID %d is not running.\n", pid);
        }
        printf("--------------------------------\n");
        sleep(10);
    }
    return 0;
}