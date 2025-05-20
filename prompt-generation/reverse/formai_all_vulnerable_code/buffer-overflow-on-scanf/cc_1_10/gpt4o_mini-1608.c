//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>

// Function prototypes
void display_menu();
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
void perform_conversion(int choice);

int main() {
    int choice;
    printf("\n");
    printf("***************************************\n");
    printf("*                                     *\n");
    printf("*     WELCOME TO THE TEMP CONVERTER   *\n");
    printf("*                                     *\n");
    printf("***************************************\n");
    
    while (1) {
        display_menu();
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);
        
        if (choice == 3) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        } else if (choice < 1 || choice > 3) {
            printf("Invalid choice! Please try again.\n");
        } else {
            perform_conversion(choice);
        }
    }
    
    return 0;
}

// Function to display the conversion menu
void display_menu() {
    printf("\n");
    printf("Choose your conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to perform the conversion based on user's choice
void perform_conversion(int choice) {
    float temperature, converted_temp;
    
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        converted_temp = celsius_to_fahrenheit(temperature);
        printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, converted_temp);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        converted_temp = fahrenheit_to_celsius(temperature);
        printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, converted_temp);
    }
    
    // Additional decorative output
    printf("***************************************\n");
    printf("Thank you for using the Temperature Converter!\n");
    printf("***************************************\n");
}