//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE    1
#define FALSE   0
#define ERR    -1
#define MAX_LEN 100

/* Function prototypes */
int is_numeric(char *str);
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main() {
    char input[MAX_LEN];
    char *endptr;
    double num;
    int choice;

    printf("Welcome to the Medieval Temperature Converter!\n");
    printf("Please enter your choice:\n");
    printf("1. Convert from Celsius to Fahrenheit\n");
    printf("2. Convert from Fahrenheit to Celsius\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            if (fgets(input, MAX_LEN, stdin) == NULL) {
                printf("Error reading input.\n");
                exit(ERR);
            }
            num = strtod(input, &endptr);
            if (is_numeric(input) == FALSE) {
                printf("Invalid input. Please enter a numeric value.\n");
                exit(ERR);
            }
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", num, celsius_to_fahrenheit(num));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            if (fgets(input, MAX_LEN, stdin) == NULL) {
                printf("Error reading input.\n");
                exit(ERR);
            }
            num = strtod(input, &endptr);
            if (is_numeric(input) == FALSE) {
                printf("Invalid input. Please enter a numeric value.\n");
                exit(ERR);
            }
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", num, fahrenheit_to_celsius(num));
            break;
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            exit(ERR);
    }

    return 0;
}

int is_numeric(char *str) {
    int i;

    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return FALSE;
        }
    }

    return TRUE;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}