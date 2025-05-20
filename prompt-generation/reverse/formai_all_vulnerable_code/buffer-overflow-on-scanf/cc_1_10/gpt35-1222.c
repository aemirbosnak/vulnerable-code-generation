//FormAI DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

void printMenu() {
    printf("\nC Unit Converter");
    printf("\n1. Kilometers to Miles");
    printf("\n2. Miles to Kilometers");
    printf("\n3. Celsius to Fahrenheit");
    printf("\n4. Fahrenheit to Celsius");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
}

void displayResult(float convertedValue, char* fromUnit, char* toUnit) {
    printf("\nConverted value: %.2f %s = %.2f %s", convertedValue, fromUnit, convertedValue, toUnit);
}

void convertKMtoMiles() {
    float kilometers, miles;
    printf("\nEnter the value in kilometers: ");
    scanf("%f", &kilometers);
    miles = kilometers * 0.621371;
    displayResult(kilometers, "km", "mi");
}

void convertMilestoKM() {
    float kilometers, miles;
    printf("\nEnter the value in miles: ");
    scanf("%f", &miles);
    kilometers = miles / 0.621371;
    displayResult(miles, "mi", "km");
}

void convertCtoF() {
    float celsius, fahrenheit;
    printf("\nEnter the value in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 1.8) + 32;
    displayResult(celsius, "C", "F");
}

void convertFtoC() {
    float celsius, fahrenheit;
    printf("\nEnter the value in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) / 1.8;
    displayResult(fahrenheit, "F", "C");
}

int main() {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                convertKMtoMiles();
                break;
            case 2:
                convertMilestoKM();
                break;
            case 3:
                convertCtoF();
                break;
            case 4:
                convertFtoC();
                break;
            case 5:
                printf("\nExiting the program...");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 5);
    return 0;
}