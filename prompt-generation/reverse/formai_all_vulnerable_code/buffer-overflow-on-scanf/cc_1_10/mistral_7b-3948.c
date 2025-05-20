//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Temperature {
    double fahrenheit;
    double celsius;
} Temp;

void fahrenheitToCelsius(Temp* temp) {
    temp->celsius = (temp->fahrenheit - 32) * 5 / 9;
}

void celsiusToFahrenheit(Temp* temp) {
    temp->fahrenheit = temp->celsius * 9 / 5 + 32;
}

void printTemp(Temp temp) {
    printf("Temperature:\n");
    printf("------------------\n");
    printf("Fahrenheit: %.2f\n", temp.fahrenheit);
    printf("Celsius: %.2f\n", temp.celsius);
}

int main(void) {
    char choice;
    Temp temp;

    do {
        system("clear");
        printf("Welcome to Temperature Converter!\n");
        printf("Enter F for Fahrenheit to Celsius conversion or C for Celsius to Fahrenheit conversion: ");
        scanf("%c", &choice);

        if (choice == 'F' || choice == 'f') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temp.fahrenheit);
            fahrenheitToCelsius(&temp);
        } else if (choice == 'C' || choice == 'c') {
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temp.celsius);
            celsiusToFahrenheit(&temp);
        } else {
            printf("Invalid input. Please enter F or C.\n");
        }

        printTemp(temp);
        printf("\nPress any key to continue...");
        getchar();
    } while (1);

    return 0;
}