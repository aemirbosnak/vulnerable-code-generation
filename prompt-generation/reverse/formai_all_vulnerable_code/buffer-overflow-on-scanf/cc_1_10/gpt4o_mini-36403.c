//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>

// Function declarations
void lengthConversion();
void weightConversion();
void temperatureConversion();
void showMenu();

int main() {
    int choice;

    do {
        showMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void showMenu() {
    printf("\n==== Unit Converter ====\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
}

void lengthConversion() {
    double meters, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084; // Conversion factor for meters to feet
    printf("%.2lf meters is equal to %.2lf feet.\n", meters, feet);
}

void weightConversion() {
    double kg, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    pounds = kg * 2.20462; // Conversion factor for kilograms to pounds
    printf("%.2lf kilograms is equal to %.2lf pounds.\n", kg, pounds);
}

void temperatureConversion() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9/5) + 32; // Conversion formula from Celsius to Fahrenheit
    printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
}