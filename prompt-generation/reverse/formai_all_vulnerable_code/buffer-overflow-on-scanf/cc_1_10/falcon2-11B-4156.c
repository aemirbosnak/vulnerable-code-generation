//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <math.h>

int main() {
    float kg, lb, g, oz;
    float convert_kg_to_lb = 2.20462;
    float convert_lb_to_kg = 0.453592;
    float convert_g_to_oz = 0.035274;
    float convert_oz_to_g = 28.3495;

    printf("Welcome to the C Unit Converter!\n");
    printf("Please enter a number to convert:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("Enter your choice: ");
    scanf("%f", &kg);

    printf("You entered: %.2f kg\n", kg);

    if (kg!= 0) {
        switch (1) {
            case 1:
                lb = kg * convert_kg_to_lb;
                printf("%.2f kg is equal to %.2f lb.\n", kg, lb);
                break;
            case 2:
                kg = lb * convert_lb_to_kg;
                printf("%.2f lb is equal to %.2f kg.\n", lb, kg);
                break;
            case 3:
                g = kg * 1000;
                oz = g * convert_g_to_oz;
                printf("%.2f kg is equal to %.2f g.\n", kg, g);
                printf("%.2f g is equal to %.2f oz.\n", g, oz);
                break;
            case 4:
                oz = g / convert_oz_to_g;
                kg = oz / convert_g_to_oz;
                printf("%.2f g is equal to %.2f oz.\n", g, oz);
                printf("%.2f oz is equal to %.2f kg.\n", oz, kg);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } else {
        printf("Please enter a valid number.\n");
    }

    return 0;
}