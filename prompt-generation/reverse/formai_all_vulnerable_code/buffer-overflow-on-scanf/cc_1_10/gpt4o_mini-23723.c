//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void display_menu();
void length_converter();
void weight_converter();
void volume_converter();

void length_converter() {
    float meters, kilometers, miles, feet;
    printf("Enter length in meters: ");
    scanf("%f", &meters);

    kilometers = meters / 1000.0;
    miles = meters / 1609.34;
    feet = meters * 3.28084;

    printf("%.2f meters is:\n", meters);
    printf("%.2f kilometers\n", kilometers);
    printf("%.2f miles\n", miles);
    printf("%.2f feet\n", feet);
}

void weight_converter() {
    float kg, pounds, ounces;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kg);

    pounds = kg * 2.20462;
    ounces = kg * 35.274;

    printf("%.2f kilograms is:\n", kg);
    printf("%.2f pounds\n", pounds);
    printf("%.2f ounces\n", ounces);
}

void volume_converter() {
    float liters, gallons, pints, quarts;
    printf("Enter volume in liters: ");
    scanf("%f", &liters);

    gallons = liters / 3.78541;
    pints = liters * 2.11338;
    quarts = liters / 0.946353;

    printf("%.2f liters is:\n", liters);
    printf("%.2f gallons\n", gallons);
    printf("%.2f pints\n", pints);
    printf("%.2f quarts\n", quarts);
}

int main() {
    int choice;
    
    printf("Welcome to the Post-Apocalyptic Unit Converter!\n");
    printf("Survivors in the wasteland need to convert units wisely.\n");
    printf("Select your conversion type:\n");
    printf("1: Length\n");
    printf("2: Weight\n");
    printf("3: Volume\n");
    printf("4: Exit\n");
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                length_converter();
                break;
            case 2:
                weight_converter();
                break;
            case 3:
                volume_converter();
                break;
            case 4:
                printf("Brave survivor, the world needs you. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. The post-apocalyptic GPS is malfunctioning...\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n===================\n");
    printf("Unit Conversion Menu\n");
    printf("===================\n");
}