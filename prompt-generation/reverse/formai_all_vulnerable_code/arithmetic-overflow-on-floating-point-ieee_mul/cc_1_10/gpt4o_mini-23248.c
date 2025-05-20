//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

void displayMenu() {
    printf("\n==============================\n");
    printf("    WELCOME TO UNIT CONVERTER  \n");
    printf("==============================\n");
    printf("Please select the unit to convert:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Kilometers to Meters\n");
    printf("4. Meters to Kilometers\n");
    printf("5. Miles to Meters\n");
    printf("6. Meters to Miles\n");
    printf("7. Exit\n");
    printf("==============================\n");
}

double kmToMiles(double km) {
    return km * 0.621371;
}

double milesToKm(double miles) {
    return miles / 0.621371;
}

double kmToMeters(double km) {
    return km * 1000;
}

double metersToKm(double meters) {
    return meters / 1000;
}

double milesToMeters(double miles) {
    return miles * 1609.34;
}

double metersToMiles(double meters) {
    return meters / 1609.34;
}

void convertUnits(int choice) {
    double value, convertedValue;

    switch (choice) {
        case 1:
            printf("Enter distance in Kilometers: ");
            scanf("%lf", &value);
            convertedValue = kmToMiles(value);
            printf("%.2f Kilometers is equal to %.2f Miles.\n", value, convertedValue);
            break;
        case 2:
            printf("Enter distance in Miles: ");
            scanf("%lf", &value);
            convertedValue = milesToKm(value);
            printf("%.2f Miles is equal to %.2f Kilometers.\n", value, convertedValue);
            break;
        case 3:
            printf("Enter distance in Kilometers: ");
            scanf("%lf", &value);
            convertedValue = kmToMeters(value);
            printf("%.2f Kilometers is equal to %.2f Meters.\n", value, convertedValue);
            break;
        case 4:
            printf("Enter distance in Meters: ");
            scanf("%lf", &value);
            convertedValue = metersToKm(value);
            printf("%.2f Meters is equal to %.2f Kilometers.\n", value, convertedValue);
            break;
        case 5:
            printf("Enter distance in Miles: ");
            scanf("%lf", &value);
            convertedValue = milesToMeters(value);
            printf("%.2f Miles is equal to %.2f Meters.\n", value, convertedValue);
            break;
        case 6:
            printf("Enter distance in Meters: ");
            scanf("%lf", &value);
            convertedValue = metersToMiles(value);
            printf("%.2f Meters is equal to %.2f Miles.\n", value, convertedValue);
            break;
        case 7:
            printf("Thank you for using the Unit Converter! Goodbye!\n");
            return;
        default:
            printf("Invalid choice! Please try again.\n");
    }
    // Continue until user decides to exit
    convertUnits(choice);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 7) break;
        convertUnits(choice);
    }

    return 0;
}