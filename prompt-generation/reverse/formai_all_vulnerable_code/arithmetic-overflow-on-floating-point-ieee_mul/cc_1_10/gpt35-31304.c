//FormAI DATASET v1.0 Category: Unit converter ; Style: funny
#include<stdio.h>

int main() {

    // Welcome the user
    printf("Hey there! I'm a unit converter bot. You can ask me to convert units and I'll try my best! \n\n");

    // Ask the user what they want to convert
    printf("So, what do you want me to convert? Here are your options:\n");
    printf("1. Feet to Meters\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Fahrenheit to Celsius\n");
    printf("5. Gallons to Liters\n");
    printf("Enter your choice (1-5): ");
    
    int option;
    scanf("%d", &option);

    float input;
    float output;

    switch(option) {

        case 1:
            printf("\nOkay, you want to convert feet to meters. Give me a value: ");
            scanf("%f", &input);
            output = input * 0.3048;
            printf("%.2f feet is %.2f meters. Easy peasy lemon squeezy! \n", input, output);
            break;

        case 2:
            printf("\nNo problem, we can convert pounds to kilograms. Enter a value: ");
            scanf("%f", &input);
            output = input * 0.453592;
            printf("%.2f pounds is equal to %.2f kilograms. I'm converting like a boss! \n", input, output);
            break;

        case 3:
            printf("\nYou got it! Let's convert miles to kilometers. Enter a value: ");
            scanf("%f", &input);
            output = input * 1.60934;
            printf("%.2f miles is equal to %.2f kilometers. This is so much fun! \n", input, output);
            break;

        case 4:
            printf("\nAlright, Fahrenheit to Celsius it is. Give me a temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = (input - 32) * 5/9;
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius. I'm on fire! \n", input, output);
            break;

        case 5:
            printf("\nGallons to liters, coming right up! Enter the number of gallons you want to convert: ");
            scanf("%f", &input);
            output = input * 3.78541;
            printf("%.2f gallons is equal to %.2f liters. This is going swimmingly! \n", input, output);
            break;

        default:
            printf("\nOops, you entered an invalid option. Please try again with a number between 1 and 5 (inclusive). \n");
            break;
    }

    // Thank the user for using the program and say goodbye
    printf("\nThanks for using my unit converter bot! Have a great day. Goodbye! \n");

    return 0;
}