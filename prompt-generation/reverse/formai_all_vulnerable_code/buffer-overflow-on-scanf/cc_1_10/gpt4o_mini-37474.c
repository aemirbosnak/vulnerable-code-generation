//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>

void displayMenu() {
    printf("Unit Converter\n");
    printf("1. Kilometers to Meters\n");
    printf("2. Kilometers to Centimeters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Meters to Kilometers\n");
    printf("5. Meters to Centimeters\n");
    printf("6. Meters to Miles\n");
    printf("7. Centimeters to Kilometers\n");
    printf("8. Centimeters to Meters\n");
    printf("9. Centimeters to Miles\n");
    printf("10. Miles to Kilometers\n");
    printf("11. Miles to Meters\n");
    printf("12. Miles to Centimeters\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

double kilometersToMeters(double km) {
    return km * 1000.0;
}

double kilometersToCentimeters(double km) {
    return km * 100000.0;
}

double kilometersToMiles(double km) {
    return km * 0.621371;
}

double metersToKilometers(double m) {
    return m / 1000.0;
}

double metersToCentimeters(double m) {
    return m * 100.0;
}

double metersToMiles(double m) {
    return m * 0.000621371;
}

double centimetersToKilometers(double cm) {
    return cm / 100000.0;
}

double centimetersToMeters(double cm) {
    return cm / 100.0;
}

double centimetersToMiles(double cm) {
    return cm * 0.00000621371;
}

double milesToKilometers(double mi) {
    return mi / 0.621371;
}

double milesToMeters(double mi) {
    return mi / 0.000621371;
}

double milesToCentimeters(double mi) {
    return mi / 0.00000621371;
}

int main() {
    int choice;
    double value;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        }

        printf("Enter the value: ");
        scanf("%lf", &value);

        switch (choice) {
            case 1:
                printf("%.2f Kilometers = %.2f Meters\n", value, kilometersToMeters(value));
                break;
            case 2:
                printf("%.2f Kilometers = %.2f Centimeters\n", value, kilometersToCentimeters(value));
                break;
            case 3:
                printf("%.2f Kilometers = %.2f Miles\n", value, kilometersToMiles(value));
                break;
            case 4:
                printf("%.2f Meters = %.2f Kilometers\n", value, metersToKilometers(value));
                break;
            case 5:
                printf("%.2f Meters = %.2f Centimeters\n", value, metersToCentimeters(value));
                break;
            case 6:
                printf("%.2f Meters = %.2f Miles\n", value, metersToMiles(value));
                break;
            case 7:
                printf("%.2f Centimeters = %.2f Kilometers\n", value, centimetersToKilometers(value));
                break;
            case 8:
                printf("%.2f Centimeters = %.2f Meters\n", value, centimetersToMeters(value));
                break;
            case 9:
                printf("%.2f Centimeters = %.2f Miles\n", value, centimetersToMiles(value));
                break;
            case 10:
                printf("%.2f Miles = %.2f Kilometers\n", value, milesToKilometers(value));
                break;
            case 11:
                printf("%.2f Miles = %.2f Meters\n", value, milesToMeters(value));
                break;
            case 12:
                printf("%.2f Miles = %.2f Centimeters\n", value, milesToCentimeters(value));
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}