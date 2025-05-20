//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LEN 100
#define MAX_ERROR_LEN 50

int is_number(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    char input[MAX_LINE_LEN];
    char error[MAX_ERROR_LEN];
    double celsius, fahrenheit;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert:\n");
    fgets(input, MAX_LINE_LEN, stdin);

    if (!is_number(input)) {
        sprintf(error, "Invalid input: %s is not a number.\n", input);
        printf("%s", error);
        exit(1);
    }

    celsius = atof(input);
    printf("Please choose the conversion type:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fahrenheit = celsius_to_fahrenheit(celsius);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
            break;
        case 2:
            fahrenheit = fahrenheit_to_celsius(celsius);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
            break;
        default:
            sprintf(error, "Invalid choice: %d\n", choice);
            printf("%s", error);
            exit(1);
    }

    return 0;
}