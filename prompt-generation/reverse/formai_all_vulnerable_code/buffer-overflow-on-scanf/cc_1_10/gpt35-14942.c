//FormAI DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>

/* Function prototypes */
void print_menu();
float convert_c_to_f(float celsius);
float convert_c_to_k(float celsius);
float convert_f_to_c(float fahrenheit);
float convert_f_to_k(float fahrenheit);
float convert_k_to_c(float kelvin);
float convert_k_to_f(float kelvin);

int main() {
    /* Variables to store user input */
    int choice;
    float temperature, result;

    /* Print menu and prompt user */
    printf("--- UNIT CONVERTER ---\n");
    print_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* Prompt user for temperature */
    printf("Enter temperature: ");
    scanf("%f", &temperature);

    /* Perform conversion based on user choice */
    switch (choice) {
        case 1:
            result = convert_c_to_f(temperature);
            printf("%.2fC = %.2fF\n", temperature, result);
            break;
        case 2:
            result = convert_c_to_k(temperature);
            printf("%.2fC = %.2fK\n", temperature, result);
            break;
        case 3:
            result = convert_f_to_c(temperature);
            printf("%.2fF = %.2fC\n", temperature, result);
            break;
        case 4:
            result = convert_f_to_k(temperature);
            printf("%.2fF = %.2fK\n", temperature, result);
            break;
        case 5:
            result = convert_k_to_c(temperature);
            printf("%.2fK = %.2fC\n", temperature, result);
            break;
        case 6:
            result = convert_k_to_f(temperature);
            printf("%.2fK = %.2fF\n", temperature, result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

/* Function to print menu */
void print_menu() {
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
}

/* Function to convert Celsius to Fahrenheit */
float convert_c_to_f(float celsius) {
    return (celsius * 1.8) + 32;
}

/* Function to convert Celsius to Kelvin */
float convert_c_to_k(float celsius) {
    return celsius + 273.15;
}

/* Function to convert Fahrenheit to Celsius */
float convert_f_to_c(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

/* Function to convert Fahrenheit to Kelvin */
float convert_f_to_k(float fahrenheit) {
    return (fahrenheit - 32) / 1.8 + 273.15;
}

/* Function to convert Kelvin to Celsius */
float convert_k_to_c(float kelvin) {
    return kelvin - 273.15;
}

/* Function to convert Kelvin to Fahrenheit */
float convert_k_to_f(float kelvin) {
    return (kelvin - 273.15) * 1.8 + 32;
}