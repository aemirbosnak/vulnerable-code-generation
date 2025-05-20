//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFFER_SIZE 128

/* function to read the current CPU usage */
float read_cpu_usage() {
    FILE* fp;
    char buffer[BUFFER_SIZE];
    float cpu_usage = 0;
    
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening /proc/stat file\n");
        exit(EXIT_FAILURE);
    }
    
    /* read the first line in /proc/stat file */
    fgets(buffer, BUFFER_SIZE, fp);
    
    /* parse the CPU usage information */
    char* token = strtok(buffer, " ");
    int count = 0;
    unsigned long long int user_time = 0, nice_time = 0, system_time = 0, idle_time = 0, iowait_time = 0, irq_time = 0, softirq_time = 0;
    while (token != NULL) {
        if (count == 1) user_time = strtoull(token, NULL, 0);
        else if (count == 2) nice_time = strtoull(token, NULL, 0);
        else if (count == 3) system_time = strtoull(token, NULL, 0);
        else if (count == 4) idle_time = strtoull(token, NULL, 0);
        else if (count == 5) iowait_time = strtoull(token, NULL, 0);
        else if (count == 6) irq_time = strtoull(token, NULL, 0);
        else if (count == 7) softirq_time = strtoull(token, NULL, 0);
        token = strtok(NULL, " ");
        count++;
    }
    
    /* calculate the total CPU time */
    unsigned long long int total_time = user_time + nice_time + system_time + idle_time + iowait_time + irq_time + softirq_time;
    
    /* calculate the CPU usage */
    unsigned long long int idle_time_diff = idle_time - 0;
    unsigned long long int total_time_diff = total_time - 0;
    cpu_usage = 100 - ((float) idle_time_diff / (float) total_time_diff) * 100;
    
    fclose(fp);
    return cpu_usage;
}

int main() {
    struct timeval start_time, end_time;
    long long int elapsed_time;
    float cpu_usage = 0;
    
    gettimeofday(&start_time, NULL); /* start the timer */
    
    /* read the CPU usage for 5 seconds */
    do {
        cpu_usage = read_cpu_usage();
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        usleep(500000); /* sleep for 500 milliseconds */
        gettimeofday(&end_time, NULL); /* end the timer */
        elapsed_time = end_time.tv_sec * 1000000 + end_time.tv_usec - start_time.tv_sec * 1000000 - start_time.tv_usec;
    } while (elapsed_time < 5000000); /* while elapsed time is less than 5 seconds */
    
    return 0;
}