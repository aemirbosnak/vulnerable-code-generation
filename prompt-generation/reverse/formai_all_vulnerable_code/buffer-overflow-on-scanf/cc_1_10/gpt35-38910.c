//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    int choice;
    float input, output;

    printf("Welcome to the C Unit Converter!\n");
    printf("Enter which conversion option you would like to use:\n");
    printf("1. Celsius to Fahrenheit Conversion\n");
    printf("2. Feet to Meters Conversion\n");
    printf("3. Kilometers to Miles Conversion\n");
    printf("4. Pounds to Kilograms Conversion\n");
    printf("5. Inches to Centimeters Conversion\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &input);
            // Celsius to Fahrenheit formula
            output = (input * 9 / 5) + 32;
            printf("%.2f°C = %.2f°F\n", input, output);
            break;
        case 2:
            printf("Enter the distance in feet: ");
            scanf("%f", &input);
            // Feet to Meters formula
            output = 0.3048 * input;
            printf("%.2fft = %.2fm\n", input, output);
            break;
        case 3:
            printf("Enter the distance in kilometers: ");
            scanf("%f", &input);
            // Kilometers to Miles formula
            output = input / 1.609;
            printf("%.2fkm = %.2fmi\n", input, output);
            break;
        case 4:
            printf("Enter the weight in pounds: ");
            scanf("%f", &input);
            // Pounds to Kilograms formula
            output = input / 2.2046;
            printf("%.2flbs = %.2fkg\n", input, output);
            break;
        case 5:
            printf("Enter the length in inches: ");
            scanf("%f", &input);
            // Inches to Centimeters formula
            output = 2.54 * input;
            printf("%.2fin = %.2fcm\n", input, output);
            break;
        default:
            printf("Invalid choice! Please input a number between 1 and 5.\n");
    }

    return 0;
}