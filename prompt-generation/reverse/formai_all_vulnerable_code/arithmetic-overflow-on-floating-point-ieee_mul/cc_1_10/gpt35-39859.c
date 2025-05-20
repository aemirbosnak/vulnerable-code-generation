//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include<stdio.h>

float pound_to_kg(float pounds) {
    return pounds * 0.453592;
}

float feet_to_meter(float feet) {
    return feet * 0.3048;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void converter(int option, float input) {

    switch(option) {
        
        case 1:
            printf("%f pounds is %f kilograms\n", input, pound_to_kg(input));
            break;
        
        case 2:
            printf("%f feet is %f meters\n", input, feet_to_meter(input));
            break;
        
        case 3:
            printf("%f Fahrenheit is %f Celsius\n", input, fahrenheit_to_celsius(input));
            break;

        default:
            printf("Invalid option\n");     
    }
}

int main() {

    int option;
    float input;

    printf("Convert:\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Feet to Meters\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    printf("Enter the value: ");
    scanf("%f", &input);
    converter(option, input);

    return 0;
}