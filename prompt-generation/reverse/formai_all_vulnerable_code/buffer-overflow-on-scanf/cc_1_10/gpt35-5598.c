//FormAI DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
/*
 * Linus Torvalds style C unit converter program
 */

#include <stdio.h>

int main()
{
    double length, cm, inch, feet, yard, meter, km, lb, kg, oz, g;
    int choice, i;

    printf("Welcome to the C Unit Converter\n");

    do {
        printf("\nEnter your choice:\n"
            "1. Length Conversion\n"
            "2. Mass/Weight Conversion\n"
            "3. Quit\n"
            "Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter length in centimeters: ");
                scanf("%lf", &length);

                inch = length / 2.54;
                feet = inch / 12;
                yard = feet / 3;
                meter = length / 100;
                km = meter / 1000;

                printf("\nConverted lengths:\n"
                    "Inches: %0.2lf\n"
                    "Feet: %0.2lf\n"
                    "Yards: %0.2lf\n"
                    "Meters: %0.2lf\n"
                    "Kilometers: %0.2lf\n", inch, feet, yard, meter, km);
                break;

            case 2:
                printf("\nEnter weight in pounds: ");
                scanf("%lf", &lb);

                kg = lb / 2.20462;
                g = kg * 1000;
                oz = lb * 16;

                printf("\nConverted weights:\n"
                    "Kilograms: %0.2lf\n"
                    "Grams: %0.2lf\n"
                    "Ounces: %0.2lf\n", kg, g, oz);
                break;

            case 3:
                printf("\nThank you for using the C Unit Converter.\n");
                break;

            default:
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}