//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: relaxed
/* Welcome to our Wi-Fi Signal Strength Analyzer program! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getSignalStrength(int min, int max) {
    // this function generates a random signal strength between min and max values
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

int main() {
    int signals[5] = {0}; // an array to store 5 randomly generated signal strength values
    int i;
    
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
    
    // prompt the user to enter the minimum and maximum values for signal strength
    int min, max;
    printf("Please enter the minimum value for signal strength (0-100): ");
    scanf("%d", &min);
    printf("Please enter the maximum value for signal strength (%d-100): ", min);
    scanf("%d", &max);
    
    // generate random signal strength values and store them in the signals array
    for (i = 0; i < 5; i++) {
        signals[i] = getSignalStrength(min, max);
    }
    
    // print out the signal strength values
    printf("Here are the 5 signal strength values that we generated:\n");
    for (i = 0; i < 5; i++) {
        printf("Signal %d: %d\n", i+1, signals[i]);
    }
    
    // calculate the average signal strength
    int total = 0;
    for (i = 0; i < 5; i++) {
        total += signals[i];
    }
    float average = (float) total / 5;
    
    // print out the average signal strength
    printf("The average signal strength is %.2f\n", average);
    
    // analyze the signal strength
    if (average >= 75) {
        printf("The signal strength is excellent!\n");
    }
    else if (average >= 50) {
        printf("The signal strength is good.\n");
    }
    else if (average >= 25) {
        printf("The signal strength is fair.\n");
    }
    else {
        printf("The signal strength is poor. You may have trouble connecting to the internet.\n");
    }
    
    return 0;
}