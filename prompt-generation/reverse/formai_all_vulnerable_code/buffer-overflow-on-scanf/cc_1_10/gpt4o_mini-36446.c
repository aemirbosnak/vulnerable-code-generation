//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: grateful
#include <stdio.h>

void print_welcome_message() {
    printf("*****************************************\n");
    printf("*           Welcome to Temperature      *\n");
    printf("*           Converter with Gratitude    *\n");
    printf("*****************************************\n\n");
    printf("Thank you for using this program! It's a pleasure to assist you.\n\n");
}

void print_options() {
    printf("Please choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit the program\n");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void perform_conversion(int choice) {
    float input_temp, converted_temp;
    if (choice == 1) {
        printf("Please enter the temperature in Celsius: ");
        scanf("%f", &input_temp);
        converted_temp = celsius_to_fahrenheit(input_temp);
        printf("Thank you for the input! %.2f Celsius is equal to %.2f Fahrenheit.\n", input_temp, converted_temp);
    } else if (choice == 2) {
        printf("Please enter the temperature in Fahrenheit: ");
        scanf("%f", &input_temp);
        converted_temp = fahrenheit_to_celsius(input_temp);
        printf("Thank you for the input! %.2f Fahrenheit is equal to %.2f Celsius.\n", input_temp, converted_temp);
    } else {
        printf("Invalid choice! Your feedback is appreciated.\n");
    }
}

int main() {
    int choice;
    
    print_welcome_message();

    while (1) {
        print_options();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Thank you for using the Temperature Converter!\n");
            printf("Your presence brightens this program. Goodbye!\n");
            break; // Exit the loop and terminate the program
        }

        perform_conversion(choice);

        printf("\nWould you like to convert another temperature? (1 for Yes, 0 for No): ");
        int continue_choice;
        scanf("%d", &continue_choice);
        if (continue_choice == 0) {
            printf("Thank you for your time! We hope to see you again!\n");
            break; // Exit the loop and terminate the program
        }
    }

    return 0;
}