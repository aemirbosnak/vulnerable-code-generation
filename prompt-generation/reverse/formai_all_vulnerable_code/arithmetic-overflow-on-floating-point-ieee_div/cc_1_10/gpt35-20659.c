//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

float get_avg_cpu_usage();
void calculate_cpu_usage(unsigned long long int* data);

int main(void)
{
    unsigned long long int data[8]; // This array stores CPU usage metrics
    memset(data, 0, sizeof(data)); // Initialize all values to 0

    while(1)
    {
        calculate_cpu_usage(data);
        float avg_usage = get_avg_cpu_usage();
        printf("CPU Usage: %.2f%%\n", avg_usage);
        sleep(1); // Wait for 1 second before checking CPU usage again
    }

    return 0; // Program should never reach this point
}

float get_avg_cpu_usage()
{
    FILE* fp;
    char buffer[BUFFER_SIZE];
    float user, nice, system, idle;
    float usage = 0.0;

    fp = fopen("/proc/stat", "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Error opening /proc/stat: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fgets(buffer, BUFFER_SIZE, fp);
    sscanf(buffer, "cpu %f %f %f %f", &user, &nice, &system, &idle);

    usage = (user + nice + system) / (user + nice + system + idle) * 100.0;

    fclose(fp);

    return usage;
}

void calculate_cpu_usage(unsigned long long int* data)
{
    FILE* fp;
    char buffer[BUFFER_SIZE];

    fp = fopen("/proc/stat", "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Error opening /proc/stat: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fgets(buffer, BUFFER_SIZE, fp);

    // Populate CPU usage metrics
    sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
            &data[0], &data[1], &data[2], &data[3],
            &data[4], &data[5], &data[6], &data[7]);

    fclose(fp);
}