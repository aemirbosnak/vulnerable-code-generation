//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <math.h>

int main()
{
    int i, j, count = 0;
    struct rusage usage;
    double cpu_usage = 0.0;
    double prev_cpu_usage = 0.0;
    double avg_cpu_usage = 0.0;
    double avg_cpu_percentage = 0.0;
    double cpu_percentage = 0.0;
    double prev_cpu_percentage = 0.0;
    double avg_cpu_percentage_prev = 0.0;
    double avg_cpu_percentage_curr = 0.0;

    printf("CPU Usage Monitor\n");
    printf("==================\n");

    while(1)
    {
        if(getrusage(RUSAGE_SELF, &usage) == -1)
        {
            perror("getrusage()");
            exit(EXIT_FAILURE);
        }

        cpu_usage = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
        cpu_percentage = cpu_usage / (double)sysconf(_SC_CLK_TCK);
        avg_cpu_percentage_prev = avg_cpu_percentage;
        avg_cpu_percentage_curr = cpu_percentage;

        if(count == 0)
        {
            avg_cpu_percentage = cpu_percentage;
        }
        else
        {
            avg_cpu_percentage = (avg_cpu_percentage_curr + avg_cpu_percentage_prev) / 2.0;
        }

        printf("\rCPU Usage: %.2f%%", cpu_percentage);
        fflush(stdout);
        usleep(500000);
        count++;
    }

    return 0;
}