//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

int main() {
    int option;
    float value;
    printf("Welcome to the Happy Unit Converter!\n");
    printf("What unit would you like to convert?\n");
    printf("1. Meters to Feet\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Milligrams to Grams\n");
    printf("5. Centimeters to Inches\n");
    printf("6. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    while (option != 6) {
        switch (option) {
            case 1:
                printf("Enter the value in meters: ");
                scanf("%f", &value);
                printf("%.2f meters = %.2f feet\n", value, value * 3.281);
                break;
            case 2:
                printf("Enter the value in kilometers: ");
                scanf("%f", &value);
                printf("%.2f kilometers = %.2f miles\n", value, value * 0.6214);
                break;
            case 3:
                printf("Enter the value in Celsius: ");
                scanf("%f", &value);
                printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value * 1.8) + 32);
                break;
            case 4:
                printf("Enter the value in milligrams: ");
                scanf("%f", &value);
                printf("%.2f milligrams = %.2f grams\n", value, value / 1000);
                break;
            case 5:
                printf("Enter the value in centimeters: ");
                scanf("%f", &value);
                printf("%.2f centimeters = %.2f inches\n", value, value / 2.54);
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
        printf("What unit would you like to convert?\n");
        printf("1. Meters to Feet\n");
        printf("2. Kilometers to Miles\n");
        printf("3. Celsius to Fahrenheit\n");
        printf("4. Milligrams to Grams\n");
        printf("5. Centimeters to Inches\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
    }
    printf("Thank you for using the Happy Unit Converter!\n");
    return 0;
}