//FormAI DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return celsius * 9 / 5 + 32;
}

// Function to convert Miles to Kilometers
double milesToKilometers(double miles) {
    return miles * 1.609;
}

// Function to convert Kilometers to Miles
double kilometersToMiles(double kilometers) {
    return kilometers / 1.609;
}

int main() {
    int choice;
    double input, output;
    
    printf("Welcome to Unit Converter!\n");
    printf("===========================\n");
    printf("Choose an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Quit\n");
    
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input);
            output = fahrenheitToCelsius(input);
            printf("Temperature in Celsius: %.2lf\n", output);
        } else if(choice == 2) {
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input);
            output = celsiusToFahrenheit(input);
            printf("Temperature in Fahrenheit: %.2lf\n", output);
        } else if(choice == 3) {
            printf("Enter distance in miles: ");
            scanf("%lf", &input);
            output = milesToKilometers(input);
            printf("Distance in kilometers: %.2lf\n", output);
        } else if(choice == 4) {
            printf("Enter distance in kilometers: ");
            scanf("%lf", &input);
            output = kilometersToMiles(input);
            printf("Distance in miles: %.2lf\n", output);
        } else if(choice == 5) {
            printf("Thank you for using our converter!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}