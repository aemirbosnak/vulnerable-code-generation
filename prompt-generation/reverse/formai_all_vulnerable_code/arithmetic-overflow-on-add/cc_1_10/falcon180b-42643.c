//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define DELTA_S 1
#define DELTA_US 1000000

int main(int argc, char *argv[]) {
    int i;
    struct rusage usage;
    struct timeval start_time, end_time;

    if (argc!= 2) {
        printf("Usage: %s <process_id>\n", argv[0]);
        exit(1);
    }

    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        printf("Error: getrusage() failed\n");
        exit(1);
    }

    gettimeofday(&start_time, NULL);

    for (i = 0; i < DELTA_S; i++) {
        if (getrusage(RUSAGE_SELF, &usage) == -1) {
            printf("Error: getrusage() failed\n");
            exit(1);
        }

        if (gettimeofday(&end_time, NULL) == -1) {
            printf("Error: gettimeofday() failed\n");
            exit(1);
        }

        if (end_time.tv_sec - start_time.tv_sec >= DELTA_S) {
            break;
        }
    }

    if (i == DELTA_S) {
        printf("Error: CPU usage could not be calculated\n");
        exit(1);
    }

    printf("CPU usage for process %d is %.2f%%\n", atoi(argv[1]),
           (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec +
            usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) /
           (DELTA_S * 1000000) * 100);

    return 0;
}