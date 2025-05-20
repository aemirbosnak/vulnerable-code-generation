//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// define constants
#define MIN_LEVEL -100
#define MAX_LEVEL -50
#define MAX_RETRY 3

// function to generate a random signal level
int generate_signal_level(){
    int level = rand() % (MAX_LEVEL - MIN_LEVEL + 1) + MIN_LEVEL;
    return level;
}

// function to calculate the average signal level
float calculate_average(int levels[], int n){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += levels[i];
    }
    float average = sum / n;
    return average;
}

// main function
int main(){
    // initialize variables
    int levels[MAX_RETRY];
    float average;
    char retry;

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");

    do{
        // generate signal levels
        printf("Generating signal levels...\n\n");
        for(int i = 0; i < MAX_RETRY; i++){
            levels[i] = generate_signal_level();
            printf("Signal strength level %d: %d dBm\n", i+1, levels[i]);
        }

        // calculate average signal level
        average = calculate_average(levels, MAX_RETRY);
        printf("\nThe average signal strength level is: %.2f dBm\n", average);

        // check if signal is strong enough
        if(average >= MAX_LEVEL){
            printf("\nThe Wi-Fi signal is strong enough for normal use.\n");
        }else{
            printf("\nThe Wi-Fi signal is weak and may cause slow internet speeds.\n");
        }

        // ask user if they want to retry
        printf("\nDo you want to retry (y/n)? ");
        scanf(" %c", &retry);

        // clear input buffer
        while(getchar() != '\n');

        // check if user wants to retry
        if(retry == 'y'){
            printf("\n");
        }

    }while(retry == 'y');

    printf("\nThank you for using the Wi-Fi Signal Strength Analyzer!\n");

    return 0;
}