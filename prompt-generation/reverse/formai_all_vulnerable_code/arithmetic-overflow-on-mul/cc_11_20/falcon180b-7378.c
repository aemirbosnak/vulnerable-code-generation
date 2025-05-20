//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

int main() {
    char input[20];
    char unit[10];
    double value;
    int choice;

    printf("Enter the value to convert: ");
    scanf("%s", input);

    printf("Enter the unit of the value (e.g. meters, grams, liters): ");
    scanf("%s", unit);

    printf("Enter the unit to convert to:\n1. meters\n2. grams\n3. liters\n4. seconds\n5. Celsius\n6. Fahrenheit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(strcmp(unit, "meters") == 0) {
                printf("Value in other units: %s meters\n", input);
            }
            else {
                value = atof(input) * 100;
                printf("Value in meters: %.2f meters\n", value);
            }
            break;

        case 2:
            if(strcmp(unit, "grams") == 0) {
                printf("Value in other units: %s grams\n", input);
            }
            else {
                value = atof(input) / 1000;
                printf("Value in grams: %.2f grams\n", value);
            }
            break;

        case 3:
            if(strcmp(unit, "liters") == 0) {
                printf("Value in other units: %s liters\n", input);
            }
            else {
                value = atof(input) * 1000;
                printf("Value in liters: %.2f liters\n", value);
            }
            break;

        case 4:
            if(strcmp(unit, "seconds") == 0) {
                printf("Value in other units: %s seconds\n", input);
            }
            else {
                value = atof(input) / 60;
                printf("Value in seconds: %.2f seconds\n", value);
            }
            break;

        case 5:
            if(strcmp(unit, "Celsius") == 0) {
                printf("Value in other units: %s Celsius\n", input);
            }
            else {
                value = (atof(input) * 9/5) + 32;
                printf("Value in Celsius: %.2f Celsius\n", value);
            }
            break;

        case 6:
            if(strcmp(unit, "Fahrenheit") == 0) {
                printf("Value in other units: %s Fahrenheit\n", input);
            }
            else {
                value = (atof(input) - 32) * 5/9;
                printf("Value in Fahrenheit: %.2f Fahrenheit\n", value);
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}