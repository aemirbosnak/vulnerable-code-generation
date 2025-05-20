//FormAI DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>

int main() {
    int choice;
    float temp;

    printf("Welcome to the Unit Converter Program!\n");
    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    scanf("%d", &choice);

    // Celsius to Fahrenheit conversion
    if (choice == 1) {
        printf("Please enter the temperature in Celsius: ");
        scanf("%f", &temp);
        printf("%.2fC = %.2fF", temp, (9.0 / 5.0) * temp + 32);
    }

    // Fahrenheit to Celsius conversion
    else if (choice == 2) {
        printf("Please enter the temperature in Fahrenheit: ");
        scanf("%f", &temp);
        printf("%.2fF = %.2fC", temp, (5.0 / 9.0) * (temp - 32));
    }

    // Meters to Feet conversion
    else if (choice == 3) {
        float meter;
        printf("Please enter the length in meters: ");
        scanf("%f", &meter);
        printf("%.2f meters = %.2f feet", meter, meter * 3.2808);
    }

    // Feet to Meters conversion
    else if (choice == 4) {
        float feet;
        printf("Please enter the length in feet: ");
        scanf("%f", &feet);
        printf("%.2f feet = %.2f meters", feet, feet / 3.2808);
    }

    // Invalid input
    else {
        printf("Invalid Choice!");
    }

    return 0;
}