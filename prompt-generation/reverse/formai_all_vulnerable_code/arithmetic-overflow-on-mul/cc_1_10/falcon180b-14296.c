//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#define TOTAL_CPU_NUM 4

int get_cpu_usage(int cpu_num) {
    FILE *file;
    char filename[20];
    int usage;

    sprintf(filename, "/proc/stat");
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    fseek(file, (cpu_num * 4), SEEK_SET);
    fscanf(file, "%d", &usage);
    fclose(file);

    return usage;
}

int get_total_cpu_usage() {
    int i, total_usage = 0;

    for (i = 0; i < TOTAL_CPU_NUM; i++) {
        total_usage += get_cpu_usage(i);
    }

    return total_usage;
}

int main() {
    int total_cpu_usage, idle_cpu_usage, system_cpu_usage, user_cpu_usage;
    struct rusage usage;

    getrusage(RUSAGE_SELF, &usage);
    idle_cpu_usage = 100 - (usage.ru_idrss + usage.ru_isrss) * 100 / (double)TOTAL_CPU_NUM;

    total_cpu_usage = get_total_cpu_usage();
    system_cpu_usage = total_cpu_usage - idle_cpu_usage;
    user_cpu_usage = idle_cpu_usage;

    printf("System CPU Usage: %d%%\n", system_cpu_usage);
    printf("User CPU Usage: %d%%\n", user_cpu_usage);

    return 0;
}