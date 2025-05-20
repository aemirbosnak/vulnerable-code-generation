//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926535

int main() {
    int choice;
    float value;
    char unit;

    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert meters to miles\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert kilograms to pounds\n");
    printf("4. Convert degrees to radians\n");
    printf("5. Convert seconds to years\n");

    scanf("Enter your choice: ", &choice);

    switch (choice) {
        case 1:
            printf("Enter the value: ");
            scanf("%f", &value);
            unit = 'm';
            printf("The converted value is: %.2f miles.\n", value * 0.621371);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%f", &value);
            unit = 'l';
            printf("The converted value is: %.2f gallons.\n", value * 0.946351);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%f", &value);
            unit = 'k';
            printf("The converted value is: %.2f pounds.\n", value * 2.20462);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%f", &value);
            unit = 'd';
            printf("The converted value is: %.2f radians.\n", value * PI);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%f", &value);
            unit = 's';
            printf("The converted value is: %.2f years.\n", value * 365.25);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("Thank you for using the Ultimate Unit Converter!\n");

    return 0;
}