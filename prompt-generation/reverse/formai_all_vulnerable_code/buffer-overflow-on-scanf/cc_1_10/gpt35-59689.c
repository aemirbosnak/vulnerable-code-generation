//FormAI DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

/* Function to convert Celsius to Fahrenheit */
float convert_c_to_f(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

/* Function to convert Fahrenheit to Celsius */
float convert_f_to_c(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

/* Function to convert Kelvin to Celsius */
float convert_k_to_c(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

/* Function to convert Celsius to Kelvin */
float convert_c_to_k(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

/* Function to convert Kelvin to Fahrenheit */
float convert_k_to_f(float kelvin) {
    float fahrenheit = ((kelvin - 273.15) * 9/5) + 32;
    return fahrenheit;
}

/* Function to convert Fahrenheit to Kelvin */
float convert_f_to_k(float fahrenheit) {
    float kelvin = ((fahrenheit - 32) * 5/9) + 273.15;
    return kelvin;
}

/* Main function */
int main() {
    int choice;
    float value, result;
    printf("Welcome to the C Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Kelvin to Celsius\n4. Celsius to Kelvin\n5. Kelvin to Fahrenheit\n6. Fahrenheit to Kelvin\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            result = convert_c_to_f(value);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", value, result);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            result = convert_f_to_c(value);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", value, result);
            break;
        case 3:
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &value);
            result = convert_k_to_c(value);
            printf("%.2f Kelvin is equal to %.2f Celsius.\n", value, result);
            break;
        case 4:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            result = convert_c_to_k(value);
            printf("%.2f Celsius is equal to %.2f Kelvin.\n", value, result);
            break;
        case 5:
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &value);
            result = convert_k_to_f(value);
            printf("%.2f Kelvin is equal to %.2f Fahrenheit.\n", value, result);
            break;
        case 6:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            result = convert_f_to_k(value);
            printf("%.2f Fahrenheit is equal to %.2f Kelvin.\n", value, result);
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
    }

    return 0;
}