//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    char name[20];
    float value;
}Unit;

Unit units[] = {{"Meter", 1.0}, {"Kilometer", 1000.0}, {"Mile", 1609.34}, {"Feet", 0.3048}, {"Inch", 0.0254}, {"Pound", 0.453592}, {"Kilogram", 2.20462}, {"Stone", 6.35029}, {"Gallon", 3.78541}, {"Liter", 0.264172}, {"Ounce", 0.035274}, {"Pint", 0.473177}, {"Quart", 0.946353}, {"Degree Celsius", 1.0}, {"Degree Fahrenheit", 1.8}, {"Radian", PI/180.0}};

void print_menu() {
    printf("\n-------------- UNIT CONVERTER --------------\n");
    printf("1. Length\n");
    printf("2. Mass\n");
    printf("3. Volume\n");
    printf("4. Temperature\n");
    printf("5. Angle\n");
    printf("6. Quit\n");
    printf("\nChoose the category and press the corresponding number: ");
}

int main() {
    int choice, choice1, choice2;
    float value, result;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_menu();
                scanf("%d", &choice1);
                printf("Enter value in: ");
                scanf("%f", &value);

                if (choice1 > 12) {
                    printf("Invalid choice.\n");
                    break;
                }

                printf("Convert %0.2f %s to: \n", value, units[choice1-1].name);
                print_menu();
                scanf("%d", &choice2);

                if (choice2 > 12) {
                    printf("Invalid choice.\n");
                    break;
                }

                result = value * (units[choice2-1].value / units[choice1-1].value);
                printf("%.2f %s = %.2f %s\n", value, units[choice1-1].name, result, units[choice2-1].name);
                break;

            case 2:
                // Mass conversion logic here
                break;

            case 3:
                // Volume conversion logic here
                break;

            case 4:
                // Temperature conversion logic here
                break;

            case 5:
                // Angle conversion logic here
                break;

            case 6:
                exit(1);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}