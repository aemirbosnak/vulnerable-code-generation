//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double num, result;
    char unit[2];
    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a number followed by its unit (C/F): ");
    scanf("%lf %s", &num, unit);
    printf("You entered %.2lf %s.\n", num, unit);
    printf("Please choose an option:\n");
    printf("1. Convert from Celsius to Fahrenheit.\n");
    printf("2. Convert from Fahrenheit to Celsius.\n");
    printf("3. Convert from Celsius to Kelvin.\n");
    printf("4. Convert from Kelvin to Celsius.\n");
    printf("5. Convert from Fahrenheit to Kelvin.\n");
    printf("6. Convert from Kelvin to Fahrenheit.\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            result = (num * 9/5) + 32;
            printf("%.2lf %s is %.2lf F.\n", num, unit, result);
            break;
        case 2:
            result = (num - 32) * 5/9;
            printf("%.2lf F is %.2lf %s.\n", num, result, "C");
            break;
        case 3:
            result = num + 273.15;
            printf("%.2lf %s is %.2lf K.\n", num, unit, result);
            break;
        case 4:
            result = num - 273.15;
            printf("%.2lf K is %.2lf %s.\n", num, result, "C");
            break;
        case 5:
            result = (num + 459.67) * 5/9;
            printf("%.2lf F is %.2lf K.\n", num, result);
            break;
        case 6:
            result = (num - 273.15) * 9/5 + 32;
            printf("%.2lf K is %.2lf F.\n", num, result);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    return 0;
}