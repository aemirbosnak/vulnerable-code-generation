//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>

// Function declarations
void displayMenu();
void convertKilometersToMiles();
void convertCelsiusToFahrenheit();
void convertLitersToGallons();
void convertKilogramsToPounds();
void convertMetersToFeet();
void returnToMenu();

int main() {
    int choice;
    printf("Welcome to the Cheerful Unit Converter!\n");
    printf("🌟 Let's make unit conversions fun! 🌟\n");

    do {
        displayMenu();
        printf("Please enter your choice (1-5) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertKilometersToMiles();
                break;
            case 2:
                convertCelsiusToFahrenheit();
                break;
            case 3:
                convertLitersToGallons();
                break;
            case 4:
                convertKilogramsToPounds();
                break;
            case 5:
                convertMetersToFeet();
                break;
            case 0:
                printf("Thank you for using the Cheerful Unit Converter! 🎉\n");
                break;
            default:
                printf("Oops! That wasn't a valid choice. Please try again! 😊\n");
                break;
        }
        returnToMenu();
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n🤗 Cheerful Unit Converter Menu 🤗\n");
    printf("1. Convert Kilometers to Miles\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert Liters to Gallons\n");
    printf("4. Convert Kilograms to Pounds\n");
    printf("5. Convert Meters to Feet\n");
    printf("0. Exit the Converter\n");
}

void convertKilometersToMiles() {
    double kilometers, miles;
    printf("\nEnter distance in kilometers: ");
    scanf("%lf", &kilometers);
    miles = kilometers * 0.621371;
    printf("🎈 %.2lf kilometers is equal to %.2lf miles! 🌍\n", kilometers, miles);
}

void convertCelsiusToFahrenheit() {
    double celsius, fahrenheit;
    printf("\nEnter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("🌡️ %.2lf degrees Celsius is %.2lf degrees Fahrenheit! ☀️\n", celsius, fahrenheit);
}

void convertLitersToGallons() {
    double liters, gallons;
    printf("\nEnter volume in liters: ");
    scanf("%lf", &liters);
    gallons = liters * 0.264172;
    printf("🚰 %.2lf liters is equal to %.2lf gallons! 🏞️\n", liters, gallons);
}

void convertKilogramsToPounds() {
    double kilograms, pounds;
    printf("\nEnter mass in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462;
    printf("💪 %.2lf kilograms is equal to %.2lf pounds! 🦸‍♂️\n", kilograms, pounds);
}

void convertMetersToFeet() {
    double meters, feet;
    printf("\nEnter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    printf("📏 %.2lf meters is equal to %.2lf feet! 👣\n", meters, feet);
}

void returnToMenu() {
    printf("✨ Press Enter to return to the main menu! ✨");
    getchar(); // Clear the newline character from input buffer
    getchar(); // Wait for user to press Enter
}