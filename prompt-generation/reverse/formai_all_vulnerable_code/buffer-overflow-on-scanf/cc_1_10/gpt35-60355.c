//FormAI DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

// Define constants for unit conversions
#define METERS_TO_FEET 3.28
#define METERS_TO_YARDS 1.09
#define MILES_TO_KILOMETERS 1.61

// Define a function to display the unit conversion options
void displayOptions(){
    printf("\nPlease select the unit conversion you would like to perform:\n");
    printf("1. Meters to Feet\n");
    printf("2. Meters to Yards\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Exit Program\n\n");
}

int main(){
    int option;
    float value, result;

    printf("Welcome to the Shape Shifting Unit Converter!\n");

    while(1){
        // Display the conversion options and get the user's choice
        displayOptions();
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option){
            // Perform the Meters to Feet conversion
            case 1:
                printf("Enter the value in Meters: ");
                scanf("%f", &value);

                // Perform the conversion
                result = value * METERS_TO_FEET;

                printf("%.2f Meters is equal to %.2f Feet.\n", value, result);
                break;

            // Perform the Meters to Yards conversion
            case 2:
                printf("Enter the value in Meters: ");
                scanf("%f", &value);

                // Perform the conversion
                result = value * METERS_TO_YARDS;

                printf("%.2f Meters is equal to %.2f Yards.\n", value, result);
                break;

            // Perform the Miles to Kilometers conversion
            case 3:
                printf("Enter the value in Miles: ");
                scanf("%f", &value);

                // Perform the conversion
                result = value * MILES_TO_KILOMETERS;

                printf("%.2f Miles is equal to %.2f Kilometers.\n", value, result);
                break;

            // Exit the program
            case 4:
                printf("Thank you for using the Shape Shifting Unit Converter!\n");
                exit(0);
                break;

            // Handle invalid input
            default:
                printf("Invalid option selected. Please try again.\n");
        }
    }

    return 0;
}