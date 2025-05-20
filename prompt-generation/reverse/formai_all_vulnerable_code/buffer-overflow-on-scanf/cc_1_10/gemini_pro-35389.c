//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: funny
#include <stdio.h>

// Let's define all the conversion factors we'll need, just for fun!
#define METERS_TO_INCHES 39.3701
#define INCHES_TO_METERS 0.0254
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define CELSIUS_TO_FAHRENHEIT(c) ((c) * 9 / 5 + 32)
#define FAHRENHEIT_TO_CELSIUS(f) ((f - 32) * 5 / 9)

// Now, let's get creative with our main function!
int main() {
    // We'll start by asking the user what they want to convert.
    printf("Hey there, conversion connoisseur! What do you want to convert today?\n");
    printf("1. Inches to meters\n");
    printf("2. Meters to inches\n");
    printf("3. Pounds to kilograms\n");
    printf("4. Kilograms to pounds\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("Enter your choice (1-6): ");

    // Let's read the user's choice.
    int choice;
    scanf("%d", &choice);

    // Now, let's handle each choice separately.
    switch (choice) {
        case 1:
            // Convert inches to meters.
            printf("Enter the number of inches: ");
            double inches;
            scanf("%lf", &inches);
            printf("%lf inches is %lf meters.\n", inches, inches / METERS_TO_INCHES);
            break;
        case 2:
            // Convert meters to inches.
            printf("Enter the number of meters: ");
            double meters;
            scanf("%lf", &meters);
            printf("%lf meters is %lf inches.\n", meters, meters * INCHES_TO_METERS);
            break;
        case 3:
            // Convert pounds to kilograms.
            printf("Enter the number of pounds: ");
            double pounds;
            scanf("%lf", &pounds);
            printf("%lf pounds is %lf kilograms.\n", pounds, pounds / POUNDS_TO_KILOGRAMS);
            break;
        case 4:
            // Convert kilograms to pounds.
            printf("Enter the number of kilograms: ");
            double kilograms;
            scanf("%lf", &kilograms);
            printf("%lf kilograms is %lf pounds.\n", kilograms, kilograms * KILOGRAMS_TO_POUNDS);
            break;
        case 5:
            // Convert Celsius to Fahrenheit.
            printf("Enter the temperature in Celsius: ");
            double celsius;
            scanf("%lf", &celsius);
            printf("%lf degrees Celsius is %lf degrees Fahrenheit.\n", celsius, CELSIUS_TO_FAHRENHEIT(celsius));
            break;
        case 6:
            // Convert Fahrenheit to Celsius.
            printf("Enter the temperature in Fahrenheit: ");
            double fahrenheit;
            scanf("%lf", &fahrenheit);
            printf("%lf degrees Fahrenheit is %lf degrees Celsius.\n", fahrenheit, FAHRENHEIT_TO_CELSIUS(fahrenheit));
            break;
        default:
            // Handle invalid choices gracefully.
            printf("Invalid choice. Please choose a number between 1 and 6.\n");
    }

    // Let's end with a touch of humor!
    printf("\nHave a converting day, folks!");

    return 0;
}