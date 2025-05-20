//FormAI DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>

int main()
{
    int choice;
    float input;

    printf("Welcome to my curious unit converter program!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Miles to Kilometers\n");
        printf("3. Convert Pounds to Kilograms\n");
        printf("4. Exit program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &input);

                float fahrenheit = (input * 9 / 5) + 32;
                printf("%.2f Celsius is %.2f Fahrenheit", input, fahrenheit);
                break;

            case 2:
                printf("\nEnter distance in miles: ");
                scanf("%f", &input);

                float kilometers = input * 1.609344;
                printf("%.2f miles is equal to %.2f kilometers", input, kilometers);
                break;

            case 3:
                printf("\nEnter weight in pounds: ");
                scanf("%f", &input);

                float kilograms = input * 0.453592;
                printf("%.2f pounds is equal to %.2f kilograms", input, kilograms);
                break;

            case 4:
                printf("\nThank you for using my curious unit converter program!");
                break;

            default:
                printf("\nInvalid choice, please select a valid option.");
                break;
        }
    } while(choice != 4);

    return 0;
}