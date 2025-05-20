//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int minTemp = -10; // minimum temperature in Celsius
    int maxTemp = 40; // maximum temperature in Celsius
    int numDays; // number of days for simulation
    int tempRange; // temperature range for each day
    int temp; // temperature for each day
    int i, j; // loop counters

    srand(time(NULL)); // initialize random number generator with current time

    printf("Enter the number of days for the simulation: ");
    scanf("%d", &numDays);

    printf("\nSimulation Results:\n\n");

    for (i=1; i<=numDays; i++) {
        tempRange = (maxTemp - minTemp) + 1; // calculate temperature range for each day
        temp = (rand() % tempRange) + minTemp; // generate random temperature for each day
        printf("Day %d: ", i);

        if (temp < 0) {
            printf("%d degrees Celsius (Freezing)\n", temp);
        }

        else if (temp >=0 && temp <= 10) {
            printf("%d degrees Celsius (Cold)\n", temp);
        }

        else if (temp > 10 && temp <= 20) {
            printf("%d degrees Celsius (Mild)\n", temp);
        }

        else if (temp > 20 && temp <= 30) {
            printf("%d degrees Celsius (Warm)\n", temp);
        }

        else {
            printf("%d degrees Celsius (Hot)\n", temp);
        }

        for (j=1; j<=temp; j++) {
            printf("*"); // print asterisks to represent temperature
        }

        printf("\n\n"); // add newline and extra space for readability
    }

    return 0;
}