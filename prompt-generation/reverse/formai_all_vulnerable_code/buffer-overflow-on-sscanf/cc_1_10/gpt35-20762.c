//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define REFRESH_INTERVAL 1.0 /* Number of seconds between updates */
#define CPU_STATES 10 /* Number of CPU states tracked */

/* Define the format for printing out CPU state information */
#define FORMAT "  %9s %9s %9s %9s %9s %9s %9s %9s %9s %9s\n"

/* Print out the CPU state column headers */
void print_header() {
    printf("CPU States:");
    printf(FORMAT, "user", "nice", "system", "idle", "iowait", "irq", "softirq", "steal", "guest", "guest_nice");
}

/* Print out the current CPU state percentages */
void print_cpu_stats(unsigned long long int* cpu_stats, unsigned long long int* prev_cpu_stats, double elapsed_time) {
    unsigned long long int total_diff = 0, diff[CPU_STATES], usage[CPU_STATES];
    int i;

    /* Calculate the difference in CPU states between the current and previous statistics */
    for (i = 0; i < CPU_STATES; i++) {
        diff[i] = (cpu_stats[i] - prev_cpu_stats[i]);
        total_diff += diff[i];
    }

    /* Calculate and print out the CPU state usage percentages */
    for (i = 0; i < CPU_STATES; i++) {
        usage[i] = (100.0 * diff[i]) / total_diff;
    }

    printf("   %6.2f%% %6.2f%% %6.2f%% %6.2f%% %6.2f%% %6.2f%% %6.2f%% %6.2f%% %6.2f%% %6.2f%%\n",
           (double) usage[0] / 100.0, (double) usage[1] / 100.0, (double) usage[2] / 100.0,
           (double) usage[3] / 100.0, (double) usage[4] / 100.0, (double) usage[5] / 100.0,
           (double) usage[6] / 100.0, (double) usage[7] / 100.0, (double) usage[8] / 100.0,
           (double) usage[9] / 100.0);
}

/* Get the current CPU statistics */
void get_cpu_stats(unsigned long long int* cpu_stats) {
    FILE* fp;
    int i;
    char buffer[1024];
    unsigned long long int cpu_time[CPU_STATES];

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error: Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), fp);
    for (i = 0; i < CPU_STATES; i++) {
        sscanf(buffer + 5, "%llu", &cpu_time[i]);
        buffer[3] = '\0';
        while (buffer[5] != ' ') {
            buffer[5]++;
        }
    }

    fclose(fp);

    /* Calculate the total CPU time */
    cpu_stats[0] = cpu_time[0] + cpu_time[1] + cpu_time[2] + cpu_time[3] + cpu_time[4] + cpu_time[5] + cpu_time[6] + cpu_time[7] + cpu_time[8] + cpu_time[9];

    /* Copy over the individual CPU state times */
    for (i = 1; i < CPU_STATES; i++) {
        cpu_stats[i] = cpu_time[i];
    }
}

int main() {
    unsigned long long int cpu_stats[CPU_STATES], prev_cpu_stats[CPU_STATES];
    double elapsed_time;

    /* Print out the initial CPU state header */
    print_header();

    /* Get the initial CPU statistics */
    get_cpu_stats(cpu_stats);
    memcpy(prev_cpu_stats, cpu_stats, sizeof(cpu_stats));

    /* Loop forever */
    while (1) {
        usleep((useconds_t)(REFRESH_INTERVAL * 1000000.0));

        /* Get the current CPU statistics */
        get_cpu_stats(cpu_stats);

        /* Calculate the elapsed time since the last update */
        elapsed_time = REFRESH_INTERVAL;

        /* Print out the current CPU state percentages */
        print_cpu_stats(cpu_stats, prev_cpu_stats, elapsed_time);

        /* Save the current CPU statistics */
        memcpy(prev_cpu_stats, cpu_stats, sizeof(cpu_stats));
    }

    return 0;
}