//FormAI DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>

// Define constants for conversion rates
#define METERS_TO_FEET 3.281
#define KILOMETERS_TO_MILES 0.6214

// Function to convert meters to feet
float convertMetersToFeet(float meters) {
    return meters * METERS_TO_FEET;
}

// Function to convert kilometers to miles
float convertKilometersToMiles(float kilometers) {
    return kilometers * KILOMETERS_TO_MILES;
}

// Main function to run the program
int main() {
    int choice;
    float value, result;
    
    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert meters to feet\n");
    printf("2. Convert kilometers to miles\n");
    printf("Enter your choice: ");
    
    // Get user's choice
    scanf("%d", &choice);
    
    // Perform the chosen conversion
    switch (choice) {
        case 1:
            printf("Enter value in meters: ");
            scanf("%f", &value);
            result = convertMetersToFeet(value);
            printf("%.2f meters is equal to %.2f feet.\n", value, result);
            break;
            
        case 2:
            printf("Enter value in kilometers: ");
            scanf("%f", &value);
            result = convertKilometersToMiles(value);
            printf("%.2f kilometers is equal to %.2f miles.\n", value, result);
            break;
            
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
    return 0;
}