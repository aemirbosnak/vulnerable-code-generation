//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>

typedef struct _cpu_usage_t {
    FILE *fd;
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
    unsigned long long guest;
    unsigned long long guest_nice;
} cpu_usage_t;

cpu_usage_t *cpu_usage_init(const char *filename)
{
    cpu_usage_t *cpu;

    cpu = malloc(sizeof(cpu_usage_t));
    if (!cpu) {
        return NULL;
    }

    cpu->fd = fopen(filename, "r");
    if (!cpu->fd) {
        free(cpu);
        return NULL;
    }

    return cpu;
}

void cpu_usage_fini(cpu_usage_t *cpu)
{
    fclose(cpu->fd);
    free(cpu);
}

int cpu_usage_get(cpu_usage_t *cpu)
{
    char buf[1024];
    int ret;

    fseek(cpu->fd, 0, SEEK_SET);
    ret = fread(buf, 1, sizeof(buf), cpu->fd);
    if (ret < 0) {
        return -1;
    }

    sscanf(buf, "cpu  %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
           &cpu->user, &cpu->nice, &cpu->system, &cpu->idle, &cpu->iowait,
           &cpu->irq, &cpu->softirq, &cpu->steal, &cpu->guest, &cpu->guest_nice);

    return 0;
}

int cpu_usage_print(cpu_usage_t *cpu)
{
    printf("user: %llu\n", cpu->user);
    printf("nice: %llu\n", cpu->nice);
    printf("system: %llu\n", cpu->system);
    printf("idle: %llu\n", cpu->idle);
    printf("iowait: %llu\n", cpu->iowait);
    printf("irq: %llu\n", cpu->irq);
    printf("softirq: %llu\n", cpu->softirq);
    printf("steal: %llu\n", cpu->steal);
    printf("guest: %llu\n", cpu->guest);
    printf("guest_nice: %llu\n", cpu->guest_nice);

    return 0;
}

int main(void)
{
    cpu_usage_t *cpu;

    cpu = cpu_usage_init("/proc/stat");
    if (!cpu) {
        return -1;
    }

    while (1) {
        if (cpu_usage_get(cpu) < 0) {
            break;
        }

        cpu_usage_print(cpu);

        sleep(1);
    }

    cpu_usage_fini(cpu);

    return 0;
}