//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9.0;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5.0) + 32;
}

// Function to convert Kilometers to Miles
float kilometers_to_miles(float kilometers) {
    return kilometers / 1.609;
}

// Function to convert Miles to Kilometers
float miles_to_kilometers(float miles) {
    return miles * 1.609;
}

int main() {
    int choice=0;
    float input=0, output=0;
    
    printf("Welcome to the Unit Converter!\n");
    printf("-----------------------------\n");
    
    while(1) {
        printf("Choose an option:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Kilometers to Miles\n");
        printf("4. Miles to Kilometers\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        
        // Validate User Input
        while (scanf("%d",&choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid choice. Please try again: ");
            while(getchar() != '\n');
        }
        
        if(choice == 5) {
            printf("Exiting...\n");
            break;
        }
        
        printf("Enter the value you want to convert: ");
        
        // Validate User Input
        while (scanf("%f",&input) != 1) {
            printf("Invalid input. Please try again: ");
            while(getchar() != '\n');
        }
        
        switch(choice) {
            case 1:
                output = fahrenheit_to_celsius(input);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", input, output);
                break;
            case 2:
                output = celsius_to_fahrenheit(input);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", input, output);                    
                break;
            case 3:
                output = kilometers_to_miles(input);
                printf("%.2f Kilometers is equal to %.2f Miles\n", input, output);
                break;
            case 4:
                output = miles_to_kilometers(input);
                printf("%.2f Miles is equal to %.2f Kilometers\n", input, output);
                break;
            default:
                printf("Invalid choice. Please try again: ");
                break;
        }
    }
    
    return 0;
}