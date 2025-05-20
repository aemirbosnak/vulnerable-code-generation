//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define CPU_TOTAL_FILE "/proc/stat"
#define CPU_PROCESS_FILE "/proc/self/stat"

typedef struct __cpu_stats {
    unsigned long long total_jiffies; /* total jiffies since boot time */
    unsigned long long total_proc_jiffies; /* total jiffies spent in process */
} cpu_stats_t;

static double get_cpu_usage(cpu_stats_t *prev, cpu_stats_t *curr, unsigned int num_cpus)
{
    unsigned long long total_delta = curr->total_jiffies - prev->total_jiffies;
    unsigned long long work_delta = curr->total_proc_jiffies - prev->total_proc_jiffies;

    return work_delta * 1.0 / total_delta / num_cpus * 100;
}

static int read_cpu_stats(FILE *fp, cpu_stats_t *stats)
{
    int ret = 0;

    if (fscanf(fp, "%*s %llu %llu %llu %llu %llu %llu %llu",
               &stats->total_jiffies, &stats->total_jiffies, &stats->total_jiffies, &stats->total_jiffies,
               &stats->total_jiffies, &stats->total_jiffies, &stats->total_jiffies) > 0)
        ret = 1;

    return ret;
}

int main(void)
{
    cpu_stats_t prev, curr;
    double cpu_usage;
    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    FILE *fp_total, *fp_process;

    while (1) {
        /* Open CPU total file for reading */
        if ((fp_total = fopen(CPU_TOTAL_FILE, "r")) == NULL) {
            printf("Unable to open %s\n", CPU_TOTAL_FILE);
            exit(EXIT_FAILURE);
        }

        /* Read total CPU stats */
        if (!read_cpu_stats(fp_total, &curr)) {
            printf("Unable to read %s\n", CPU_TOTAL_FILE);
            fclose(fp_total);
            exit(EXIT_FAILURE);
        }

        fclose(fp_total);

        /* Open CPU process file for reading */
        if ((fp_process = fopen(CPU_PROCESS_FILE, "r")) == NULL) {
            printf("Unable to open %s\n", CPU_PROCESS_FILE);
            exit(EXIT_FAILURE);
        }

        /* Read process CPU stats */
        if (!read_cpu_stats(fp_process, &prev)) {
            printf("Unable to read %s\n", CPU_PROCESS_FILE);
            fclose(fp_process);
            exit(EXIT_FAILURE);
        }

        fclose(fp_process);

        /* Calculate CPU usage */
        cpu_usage = get_cpu_usage(&prev, &curr, num_cpus);

        printf("CPU usage: %.2f%%\n", cpu_usage);

        /* Sleep for 1 second */
        sleep(1);
    }

    return 0;
}