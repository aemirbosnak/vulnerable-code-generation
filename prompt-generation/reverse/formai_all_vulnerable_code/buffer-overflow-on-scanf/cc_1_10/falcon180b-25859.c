//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define COUNT 10
#define DELAY 2

int main() {
    int i, j, n;
    double temp[COUNT];
    char name[COUNT][20];
    time_t start_time, end_time;
    double elapsed_time;

    // get sensor names and initialize temperatures
    for (i = 0; i < COUNT; i++) {
        printf("Enter sensor name: ");
        scanf("%s", name[i]);
        temp[i] = 0.0;
    }

    // start monitoring
    start_time = time(NULL);
    while (1) {
        // read sensor values
        for (i = 0; i < COUNT; i++) {
            printf("Reading sensor %s...\n", name[i]);
            scanf("%lf", &temp[i]);
        }

        // calculate average temperature
        double avg_temp = 0.0;
        for (i = 0; i < COUNT; i++) {
            avg_temp += temp[i];
        }
        avg_temp /= COUNT;

        // print results
        printf("\nAverage temperature: %.2lf\n", avg_temp);
        for (i = 0; i < COUNT; i++) {
            printf("Sensor %s: %.2lf\n", name[i], temp[i]);
        }

        // wait for DELAY seconds
        for (j = 0; j < DELAY; j++) {
            printf("\rWaiting for %d seconds... ", DELAY - j);
            fflush(stdout);
            sleep(1);
        }

        // check if program should exit
        printf("\nPress any key to continue or 'q' to quit...\n");
        scanf(" %c", &n);
        if (n == 'q' || n == 'Q') {
            break;
        }
    }

    // calculate elapsed time
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    // print elapsed time
    printf("\nProgram ran for %ld seconds.\n", elapsed_time);

    return 0;
}