//FormAI DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>

float convertMilesToKilometers(float input) {
    return input * 1.60934;
}

float convertKilometersToMiles(float input) {
    return input * 0.621371;
}

float convertInchesToCentimeters(float input) {
    return input * 2.54;
}

float convertCentimetersToInches(float input) {
    return input * 0.393701;
}

int main() {
    int choice1, choice2;

    printf("Welcome to the Unit Converter Program!\n");
    printf("------------------------------------\n");

    while (1) {
        printf("\nPlease choose the unit category you want to convert from:\n");
        printf("1. Length\n");
        printf("2. Distance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);

        if (choice1 == 3) {
            printf("Thank you for using our program!\n");
            break;
        }

        printf("\nPlease choose the unit category you want to convert to:\n");
        printf("1. Length\n");
        printf("2. Distance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice2);

        if (choice2 == 3) {
            printf("Thank you for using our program!\n");
            break;
        }

        float input;
        printf("\nEnter the value to be converted: ");
        scanf("%f", &input);

        float result;

        if (choice1 == 1 && choice2 == 2) {
            result = convertInchesToCentimeters(input);
            printf("%.2f inches = %.2f centimeters\n", input, result);
        } else if (choice1 == 2 && choice2 == 1) {
            result = convertCentimetersToInches(input);
            printf("%.2f centimeters = %.2f inches\n", input, result);
        } else if (choice1 == 2 && choice2 == 2) {
            printf("Invalid choice! Please try again\n");
            continue;
        } else if (choice1 == 1 && choice2 == 1) {
            printf("Invalid choice! Please try again\n");
            continue;
        } else if (choice1 == 1 && choice2 == 2) {
            result = convertMilesToKilometers(input);
            printf("%.2f miles = %.2f kilometers\n", input, result);
        } else if (choice1 == 2 && choice2 == 1) {
            result = convertKilometersToMiles(input);
            printf("%.2f kilometers = %.2f miles\n", input, result);
        } else {
            printf("Invalid choice! Please try again\n");
            continue;
        }
    }

    return 0;
}