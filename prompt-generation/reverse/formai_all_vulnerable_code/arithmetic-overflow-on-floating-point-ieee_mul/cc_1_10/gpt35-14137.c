//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to the fantastic Unit Converter 1.0!\n");

    int choice;
    float value;

    do {
        printf("\nWhat would you like to convert today?\n");
        printf("1. Feet to Meters\n");
        printf("2. Miles to Kilometers\n");
        printf("3. Fahrenheit to Celsius\n");
        printf("4. Gallons to Liters\n");
        printf("5. Pounds to Kilograms\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value in feet: ");
                scanf("%f", &value);
                printf("%.2f feet is equal to %.2f meters.\n", value, value/3.281);
                break;
            case 2:
                printf("Enter the value in miles: ");
                scanf("%f", &value);
                printf("%.2f miles is equal to %.2f kilometers.\n", value, value*1.609);
                break;
            case 3:
                printf("Enter the value in Fahrenheit: ");
                scanf("%f", &value);
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", value, (value-32)*5/9);
                break;
            case 4:
                printf("Enter the value in gallons: ");
                scanf("%f", &value);
                printf("%.2f gallons is equal to %.2f liters.\n", value, value*3.785);
                break;
            case 5:
                printf("Enter the value in pounds: ");
                scanf("%f", &value);
                printf("%.2f pounds is equal to %.2f kilograms.\n", value, value*0.454);
                break;
            case 6:
                printf("Exiting the Unit Converter 1.0. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please enter a value between 1-6.\n");
        }
    } while (choice != 6);

    return 0;
}