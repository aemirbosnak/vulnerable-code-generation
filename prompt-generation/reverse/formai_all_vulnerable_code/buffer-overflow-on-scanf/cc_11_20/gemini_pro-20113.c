//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's make a magical unit converter! 🎩✨
    float input, result;
    int choice;

    printf("Howdy there, my curious friend! Welcome to the Unit Conversion Extravaganza! 🎪\n");

    while (1) {
        printf("\nHere's the menu of your conversion options:\n\n");
        printf("1. Feet to Meters 👣\n");
        printf("2. Meters to Feet 🗼\n");
        printf("3. Pounds to Kilograms ⚖️\n");
        printf("4. Kilograms to Pounds 🏋️‍♀️\n");
        printf("5. Miles to Kilometers 🛣️\n");
        printf("6. Kilometers to Miles 🚗\n");
        printf("7. Gallons to Liters 💧\n");
        printf("8. Liters to Gallons 🚰\n");
        printf("9. Quit 🚪\n");

        printf("\nPick a number and let's do some unit-hopping magic! 🧙‍♂️: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Give me a value in feet: ");
            scanf("%f", &input);
            result = input * 0.3048;
            printf("%.2f feet is equal to %.2f meters.\n", input, result);
            break;
        case 2:
            printf("Give me a value in meters: ");
            scanf("%f", &input);
            result = input * 3.281;
            printf("%.2f meters is equal to %.2f feet.\n", input, result);
            break;
        case 3:
            printf("Give me a value in pounds: ");
            scanf("%f", &input);
            result = input * 0.4536;
            printf("%.2f pounds is equal to %.2f kilograms.\n", input, result);
            break;
        case 4:
            printf("Give me a value in kilograms: ");
            scanf("%f", &input);
            result = input * 2.205;
            printf("%.2f kilograms is equal to %.2f pounds.\n", input, result);
            break;
        case 5:
            printf("Give me a value in miles: ");
            scanf("%f", &input);
            result = input * 1.609;
            printf("%.2f miles is equal to %.2f kilometers.\n", input, result);
            break;
        case 6:
            printf("Give me a value in kilometers: ");
            scanf("%f", &input);
            result = input * 0.6214;
            printf("%.2f kilometers is equal to %.2f miles.\n", input, result);
            break;
        case 7:
            printf("Give me a value in gallons: ");
            scanf("%f", &input);
            result = input * 3.785;
            printf("%.2f gallons is equal to %.2f liters.\n", input, result);
            break;
        case 8:
            printf("Give me a value in liters: ");
            scanf("%f", &input);
            result = input * 0.2642;
            printf("%.2f liters is equal to %.2f gallons.\n", input, result);
            break;
        case 9:
            printf("Farewell, my curious friend! May your future conversions be filled with accuracy and joy! ✨\n");
            return 0;
        default:
            printf("Oops, that's not a valid option. Try again! 🤔\n");
        }
    }

    return 0;
}