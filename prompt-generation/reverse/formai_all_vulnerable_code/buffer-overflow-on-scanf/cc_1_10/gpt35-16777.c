//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int main()
{
    // initialize variables
    int wifiStrength[MAX_SIGNAL_STRENGTH], i, input, upperBound, lowerBound, count = 0;
    
    // prompt user for upper and lower bounds
    printf("Enter lower bound: ");
    scanf("%d", &lowerBound);

    printf("Enter upper bound: ");
    scanf("%d", &upperBound);

    // validate input
    if (lowerBound < MIN_SIGNAL_STRENGTH || upperBound > MAX_SIGNAL_STRENGTH || lowerBound > upperBound) {
        printf("Invalid input. Bounds must be between 0 and 100 and lower bound must be less than or equal to upper bound.\n");
        return 1;
    }

    // simulate wifi strength data
    srand(time(NULL));
    for (i = 0; i < MAX_SIGNAL_STRENGTH; i++) {
        wifiStrength[i] = rand() % (MAX_SIGNAL_STRENGTH + 1);
    }
    
    // loop through wifi strength data
    for (i = 0; i < MAX_SIGNAL_STRENGTH; i++) {
        // check if wifi strength is within bounds
        if (wifiStrength[i] >= lowerBound && wifiStrength[i] <= upperBound) {
            count++;
        }
    }

    // calculate percentage of wifi strength within bounds
    float percentage = (float)count / MAX_SIGNAL_STRENGTH * 100;

    // print results
    printf("Wifi strength data:\n");
    for (i = 0; i < MAX_SIGNAL_STRENGTH; i++) {
        printf("%d ", wifiStrength[i]);
    }
    printf("\n");
    printf("%d wifi strength readings were within the bounds %d to %d, which is %.2f percent of the total.\n", count, lowerBound, upperBound, percentage);

    return 0;
}