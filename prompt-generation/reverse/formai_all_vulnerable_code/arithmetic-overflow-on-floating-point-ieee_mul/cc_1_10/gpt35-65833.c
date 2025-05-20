//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>

// function prototypes
void menu();
void convertTemp();
void convertLength();
void convertWeight();

int main() {
    // display the menu
    menu();

    return 0;
}

// function definitions
void menu() {
    int choice;
    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option below:\n");
    printf("1. Convert Temperature\n");
    printf("2. Convert Length\n");
    printf("3. Convert Weight\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            convertTemp();
            break;
        case 2:
            convertLength();
            break;
        case 3:
            convertWeight();
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            menu();
    }
}

void convertTemp() {
    float temp, fahrenheit, celsius;
    int choice;
    printf("Enter the temperature to convert: ");
    scanf("%f", &temp);
    printf("Select an option below:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            celsius = (temp - 32) * 5 / 9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temp, celsius);
            break;
        case 2:
            fahrenheit = (temp * 9 / 5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp, fahrenheit);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            convertTemp();
    }
}

void convertLength() {
    float length, meters, feet;
    int choice;
    printf("Enter the length to convert: ");
    scanf("%f", &length);
    printf("Select an option below:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            feet = length * 3.281;
            printf("%.2f meters is equal to %.2f feet.\n", length, feet);
            break;
        case 2:
            meters = length / 3.281;
            printf("%.2f feet is equal to %.2f meters.\n", length, meters);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            convertLength();
    }
}

void convertWeight() {
    float weight, kilograms, pounds;
    int choice;
    printf("Enter the weight to convert: ");
    scanf("%f", &weight);
    printf("Select an option below:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            pounds = weight * 2.205;
            printf("%.2f kilograms is equal to %.2f pounds.\n", weight, pounds);
            break;
        case 2:
            kilograms = weight / 2.205;
            printf("%.2f pounds is equal to %.2f kilograms.\n", weight, kilograms);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            convertWeight();
    }
}