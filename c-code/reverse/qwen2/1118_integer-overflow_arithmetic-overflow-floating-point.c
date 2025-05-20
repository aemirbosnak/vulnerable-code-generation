#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int convertToGalactic(int celsius) {
    return (celsius * 9 / 5) + 32;
}

void printMenu() {
    printf("1. Convert Celsius to Galactic\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

int getUserChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

int getTemperature() {
    int temp;
    printf("Enter temperature in Celsius: ");
    scanf("%d", &temp);
    return temp;
}

void handleInvalidInput() {
    printf("Invalid input! Please try again.\n");
}

int main() {
    int choice, temp;

    while (1) {
        printMenu();
        choice = getUserChoice();

        switch (choice) {
            case 1:
                temp = getTemperature();
                printf("Temperature in Galactic: %d\n", convertToGalactic(temp));
                break;
            case 2:
                return 0;
            default:
                handleInvalidInput();
        }
    }

    return 0;
}
