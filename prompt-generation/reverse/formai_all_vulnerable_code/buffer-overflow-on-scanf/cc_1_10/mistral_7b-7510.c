//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

void convertFtoC(float fahrenheit) {
    float celsius;
    celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);
}

void convertCtoF(float celsius) {
    float fahrenheit;
    fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

int main() {
    char inputStr[MAX_INPUT_SIZE];
    float fahrenheit, celsius;
    int choice;

    do {
        printf("\n1. Convert Fahrenheit to Celsius\n");
        printf("2. Convert Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                convertFtoC(fahrenheit);
                break;

            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);
                convertCtoF(celsius);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while(1);

    return 0;
}