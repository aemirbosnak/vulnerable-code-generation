//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>

void displayMenu();
void convertDistance();
void convertWeight();
void convertTemperature();
void convertVolume();
void pause();

int main(void) {
    int choice;

    do {
        displayMenu();
        printf("Pray, enter thy choice (1-5, or 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertDistance();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                convertVolume();
                break;
            case 0:
                printf("Farewell, noble traveler!\n");
                break;
            default:
                printf("Alas! Thy choice is out of range, please try again.\n");
                break;
        }
        pause();
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n===== The Grand Unit Converter =====\n");
    printf("1. Convert Distance (e.g., miles to kilometers)\n");
    printf("2. Convert Weight (e.g., pounds to kilograms)\n");
    printf("3. Convert Temperature (e.g., Celsius to Fahrenheit)\n");
    printf("4. Convert Volume (e.g., gallons to liters)\n");
    printf("0. Exit this realm\n");
    printf("=====================================\n");
}

void convertDistance() {
    double miles, kilometers;
    printf("Enter the distance in miles: ");
    scanf("%lf", &miles);
    kilometers = miles * 1.60934;
    printf("%.2f miles is equal to %.2f kilometers.\n", miles, kilometers);
}

void convertWeight() {
    double pounds, kilograms;
    printf("Enter the weight in pounds: ");
    scanf("%lf", &pounds);
    kilograms = pounds * 0.453592;
    printf("%.2f pounds is equal to %.2f kilograms.\n", pounds, kilograms);
}

void convertTemperature() {
    double celsius, fahrenheit;
    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

void convertVolume() {
    double gallons, liters;
    printf("Enter the volume in gallons: ");
    scanf("%lf", &gallons);
    liters = gallons * 3.78541;
    printf("%.2f gallons is equal to %.2f liters.\n", gallons, liters);
}

void pause() {
    printf("Press Enter to continue...");
    while ((getchar()) != '\n'); // Consume leftover newline
    getchar(); // Wait for the user to press Enter
}