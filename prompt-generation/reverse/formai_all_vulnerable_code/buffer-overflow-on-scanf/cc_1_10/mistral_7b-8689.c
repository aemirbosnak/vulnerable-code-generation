//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperature {
    float celcius;
    float fahrenheit;
} Temperature;

void print_menu() {
    printf("\n--- Temperature Converter Menu ---\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

void celsius_to_fahrenheit(Temperature *temp) {
    temp->fahrenheit = (temp->celcius * 9.0 / 5.0) + 32.0;
}

void fahrenheit_to_celsius(Temperature *temp) {
    temp->celcius = (temp->fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    int choice;
    Temperature temp;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temp.celcius);
                celsius_to_fahrenheit(&temp);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp.celcius, temp.fahrenheit);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temp.fahrenheit);
                fahrenheit_to_celsius(&temp);
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temp.fahrenheit, temp.celcius);
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid option, please try again.\n");
        }
    } while (1);

    return 0;
}