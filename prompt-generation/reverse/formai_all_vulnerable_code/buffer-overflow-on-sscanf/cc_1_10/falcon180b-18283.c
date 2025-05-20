//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PROCESSOR_COUNT 1
#define PROCESSOR_NAME "processor"
#define TOTAL_MEMORY (1024 * 1024) // 1 MB
#define PROCESS_NAME "postapoc"

typedef struct process_info {
    char name[100];
    int pid;
    int cpu_usage;
    int memory_usage;
} ProcessInfo;

void get_cpu_usage(ProcessInfo* process) {
    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        printf("Error: Failed to open /proc/stat\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            sscanf(line, "cpu %d %d %d %d", &process->cpu_usage, &process->cpu_usage, &process->cpu_usage, &process->cpu_usage);
            break;
        }
    }

    fclose(file);
}

void get_memory_usage(ProcessInfo* process) {
    char filename[50];
    sprintf(filename, "/proc/%d/statm", process->pid);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Failed to open %s\n", filename);
        exit(1);
    }

    int size;
    fscanf(file, "%d", &size);
    process->memory_usage = size * (TOTAL_MEMORY / 4096);

    fclose(file);
}

int main() {
    ProcessInfo info;
    info.pid = getpid();
    strcpy(info.name, PROCESS_NAME);

    get_cpu_usage(&info);
    get_memory_usage(&info);

    printf("Process Name: %s\n", info.name);
    printf("PID: %d\n", info.pid);
    printf("CPU Usage: %d%%\n", info.cpu_usage);
    printf("Memory Usage: %d MB\n", info.memory_usage);

    return 0;
}