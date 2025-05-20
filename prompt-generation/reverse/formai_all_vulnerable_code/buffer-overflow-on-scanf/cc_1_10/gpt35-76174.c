//FormAI DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

int main() {
    float number, convertedNumber;
    int choice;

    printf("Welcome to the Unit Converter!\n\n");

    printf("Enter the number you want to convert: ");
    scanf("%f", &number);

    printf("\nTIME CONVERSIONS:\n");
    printf("1. Seconds to Minutes\n");
    printf("2. Minutes to Hours\n");
    printf("3. Hours to Days\n");
    printf("4. Days to Weeks\n");

    printf("\nLENGTH CONVERSIONS:\n");
    printf("5. Inches to Centimeters\n");
    printf("6. Centimeters to Meters\n");
    printf("7. Meters to Kilometers\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Conversion from seconds to minutes
            convertedNumber = number / 60;
            printf("\n%.2f Seconds = %.2f Minutes\n", number, convertedNumber);
            break;

        case 2:
            // Conversion from minutes to hours
            convertedNumber = number / 60;
            printf("\n%.2f Minutes = %.2f Hours\n", number, convertedNumber);
            break;

        case 3:
            // Conversion from hours to days
            convertedNumber = number / 24;
            printf("\n%.2f Hours = %.2f Days\n", number, convertedNumber);
            break;

        case 4:
            // Conversion from days to weeks
            convertedNumber = number / 7;
            printf("\n%.2f Days = %.2f Weeks\n", number, convertedNumber);
            break;

        case 5:
            // Conversion from inches to centimeters
            convertedNumber = number * 2.54;
            printf("\n%.2f Inches = %.2f Centimeters\n", number, convertedNumber);
            break;

        case 6:
            // Conversion from centimeters to meters
            convertedNumber = number / 100;
            printf("\n%.2f Centimeters = %.2f Meters\n", number, convertedNumber);
            break;

        case 7:
            // Conversion from meters to kilometers
            convertedNumber = number / 1000;
            printf("\n%.2f Meters = %.2f Kilometers\n", number, convertedNumber);
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
    }

    return 0;
}