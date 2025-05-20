//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, num;
    double value, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select a unit of measurement:\n");
    printf("1. Length\n2. Mass\n3. Volume\n4. Temperature\n5. Time\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Please enter a value for length:\n");
            scanf("%lf", &value);

            printf("Please select a unit of measurement:\n");
            printf("1. Millimeters\n2. Centimeters\n3. Meters\n4. Kilometers\n");
            scanf("%d", &num);

            switch(num) {
                case 1:
                    result = value * 1000;
                    printf("%lf millimeters is equal to %lf meters.\n", value, result);
                    break;
                case 2:
                    result = value * 100;
                    printf("%lf centimeters is equal to %lf meters.\n", value, result);
                    break;
                case 3:
                    result = value;
                    printf("%lf meters is equal to %lf meters.\n", value, result);
                    break;
                case 4:
                    result = value / 1000;
                    printf("%lf kilometers is equal to %lf meters.\n", value, result);
                    break;
            }
            break;
        case 2:
            printf("Please enter a value for mass:\n");
            scanf("%lf", &value);

            printf("Please select a unit of measurement:\n");
            printf("1. Grams\n2. Kilograms\n");
            scanf("%d", &num);

            switch(num) {
                case 1:
                    result = value * 1000;
                    printf("%lf grams is equal to %lf kilograms.\n", value, result);
                    break;
                case 2:
                    result = value;
                    printf("%lf kilograms is equal to %lf kilograms.\n", value, result);
                    break;
            }
            break;
        case 3:
            printf("Please enter a value for volume:\n");
            scanf("%lf", &value);

            printf("Please select a unit of measurement:\n");
            printf("1. Milliliters\n2. Liters\n");
            scanf("%d", &num);

            switch(num) {
                case 1:
                    result = value * 1000;
                    printf("%lf milliliters is equal to %lf liters.\n", value, result);
                    break;
                case 2:
                    result = value;
                    printf("%lf liters is equal to %lf liters.\n", value, result);
                    break;
            }
            break;
        case 4:
            printf("Please enter a value for temperature:\n");
            scanf("%lf", &value);

            printf("Please select a unit of measurement:\n");
            printf("1. Celsius\n2. Fahrenheit\n");
            scanf("%d", &num);

            switch(num) {
                case 1:
                    result = value * 9 / 5 + 32;
                    printf("%lf degrees Celsius is equal to %lf degrees Fahrenheit.\n", value, result);
                    break;
                case 2:
                    result = (value - 32) * 5 / 9;
                    printf("%lf degrees Fahrenheit is equal to %lf degrees Celsius.\n", value, result);
                    break;
            }
            break;
        case 5:
            printf("Please enter a value for time:\n");
            scanf("%lf", &value);

            printf("Please select a unit of measurement:\n");
            printf("1. Seconds\n2. Minutes\n3. Hours\n");
            scanf("%d", &num);

            switch(num) {
                case 1:
                    result = value;
                    printf("%lf seconds is equal to %lf minutes.\n", value, value / 60);
                    printf("%lf seconds is equal to %lf hours.\n", value, value / 3600);
                    break;
                case 2:
                    result = value / 60;
                    printf("%lf minutes is equal to %lf hours.\n", value, result);
                    break;
                case 3:
                    result = value / 3600;
                    printf("%lf hours is equal to %lf hours.\n", value, result);
                    break;
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}