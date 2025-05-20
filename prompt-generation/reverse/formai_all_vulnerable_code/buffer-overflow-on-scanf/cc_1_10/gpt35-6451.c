//FormAI DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float c_to_f(float celsius);
float c_to_k(float celsius);
float f_to_c(float fahrenheit);
float k_to_c(float kelvin);
void print_menu();
void clear_input_buffer();

int main()
{
    int choice;
    float value, result;
    char unit;

    do {
        print_menu();
        scanf("%d", &choice);
        clear_input_buffer(); // Clearing input buffer to prevent unwanted inputs

        switch(choice) {
            case 1:
                printf("Enter the Celsius value: ");
                scanf("%f", &value);
                clear_input_buffer();
                printf("Convert to (F)ahrenheit or (K)elvin? ");
                scanf("%c", &unit);
                clear_input_buffer();

                if (unit == 'F') {
                    result = c_to_f(value);
                    printf("%.2f C = %.2f F\n", value, result);
                } else if (unit == 'K') {
                    result = c_to_k(value);
                    printf("%.2f C = %.2f K\n", value, result);
                } else {
                    printf("Invalid unit entered!\n");
                }

                break;
                
            case 2:
                printf("Enter the Fahrenheit value: ");
                scanf("%f", &value);
                clear_input_buffer();
                result = f_to_c(value);
                printf("%.2f F = %.2f C\n", value, result);
                break;

            case 3:
                printf("Enter the Kelvin value: ");
                scanf("%f", &value);
                clear_input_buffer();
                result = k_to_c(value);
                printf("%.2f K = %.2f C\n", value, result);
                break;

            case 4:
                printf("Thank you for using the converter!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice entered!\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to convert Celsius to Fahrenheit
float c_to_f(float celsius)
{
    return (9.0 * celsius / 5.0) + 32.0;
}

// Function to convert Celsius to Kelvin 
float c_to_k(float celsius)
{
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius 
float f_to_c(float fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

// Function to convert Kelvin to Celsius
float k_to_c(float kelvin)
{
    return kelvin - 273.15;
}

// Function to print menu
void print_menu()
{
    printf("Unit Converter\n");
    printf("--------------\n");
    printf("1. Celsius to Fahrenheit or Kelvin\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function to clear input buffer
void clear_input_buffer()
{
    while (getchar() != '\n');
}