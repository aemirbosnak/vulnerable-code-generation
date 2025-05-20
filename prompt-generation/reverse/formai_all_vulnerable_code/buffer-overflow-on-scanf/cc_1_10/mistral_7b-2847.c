//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define F_TO_C_INTERVAL 1.8
#define C_TO_F_INTERVAL 32

void temperatureConverter(float temperature, int conversionType) {
    if (conversionType == 1) {
        float celsius = temperature * F_TO_C_INTERVAL;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, celsius);
    } else if (conversionType == 2) {
        float fahrenheit = temperature * C_TO_F_INTERVAL + C_TO_F_INTERVAL;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, fahrenheit);
    } else {
        printf("Invalid conversion type. Please enter either 1 for Fahrenheit to Celsius or 2 for Celsius to Fahrenheit.\n");
    }
}

void displayArt() {
    printf("\n*************************************************\n");
    printf("*                                               *\n");
    printf("* Welcome to Temperature Converter!               *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("* 1. Fahrenheit to Celsius                       *\n");
    printf("* 2. Celsius to Fahrenheit                       *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
}

int main() {
    int choice, validInput = 0;
    float temperature;

    srand(time(NULL));

    system("clear"); // Linux/MacOS
    //system("cls"); // Windows

    displayArt();

    while (!validInput) {
        printf("Enter the conversion type (1/2): ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            validInput = 1;
        } else {
            printf("Invalid input. Please enter either 1 or 2.\n");
            printf("Try again: ");
            fflush(stdin);
        }
    }

    printf("Enter the temperature value: ");
    scanf("%f", &temperature);

    temperatureConverter(temperature, choice);

    return 0;
}