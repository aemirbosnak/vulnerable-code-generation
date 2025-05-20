//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
// Welcome to the Super Cool C Unit Converter!
// This program is designed to convert between various units.
// Let's get started with some awesome code!

#include <stdio.h> // Standard input/output library

int main() {
    double kilometers, miles, pounds, kilograms, hours, minutes, seconds;
    int choice;

    printf("Welcome to the Super Cool C Unit Converter!\n\n");
    printf("Please select the conversion type:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("5. Hours to Minutes\n");
    printf("6. Minutes to Seconds\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the value in kilometers: ");
            scanf("%lf", &kilometers);
            miles = kilometers * 0.621371;
            printf("%.2lf kilometers is equal to %.2lf miles.\n", kilometers, miles);
            break;
        case 2:
            printf("Enter the value in miles: ");
            scanf("%lf", &miles);
            kilometers = miles / 0.621371;
            printf("%.2lf miles is equal to %.2lf kilometers.\n", miles, kilometers);
            break;
        case 3:
            printf("Enter the value in pounds: ");
            scanf("%lf", &pounds);
            kilograms = pounds / 2.20462;
            printf("%.2lf pounds is equal to %.2lf kilograms.\n", pounds, kilograms);
            break;
        case 4:
            printf("Enter the value in kilograms: ");
            scanf("%lf", &kilograms);
            pounds = kilograms * 2.20462;
            printf("%.2lf kilograms is equal to %.2lf pounds.\n", kilograms, pounds);
            break;
        case 5:
            printf("Enter the value in hours: ");
            scanf("%lf", &hours);
            minutes = hours * 60;
            printf("%.2lf hours is equal to %.2lf minutes.\n", hours, minutes);
            break;
        case 6:
            printf("Enter the value in minutes: ");
            scanf("%lf", &minutes);
            seconds = minutes * 60;
            printf("%.2lf minutes is equal to %.2lf seconds.\n", minutes, seconds);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    printf("\nThanks for using the Super Cool C Unit Converter!\n");

    return 0;
}