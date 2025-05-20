//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>

int main() {
    int option;
    float input, output;

    printf("\n===UNIT CONVERTER PROGRAM===\n");
    printf("1. Convert meters to kilometers\n");
    printf("2. Convert kilometers to meters\n");
    printf("3. Convert Celsius to Fahrenheit\n");
    printf("4. Convert Fahrenheit to Celsius\n");
    printf("5. Convert kilograms to pounds\n");
    printf("6. Convert pounds to kilograms\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter meters: ");
            scanf("%f", &input);
            output = input / 1000;
            printf("%.6f meters is equal to %.6f kilometers\n", input, output);
            break;

        case 2:
            printf("Enter kilometers: ");
            scanf("%f", &input);
            output = input * 1000;
            printf("%.6f kilometers is equal to %.6f meters\n", input, output);
            break;

        case 3:
            printf("Enter Celsius: ");
            scanf("%f", &input);
            output = (input * 9/5) + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", input, output);
            break;

        case 4:
            printf("Enter Fahrenheit: ");
            scanf("%f", &input);
            output = (input - 32) * 5/9;
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", input, output);
            break;

        case 5:
            printf("Enter kilograms: ");
            scanf("%f", &input);
            output = input * 2.20462;
            printf("%.6f kilograms is equal to %.6f pounds\n", input, output);
            break;

        case 6:
            printf("Enter pounds: ");
            scanf("%f", &input);
            output = input * 0.453592;
            printf("%.6f pounds is equal to %.6f kilograms\n", input, output);
            break;

        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}