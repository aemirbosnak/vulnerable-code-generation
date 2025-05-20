//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>

void displayMenu() {
    printf("Unit Converter\n");
    printf("===============\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Volume Converter\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

void lengthConverter() {
    double meters, feet, inches;
    printf("Length Conversion:\n");
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    inches = meters * 39.3701;
    printf("%.2f meters is %.2f feet\n", meters, feet);
    printf("%.2f meters is %.2f inches\n", meters, inches);
}

void weightConverter() {
    double kg, pounds, ounces;
    printf("Weight Conversion:\n");
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    pounds = kg * 2.20462;
    ounces = kg * 35.274;
    printf("%.2f kilograms is %.2f pounds\n", kg, pounds);
    printf("%.2f kilograms is %.2f ounces\n", kg, ounces);
}

void temperatureConverter() {
    double celsius, fahrenheit;
    printf("Temperature Conversion:\n");
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
}

void volumeConverter() {
    double liters, gallons, quarts;
    printf("Volume Conversion:\n");
    printf("Enter volume in liters: ");
    scanf("%lf", &liters);
    gallons = liters * 0.264172;
    quarts = liters * 1.05669;
    printf("%.2f liters is %.2f gallons\n", liters, gallons);
    printf("%.2f liters is %.2f quarts\n", liters, quarts);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConverter();
                break;
            case 2:
                weightConverter();
                break;
            case 3:
                temperatureConverter();
                break;
            case 4:
                volumeConverter();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                return 0;
            default:
                printf("Invalid option! Please choose between 1 to 5.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}