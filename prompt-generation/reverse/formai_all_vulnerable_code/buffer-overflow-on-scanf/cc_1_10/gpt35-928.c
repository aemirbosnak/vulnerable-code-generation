//FormAI DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>

void convert_temp() {
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
}

void convert_length() {
    float meters, feet;

    printf("Enter length in meters: ");
    scanf("%f", &meters);

    // Convert meters to feet
    feet = meters * 3.281;

    printf("%.2f meters = %.2f feet\n", meters, feet);
}

int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert meters to feet\n");
    printf("3. Quit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            convert_temp();
            break;
        case 2:
            convert_length();
            break;
        case 3:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}