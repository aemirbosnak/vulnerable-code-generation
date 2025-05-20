//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESS 10
#define MAX_COMMAND 50

typedef struct {
    int pid;
    char command[MAX_COMMAND];
    float cpu_usage;
} ProcessInfo;

int main() {
    ProcessInfo processes[MAX_PROCESS];
    int process_count = 0;
    FILE *fp;
    char path[MAX_COMMAND];
    char buffer[MAX_COMMAND];
    int i, j;

    while(1) {
        for(i = 0; i < process_count; i++) {
            sprintf(path, "/proc/%d/stat", processes[i].pid);
            fp = fopen(path, "r");
            if(fp == NULL) {
                printf("Error: Cannot open file for process %d", processes[i].pid);
                process_count--;
                for(j = i; j < process_count; j++) {
                    processes[j] = processes[j + 1];
                }
                i--;
                continue;
            }
            fgets(buffer, MAX_COMMAND, fp);
            fclose(fp);

            char *token = strtok(buffer, " ");
            int count = 0;
            while(token != NULL) {
                count++;
                if(count == 14) {
                    float utime = atof(token);
                    token = strtok(NULL, " ");
                    float stime = atof(token);
                    token = strtok(NULL, " ");
                    float cutime = atof(token);
                    token = strtok(NULL, " ");
                    float cstime = atof(token);
                    token = strtok(NULL, " ");
                    float starttime = atof(token);
                    float total_time = utime + stime + cutime + cstime;
                    float uptime = atof(buffer + strlen(buffer) - 15);
                    float seconds = uptime - (starttime / sysconf(_SC_CLK_TCK));
                    processes[i].cpu_usage = 100 * ((total_time / sysconf(_SC_CLK_TCK)) / seconds);
                    break;
                }
                token = strtok(NULL, " ");
            }
        }

        fp = popen("ps -eo pid,comm", "r");
        if(fp == NULL) {
            printf("Error in popen");
            return 1;
        }

        int new_process_count = 0;
        while(fgets(buffer, MAX_COMMAND, fp)) {
            int pid;
            char command[MAX_COMMAND];
            sscanf(buffer, "%d %s", &pid, command);
            for(i = 0; i < process_count; i++) {
                if(processes[i].pid == pid) {
                    new_process_count++;
                    break;
                }
            }
            if(i == process_count) {
                ProcessInfo info;
                info.pid = pid;
                strcpy(info.command, command);
                info.cpu_usage = 0;
                processes[process_count] = info;
                new_process_count++;
                process_count++;
            }
        }
        pclose(fp);

        system("clear");
        printf("%-10s%-30s%-20s\n", "PID", "Command", "CPU Usage");
        for(i = 0; i < process_count; i++) {
            printf("%-10d%-30s%-20.2f\n", processes[i].pid, processes[i].command, processes[i].cpu_usage);
        }

        process_count = new_process_count;
        sleep(1);
    }

    return 0;
}