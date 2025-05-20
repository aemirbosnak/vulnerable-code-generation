//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

typedef struct ProcessDetails {
    char pid[MAX_SIZE];
    char pname[MAX_SIZE];
    char pcpu[MAX_SIZE];
} ProcessDetails;

ProcessDetails* createProcessDetails() {
    ProcessDetails* pd = (ProcessDetails*) malloc(sizeof(ProcessDetails));
    sprintf(pd->pid, "%d", getpid());
    sprintf(pd->pname, "%s", "CPU Monitor");
    return pd;
}

void print_usage(ProcessDetails* pd) {
    FILE* fp;
    char pid[MAX_SIZE];
    char pname[MAX_SIZE];
    char pcpu[MAX_SIZE];
    fp = fopen("/proc/stat", "r");
    int total_cpu_time_1 = 0;
    int idle_cpu_time_1 = 0;
    int total_cpu_time_2 = 0;
    int idle_cpu_time_2 = 0;
    if (fp != NULL) {
        char buffer[MAX_SIZE];
        fgets(buffer, MAX_SIZE, fp);
        sscanf(buffer, "%*s %d %d %d %d %d %d %d", &total_cpu_time_1, &idle_cpu_time_1, &total_cpu_time_1, &total_cpu_time_1, &total_cpu_time_1, &total_cpu_time_1, &total_cpu_time_1);
    }
    fclose(fp);
    sleep(1);
    fp = fopen("/proc/stat", "r");
    if (fp != NULL) {
        char buffer[MAX_SIZE];
        fgets(buffer, MAX_SIZE, fp);
        sscanf(buffer, "%*s %d %d %d %d %d %d %d", &total_cpu_time_2, &idle_cpu_time_2, &total_cpu_time_2, &total_cpu_time_2, &total_cpu_time_2, &total_cpu_time_2, &total_cpu_time_2);
    }
    fclose(fp);
    float cpu_usage = 100.0 * (1.0 - ((float)(idle_cpu_time_2 - idle_cpu_time_1)) / ((float)(total_cpu_time_2 - total_cpu_time_1)));
    sprintf(pd->pcpu, "%.2f", cpu_usage);
    printf("%s - PID: %s, CPU Usage: %s%%\n", pd->pname, pd->pid, pd->pcpu);
}

int main() {
    ProcessDetails* pd = createProcessDetails();
    while(1) {
        print_usage(pd);
    }
    free(pd);
    return 0;
}