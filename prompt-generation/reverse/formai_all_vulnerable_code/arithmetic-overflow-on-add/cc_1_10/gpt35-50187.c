//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BILLION  1000000000L

int main(void) {
    int i, j, year, month;
    long int ns, sec, ms;
    struct tm *date;
    struct timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);

    // Travel back in time
    for (i = 0; i < 10; i++) {
        // Subtract a random number of seconds
        sec = rand() % BILLION;
        nanosleep((const struct timespec[]){{0, sec}}, NULL);
        printf("Traveling back in time...\n");
    }

    // Print current date and time
    clock_gettime(CLOCK_REALTIME, &end);
    ns = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    sec = ns / BILLION;
    ms = ns % BILLION / 1000000;
    printf("Current date and time: %s", asctime(localtime(&end.tv_sec)));
    printf("Time travel duration: %ld.%03ld seconds\n", sec, ms);

    // Set a random date in the past
    year = 1900 + rand() % 120;
    month = rand() % 12 + 1;
    date = (struct tm *) malloc(sizeof(struct tm ));
    date->tm_year = year - 1900;
    date->tm_mon = month - 1;
    date->tm_mday = 1;
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;
    mktime(date);

    // Travel to the random date
    for (j = 0; j < month; j++) {
        // Add a random number of days
        date->tm_mday += rand() % 31;
        mktime(date);
        printf("Traveling to %s", asctime(date));
    }

    // Print final date and time
    clock_gettime(CLOCK_REALTIME, &end);
    ns = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    sec = ns / BILLION;
    ms = ns % BILLION / 1000000;
    printf("Final date and time: %s", asctime(date));
    printf("Total time travel duration: %ld.%03ld seconds\n", sec, ms);

    free(date);
    return 0;
}