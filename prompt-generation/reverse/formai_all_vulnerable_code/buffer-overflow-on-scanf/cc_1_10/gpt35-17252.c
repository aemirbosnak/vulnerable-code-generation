//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 64

int main() {
    int pid;
    int mem_percentage;
    char command[MAX_BUFF_SIZE];

    printf("Enter the process ID to monitor memory usage:\n");
    scanf("%d", &pid);
    sprintf(command, "pmap %d | tail -n 1 | awk '{print $2}'", pid);

    while (1) {
        FILE* fp;
        char buffer[MAX_BUFF_SIZE];
        int total_mem, used_mem;

        fp = popen(command, "r");
        if (fp == NULL) {
            printf("Error: Failed to execute command.\n");
            exit(-1);
        }

        fgets(buffer, MAX_BUFF_SIZE, fp);
        total_mem = atoi(buffer);
        pclose(fp);

        fp = popen("free | grep Mem | awk '{print $2}'", "r");
        if (fp == NULL) {
            printf("Error: Failed to execute command.\n");
            exit(-1);
        }

        fgets(buffer, MAX_BUFF_SIZE, fp);
        used_mem = atoi(buffer);
        pclose(fp);

        mem_percentage = (used_mem / (float) total_mem) * 100;

        printf("Process ID: %d, Memory Usage: %d%%\n", pid, mem_percentage);

        sleep(5);
    }

    return 0;
}