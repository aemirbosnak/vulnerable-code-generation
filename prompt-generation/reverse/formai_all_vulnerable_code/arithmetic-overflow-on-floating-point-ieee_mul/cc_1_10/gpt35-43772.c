//FormAI DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>

int main() {
    int choice; // to store the user's choice of conversion
    double measurement; // to store the measurement to be converted

    printf("Welcome to the unit converter program!\n");

    // loop through the program until the user chooses to exit
    do {
        // display the menu to the user
        printf("\nWhich conversion would you like to perform?\n");
        printf("1. Inches to Centimeters\n");
        printf("2. Feet to Meters\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Gallons to Liters\n");
        printf("5. Pounds to Kilograms\n");
        printf("Enter 0 to exit\n");

        // get user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // perform the chosen conversion, or exit if the user chooses 0
        switch (choice) {
            case 0:
                printf("Exiting program...\n");
                break;
            case 1:
                printf("Enter measurement in inches: ");
                scanf("%lf", &measurement);
                printf("%.2f inches = %.2f centimeters\n", measurement, measurement * 2.54);
                break;
            case 2:
                printf("Enter measurement in feet: ");
                scanf("%lf", &measurement);
                printf("%.2f feet = %.2f meters\n", measurement, measurement * 0.3048);
                break;
            case 3:
                printf("Enter measurement in miles: ");
                scanf("%lf", &measurement);
                printf("%.2f miles = %.2f kilometers\n", measurement, measurement * 1.60934);
                break;
            case 4:
                printf("Enter measurement in gallons: ");
                scanf("%lf", &measurement);
                printf("%.2f gallons = %.2f liters\n", measurement, measurement * 3.78541);
                break;
            case 5:
                printf("Enter measurement in pounds: ");
                scanf("%lf", &measurement);
                printf("%.2f pounds = %.2f kilograms\n", measurement, measurement * 0.453592);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}