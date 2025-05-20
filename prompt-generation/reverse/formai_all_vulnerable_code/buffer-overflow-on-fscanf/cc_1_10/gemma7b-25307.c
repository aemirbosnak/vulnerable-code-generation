//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define PROC_DIR "/proc"

typedef struct process_info {
    char name[256];
    int pid;
    int ppid;
    long memory_usage;
    long cpu_usage;
    char state;
} process_info;

process_info get_process_info(int pid) {
    process_info process;
    char buf[1024];
    FILE *file;

    snprintf(process.name, 256, "%s/%d/stat", PROC_DIR, pid);
    file = fopen(process.name, "r");
    fscanf(file, "%d %d %c %ld %ld", &process.pid, &process.ppid, &process.state, &process.memory_usage, &process.cpu_usage);
    fclose(file);

    return process;
}

int main() {
    system("clear");

    printf("------------------------------------------------------------------------\n");
    printf("  Process Viewer                                 \n");
    printf("------------------------------------------------------------------------\n");

    printf("PID\t\tName\t\tPPID\t\tMemory\t\tCPU Usage\t\tState\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < 10; i++) {
        process_info process = get_process_info(i);
        printf("%d\t\t%s\t\t%d\t\t%ld KB\t\t%ld%%\t\t%c\n", process.pid, process.name, process.ppid, process.memory_usage, process.cpu_usage, process.state);
    }

    printf("------------------------------------------------------------------------\n");

    return 0;
}