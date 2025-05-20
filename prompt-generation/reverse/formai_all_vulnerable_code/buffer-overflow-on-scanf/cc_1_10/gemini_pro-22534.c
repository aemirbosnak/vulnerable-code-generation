//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>
#define MIN_TEMP -273.15
#define MAX_TEMP 5778
#define TEMP_INCREMENT 0.1

// Function to check if the temperature is within the valid range.
int is_valid_temp(double temp) {
    return temp >= MIN_TEMP && temp <= MAX_TEMP;
}

// Function to convert Celsius to Fahrenheit.
double celsius_to_fahrenheit(double temp) {
    return (temp * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius.
double fahrenheit_to_celsius(double temp) {
    return (temp - 32) / 1.8;
}

// Function to print the temperature conversion table.
void print_conversion_table(double start_temp, double end_temp, double increment) {
    printf("Celsius\tFahrenheit\n");
    for (double temp = start_temp; temp <= end_temp; temp += increment) {
        printf("%.1f\t%.1f\n", temp, celsius_to_fahrenheit(temp));
    }
}

// Main function.
int main() {
    // Get the starting temperature from the user.
    printf("Enter the starting temperature in Celsius: ");
    double start_temp;
    scanf("%lf", &start_temp);

    // Get the ending temperature from the user.
    printf("Enter the ending temperature in Celsius: ");
    double end_temp;
    scanf("%lf", &end_temp);

    // Get the temperature increment from the user.
    printf("Enter the temperature increment: ");
    double increment;
    scanf("%lf", &increment);

    // Check if the temperatures are valid.
    if (!is_valid_temp(start_temp) || !is_valid_temp(end_temp)) {
        printf("Error: Invalid temperature.\n");
        return 1;
    }

    // Check if the increment is valid.
    if (increment <= 0) {
        printf("Error: Invalid temperature increment.\n");
        return 1;
    }

    // Print the temperature conversion table.
    print_conversion_table(start_temp, end_temp, increment);

    return 0;
}