//FormAI DATASET v1.0 Category: Temperature monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MIN_TEMP -10 // minimum temperature
#define MAX_TEMP 50 // maximum temperature
#define TEMP_INTERVAL 5 // temperature interval

bool isInRange(double temp) { // check if temperature is within valid range
    return temp >= MIN_TEMP && temp <= MAX_TEMP;
}

int main(void) {
    srand((unsigned int) time(NULL)); // seed random number generator
    
    double current_temp = 0.0; // initialize current temperature to 0
    char unit[3]; // temperature unit (Celsius or Fahrenheit)
    double threshold_temp = 0.0; // temperature threshold
    char threshold_unit[3]; // threshold temperature unit (Celsius or Fahrenheit)

    printf("Welcome to the Temperature Monitor!\n");

    printf("\nPlease enter the current temperature in Celsius: ");
    scanf("%lf", &current_temp); // read in current temperature
    while (!isInRange(current_temp)) { // validate current temperature
        printf("\nInvalid temperature entered, please enter a temperature between %d°C and %d°C: ", MIN_TEMP, MAX_TEMP);
        scanf("%lf", &current_temp);
    }

    printf("\nEnter temperature unit (Celsius or Fahrenheit): ");
    scanf("%s", unit);
    while (strcmp(unit, "Celsius") != 0 && strcmp(unit, "Fahrenheit") != 0){ // validate unit
        printf("\nInvalid unit entered, please enter Celsius or Fahrenheit: ");
        scanf("%s", unit);
    }

    printf("\nEnter threshold temperature: ");
    scanf("%lf", &threshold_temp); // read in threshold temperature
    while (!isInRange(threshold_temp)) { // validate threshold temperature
        printf("\nInvalid temperature entered, please enter a temperature between %d°C and %d°C: ", MIN_TEMP, MAX_TEMP);
        scanf("%lf", &threshold_temp);
    }

    printf("\nEnter threshold temperature unit (Celsius or Fahrenheit): ");
    scanf("%s", threshold_unit); // read in threshold temperature unit 
    while (strcmp(threshold_unit, "Celsius") != 0 && strcmp(threshold_unit, "Fahrenheit") != 0){ // validate threshold unit
        printf("\nInvalid unit entered, please enter Celsius or Fahrenheit: ");
        scanf("%s", threshold_unit);
    }

    if (strcmp(threshold_unit, unit) != 0){ // if threshold unit is different from current unit, convert threshold temperature
        if (strcmp(unit, "Celsius") == 0) {
            threshold_temp = ((threshold_temp * 9) / 5) + 32;
        } else {
            threshold_temp = ((threshold_temp - 32) * 5) / 9;
        }
        printf("\nThreshold temperature converted to %s: %.1lf%s", unit, threshold_temp, unit);
    }

    printf("\n\nCurrent Temperature: %.1lf%s\n", current_temp, unit);

    while (true) { // infinite loop to continuously monitor temperature
        double delta = ((double) rand() / RAND_MAX) * TEMP_INTERVAL * 2 - TEMP_INTERVAL; // generate a random fluctuation in temperature
        current_temp += delta; // adjust current temperature
        printf("Temperature Fluctuation: %.1lf%s\n", delta, unit); // print temperature fluctuation
        printf("Current Temperature: %.1lf%s\n", current_temp, unit); // print current temperature

        if (strcmp(unit, "Celsius") == 0 && current_temp >= threshold_temp){ // if temperature surpasses threshold, alert user and break loop
            printf("\nTemperature threshold exceeded! %.1lf%s is higher than %.1lf%s.", current_temp, unit, threshold_temp, unit);
            break;
        } else if (strcmp(unit, "Fahrenheit") == 0 && current_temp >= ((threshold_temp - 32) * 5) / 9) { 
            printf("\nTemperature threshold exceeded! %.1lf%s is higher than %.1lf%s.", current_temp, unit, threshold_temp, unit);
            break;
        }

        printf("\nSleeping for 5 seconds...\n");
        for (int i = 0; i < 5; i++) {
            printf("%d...\n", 5 - i); // countdown until next temperature reading
            sleep(1); // wait 1 second before next iteration
        }
        printf("\n");
    }

    printf("\n\nTemperature monitor has stopped."); // program ends after threshold temperature is exceeded
    return 0;
}