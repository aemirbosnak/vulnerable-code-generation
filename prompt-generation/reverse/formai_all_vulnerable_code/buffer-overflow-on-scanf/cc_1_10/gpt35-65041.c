//FormAI DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random temperature */
float generateTemperature(float start, float end) {
    float range = end - start;
    float random = ((float) rand()) / (float) RAND_MAX;
    return (start + (random * range));
}

int main() {
    srand(time(NULL));
    float minTemperature = 20.0;
    float maxTemperature = 40.0;

    /* Displaying the weather simulation heading */
    printf("========================\n");
    printf("WEATHER SIMULATION PROGRAM\n");
    printf("========================\n");

    /* Displaying current date and time */
    time_t now;
    time(&now);
    printf("\nToday's date and time : %s", ctime(&now));

    /* Asking user for number of simulation days */
    int noOfDays;
    printf("Enter number of days for simulation : ");
    scanf("%d", &noOfDays);

    /* Displaying temperatures for each day */
    for (int i = 1; i <= noOfDays; i++) {
        float temperature = generateTemperature(minTemperature, maxTemperature);
        printf("\nDay %d : %0.2f degrees Celsius\n", i, temperature);
    }

    /* Calculating and displaying average temperature for the simulation period */
    float totalTemperature = 0.0;
    for (int i = 1; i <= noOfDays; i++) {
        totalTemperature += generateTemperature(minTemperature, maxTemperature);
    }
    float avgTemperature = totalTemperature / noOfDays;
    printf("\nAverage temperature over %d days is %0.2f degrees Celsius\n", noOfDays, avgTemperature);

    /* Displaying closing message */
    printf("\nThank you for using Weather Simulation Program! Have a nice day!\n");

    return 0;
}