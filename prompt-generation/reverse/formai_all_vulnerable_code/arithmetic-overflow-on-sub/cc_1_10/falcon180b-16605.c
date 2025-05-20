//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>

#define DELTA_T 1 // time interval between samples in seconds

int main()
{
    int fd;
    struct rusage ru_before, ru_after;
    double cpu_usage;

    // open /proc/self/stat for reading
    fd = open("/proc/self/stat", O_RDONLY);
    if (fd == -1)
    {
        printf("Error: could not open /proc/self/stat\n");
        exit(1);
    }

    // initialize structures
    getrusage(RUSAGE_SELF, &ru_before);
    getrusage(RUSAGE_SELF, &ru_after);

    // calculate CPU usage
    ru_after.ru_utime.tv_sec -= ru_before.ru_utime.tv_sec;
    ru_after.ru_stime.tv_sec -= ru_before.ru_stime.tv_sec;
    cpu_usage = (ru_after.ru_utime.tv_sec + ru_after.ru_stime.tv_sec) / DELTA_T;

    while (1)
    {
        // read current CPU usage
        getrusage(RUSAGE_SELF, &ru_after);

        // calculate CPU usage
        ru_after.ru_utime.tv_sec -= ru_before.ru_utime.tv_sec;
        ru_after.ru_stime.tv_sec -= ru_before.ru_stime.tv_sec;
        cpu_usage = (ru_after.ru_utime.tv_sec + ru_after.ru_stime.tv_sec) / DELTA_T;

        // print current CPU usage
        printf("CPU usage: %.2f%%\n", cpu_usage * 100);

        // wait for 1 second before sampling again
        sleep(1);

        // reset structures for next sample
        ru_before = ru_after;
    }

    return 0;
}