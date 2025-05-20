//FormAI DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>

/* A Unit Converter in a Medieval Style */

int main() {
    char from_unit[20], to_unit[20];
    double value, converted;

    printf("Hail traveler, welcome to the Medieval Unit Converter!\n");
    printf("I can convert lengths, weights and temperatures for you.\n\n");

    printf("What unit are you converting from? (e.g. feet, pounds, celsius)\n");
    scanf("%s", from_unit);

    printf("What unit are you converting to? (e.g. meters, kilograms, fahrenheit)\n");
    scanf("%s", to_unit);

    printf("Enter the value to convert:\n");
    scanf("%lf", &value);

    // Length Conversion
    if(strcmp(from_unit, "feet") == 0 && strcmp(to_unit, "meters") == 0) {
        converted = value / 3.281; // conversion rate: 1 foot = 0.3048 meters
        printf("%.2f feet is %.2f meters\n", value, converted);
    } else if(strcmp(from_unit, "meters") == 0 && strcmp(to_unit, "feet") == 0) {
        converted = value * 3.281;
        printf("%.2f meters is %.2f feet\n", value, converted);
    }

    // Weight Conversion
    else if(strcmp(from_unit, "pounds") == 0 && strcmp(to_unit, "stones") == 0) {
        converted = value / 14; // conversion rate: 1 pound = 0.0714286 stones
        printf("%.2f pounds is %.2f stones\n", value, converted);
    } else if(strcmp(from_unit, "stones") == 0 && strcmp(to_unit, "pounds") == 0) {
        converted = value * 14;
        printf("%.2f stones is %.2f pounds\n", value, converted);
    }

    // Temperature Conversion
    else if(strcmp(from_unit, "celsius") == 0 && strcmp(to_unit, "fahrenheit") == 0) {
        converted = (value * 1.8) + 32; // conversion formula: fahrenheit = celsius * 1.8 + 32
        printf("%.2f celsius is %.2f fahrenheit\n", value, converted);
    } else if(strcmp(from_unit, "fahrenheit") == 0 && strcmp(to_unit, "celsius") == 0) {
        converted = (value - 32) / 1.8;
        printf("%.2f fahrenheit is %.2f celsius\n", value, converted);
    }

    else {
        printf("I'm sorry, I cannot convert those units. Please try another pair.\n");
    }

    printf("Goodbye traveler, and may the heavens guide your path.\n");

    return 0;
}