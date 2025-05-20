//Falcon2-11B DATASET v1.0 Category: CPU usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <math.h>

struct timeval start, end;
double elapsed_time;

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <interval in seconds>\n", argv[0]);
        exit(1);
    }

    // Parse interval
    double interval = atof(argv[1]);

    // Open /proc/self/stat file for reading
    int fd = open("/proc/self/stat", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read system statistics
    if (read(fd, &start, sizeof(start))!= sizeof(start)) {
        perror("read");
        exit(1);
    }

    // Loop forever
    while (1) {
        // Sleep for interval
        usleep(interval * 1000000);

        // Read system statistics again
        if (read(fd, &end, sizeof(end))!= sizeof(end)) {
            perror("read");
            exit(1);
        }

        // Calculate elapsed time
        gettimeofday(&end, NULL);
        elapsed_time = ((double) (end.tv_sec - start.tv_sec)) + (end.tv_usec - start.tv_usec) / 1000000.0;

        // Calculate CPU usage
        double user_time = (end.tv_usec - start.tv_usec) / 1000000.0;
        double system_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        double idle_time = elapsed_time - user_time - system_time;
        double cpu_usage = (user_time + system_time) / elapsed_time * 100.0;

        // Print CPU usage
        printf("%lf%% CPU usage\n", cpu_usage);
    }

    close(fd);
    return 0;
}