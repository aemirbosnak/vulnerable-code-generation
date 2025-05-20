//FormAI DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

int main() {
    // Greeting the user
    printf("Hello there! Thank you for using our unit converter.\n\n");

    // Variables to hold user input and converted results
    float input, output;
    int choice;

    // Displaying menu options
    printf("Please choose which conversion you would like to make:\n");
    printf("1. Inches to centimeters\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Miles to kilometers\n");

    // Getting user choice
    scanf("%d", &choice);

    // Switch statement to handle user choice
    switch (choice) {
        case 1:
            printf("You selected Inches to centimeters.\n");
            printf("Please enter the number of inches you would like to convert: ");
            scanf("%f", &input);

            // Conversion calculation
            output = input * 2.54;

            printf("%.2f inches is equal to %.2f centimeters.", input, output);
            break;
        case 2:
            printf("You selected Fahrenheit to Celsius.\n");
            printf("Please enter the temperature in Fahrenheit you would like to convert: ");
            scanf("%f", &input);

            // Conversion calculation
            output = (input - 32) * 5 / 9;

            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", input, output);
            break;
        case 3:
            printf("You selected Miles to kilometers.\n");
            printf("Please enter the number of miles you would like to convert: ");
            scanf("%f", &input);

            // Conversion calculation
            output = input * 1.609344;

            printf("%.2f miles is equal to %.2f kilometers.", input, output);
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }

    // Thanking the user for using the program
    printf("\n\nThank you for using our converter! Have a great day.");
    
    return 0;
}