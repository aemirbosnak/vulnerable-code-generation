//FormAI DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void print_menu();  // Function to print menu
void celsius_to_fahrenheit();  // Function to convert Celsius to Fahrenheit
void fahrenheit_to_celsius();  // Function to convert Fahrenheit to Celsius
void meters_to_feet();  // Function to convert Meters to Feet
void feet_to_meters();  // Function to convert Feet to Meters

int main()
{
    int choice; // Variable to store user's choice from menu
    
    do{
        print_menu();  // Call function to print menu
        scanf("%d", &choice);  // Take user's choice as input
        
        switch(choice)
        {
            case 1:
                celsius_to_fahrenheit();  // Call function to convert Celsius to Fahrenheit
                break;
            case 2:
                fahrenheit_to_celsius();  // Call function to convert Fahrenheit to Celsius
                break;
            case 3:
                meters_to_feet();  // Call function to convert Meters to Feet
                break;
            case 4:
                feet_to_meters();  // Call function to convert Feet to Meters
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
        
    } while(choice != 5);  // Continue until user chooses to exit
    
    return 0;
}

// Function to print menu
void print_menu()
{
    printf("\nUNIT CONVERTER\n");
    printf("------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to convert Celsius to Fahrenheit
void celsius_to_fahrenheit()
{
    float celsius, fahrenheit;
    
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 1.8) + 32; // Formula for Celsius to Fahrenheit conversion
    
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void fahrenheit_to_celsius()
{
    float celsius, fahrenheit;
    
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    
    celsius = (fahrenheit - 32) / 1.8; // Formula for Fahrenheit to Celsius conversion
    
    printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
}

// Function to convert Meters to Feet
void meters_to_feet()
{
    float meters, feet;
    
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    
    feet = meters * 3.281; // Formula for Meters to Feet conversion
    
    printf("%.2f meters = %.2f feet\n", meters, feet);
}

// Function to convert Feet to Meters
void feet_to_meters()
{
    float meters, feet;
    
    printf("Enter length in feet: ");
    scanf("%f", &feet);
    
    meters = feet / 3.281; // Formula for Feet to Meters conversion
    
    printf("%.2f feet = %.2f meters\n", feet, meters);
}