//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define ADA_DEBUG 0
#define CPU_USAGE_INTERVAL 5 // seconds
#define CPU_USAGE_HISTORY_SIZE 10

typedef struct {
    time_t timestamp;
    double cpu_usage;
} cpu_usage_record_t;

cpu_usage_record_t cpu_usage_history[CPU_USAGE_HISTORY_SIZE];
int cpu_usage_history_index = 0;

void get_cpu_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    double cpu_usage = (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) + (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000.0;
    cpu_usage_history[cpu_usage_history_index] = (cpu_usage_record_t) { time(NULL), cpu_usage };
    cpu_usage_history_index = (cpu_usage_history_index + 1) % CPU_USAGE_HISTORY_SIZE;
}

void print_cpu_usage() {
    int i;
    printf("+------------------------+------------+\n");
    printf("| Timestamp              | CPU Usage   |\n");
    printf("+------------------------+------------+\n");
    for (i = 0; i < CPU_USAGE_HISTORY_SIZE; i++) {
        printf("| %.24s | %.2f %%  |\n", ctime(&(cpu_usage_history[i].timestamp)), cpu_usage_history[i].cpu_usage);
    }
    printf("+------------------------+------------+\n");
}

int main(int argc, char *argv[]) {
    #if ADA_DEBUG
    printf("+--------------------------------+\n");
    printf("| Ada Lovelace CPU Usage Monitor |\n");
    printf("+--------------------------------+\n\n");
    #endif
    while (1) {
        get_cpu_usage();
        print_cpu_usage();
        sleep(CPU_USAGE_INTERVAL);
    }
    return 0;
}