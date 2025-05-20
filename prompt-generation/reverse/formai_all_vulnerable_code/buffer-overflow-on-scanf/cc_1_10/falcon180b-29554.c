//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int i, j;
    double temp, prevTemp;
    time_t startTime, endTime;
    struct tm* startTm, *endTm;

    // Initialize variables
    temp = 0;
    prevTemp = 0;

    // Get current temperature
    printf("Enter current temperature in Celsius: ");
    scanf("%lf", &temp);

    // Convert temperature to Fahrenheit
    temp = (temp * 9/5) + 32;

    // Display current temperature
    printf("Current temperature: %.2lf degrees Fahrenheit\n", temp);

    // Start temperature monitoring loop
    while(1) {
        // Get current time
        time(&startTime);
        startTm = localtime(&startTime);

        // Get temperature
        for(i=0; i<10; i++) {
            temp = (double)rand() / RAND_MAX * 100;
            if(temp!= prevTemp) {
                prevTemp = temp;
                printf("Temperature reading %d: %.2lf degrees Fahrenheit\n", i+1, temp);
            }
        }

        // Wait for 5 seconds
        for(j=0; j<10; j++) {
            printf("Waiting... %d\n", j+1);
            fflush(stdout);
            usleep(500000);
        }

        // End temperature monitoring loop
        endTime = time(NULL);
        endTm = localtime(&endTime);
        printf("Temperature monitoring ended at %s\n", asctime(endTm));
        break;
    }

    return 0;
}