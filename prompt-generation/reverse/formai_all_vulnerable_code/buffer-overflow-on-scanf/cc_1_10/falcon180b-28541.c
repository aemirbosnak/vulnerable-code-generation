//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    float value, result;
    char unit[20];

    printf("Enter your choice:\n");
    printf("1. Length\n2. Weight\n3. Temperature\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the value and unit of length:\n");
            scanf("%f %s", &value, unit);

            if(strcmp(unit, "meter") == 0) {
                result = value * 3.28084;
                printf("%f meter = %f feet\n", value, result);
            }
            else if(strcmp(unit, "feet") == 0) {
                result = value / 3.28084;
                printf("%f feet = %f meter\n", value, result);
            }
            else {
                printf("Invalid unit!\n");
            }

            break;

        case 2:
            printf("Enter the value and unit of weight:\n");
            scanf("%f %s", &value, unit);

            if(strcmp(unit, "gram") == 0) {
                result = value * 0.035274;
                printf("%f gram = %f ounce\n", value, result);
            }
            else if(strcmp(unit, "ounce") == 0) {
                result = value / 0.035274;
                printf("%f ounce = %f gram\n", value, result);
            }
            else {
                printf("Invalid unit!\n");
            }

            break;

        case 3:
            printf("Enter the value and unit of temperature:\n");
            scanf("%f %s", &value, unit);

            if(strcmp(unit, "celsius") == 0) {
                result = value * 9/5 + 32;
                printf("%f celsius = %f fahrenheit\n", value, result);
            }
            else if(strcmp(unit, "fahrenheit") == 0) {
                result = (value - 32) * 5/9;
                printf("%f fahrenheit = %f celsius\n", value, result);
            }
            else {
                printf("Invalid unit!\n");
            }

            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}