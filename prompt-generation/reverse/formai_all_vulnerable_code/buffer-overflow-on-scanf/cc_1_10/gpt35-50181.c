//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int alienProb, numDays, numCities, maxDamage, totalDamage, dayCount;
    float damagePerDay;

    srand(time(NULL));  // set the seed for random number generator

    // prompt the user for input
    printf("Enter the probability of an alien invasion (0-100): ");
    scanf("%d", &alienProb);

    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    printf("Enter the number of cities to protect: ");
    scanf("%d", &numCities);

    printf("Enter the maximum damage each alien ship can cause: ");
    scanf("%d", &maxDamage);

    printf("\n");

    // calculate the probability of alien invasion per city
    float cityProb = (float)alienProb / 100 / numCities;

    // initialize variables
    totalDamage = 0;
    dayCount = 1;

    // run simulation for given number of days
    while (dayCount <= numDays) {
        printf("Day %d:\n", dayCount);

        // loop over each city and determine if invaded or not
        for (int i = 1; i <= numCities; i++) {
            int invasion = rand() % 100 < cityProb * 100;

            if (invasion) {
                int cityDamage = rand() % maxDamage + 1;
                printf("City %d was invaded!\n", i);
                printf("Damage caused: %d\n", cityDamage);

                totalDamage += cityDamage;
            } else {
                printf("City %d was not invaded.\n", i);
            }
        }

        dayCount++;

        printf("\n");
    }

    // calculate average damage per day and print results
    damagePerDay = (float)totalDamage / numDays;

    printf("Total damage caused over %d days: %d\n", numDays, totalDamage);
    printf("Average damage caused per day: %.2f\n", damagePerDay);

    return 0;
}