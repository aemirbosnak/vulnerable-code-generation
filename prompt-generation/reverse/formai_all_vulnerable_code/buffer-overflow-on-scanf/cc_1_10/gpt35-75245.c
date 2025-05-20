//FormAI DATASET v1.0 Category: Unit converter ; Style: realistic
#include<stdio.h>

int main(){

    int option;
    float input, output;

    printf("Select a conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Inches to Centimeters\n");
    printf("4. Centimeters to Inches\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    scanf("%d", &option);

    switch(option){

        case 1:
            printf("Enter temperature in Celsius:\n");
            scanf("%f", &input);
            output = input * 1.8 + 32;
            printf("%.2f\u00B0C = %.2f\u00B0F\n", input, output);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit:\n");
            scanf("%f", &input);
            output = (input - 32) / 1.8;
            printf("%.2f\u00B0F = %.2f\u00B0C\n", input, output);
            break;

        case 3:
            printf("Enter length in inches:\n");
            scanf("%f", &input);
            output = input * 2.54;
            printf("%.2f in = %.2f cm\n", input, output);
            break;

        case 4:
            printf("Enter length in centimeters:\n");
            scanf("%f", &input);
            output = input / 2.54;
            printf("%.2f cm = %.2f in\n", input, output);
            break;

        case 5:
            printf("Enter weight in pounds:\n");
            scanf("%f", &input);
            output = input / 2.2046;
            printf("%.2f lb = %.2f kg\n", input, output);
            break;

        case 6:
            printf("Enter weight in kilograms:\n");
            scanf("%f", &input);
            output = input * 2.2046;
            printf("%.2f kg = %.2f lb\n", input, output);
            break;

        default:
            printf("Invalid option selected.\n");
            break;

    }

    return 0;

}