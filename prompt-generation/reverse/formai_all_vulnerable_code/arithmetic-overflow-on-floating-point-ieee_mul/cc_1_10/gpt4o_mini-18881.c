//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

// Function that converts Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit;
    // Apply the conversion formula
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

// Function that converts Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    double celsius;
    // Apply the conversion formula
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

// Function that displays the conversion menu to the user
void display_menu() {
    printf("Temperature Converter\n");
    printf("=====================\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("=====================\n");
}

// Function that handles the conversion operation based on user choice
void convert_temperature(int choice) {
    double input_temp, converted_temp;
    
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &input_temp);
        converted_temp = celsius_to_fahrenheit(input_temp);
        printf("%.2f Celsius is equal to %.2f Fahrenheit\n", input_temp, converted_temp);
    } 
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &input_temp);
        converted_temp = fahrenheit_to_celsius(input_temp);
        printf("%.2f Fahrenheit is equal to %.2f Celsius\n", input_temp, converted_temp);
    } 
    else {
        printf("Invalid choice. Please select 1 or 2.\n");
    }
}

// Main function to execute the program logic
int main() {
    int user_choice;

    // Loop until the user decides to exit
    do {
        display_menu();
        printf("Please enter your choice (1-3): ");
        scanf("%d", &user_choice);
        
        // Check if user wants to exit
        if (user_choice == 3) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        // Convert temperature based on user input
        convert_temperature(user_choice);
        
    } while (user_choice != 3);  // This condition allows us to repeat until exit option is selected.

    return 0;  // End of the program
}