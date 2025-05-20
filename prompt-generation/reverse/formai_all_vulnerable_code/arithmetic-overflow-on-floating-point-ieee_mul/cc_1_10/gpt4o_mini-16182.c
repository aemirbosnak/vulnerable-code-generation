//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void distanceConversion();
void temperatureConversion();
void weightConversion();
void playerInput(int playerNum);

int main() {
    int playerCount, i;

    printf("Welcome to the Multiplayer Unit Converter!\n");
    printf("Enter the number of players: ");
    scanf("%d", &playerCount);

    for (i = 1; i <= playerCount; i++) {
        playerInput(i);
    }

    printf("Thank you for using the Unit Converter! Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\nUnit Conversion Menu:\n");
    printf("1. Distance Conversion\n");
    printf("2. Temperature Conversion\n");
    printf("3. Weight Conversion\n");
    printf("Choose an option (1-3): ");
}

void distanceConversion() {
    double value, result;
    int choice;

    printf("Distance Conversion Menu:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("Choose an option (1-2): ");
    scanf("%d", &choice);

    printf("Enter the distance: ");
    scanf("%lf", &value);

    if (choice == 1) {
        result = value * 0.621371;
        printf("%.2f Kilometers is %.2f Miles.\n", value, result);
    } else if (choice == 2) {
        result = value / 0.621371;
        printf("%.2f Miles is %.2f Kilometers.\n", value, result);
    } else {
        printf("Invalid choice!\n");
    }
}

void temperatureConversion() {
    double value, result;
    int choice;

    printf("Temperature Conversion Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose an option (1-2): ");
    scanf("%d", &choice);

    printf("Enter the temperature: ");
    scanf("%lf", &value);

    if (choice == 1) {
        result = (value * 9/5) + 32;
        printf("%.2f Celsius is %.2f Fahrenheit.\n", value, result);
    } else if (choice == 2) {
        result = (value - 32) * 5/9;
        printf("%.2f Fahrenheit is %.2f Celsius.\n", value, result);
    } else {
        printf("Invalid choice!\n");
    }
}

void weightConversion() {
    double value, result;
    int choice;

    printf("Weight Conversion Menu:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Choose an option (1-2): ");
    scanf("%d", &choice);

    printf("Enter the weight: ");
    scanf("%lf", &value);

    if (choice == 1) {
        result = value * 2.20462;
        printf("%.2f Kilograms is %.2f Pounds.\n", value, result);
    } else if (choice == 2) {
        result = value / 2.20462;
        printf("%.2f Pounds is %.2f Kilograms.\n", value, result);
    } else {
        printf("Invalid choice!\n");
    }
}

void playerInput(int playerNum) {
    printf("\n--- Player %d's Turn ---\n", playerNum);
    displayMenu();

    int option;
    scanf("%d", &option);

    switch(option) {
        case 1:
            distanceConversion();
            break;
        case 2:
            temperatureConversion();
            break;
        case 3:
            weightConversion();
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            playerInput(playerNum);
    }
}