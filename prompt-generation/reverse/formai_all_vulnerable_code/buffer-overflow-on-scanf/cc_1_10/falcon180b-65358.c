//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// function prototypes
int is_valid_input(char *input);
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main() {
    char input[50];
    int choice;
    double temperature;

    srand(time(NULL));
    printf("Welcome to the Temperature Converter!\n");
    printf("Enter the temperature you want to convert (e.g. 25 C): ");
    scanf("%s", input);

    while (!is_valid_input(input)) {
        printf("Invalid input! Please enter the temperature in the format 'XX C' or 'XX F' (e.g. 25 C): ");
        scanf("%s", input);
    }

    temperature = atof(input);

    printf("Enter 1 to convert from Celsius to Fahrenheit or 2 to convert from Fahrenheit to Celsius: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%.2lf C = %.2lf F\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("%.2lf F = %.2lf C\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

int is_valid_input(char *input) {
    int i, j;
    int is_celsius = FALSE;
    int is_fahrenheit = FALSE;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 'C' || input[i] == 'c') {
            is_celsius = TRUE;
        } else if (input[i] == 'F' || input[i] == 'f') {
            is_fahrenheit = TRUE;
        }
    }

    if (is_celsius && is_fahrenheit) {
        return FALSE;
    } else if (!is_celsius &&!is_fahrenheit) {
        return FALSE;
    } else {
        return TRUE;
    }
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}