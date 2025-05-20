//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 256

bool check_pid(char* pid_str) {
    int i;
    for (i = 0; i < strlen(pid_str); i++) {
        if (!isdigit(pid_str[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    long pid = getpid();
    char* pid_str;
    if (argc > 1) {
        pid_str = argv[1];
        if (check_pid(pid_str)) {
            pid = strtol(pid_str, NULL, 10);
        } else {
            fprintf(stderr, "Invalid PID: %s\n", pid_str);
            return 1;
        }
    }
    
    struct sysinfo sys_info;
    if (sysinfo(&sys_info) != 0) {
        fprintf(stderr, "Error getting system information.\n");
        return 1;
    }
    
    printf("PID\tMemory Usage\n");
    printf("=========================\n");

    char command[BUFFER_SIZE];
    sprintf(command, "cat /proc/%ld/status | grep VmSize | awk '{print $2}'", pid);

    char buffer[BUFFER_SIZE];
    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error executing command: %s\n", command);
        return 1;
    }
    fgets(buffer, BUFFER_SIZE, fp);
    pclose(fp);
    
    long mem_usage_kb = atol(buffer);
    printf("%ld\t%ld KiB\n", pid, mem_usage_kb);

    return 0;
}