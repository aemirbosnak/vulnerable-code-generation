//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * (5.0/9.0);
    return celsius;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * (9.0/5.0)) + 32;
    return fahrenheit;
}

// Function to convert Miles to Kilometers
float miles_to_kilometers(float miles) {
    float kilometers = miles * 1.60934;
    return kilometers;
}

// Function to convert Kilometers to Miles
float kilometers_to_miles(float kilometers) {
    float miles = kilometers / 1.60934;
    return miles;
}

// Function to print the menu
void print_menu() {
    printf("\n-------------------------\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("-------------------------\n");
}

int main() {
    int choice;
    float input_value, output_value;
    
    printf("Welcome to the Unit Converter!\n");
    
    do {
        // Print the menu
        print_menu();
        
        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Get the input value from the user
        printf("Enter the value to convert: ");
        scanf("%f", &input_value);
        
        // Convert based on the user's choice
        switch(choice) {
            case 1:
                output_value = fahrenheit_to_celsius(input_value);
                printf("%f Fahrenheit is equal to %f Celsius.\n", input_value, output_value);
                break;
            case 2:
                output_value = celsius_to_fahrenheit(input_value);
                printf("%f Celsius is equal to %f Fahrenheit.\n", input_value, output_value);
                break;
            case 3:
                output_value = miles_to_kilometers(input_value);
                printf("%f Miles is equal to %f Kilometers.\n", input_value, output_value);
                break;
            case 4:
                output_value = kilometers_to_miles(input_value);
                printf("%f Kilometers is equal to %f Miles.\n", input_value, output_value);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    } while(choice != 0);
    
    printf("Thanks for using the Unit Converter!\n");
    
    return 0;
}