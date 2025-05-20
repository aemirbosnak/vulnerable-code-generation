//FormAI DATASET v1.0 Category: Temperature monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to our temperature monitoring system!\n\n");
    printf("Please enter the minimum and maximum temperatures for the system to monitor:\n");

    float min_temp, max_temp;

    // Get user input for min and max temperatures
    printf("Minimum Temperature: ");
    scanf("%f", &min_temp);
    printf("Maximum Temperature: ");
    scanf("%f", &max_temp);

    while (max_temp < min_temp) {
        printf("Invalid input! Maximum temperature must be greater than minimum temperature.\n");
        printf("Please enter minimum and maximum temperatures again:\n");
        printf("Minimum Temperature: ");
        scanf("%f", &min_temp);
        printf("Maximum Temperature: ");
        scanf("%f", &max_temp);
    }

    srand(time(NULL)); // initialize random number generator with current time
    float current_temp; // variable to store current temperature reading

    printf("\nTemperature readings:\n");

    for (int i=0; i<10; i++) {
        current_temp = ((float)rand()/(float)(RAND_MAX)) * (max_temp - min_temp) + min_temp;

        if (current_temp <= min_temp + 5) {
            printf("Low temperature alert! The current temperature is %.1f degrees Celsius.\n", current_temp);
        } else if (current_temp >= max_temp - 5) {
            printf("High temperature alert! The current temperature is %.1f degrees Celsius.\n", current_temp);
        } else {
            printf("The current temperature is %.1f degrees Celsius.\n", current_temp);
        }

        // wait for 1 second before taking next temperature reading
        for (int j=0; j<1000000000; j++);
    }

    printf("\nTemperature monitoring complete. Thank you for using our system!");

    return 0;
}