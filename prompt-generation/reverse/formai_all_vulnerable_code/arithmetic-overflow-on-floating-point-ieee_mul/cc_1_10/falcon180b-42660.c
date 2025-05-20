//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_TEMP 1000

// Function prototypes
int is_valid_temp(double temp);
int celsius_to_fahrenheit(double celsius);
int fahrenheit_to_celsius(double fahrenheit);

int main(void) {
    double temp;
    char choice;

    do {
        // Get temperature input from user
        printf("Enter temperature (Celsius/Fahrenheit): ");
        if (scanf("%lf", &temp)!= 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        // Get temperature unit input from user
        printf("Enter temperature unit (C/F): ");
        scanf(" %c", &choice);

        // Convert temperature based on user input
        if (choice == 'C' || choice == 'c') {
            temp = celsius_to_fahrenheit(temp);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temp, temp);
        } else if (choice == 'F' || choice == 'f') {
            temp = fahrenheit_to_celsius(temp);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temp, temp);
        } else {
            printf("Invalid temperature unit. Please enter C or F.\n");
        }

        // Ask user if they want to continue
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

// Function to check if temperature is valid (between -1000 and 1000)
int is_valid_temp(double temp) {
    if (temp >= -MAX_TEMP && temp <= MAX_TEMP) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// Function to convert Celsius to Fahrenheit
int celsius_to_fahrenheit(double celsius) {
    return (int)((celsius * 9.0) / 5.0 + 32.0);
}

// Function to convert Fahrenheit to Celsius
int fahrenheit_to_celsius(double fahrenheit) {
    return (int)((fahrenheit - 32.0) * 5.0 / 9.0);
}