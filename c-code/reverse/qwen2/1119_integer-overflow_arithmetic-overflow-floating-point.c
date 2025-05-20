#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

float celsiusToGalactic(float celsius) {
    return celsius * 1.5 + 30;
}

float galacticToCelsius(float galactic) {
    return (galactic - 30) / 1.5;
}

void printMenu() {
    printf("Temperature Converter\n");
    printf("1. Celsius to Galactic\n");
    printf("2. Galactic to Celsius\n");
    printf("3. Exit\n");
}

int getUserChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void handleConversion(int choice) {
    float temp;
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);
        printf("%.2f Celsius is %.2f Galactic\n", temp, celsiusToGalactic(temp));
    } else if (choice == 2) {
        printf("Enter temperature in Galactic: ");
        scanf("%f", &temp);
        printf("%.2f Galactic is %.2f Celsius\n", temp, galacticToCelsius(temp));
    }
}

int main() {
    int choice = 0;
    while (choice != 3) {
        printMenu();
        choice = getUserChoice();
        if (choice >= 1 && choice <= 2) {
            handleConversion(choice);
        } else if (choice != 3) {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
