//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;
    int valid_input = 0;
    do {
        printf("Enter temperature type (C/F/K): ");
        scanf("%c", &choice);
        switch(choice) {
            case 'C':
                printf("Enter temperature in Celsius: ");
                if(scanf("%lf", &celsius) == 1) {
                    valid_input = 1;
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 'F':
                printf("Enter temperature in Fahrenheit: ");
                if(scanf("%lf", &fahrenheit) == 1) {
                    valid_input = 1;
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 'K':
                printf("Enter temperature in Kelvin: ");
                if(scanf("%lf", &kelvin) == 1) {
                    valid_input = 1;
                } else {
                    printf("Invalid input.\n");
                }
                break;
            default:
                printf("Invalid input.\n");
        }
    } while(!valid_input);

    switch(choice) {
        case 'C':
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit and %.2lf Kelvin.\n", celsius, celsius * 9/5 + 32, celsius + 273.15);
            break;
        case 'F':
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius and %.2lf Kelvin.\n", fahrenheit, (fahrenheit - 32) * 5/9, fahrenheit + 459.67);
            break;
        case 'K':
            printf("%.2lf Kelvin is equal to %.2lf degrees Celsius and %.2lf degrees Fahrenheit.\n", kelvin, kelvin - 273.15, kelvin * 9/5 - 459.67);
            break;
    }

    return 0;
}