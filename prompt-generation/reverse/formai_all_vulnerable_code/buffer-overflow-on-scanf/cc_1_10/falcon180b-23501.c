//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_TIME 10000
#define TIME_STEP 10

struct time_travel {
    int time;
    char destination[100];
};

int main() {
    int num_travels;
    struct time_travel travels[MAX_TIME];
    int i, j;

    // Read in the number of time travels
    printf("Enter the number of time travels: ");
    scanf("%d", &num_travels);

    // Read in the time travels
    for (i = 0; i < num_travels; i++) {
        printf("Enter the time and destination for time travel %d:\n", i + 1);
        scanf("%d %s", &travels[i].time, travels[i].destination);
    }

    // Sort the time travels by time
    for (i = 0; i < num_travels - 1; i++) {
        for (j = i + 1; j < num_travels; j++) {
            if (travels[i].time > travels[j].time) {
                struct time_travel temp = travels[i];
                travels[i] = travels[j];
                travels[j] = temp;
            }
        }
    }

    // Perform the time travels
    for (i = 0; i < num_travels; i++) {
        printf("Time traveling to %s...\n", travels[i].destination);
        sleep(travels[i].time / TIME_STEP);
        printf("Arrived at %s!\n", travels[i].destination);
    }

    return 0;
}