//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <math.h>

int main(void) {
    double value;
    char unit[50], to_unit[50];
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Please enter the current unit of the value: ");
    scanf("%s", unit);

    printf("Please enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    printf("\nPlease choose the conversion you want to perform:\n");
    printf("1. Length\n2. Weight\n3. Temperature\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Please choose the length conversion you want to perform:\n");
            printf("1. Millimeters to inches\n2. Inches to millimeters\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    value /= 25.4;
                    printf("%lf %s = %lf %s\n", value, unit, value, to_unit);
                    break;
                case 2:
                    value *= 25.4;
                    printf("%lf %s = %lf %s\n", value, unit, value, to_unit);
                    break;
            }
            break;
        case 2:
            printf("Please choose the weight conversion you want to perform:\n");
            printf("1. Grams to ounces\n2. Ounces to grams\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    value /= 28.35;
                    printf("%lf %s = %lf %s\n", value, unit, value, to_unit);
                    break;
                case 2:
                    value *= 28.35;
                    printf("%lf %s = %lf %s\n", value, unit, value, to_unit);
                    break;
            }
            break;
        case 3:
            printf("Please choose the temperature conversion you want to perform:\n");
            printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    value = (value * 9/5) + 32;
                    printf("%lf %s = %lf %s\n", value, unit, value, to_unit);
                    break;
                case 2:
                    value = (value - 32) * 5/9;
                    printf("%lf %s = %lf %s\n", value, unit, value, to_unit);
                    break;
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}