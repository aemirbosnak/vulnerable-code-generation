//FormAI DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>

void printHeader(){
    printf("=========== Unit Converter ===========\n");
    printf("        Written by Your Name\n");
    printf("======================================\n");
}

int main () {
    int choice;
    float input, output;

    printHeader();

    // Display menu
    printf("Select an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Meters to Feet\n");
    printf("4. Convert Feet to Meters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform conversion based on user's choice
    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            output = (input * 1.8) + 32;
            printf("%.2f Celsius is %.2f Fahrenheit\n", input, output);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = (input - 32) / 1.8;
            printf("%.2f Fahrenheit is %.2f Celsius\n", input, output);
            break;
        case 3:
            printf("Enter length in meters: ");
            scanf("%f", &input);
            output = input * 3.28084;
            printf("%.2f meters is %.2f feet\n", input, output);
            break;
        case 4:
            printf("Enter length in feet: ");
            scanf("%f", &input);
            output = input / 3.28084;
            printf("%.2f feet is %.2f meters\n", input, output);
            break;
        default:
            printf("Invalid choice. Please enter an integer between 1-4.\n");
            break;
    }

    return 0;
}