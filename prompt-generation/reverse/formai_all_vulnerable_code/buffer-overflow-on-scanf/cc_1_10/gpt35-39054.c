//FormAI DATASET v1.0 Category: Temperature monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 200.0
#define TEMP_DIFF 10.0

/* function to generate a random temperature */
double generate_random_temperature() {
    double random_temp = (double)rand() / RAND_MAX * MAX_TEMP;
    return random_temp;
}

/* function to check the temperature */
void check_temperature(double temperature, double threshold) {
    if (temperature >= threshold) {
        printf("\nWARNING: Current temperature is above the specified threshold of %.2f degrees Celsius!", threshold);
    }
}

int main() {
    int num_readings;
    double threshold;
    
    printf("Welcome to the Temperature Monitor Program!\n");
    printf("How many temperature readings would you like to generate? ");
    scanf("%d", &num_readings);
    
    printf("\nWhat threshold temperature (in degrees Celsius) would you like to set for a warning message? ");
    scanf("%lf", &threshold);
    
    /* seed random number generator */
    srand(time(NULL));
    
    double temperatures[num_readings];
    
    for (int i=0; i<num_readings; i++) {
        temperatures[i] = generate_random_temperature();
        printf("Temperature reading %d: %.2f degrees Celsius\n", i+1, temperatures[i]);
        check_temperature(temperatures[i], threshold);
    }
    
    double average_temp = 0.0;
    for (int i=0; i<num_readings; i++) {
        average_temp += temperatures[i];
    }
    average_temp = average_temp / num_readings;
    
    printf("\nAverage temperature: %.2f degrees Celsius\n", average_temp);
    
    /* generate range of temperatures for warning message */
    double warning_min = threshold - TEMP_DIFF;
    double warning_max = threshold + TEMP_DIFF;
    printf("Warning range: %.2f - %.2f degrees Celsius\n", warning_min, warning_max);
    
    return 0;
}