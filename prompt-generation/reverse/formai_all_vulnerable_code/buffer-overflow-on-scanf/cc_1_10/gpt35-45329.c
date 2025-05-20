//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>

int main() {
    int choice;
    float input, output;

    printf("****Unit Converter****\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Inches to Centimeters\n");
    printf("Choose an option (1/2/3/4): ");
    scanf("%d", &choice);

    switch(choice) {
        
        case 1:
            printf("Enter distance in miles: ");
            scanf("%f", &input);
            output = input * 1.60934;
            printf("%.2f miles is equal to %.2f kilometers.\n", input, output);
            break;

        case 2:
            printf("Enter weight in pounds: ");
            scanf("%f", &input);
            output = input / 2.20462;
            printf("%.2f pounds is equal to %.2f kilograms.\n", input, output);
            break;

        case 3:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = (input - 32) * 5.0/9.0;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", input, output);
            break;

        case 4:
            printf("Enter length in inches: ");
            scanf("%f", &input);
            output = input * 2.54;
            printf("%.2f inches is equal to %.2f centimeters.\n", input, output);
            break;

        default:
            printf("Invalid choice. Please choose either 1, 2, 3 or 4.\n");
    }

    return 0;
}