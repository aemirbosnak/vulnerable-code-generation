//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>

void display_welcome_message() {
    printf("***********************************************\n");
    printf("*                                             *\n");
    printf("*           WELCOME TO TEMP CONVERTER        *\n");
    printf("*                                             *\n");
    printf("***********************************************\n");
    printf("\n");
    printf("This program helps you convert temperatures\n");
    printf("between Celsius and Fahrenheit.\n");
    printf("Please follow the prompts to make your choice.\n");
    printf("\n");
}

void display_instructions() {
    printf("Instructions:\n");
    printf("1. Enter 'C' to convert from Celsius to Fahrenheit.\n");
    printf("2. Enter 'F' to convert from Fahrenheit to Celsius.\n");
    printf("3. Enter 'Q' to quit the program.\n");
    printf("Please choose your option: ");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void convert_temperature() {
    char choice;
    float input_temp, output_temp;
    
    while (1) {
        display_instructions();
        scanf(" %c", &choice); // Added space before %c to consume any newline characters
        
        if (choice == 'C' || choice == 'c') {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input_temp);
            output_temp = celsius_to_fahrenheit(input_temp);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n\n", input_temp, output_temp);
        } 
        else if (choice == 'F' || choice == 'f') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input_temp);
            output_temp = fahrenheit_to_celsius(input_temp);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n\n", input_temp, output_temp);
        } 
        else if (choice == 'Q' || choice == 'q') {
            printf("Thank you for using the Temp Converter!\n");
            break;
        } 
        else {
            printf("Invalid choice! Please enter C, F, or Q.\n\n");
        }
    }
}

int main() {
    display_welcome_message();
    convert_temperature();
    
    printf("***********************************************\n");
    printf("*                                             *\n");
    printf("*          GOODBYE AND STAY WARM!            *\n");
    printf("*                                             *\n");
    printf("***********************************************\n");

    return 0;
}