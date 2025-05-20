//FormAI DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>

void print_menu() {
    printf("\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Kilometers to Miles\n");
    printf("4. Convert Miles to Kilometers\n");
    printf("5. Exit\n");
    printf("\n");
}

void celsius_to_fahrenheit() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

void fahrenheit_to_celsius() {
    float celsius, fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
}

void kilometers_to_miles() {
    float kilometers, miles;
    printf("Enter distance in kilometers: ");
    scanf("%f", &kilometers);
    miles = kilometers * 0.621371;
    printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, miles);
}

void miles_to_kilometers() {
    float kilometers, miles;
    printf("Enter distance in miles: ");
    scanf("%f", &miles);
    kilometers = miles * 1.60934;
    printf("%.2f miles is equal to %.2f kilometers.\n", miles, kilometers);
}

int main() {
    int option;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1: celsius_to_fahrenheit(); break;
            case 2: fahrenheit_to_celsius(); break;
            case 3: kilometers_to_miles(); break;
            case 4: miles_to_kilometers(); break;
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid option! Try again.\n");
        }
    } while (option != 5);

    return 0;
}