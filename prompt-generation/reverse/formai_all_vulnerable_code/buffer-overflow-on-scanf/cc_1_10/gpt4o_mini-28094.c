//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void printIntroduction();
void displayMenu();
void dustToGrain(double dust);
void grainToDust(double grain);
void milesToKilometers(double miles);
void kilometersToMiles(double kilometers);
void lightYearsToParsecs(double lightYears);
void parsecsToLightYears(double parsecs);

void printIntroduction() {
    printf("=======================================\n");
    printf("   Wasteland Unit Conversion System   \n");
    printf("=======================================\n");
    printf("After the Great Collapse, our sense of measurement has been twisted by the fallout.\n");
    printf("Here, we strive to convert units for navigation and survival.\n");
    printf("=====================================================\n\n");
}

void displayMenu() {
    printf("Available Conversions:\n");
    printf("1. Dust to Grain\n");
    printf("2. Grain to Dust\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Light Years to Parsecs\n");
    printf("6. Parsecs to Light Years\n");
    printf("0. Exit\n");
    printf("Choose your option (0-6): ");
}

void dustToGrain(double dust) {
    double grain = dust * 0.064; // A modified conversion factor
    printf("%f Dust is approximately %f Grain.\n", dust, grain);
}

void grainToDust(double grain) {
    double dust = grain * 15.625; // Inverted modified conversion
    printf("%f Grain is approximately %f Dust.\n", grain, dust);
}

void milesToKilometers(double miles) {
    double kilometers = miles * 1.60934; // Standard conversion
    printf("%f Miles is approximately %f Kilometers.\n", miles, kilometers);
}

void kilometersToMiles(double kilometers) {
    double miles = kilometers * 0.621371; // Inverted standard conversion
    printf("%f Kilometers is approximately %f Miles.\n", kilometers, miles);
}

void lightYearsToParsecs(double lightYears) {
    double parsecs = lightYears / 3.26156; // Standard conversion
    printf("%f Light Years is approximately %f Parsecs.\n", lightYears, parsecs);
}

void parsecsToLightYears(double parsecs) {
    double lightYears = parsecs * 3.26156; // Inverted standard conversion
    printf("%f Parsecs is approximately %f Light Years.\n", parsecs, lightYears);
}

int main() {
    printIntroduction();
    int option;
    double value;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        if (option == 0) {
            printf("Safe travels, survivor!\n");
            break;
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        switch (option) {
            case 1:
                dustToGrain(value);
                break;
            case 2:
                grainToDust(value);
                break;
            case 3:
                milesToKilometers(value);
                break;
            case 4:
                kilometersToMiles(value);
                break;
            case 5:
                lightYearsToParsecs(value);
                break;
            case 6:
                parsecsToLightYears(value);
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}