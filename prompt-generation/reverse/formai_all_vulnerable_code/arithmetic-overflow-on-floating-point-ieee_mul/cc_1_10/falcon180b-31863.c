//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if a string is a valid temperature
int is_temp(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double c) {
    return (c * 9.0/5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double f) {
    return (f - 32.0) * 5.0/9.0;
}

// Function to get a valid input from the user
void get_input(char* input) {
    while (!is_temp(input)) {
        printf("Invalid input. Please enter a valid temperature:\n");
        scanf("%s", input);
    }
}

// Function to get a unit from the user
void get_unit(char* unit) {
    printf("Enter the unit of the temperature (C or F):\n");
    scanf(" %c", &unit[0]);
    unit[1] = '\0';
    while (unit[0]!= 'C' && unit[0]!= 'F') {
        printf("Invalid unit. Please enter C or F:\n");
        scanf(" %c", &unit[0]);
        unit[1] = '\0';
    }
}

// Function to convert the temperature and print the result
void convert_temp(double temp, char* unit) {
    switch (unit[0]) {
        case 'C':
            printf("%.2f C = %.2f F\n", temp, celsius_to_fahrenheit(temp));
            break;
        case 'F':
            printf("%.2f F = %.2f C\n", temp, fahrenheit_to_celsius(temp));
            break;
        default:
            printf("Invalid unit.\n");
            break;
    }
}

int main() {
    char input[20];
    char unit[3];

    printf("Welcome to the Medieval Temperature Converter!\n");
    printf("Enter a temperature and its unit to convert it:\n");

    get_input(input);
    get_unit(unit);

    double temp = atof(input);
    convert_temp(temp, unit);

    return 0;
}