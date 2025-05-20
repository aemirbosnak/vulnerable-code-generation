//FormAI DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>

// Function prototypes
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();

int main() {
    int choice;

    printf("Welcome to the Unit Converter!\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                printf("Thank you for using the Unit Converter!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("Select an option:\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Temperature\n");
    printf("4. Exit\n");
}

void convertLength() {
    float cm, m, km;

    printf("Enter the length in centimeters: ");
    scanf("%f", &cm);

    m = cm / 100.0;
    km = cm / 100000.0;

    printf("Length in meters: %.2f\n", m);
    printf("Length in kilometers: %.2f\n", km);
}

void convertWeight() {
    float g, kg;

    printf("Enter the weight in grams: ");
    scanf("%f", &g);

    kg = g / 1000.0;

    printf("Weight in kilograms: %.2f\n", kg);
}

void convertTemperature() {
    float f, c;

    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &f);

    c = (f - 32.0) * 5.0 / 9.0;

    printf("Temperature in Celsius: %.2f\n", c);
}