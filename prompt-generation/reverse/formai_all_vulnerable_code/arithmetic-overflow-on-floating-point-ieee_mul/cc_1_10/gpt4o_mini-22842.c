//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OPTIONS 5

// Function Prototypes
void displayIntro();
void showMenu();
void clearScreen();
double convertUnits(int choice, double value);
void displayConversionResult(int choice, double value, double result);
void handleExit();

// Cyberpunk unit options
const char* unitOptions[MAX_OPTIONS] = {
    "1. Neon Bytes to GigaQuads",
    "2. Metrons to NanoMetros",
    "3. MegaPixel Slug to BitRate",
    "4. Galactic Credits to Eurochips",
    "5. Cyber Shields to Energy Units"
};

// Conversion Ratios
const double conversionRates[MAX_OPTIONS][2] = {
    {1000, 1},   // Neon Bytes to GigaQuads
    {1000000, 1}, // Metrons to NanoMetros
    {0.001, 1},  // MegaPixel Slug to BitRate
    {100.0, 1},  // Galactic Credits to Eurochips
    {1.0, 2.0}   // Cyber Shields to Energy Units
};

int main() {
    int choice;
    double value, result;

    clearScreen();
    displayIntro();

    while (1) {
        showMenu();
        printf("Select a conversion option (1-5) or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            handleExit();
        } else if (choice < 1 || choice > MAX_OPTIONS) {
            printf("Invalid choice. Please try again.\n");
        } else {
            printf("Enter the value to convert: ");
            scanf("%lf", &value);

            result = convertUnits(choice - 1, value);
            displayConversionResult(choice - 1, value, result);
        }
    }

    return 0;
}

void displayIntro() {
    printf("*******************************\n");
    printf("*     CYBERPUNK UNIT CONVERTER *\n");
    printf("*******************************\n");
    printf("Welcome to the neon-drenched world of conversion!\n");
    printf("Where numbers twist and matrices glow in the dark.\n");
    printf("Prepare yourself to shift dimensions!\n");
}

void showMenu() {
    printf("\nConversion Options:\n");
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%s\n", unitOptions[i]);
    }
}

void clearScreen() {
    // Use ANSI escape codes to clear screen
    printf("\033[H\033[J");
}

double convertUnits(int choice, double value) {
    return value * conversionRates[choice][0] / conversionRates[choice][1];
}

void displayConversionResult(int choice, double value, double result) {
    switch (choice) {
        case 0:
            printf("%.2f Neon Bytes is equal to %.2f GigaQuads\n", value, result);
            break;
        case 1:
            printf("%.2f Metrons is equal to %.2f NanoMetros\n", value, result);
            break;
        case 2:
            printf("%.2f MegaPixel Slug is equal to %.2f BitRate\n", value, result);
            break;
        case 3:
            printf("%.2f Galactic Credits is equal to %.2f Eurochips\n", value, result);
            break;
        case 4:
            printf("%.2f Cyber Shields is equal to %.2f Energy Units\n", value, result);
            break;
        default:
            break;
    }
}

void handleExit() {
    printf("Exiting the Neon Realm... Until next time!\n");
    exit(0);
}