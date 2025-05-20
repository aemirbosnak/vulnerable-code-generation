//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char input[50];
    double celsius;
    double fahrenheit;
    int choice;
} data;

void convert_celsius(data *d) {
    d->fahrenheit = (d->celsius * 9 / 5) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n\n", d->celsius, d->fahrenheit);
}

void convert_fahrenheit(data *d) {
    d->celsius = (d->fahrenheit - 32) * 5 / 9;
    printf("%.2f Fahrenheit is equal to %.2f Celsius.\n\n", d->fahrenheit, d->celsius);
}

int main() {
    data d;
    char choice;
    do {
        printf("Enter the temperature in Celsius or Fahrenheit: ");
        scanf("%s", d.input);
        if (isdigit(d.input[0])) {
            d.celsius = atof(d.input);
            printf("You have entered %s.\n", d.input);
            printf("Select the conversion type:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
            scanf(" %c", &choice);
            switch (choice) {
                case '1':
                    convert_celsius(&d);
                    break;
                case '2':
                    convert_fahrenheit(&d);
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        } else {
            printf("Invalid input. Please enter a number.\n");
        }
    } while (TRUE);
    return 0;
}