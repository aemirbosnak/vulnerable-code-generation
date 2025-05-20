//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100
#define TEMP_UNITS 2

// Enum for temperature units
typedef enum {
    CELSIUS = 0,
    FAHRENHEIT = 1
} TemperatureUnit;

// Function prototypes
void display_menu();
void convert_temperature();
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
void input_handler(char *buffer, int size);
void clear_input_buffer();

int main() {
    int choice;

    do {
        display_menu();
        input_handler((char *) &choice, sizeof(choice));

        switch (choice) {
            case 1:
                convert_temperature();
                break;
            case 2:
                printf("Exiting the Temperature Converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

void display_menu() {
    printf("\n=========================\n");
    printf("     Temperature Menu    \n");
    printf("=========================\n");
    printf("1. Convert Temperature\n");
    printf("2. Exit\n");
    printf("Please enter your choice: ");
}

void convert_temperature() {
    char input_buffer[MAX_INPUT_LENGTH];
    float input_temp;
    int unit_choice;

    printf("Choose the temperature unit to convert from:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("Enter your choice (1/2): ");
    input_handler(input_buffer, sizeof(input_buffer));
    unit_choice = atoi(input_buffer);

    if (unit_choice < 1 || unit_choice > TEMP_UNITS) {
        printf("Invalid unit choice. Returning to main menu.\n");
        return;
    }

    printf("Enter the temperature value to convert: ");
    input_handler(input_buffer, sizeof(input_buffer));
    input_temp = atof(input_buffer);

    if (unit_choice == CELSIUS) {
        float converted_temp = celsius_to_fahrenheit(input_temp);
        printf("%.2f Celsius is %.2f Fahrenheit\n", input_temp, converted_temp);
    } else {
        float converted_temp = fahrenheit_to_celsius(input_temp);
        printf("%.2f Fahrenheit is %.2f Celsius\n", input_temp, converted_temp);
    }
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void input_handler(char *buffer, int size) {
    fgets(buffer, size, stdin);
    clear_input_buffer();  // Clear any additional characters in the input buffer
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Discard the rest of the input buffer
}