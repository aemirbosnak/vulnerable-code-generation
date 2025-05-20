//FormAI DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>

int main() {
    float distance, convertedDistance;
    int choice;

    printf("Welcome to Unit Converter!\n");
    printf("--------------------------\n");

    printf("Select Conversion Type\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Centimeters to Inches\n");
    printf("6. Inches to Centimeters\n");
    printf("7. Exit\n");

    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);

    if(choice < 1 || choice > 7) {
        printf("Invalid input. Please select a number between 1 and 7.\n");
        main();
    } else if(choice == 7) {
        printf("Exiting Unit Converter. Thank you for using our service!\n");
        return 0;
    }

    printf("Enter the distance you want to convert: ");
    scanf("%f", &distance);

    switch(choice) {
        case 1:
            convertedDistance = distance * 0.621371;
            printf("%.2f kilometers is equal to %.2f miles.\n", distance, convertedDistance);
            break;
        case 2:
            convertedDistance = distance * 1.60934;
            printf("%.2f miles is equal to %.2f kilometers.\n", distance, convertedDistance);
            break;
        case 3:
            convertedDistance = distance * 3.28084;
            printf("%.2f meters is equal to %.2f feet.\n", distance, convertedDistance);
            break;
        case 4:
            convertedDistance = distance * 0.3048;
            printf("%.2f feet is equal to %.2f meters.\n", distance, convertedDistance);
            break;
        case 5:
            convertedDistance = distance * 0.393701;
            printf("%.2f centimeters is equal to %.2f inches.\n", distance, convertedDistance);
            break;
        case 6:
            convertedDistance = distance * 2.54;
            printf("%.2f inches is equal to %.2f centimeters.\n", distance, convertedDistance);
            break;
    }

    main();
    return 0;
}