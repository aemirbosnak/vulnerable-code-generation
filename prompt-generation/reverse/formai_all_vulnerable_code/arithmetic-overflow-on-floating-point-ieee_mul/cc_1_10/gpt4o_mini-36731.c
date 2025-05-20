//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: interoperable
#include <stdio.h>

#define KELVIN_OFFSET 273.15

// Function declarations
void display_menu();
void convert_temperature();
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double celsius_to_kelvin(double celsius);
double kelvin_to_celsius(double kelvin);
double fahrenheit_to_kelvin(double fahrenheit);
double kelvin_to_fahrenheit(double kelvin);

int main() {
    char choice;
    
    do {
        display_menu();
        printf("Choose an option (1-5) or 'q' to quit: ");
        choice = getchar();
        getchar(); // To consume the newline character

        switch(choice) {
            case '1':
                convert_temperature();
                break;
            case '2':
                printf("Thank you for using the Temperature Converter!\n");
                break;
            case 'q':
            case 'Q':
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 'q' && choice != 'Q');
    
    return 0;
}

void display_menu() {
    printf("\n---- Temperature Converter ----\n");
    printf("1. Convert Temperature\n");
    printf("2. Exit\n");
    printf("------------------------------\n");
}

void convert_temperature() {
    int from, to;
    double input_temp, converted_temp;

    printf("Select the temperature unit you want to convert from:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &from);
    
    printf("Select the temperature unit you want to convert to:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &to);
    
    printf("Enter the temperature you want to convert: ");
    scanf("%lf", &input_temp);
    
    switch(from) {
        case 1: // Celsius
            if (to == 1) {
                converted_temp = input_temp; // Celsius to Celsius
            } else if (to == 2) {
                converted_temp = celsius_to_fahrenheit(input_temp);
            } else if (to == 3) {
                converted_temp = celsius_to_kelvin(input_temp);
            }
            break;
        case 2: // Fahrenheit
            if (to == 1) {
                converted_temp = fahrenheit_to_celsius(input_temp);
            } else if (to == 2) {
                converted_temp = input_temp; // Fahrenheit to Fahrenheit
            } else if (to == 3) {
                converted_temp = fahrenheit_to_kelvin(input_temp);
            }
            break;
        case 3: // Kelvin
            if (to == 1) {
                converted_temp = kelvin_to_celsius(input_temp);
            } else if (to == 2) {
                converted_temp = kelvin_to_fahrenheit(input_temp);
            } else if (to == 3) {
                converted_temp = input_temp; // Kelvin to Kelvin
            }
            break;
        default:
            printf("Invalid temperature unit!\n");
            return;
    }

    printf("Converted temperature: %.2lf\n", converted_temp);
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double celsius_to_kelvin(double celsius) {
    return celsius + KELVIN_OFFSET;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - KELVIN_OFFSET;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

double kelvin_to_fahrenheit(double kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}