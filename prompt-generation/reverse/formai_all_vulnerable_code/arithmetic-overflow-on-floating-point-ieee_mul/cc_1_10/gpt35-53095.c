//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>

int main() {
    float input;
    char choice;

    printf("Welcome to the Unit Converter!\n");
    printf("-----------------------------\n");

    do {
        printf("\nPlease choose which unit you would like to convert to:\n");
        printf("a. Inches to Centimeters\n");
        printf("b. Feet to Meters\n");
        printf("c. Miles to Kilometers\n");
        printf("d. Fahrenheit to Celsius\n");
        printf("e. Pounds to Kilograms\n");
        printf("f. Quit\n");

        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                printf("\nEnter the length in inches: ");
                scanf("%f", &input);

                printf("%.2f inches is equal to %.2f centimeters.\n", input, input*2.54);
                break;
            case 'b':
                printf("\nEnter the length in feet: ");
                scanf("%f", &input);

                printf("%.2f feet is equal to %.2f meters.\n", input, input*0.3048);
                break;
            case 'c':
                printf("\nEnter the distance in miles: ");
                scanf("%f", &input);

                printf("%.2f miles is equal to %.2f kilometers.\n", input, input*1.60934);
                break;
            case 'd':
                printf("\nEnter the temperature in Fahrenheit: ");
                scanf("%f", &input);

                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", input, (input-32)*5/9);
                break;
            case 'e':
                printf("\nEnter the weight in pounds: ");
                scanf("%f", &input);

                printf("%.2f pounds is equal to %.2f kilograms.\n", input, input*0.453592);
                break;
            case 'f':
                printf("\nThank you for using the Unit Converter!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please choose a valid option.\n");
                break;
        }
    } while(1);

    return 0;
}