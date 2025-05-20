//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define MAX_FIELD_LENGTH 20
#define MAX_PROC_NAME_LENGTH 256

typedef struct proc_info {
    int pid;
    char name[MAX_PROC_NAME_LENGTH];
    int rss;
} proc_info;

void tokenize_pid_name(char* line, char* pid, char* name) {
    char* tok = strtok(line, " ");
    while (tok != NULL) {
        if (*tok == '[' || *tok == '(') {
            int len = strlen(tok) - 2;
            strncpy(pid, &tok[1], len);
            pid[len] = '\0';
        }
        else {
            strncpy(name, tok, MAX_PROC_NAME_LENGTH);
            name[MAX_PROC_NAME_LENGTH - 1] = '\0';
        }
        tok = strtok(NULL, " ");
    }
}


int main() {
    // Keep track of the process with the highest rss
    int max_rss = -1;
    char max_rss_name[MAX_PROC_NAME_LENGTH];

    while (1) {
        FILE* file = fopen("/proc/meminfo", "r");
        if (file == NULL) {
            fprintf(stderr, "Error: File cannot be opened");
            exit(1);
        }

        char line[MAX_LINE_LENGTH];
        char total_mem[MAX_FIELD_LENGTH];
        char free_mem[MAX_FIELD_LENGTH];
        char available_mem[MAX_FIELD_LENGTH];

        // Get the total, free and available memory
        fgets(line, MAX_LINE_LENGTH, file);
        sscanf(line, "MemTotal: %s kB", total_mem);
        fgets(line, MAX_LINE_LENGTH, file);
        sscanf(line, "MemFree: %s kB", free_mem);
        fgets(line, MAX_LINE_LENGTH, file);
        sscanf(line, "MemAvailable: %s kB", available_mem);

        fclose(file);

        printf("Total Memory: %s kB\n", total_mem);
        printf("Free Memory: %s kB\n", free_mem);
        printf("Available Memory: %s kB\n", available_mem);

        // Get the process with the highest rss
        file = fopen("/proc/meminfo", "r");
        if (file == NULL) {
            fprintf(stderr, "Error: File cannot be opened");
            exit(1);
        }

        proc_info max_rss_proc = { 0, "", -1 };

        while (fgets(line, MAX_LINE_LENGTH, file)) {
            if (strncmp(line, "Pid:", 4) == 0) {
                char pid[MAX_FIELD_LENGTH];
                strncpy(pid, &line[5], MAX_FIELD_LENGTH - 1);
                pid[MAX_FIELD_LENGTH - 1] = '\0';

                // Get process name from the /proc/<pid>/status file
                char cmd[MAX_LINE_LENGTH];
                snprintf(cmd, MAX_LINE_LENGTH, "/bin/cat /proc/%s/status", pid);
                FILE* proc_file = popen(cmd, "r");
                if (proc_file == NULL) {
                    fprintf(stderr, "Error: File cannot be opened");
                    exit(1);
                }

                char name[MAX_PROC_NAME_LENGTH] = "";
                while (fgets(line, MAX_LINE_LENGTH, proc_file)) {
                    if (strncmp(line, "Name:", 5) == 0) {
                        tokenize_pid_name(line, pid, name);
                        break;
                    }
                }

                // Get RSS value from the /proc/<pid>/status file
                snprintf(cmd, MAX_LINE_LENGTH, "/bin/cat /proc/%s/status | grep RSS | awk '{print $2}'", pid);
                proc_file = popen(cmd, "r");
                if (proc_file == NULL) {
                    fprintf(stderr, "Error: File cannot be opened");
                    exit(1);
                }

                char rss_str[MAX_FIELD_LENGTH];
                fgets(rss_str, MAX_FIELD_LENGTH, proc_file);
                int rss = atoi(rss_str);

                proc_info proc = { atoi(pid), name, rss };

                if (proc.rss > max_rss_proc.rss) {
                    max_rss_proc = proc;
                }

                pclose(proc_file);
            }
        }

        fclose(file);

        if (max_rss_proc.rss > max_rss) {
            max_rss = max_rss_proc.rss;
            strncpy(max_rss_name, max_rss_proc.name, MAX_PROC_NAME_LENGTH);
            max_rss_name[MAX_PROC_NAME_LENGTH - 1] = '\0';
        }

        printf("Process with highest RSS: %d (%s) - %d kB\n\n", max_rss_proc.pid, max_rss_proc.name, max_rss_proc.rss);

        sleep(5);
    }

    return 0;
}