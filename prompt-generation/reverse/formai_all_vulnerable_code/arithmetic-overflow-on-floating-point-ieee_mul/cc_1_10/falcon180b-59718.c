//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int main() {
    char choice;
    double celsius, fahrenheit;

    printf("Welcome to the Happy Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("C) Convert from Celsius to Fahrenheit\n");
    printf("F) Convert from Fahrenheit to Celsius\n");
    printf("Q) Quit program\n");

    choice = getchar();

    switch(choice) {
        case 'C':
        case 'c':
            printf("Enter temperature in Celsius: ");
            if (scanf("%lf", &celsius)!= 1) {
                printf("Invalid input. Please try again.\n");
                return 0;
            }
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
            break;
        case 'F':
        case 'f':
            printf("Enter temperature in Fahrenheit: ");
            if (scanf("%lf", &fahrenheit)!= 1) {
                printf("Invalid input. Please try again.\n");
                return 0;
            }
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
            break;
        case 'Q':
        case 'q':
            printf("Thanks for using the Happy Temperature Converter! Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            return 0;
    }

    return 0;
}