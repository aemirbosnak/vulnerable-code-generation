//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>

void displayMenu() {
    printf("\n");
    printf("**************************\n");
    printf("Welcome to the Unit Convertor\n");
    printf("**************************\n");
    printf("1. Convert Kilometers to Miles\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert Meters to Feet\n");
    printf("4. Convert Kilograms to Pounds\n");
    printf("5. Exit\n");
    printf("**************************\n");
    printf("Enter your choice (1-5): ");
}

double kilometersToMiles(double kilometers) {
    return kilometers * 0.621371;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double metersToFeet(double meters) {
    return meters * 3.28084;
}

double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

void romanticConversion(char *unit, double value, double (*conversionFunction)(double)) {
    double result = conversionFunction(value);
    printf("Oh! My beloved, %.2f %s is equivalent to %.2f in the new world of love.\n", value, unit, result);
}

int main() {
    int choice;
    double value;

    printf("Oh, dear heart! Let's embark on a journey of conversion, where every unit sings a melodious song!\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("Ah! My darling, your choice is out of bounds. Please choose wisely!\n");
            continue;
        }

        if (choice != 5) {
            printf("Please, whisper the value you wish to convert: ");
            scanf("%lf", &value);
        }

        switch (choice) {
            case 1:
                romanticConversion("Kilometers", value, kilometersToMiles);
                break;
            case 2:
                romanticConversion("Celsius", value, celsiusToFahrenheit);
                break;
            case 3:
                romanticConversion("Meters", value, metersToFeet);
                break;
            case 4:
                romanticConversion("Kilograms", value, kilogramsToPounds);
                break;
            case 5:
                printf("Ah, dear! May your heart find peace as you part away from this lovely encounter.\n");
                break;
        }
    } while (choice != 5);

    printf("Until our paths cross again, cherish the memories of these sweet conversions.\n");
    return 0;
}