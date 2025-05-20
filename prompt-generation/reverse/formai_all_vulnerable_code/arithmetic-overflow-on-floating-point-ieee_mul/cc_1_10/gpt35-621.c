//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>

int main() {
    int option;
    float value, converted_value;
    
    printf("\tWelcome to the Unit Converter!\n");
    printf("Choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Meters to Feet\n");
    printf("4. Centimeters to Inches\n");
    printf("5. Kilograms to Pounds\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("\nEnter the temperature in Celsius: ");
            scanf("%f", &value);
            converted_value = ((value * 9) / 5) + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit.", value, converted_value);
            break;
        case 2:
            printf("\nEnter the distance in Kilometers: ");
            scanf("%f", &value);
            converted_value = value / 1.609;
            printf("%.2f Kilometers is equal to %.2f Miles.", value, converted_value);
            break;
        case 3:
            printf("\nEnter the distance in Meters: ");
            scanf("%f", &value);
            converted_value = value / 0.3048;
            printf("%.2f Meters is equal to %.2f Feet.", value, converted_value);
            break;
        case 4:
            printf("\nEnter the distance in Centimeters: ");
            scanf("%f", &value);
            converted_value = value / 2.54;
            printf("%.2f Centimeters is equal to %.2f Inches.", value, converted_value);
            break;
        case 5:
            printf("\nEnter the weight in Kilograms: ");
            scanf("%f", &value);
            converted_value = value * 2.20462;
            printf("%.2f Kilograms is equal to %.2f Pounds.", value, converted_value);
            break;
        default:
            printf("\nInvalid option! Please choose between 1-5.");
            break;
    }
    
    return 0;
}