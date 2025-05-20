//FormAI DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

char menu();
float convertTemp(float input, char type);
float convertDist(float input, char type);
float convertWeight(float input, char type);

int main()
{
    char selection;
    double input;
    printf("Welcome to the Unit Converter!\n");

    do {
        selection = menu();
        printf("\nEnter a number: ");
        scanf("%lf", &input);
    

        switch(selection) {
            case 'T':
                printf("\nCelsius: %.2f\nFahrenheit: %.2f\n", input, convertTemp(input, 'C'));
                break;
            case 'D':
                printf("\nMiles: %.2f\nKilometers: %.2f\n", input, convertDist(input, 'M'));
                break;
            case 'W':
                printf("\nPounds: %.2f\nKilograms: %.2f\n", input, convertWeight(input, 'P'));
                break;
            case 'Q':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid entry.\n");
                break;
        }
    } while (selection != 'Q');
    
    return 0;
}

char menu() {
    char selection;

    printf("\nMenu:\n");
    printf("T - Temperature Conversion\n");
    printf("D - Distance Conversion\n");
    printf("W - Weight Conversion\n");
    printf("Q - Quit\n");
    printf("\nEnter the letter of your choice: ");
    scanf(" %c", &selection);

    return selection;
}

float convertTemp(float input, char type) {
    if (type == 'C') {
        return (input * (9.0/5.0)) + 32;
    } else {
        return (input - 32) * (5.0/9.0);
    }
}

float convertDist(float input, char type) {
    if (type == 'M') {
        return input * 1.609;
    } else {
        return input / 1.609;
    }
}

float convertWeight(float input, char type) {
    if (type == 'P') {
        return input / 2.205;
    } else {
        return input * 2.205;
    }
}