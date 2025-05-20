//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

void convertFtoC(float);
void convertCtoF(float);

void printMenu() {
    printf("\nTemperature Conversion Menu:\n");
    printf("-----------------------------\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}

int main() {
    char choice;
    float fahrenheit, celsius;

    do {
        printMenu();
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                convertFtoC(fahrenheit);
                break;
            case '2':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);
                convertCtoF(celsius);
                break;
            case '3':
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
                break;
        }

    } while (choice != '3');

    return 0;
}

void convertFtoC(float f) {
    float c;

    c = (f - 32) * 5.0 / 9.0;

    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", f, c);
}

void convertCtoF(float c) {
    float f;

    f = c * 9.0 / 5.0 + 32;

    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", c, f);
}