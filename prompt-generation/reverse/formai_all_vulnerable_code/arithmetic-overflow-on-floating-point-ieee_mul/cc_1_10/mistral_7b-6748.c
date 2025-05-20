//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct Temperature {
    float celcius;
    float fahrenheit;
} Temperature;

void CelciusToFahrenheit(Temperature* temp) {
    temp->fahrenheit = (temp->celcius * 9 / 5) + 32;
}

void FahrenheitToCelcius(Temperature* temp) {
    temp->celcius = (temp->fahrenheit - 32) * 5 / 9;
}

int main() {
    Temperature temp;
    char choice;

    printf("\n\t---------------------------------------------\n");
    printf("\t|           Futuristic Temperature Converter  |\n");
    printf("\t|                                            |\n");
    printf("\t|  This program converts temperature between  |\n");
    printf("\t|  Celcius and Fahrenheit in a futuristic way  |\n");
    printf("\t|                                            |\n");
    printf("\t|  Developed by: AI Developer X-23             |\n");
    printf("\t---------------------------------------------\n\n");

    do {
        printf("\n\tEnter C for Celcius to Fahrenheit conversion: ");
        scanf(" %c", &choice);

        if (choice != 'C') {
            printf("\n\tEnter F for Fahrenheit to Celcius conversion: ");
            scanf(" %c", &choice);
        }

        if (choice == 'C') {
            printf("\n\tEnter Celcius: ");
            scanf("%f", &temp.celcius);
            CelciusToFahrenheit(&temp);
            printf("\n\t%0.2f Celcius is equal to %0.2f Fahrenheit.\n", temp.celcius, temp.fahrenheit);
        }

        if (choice == 'F') {
            printf("\n\tEnter Fahrenheit: ");
            scanf("%f", &temp.fahrenheit);
            FahrenheitToCelcius(&temp);
            printf("\n\t%0.2f Fahrenheit is equal to %0.2f Celcius.\n", temp.fahrenheit, temp.celcius);
        }

        printf("\n\tDo you want to perform another conversion? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice != 'N');

    return 0;
}