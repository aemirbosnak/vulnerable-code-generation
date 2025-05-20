//MISTRAL-7B DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sysinfo.h>

#define CPU_FILE "/proc/stat"
#define BUF_SIZE 128

void get_cpu_usage(void) {
    struct stat old_stat, new_stat;
    char cpu_stat[BUF_SIZE];
    long int idle_prev, total_prev, idle_cur, total_cur, usage;

    if (stat(CPU_FILE, &old_stat) != 0) {
        fprintf(stderr, "Error reading old cpu stats\n");
        exit(EXIT_FAILURE);
    }

    if (stat(CPU_FILE, &new_stat) != 0) {
        fprintf(stderr, "Error reading new cpu stats\n");
        exit(EXIT_FAILURE);
    }

    if (new_stat.st_size < BUF_SIZE) {
        if (read(open(CPU_FILE, O_RDONLY), BUF_SIZE, BUF_SIZE) < 0) {
            perror("Error reading cpu stats\n");
            exit(EXIT_FAILURE);
        }
    }

    sscanf(cpu_stat, "%*s %ld %ld", &idle_prev, &total_prev);
    memset(cpu_stat, '\0', BUF_SIZE);

    while (read(open(CPU_FILE, O_RDONLY), &cpu_stat[0], 1) > 0) {
        if (strcmp(cpu_stat, "cpu") == 0) {
            sscanf(cpu_stat + 4, "%ld %ld", &idle_cur, &total_cur);
            break;
        }
    }

    usage = ((total_cur - total_prev) - (idle_cur - idle_prev)) * 100 / (total_cur - total_prev);

    printf("CPU usage: %.2f%%\n", usage);
}

int main(void) {
    struct sysinfo info;
    int cpu_count;

    if (sysconf(_SC_NPROCESSORS_CONF) < 0) {
        perror("Error getting number of processors\n");
        exit(EXIT_FAILURE);
    }

    cpu_count = sysconf(_SC_NPROCESSORS_CONF);

    if (sysinfo(&info) < 0) {
        perror("Error getting system info\n");
        exit(EXIT_FAILURE);
    }

    printf("Total memory: %ld bytes\n", (long int) info.totalram);
    printf("Free memory: %ld bytes\n", (long int) info.freeram);

    while (cpu_count--) {
        get_cpu_usage();
        sleep(1);
    }

    return EXIT_SUCCESS;
}