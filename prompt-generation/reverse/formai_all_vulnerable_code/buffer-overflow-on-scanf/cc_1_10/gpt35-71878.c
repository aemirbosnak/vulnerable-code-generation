//FormAI DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

float meters_to_feet(float meters) {
    return meters * 3.28084;
}

float feet_to_meters(float feet) {
    return feet * 0.3048;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 0.555556;
}

int main() {
    int option;
    float value;
    
    printf("Welcome to the minimalist unit converter!\n\n");
    
    while(1) {
        printf("Please select an option:\n");
        printf("1. Meters to Feet\n");
        printf("2. Feet to Meters\n");
        printf("3. Celsius to Fahrenheit\n");
        printf("4. Fahrenheit to Celsius\n");
        printf("5. Exit\n");
        
        scanf("%d", &option);
        
        if(option == 5) {
            printf("Goodbye!\n");
            break;
        }
        
        printf("Enter value to convert: ");
        scanf("%f", &value);
        
        if(option == 1) {
            printf("%.2f meters is equal to %.2f feet.\n\n", value, meters_to_feet(value));
        }
        else if(option == 2) {
            printf("%.2f feet is equal to %.2f meters.\n\n", value, feet_to_meters(value));
        }
        else if(option == 3) {
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n\n", value, celsius_to_fahrenheit(value));
        }
        else if(option == 4) {
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", value, fahrenheit_to_celsius(value));
        }
        else {
            printf("Invalid option.\n\n");
        }
    }
    
    return 0;
}