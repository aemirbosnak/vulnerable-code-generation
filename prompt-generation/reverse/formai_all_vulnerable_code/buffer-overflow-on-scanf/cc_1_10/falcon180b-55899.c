//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double value, result;
    char unit[10];
    printf("Welcome to the Unit Converter!\n");
    printf("Press 1 to convert length units.\n");
    printf("Press 2 to convert weight units.\n");
    printf("Press 3 to convert temperature units.\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter the value to convert: ");
            scanf("%lf", &value);
            printf("Enter the unit of measurement (e.g. meters, feet): ");
            scanf("%s", unit);
            if(strcmp(unit, "meters") == 0) {
                result = value * 3.28084;
                printf("%lf meters is equal to %lf feet.\n", value, result);
            } else if(strcmp(unit, "feet") == 0) {
                result = value / 3.28084;
                printf("%lf feet is equal to %lf meters.\n", value, result);
            } else {
                printf("Invalid unit of measurement.\n");
            }
            break;
        case 2:
            printf("Enter the value to convert: ");
            scanf("%lf", &value);
            printf("Enter the unit of measurement (e.g. kilograms, pounds): ");
            scanf("%s", unit);
            if(strcmp(unit, "kilograms") == 0) {
                result = value * 2.20462;
                printf("%lf kilograms is equal to %lf pounds.\n", value, result);
            } else if(strcmp(unit, "pounds") == 0) {
                result = value / 2.20462;
                printf("%lf pounds is equal to %lf kilograms.\n", value, result);
            } else {
                printf("Invalid unit of measurement.\n");
            }
            break;
        case 3:
            printf("Enter the value to convert: ");
            scanf("%lf", &value);
            printf("Enter the unit of measurement (e.g. Celsius, Fahrenheit): ");
            scanf("%s", unit);
            if(strcmp(unit, "Celsius") == 0) {
                result = (value * 9/5) + 32;
                printf("%lf Celsius is equal to %lf Fahrenheit.\n", value, result);
            } else if(strcmp(unit, "Fahrenheit") == 0) {
                result = (value - 32) * 5/9;
                printf("%lf Fahrenheit is equal to %lf Celsius.\n", value, result);
            } else {
                printf("Invalid unit of measurement.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}