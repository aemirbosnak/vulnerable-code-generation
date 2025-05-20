//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TEMP 1000 // maximum temperature range
#define MIN_TEMP -273.15 // minimum temperature range
#define TEMP_STEP 1 // temperature step for display

int main() {
    double temperature;
    int choice;
    
    while (1) {
        // display menu
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Display temperature range\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // perform selected action
        switch (choice) {
            case 1:
                // Celsius to Fahrenheit
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                temperature = (temperature * 9.0/5.0) + 32.0;
                printf("Temperature in Fahrenheit: %.2lf\n", temperature);
                break;
            case 2:
                // Fahrenheit to Celsius
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                temperature = (temperature - 32.0) * 5.0/9.0;
                printf("Temperature in Celsius: %.2lf\n", temperature);
                break;
            case 3:
                // display temperature range
                printf("Temperature range: %.2lf - %.2lf\n", MIN_TEMP, MAX_TEMP);
                break;
            case 4:
                // exit program
                printf("Exiting program...\n");
                exit(0);
            default:
                // invalid input
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}