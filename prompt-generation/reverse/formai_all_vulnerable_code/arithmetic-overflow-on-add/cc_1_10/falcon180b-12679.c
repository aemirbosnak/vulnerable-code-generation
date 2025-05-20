//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

// Get CPU usage in percentage (0-100)
int get_cpu_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return (int) ((double) usage.ru_utime.tv_sec + usage.ru_stime.tv_sec +
                    (double) usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / (double) (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec + (double) usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) * 100;
}

int main() {
    int cpu_usage = 0;
    char buffer[1024];

    while (1) {
        // Get current CPU usage
        cpu_usage = get_cpu_usage();

        // Clear console
        system("clear");

        // Print CPU usage in a funny way
        printf("\n");
        printf("CPU Usage: ");
        for (int i = 0; i < 50; i++) {
            if (i < cpu_usage) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");

        // Print some silly message
        sprintf(buffer, "CPU is working hard! %d%% usage", cpu_usage);
        printf("%s\n", buffer);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}