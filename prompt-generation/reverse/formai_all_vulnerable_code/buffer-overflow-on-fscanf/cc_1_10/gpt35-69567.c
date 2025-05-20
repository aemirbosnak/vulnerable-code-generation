//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

/* declare global variables */
double total_cpu_time = 0.0;
double total_idle_time = 0.0;
double prev_total_cpu_time = 0.0;
double prev_total_idle_time = 0.0;
double cpu_usage = 0.0;

/* function to calculate CPU usage */
void calculate_cpu_usage() {
    /* open file pointer for cpu usage information */
    FILE* fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    /* declare variables */
    double user_time = 0.0;
    double nice_time = 0.0;
    double system_time = 0.0;
    double idle_time = 0.0;

    /* read the content of the file and extract the relevant information */
    fscanf(fp, "cpu %lf %lf %lf %lf", &user_time, &nice_time, &system_time, &idle_time);

    /* close the file pointer */
    fclose(fp);

    /* calculate the total CPU time */
    total_cpu_time = user_time + nice_time + system_time + idle_time;

    /* calculate the total idle time */
    total_idle_time = idle_time;

    /* calculate the CPU usage */
    cpu_usage = (1 - ((total_cpu_time - prev_total_cpu_time) - (total_idle_time - prev_total_idle_time)) / (total_cpu_time - prev_total_cpu_time)) * 100;

    /* update the previous values to the current values */
    prev_total_cpu_time = total_cpu_time;
    prev_total_idle_time = total_idle_time;
}

int main() {
    /* run the loop infinitely */
    while (1) {
        /* call the function to calculate CPU usage */
        calculate_cpu_usage();

        /* display the calculated CPU usage */
        printf("CPU USAGE: %.2f%%\n", cpu_usage);

        /* wait for 1 second */
        sleep(1);
    }

    return 0;
}