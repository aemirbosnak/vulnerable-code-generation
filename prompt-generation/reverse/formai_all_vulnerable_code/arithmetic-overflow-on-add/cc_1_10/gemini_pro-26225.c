//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    struct timeval start, end;
    struct rusage usage;
    int fd;
    char buf[1024];
    int i, j;

    // Open a file for writing
    fd = open("usage.log", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Get the current time
    gettimeofday(&start, NULL);

    // Loop for 10 seconds
    for (i = 0; i < 10; i++) {
        // Get the current CPU usage
        getrusage(RUSAGE_SELF, &usage);

        // Write the CPU usage to the file
        snprintf(buf, sizeof(buf), "%ld.%06ld %ld %ld\n",
                 start.tv_sec + usage.ru_utime.tv_sec,
                 start.tv_usec + usage.ru_utime.tv_usec,
                 start.tv_sec + usage.ru_stime.tv_sec,
                 start.tv_usec + usage.ru_stime.tv_usec);
        write(fd, buf, strlen(buf));

        // Sleep for 100 milliseconds
        usleep(100000);
    }

    // Get the current time again
    gettimeofday(&end, NULL);

    // Close the file
    close(fd);

    // Calculate the total CPU time used
    double total_time = (double)(end.tv_sec - start.tv_sec) +
                            (double)(end.tv_usec - start.tv_usec) / 1000000.0;

    // Print the total CPU time used
    printf("Total CPU time used: %.6f seconds\n", total_time);

    return 0;
}