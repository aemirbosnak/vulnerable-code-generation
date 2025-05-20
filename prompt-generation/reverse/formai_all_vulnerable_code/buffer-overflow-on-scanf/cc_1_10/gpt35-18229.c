//FormAI DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>

int main() {
    float value = 0, convertedValue = 0;
    int choice = 0;

    printf("*** Unit Converter ***\n");
    printf("1. Feet to Meters\n");
    printf("2. Inches to Centimeters\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Pounds to Kilograms\n");
    printf("5. Quit\n");

    do {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value in Feet: ");
                scanf("%f", &value);
                convertedValue = value / 3.281;
                printf("%.2f Feet = %.2f Meters\n", value, convertedValue);
                break;
            case 2:
                printf("Enter value in Inches: ");
                scanf("%f", &value);
                convertedValue = value * 2.54;
                printf("%.2f Inches = %.2f Centimeters\n", value, convertedValue);
                break;
            case 3:
                printf("Enter value in Miles: ");
                scanf("%f", &value);
                convertedValue = value * 1.609;
                printf("%.2f Miles = %.2f Kilometers\n", value, convertedValue);
                break;
            case 4:
                printf("Enter value in Pounds: ");
                scanf("%f", &value);
                convertedValue = value * 0.454;
                printf("%.2f Pounds = %.2f Kilograms\n", value, convertedValue);
                break;
            case 5:
                printf("Thank you for using Unit Converter.\n");
                break;
            default:
                printf("Invalid choice, please select 1-5.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}