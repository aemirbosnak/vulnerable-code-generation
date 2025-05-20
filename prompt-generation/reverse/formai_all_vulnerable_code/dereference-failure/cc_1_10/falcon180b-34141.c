//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <fcntl.h>

#define MB (1024 * 1024)

typedef struct {
    char *name;
    unsigned long long size;
    unsigned long long used;
    float percent;
} Process;

void print_processes(Process *processes, int count) {
    printf("Process\t\tSize\tUsed\tPercent\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%llu MB\t%llu MB\t%.2f%%\n", processes[i].name, processes[i].size / MB, processes[i].used / MB, processes[i].percent);
    }
}

int main() {
    char command[100] = "ps -eo pid,%mem,comm --sort=-%mem | awk 'NR>2 {printf \"%.0f\t\", $1*100} {printf \"%s\", $NF}'";
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    Process processes[10];
    int count = 0;

    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error executing command\n");
        return 1;
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        if (count >= 10) {
            break;
        }
        processes[count].name = strdup(line);
        processes[count].size = atoll(line) * 1024;
        processes[count].used = processes[count].size;
        count++;
    }

    pclose(fp);

    for (int i = 0; i < count; i++) {
        unsigned long long total_memory = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
        processes[i].percent = (float) processes[i].used / total_memory * 100;
    }

    print_processes(processes, count);

    return 0;
}