//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double value, result;
    char unit[10];

    printf("Enter the number you want to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the number: ");
    scanf("%s", unit);

    printf("\nSelect the conversion type:\n");
    printf("1. Length\n2. Weight\n3. Volume\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Length conversion
            printf("\nSelect the length unit:\n");
            printf("1. Meter\n2. Centimeter\n3. Millimeter\n4. Kilometer\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    result = value;
                    break;
                case 2:
                    result = value / 100;
                    break;
                case 3:
                    result = value / 1000;
                    break;
                case 4:
                    result = value / 1000000;
                    break;
            }
            printf("\n%lf %s = %lf %s\n", value, unit, result, "m");
            break;

        case 2: // Weight conversion
            printf("\nSelect the weight unit:\n");
            printf("1. Kilogram\n2. Gram\n3. Milligram\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    result = value;
                    break;
                case 2:
                    result = value / 1000;
                    break;
                case 3:
                    result = value / 1000000;
                    break;
            }
            printf("\n%lf %s = %lf %s\n", value, unit, result, "kg");
            break;

        case 3: // Volume conversion
            printf("\nSelect the volume unit:\n");
            printf("1. Liter\n2. Milliliter\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    result = value;
                    break;
                case 2:
                    result = value / 1000;
                    break;
            }
            printf("\n%lf %s = %lf %s\n", value, unit, result, "l");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}