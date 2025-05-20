//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 1024

// Function Declarations
void display_menu();
void convert_length();
void convert_weight();
void convert_temperature();
void clear_screen();
void pause();

int main() {
    int choice;

    // Post-apocalyptic welcome message
    printf("=== Welcome to the Ruins of Measurement ===\n");
    printf("Amidst the desolate wasteland, numbers and conversions remain.\n");
    pause();

    do {
        clear_screen();
        display_menu();
        printf("Choose your weapon of conversion (1-3, or 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_length();
                break;
            case 2:
                convert_weight();
                break;
            case 3:
                convert_temperature();
                break;
            case 0:
                printf("Retreating to the shadows...\n");
                return 0;
            default:
                printf("Hasty choice – there are no such conversions here!\n");
                pause();
        }
    } while (1);
    
    return 0;
}

void display_menu() {
    printf("=== Conversion Options ===\n");
    printf("1. Length - It feels like miles and miles to the next town...\n");
    printf("2. Weight - When the supplies are scarce, every ounce counts...\n");
    printf("3. Temperature - The heat is relentless, or is it just hope?...\n");
    printf("0. Exit - Vanish into the unknown...\n");
}

void convert_length() {
    float original, converted;
    int unit_type;

    printf("Enter length (in meters): ");
    scanf("%f", &original);

    printf("Convert to:\n");
    printf("1. Kilometers\n");
    printf("2. Centimeters\n");
    printf("3. Millimeters\n");
    printf("Enter your choice: ");
    scanf("%d", &unit_type);

    switch (unit_type) {
        case 1:
            converted = original / 1000.0;
            printf("%.2f meters is %.2f kilometers\n", original, converted);
            break;
        case 2:
            converted = original * 100.0;
            printf("%.2f meters is %.2f centimeters\n", original, converted);
            break;
        case 3:
            converted = original * 1000.0;
            printf("%.2f meters is %.2f millimeters\n", original, converted);
            break;
        default:
            printf("Scraps in the wind – no such length conversion exists!\n");
    }
    pause();
}

void convert_weight() {
    float original, converted;
    int unit_type;

    printf("Enter weight (in kilograms): ");
    scanf("%f", &original);

    printf("Convert to:\n");
    printf("1. Grams\n");
    printf("2. Pounds\n");
    printf("3. Ounces\n");
    printf("Enter your choice: ");
    scanf("%d", &unit_type);

    switch (unit_type) {
        case 1:
            converted = original * 1000.0;
            printf("%.2f kilograms is %.2f grams\n", original, converted);
            break;
        case 2:
            converted = original * 2.20462;
            printf("%.2f kilograms is %.2f pounds\n", original, converted);
            break;
        case 3:
            converted = original * 35.274;
            printf("%.2f kilograms is %.2f ounces\n", original, converted);
            break;
        default:
            printf("The weight of uncertainty – no such conversion available!\n");
    }
    pause();
}

void convert_temperature() {
    float original, converted;
    int unit_type;

    printf("Enter temperature:\n");
    printf("Note! Use Celsius scale - the only known in this barren land.\n");
    scanf("%f", &original);

    printf("Convert to:\n");
    printf("1. Fahrenheit\n");
    printf("2. Kelvin\n");
    printf("Enter your choice: ");
    scanf("%d", &unit_type);

    switch (unit_type) {
        case 1:
            converted = (original * 9.0 / 5.0) + 32.0;
            printf("%.2f Celsius is %.2f Fahrenheit\n", original, converted);
            break;
        case 2:
            converted = original + 273.15;
            printf("%.2f Celsius is %.2f Kelvin\n", original, converted);
            break;
        default:
            printf("A chilling choice – conversion unrecognized in this world!\n");
    }
    pause();
}

void clear_screen() {
    // Use ANSI escape codes to clear the terminal
    printf("\033[H\033[J");
}

void pause() {
    printf("Press Enter to continue...");
    while (getchar() != '\n');  // Clear any buffered input
    getchar(); // Wait for user to press Enter
}