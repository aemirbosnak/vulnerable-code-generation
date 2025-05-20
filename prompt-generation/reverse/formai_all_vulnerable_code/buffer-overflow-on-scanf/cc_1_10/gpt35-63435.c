//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float current_temp = 0.0;
    float min_temp = 100.0;
    float max_temp = 0.0;
    float temp_sum = 0.0;
    int num_readings = 0;
    char user_choice;

    srand(time(NULL)); // generate seed for random numbers

    printf("Welcome to the temperature monitor program!\n");

    // prompt user for input
    printf("How many temperature readings would you like to take? ");
    scanf("%d", &num_readings);

    // simulate temperature readings
    for (int i = 1; i <= num_readings; i++) {
        current_temp = (float) rand() / (float) (RAND_MAX / 100.0); // generate random temperature between 0 and 100 degrees Celsius
        printf("Temperature reading %d: %.2f degrees Celsius\n", i, current_temp);

        if (current_temp < min_temp) {
            min_temp = current_temp;
        }

        if (current_temp > max_temp) {
            max_temp = current_temp;
        }

        temp_sum += current_temp;
    }

    // calculate average temperature
    float avg_temp = temp_sum / num_readings;

    printf("\nMinimum temperature reading: %.2f degrees Celsius\n", min_temp);
    printf("Maximum temperature reading: %.2f degrees Celsius\n", max_temp);
    printf("Average temperature reading: %.2f degrees Celsius\n", avg_temp);

    // ask user if they want to repeat the program
    printf("\nWould you like to take another set of temperature readings? (y/n) ");
    scanf(" %c", &user_choice);

    if (user_choice == 'y' || user_choice == 'Y') {
        main(); // call main function again to repeat program
    }

    return 0;
}