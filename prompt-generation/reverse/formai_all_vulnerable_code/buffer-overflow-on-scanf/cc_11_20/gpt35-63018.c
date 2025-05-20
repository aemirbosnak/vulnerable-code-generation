//FormAI DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    float temp, converted;
    char scale1, scale2;

    printf("Welcome to the Temperature Converter program!\n");
    printf("Please enter the temperature value: ");
    scanf("%f", &temp);

    printf("Please enter the temperature scale (F/C/K): ");
    scanf(" %c", &scale1);

    if (scale1 == 'F' || scale1 == 'f') {
        printf("You entered %.2f degrees Fahrenheit.\n", temp);
        printf("Which temperature scale would you like to convert to (C/K)? ");
        scanf(" %c", &scale2);

        if (scale2 == 'C' || scale2 == 'c') {
            converted = (temp - 32) * 5 / 9;
            printf("%.2f degrees Fahrenheit is equivalent to %.2f degrees Celsius.\n", temp, converted);
        }
        else if (scale2 == 'K' || scale2 == 'k') {
            converted = (temp - 32) * 5 / 9 + 273.15;
            printf("%.2f degrees Fahrenheit is equivalent to %.2f degrees Kelvin.\n", temp, converted);
        }
        else {
            printf("Invalid input, please try again.\n");
        }
    }
    else if (scale1 == 'C' || scale1 == 'c') {
        printf("You entered %.2f degrees Celsius.\n", temp);
        printf("Which temperature scale would you like to convert to (F/K)? ");
        scanf(" %c", &scale2);

        if (scale2 == 'F' || scale2 == 'f') {
            converted = (temp * 9 / 5) + 32;
            printf("%.2f degrees Celsius is equivalent to %.2f degrees Fahrenheit.\n", temp, converted);
        }
        else if (scale2 == 'K' || scale2 == 'k') {
            converted = temp + 273.15;
            printf("%.2f degrees Celsius is equivalent to %.2f degrees Kelvin.\n", temp, converted);
        }
        else {
            printf("Invalid input, please try again.\n");
        }
    }
    else if (scale1 == 'K' || scale1 == 'k') {
        printf("You entered %.2f degrees Kelvin.\n", temp);
        printf("Which temperature scale would you like to convert to (F/C)? ");
        scanf(" %c", &scale2);

        if (scale2 == 'F' || scale2 == 'f') {
            converted = (temp - 273.15) * 9 / 5 + 32;
            printf("%.2f degrees Kelvin is equivalent to %.2f degrees Fahrenheit.\n", temp, converted);
        }
        else if (scale2 == 'C' || scale2 == 'c') {
            converted = temp - 273.15;
            printf("%.2f degrees Kelvin is equivalent to %.2f degrees Celsius.\n", temp, converted);
        }
        else {
            printf("Invalid input, please try again.\n");
        }
    }
    else {
        printf("Invalid input, please try again.\n");
    }

    printf("Thank you for using the Temperature Converter program!\n");
    return 0;
}