//FormAI DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int menu(); // function prototype

int main()
{
    int choice = 0;
    float input = 0.0;
    float output = 0.0;

    while (choice != 5) { // use a while loop to keep showing menu until user quits
        choice = menu(); // call the menu function and store user input

        // use a switch statement to call appropriate conversion function based on user choice
        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input);
                output = (input - 32) * 5/9;
                printf("%.2fF = %.2fC\n", input, output);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                output = (input * 9/5) + 32;
                printf("%.2fC = %.2fF\n", input, output);
                break;
            case 3:
                printf("Enter distance in miles: ");
                scanf("%f", &input);
                output = input * 1.60934;
                printf("%.2f miles = %.2f kilometers\n", input, output);
                break;
            case 4:
                printf("Enter distance in kilometers: ");
                scanf("%f", &input);
                output = input * 0.621371;
                printf("%.2f kilometers = %.2f miles\n", input, output);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    printf("Thank you for using the unit converter!\n");

    return 0;
}

int menu()
{
    int choice = 0;

    printf("\nUnit Converter Menu:\n");
    printf("---------------------\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}