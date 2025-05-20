//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>

int main()
{
    float temp_f, temp_c, length_cm, length_inches;
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("\nPlease select an option:\n");
    printf("1. Fahrenheit to Celsius converter\n");
    printf("2. Celsius to Fahrenheit converter\n");
    printf("3. Centimeters to Inches converter\n");
    printf("4. Inches to Centimeters converter\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    while(choice != 5)
    {
        switch(choice)
        {
            case 1:
                printf("\nEnter the temperature in Fahrenheit: ");
                scanf("%f", &temp_f);
                temp_c = (temp_f - 32) * 5 / 9;
                printf("The temperature in Celsius is: %.2f\n\n", temp_c);
                break;

            case 2:
                printf("\nEnter the temperature in Celsius: ");
                scanf("%f", &temp_c);
                temp_f = (temp_c * 9 / 5) + 32;
                printf("The temperature in Fahrenheit is: %.2f\n\n", temp_f);
                break;

            case 3:
                printf("\nEnter the length in centimeters: ");
                scanf("%f", &length_cm);
                length_inches = length_cm / 2.54;
                printf("The length in inches is: %.2f\n\n", length_inches);
                break;

            case 4:
                printf("\nEnter the length in inches: ");
                scanf("%f", &length_inches);
                length_cm = length_inches * 2.54;
                printf("The length in centimeters is: %.2f\n\n", length_cm);
                break;

            default:
                printf("\nInvalid option selected!\n");
                break;
        }

        printf("Please select another option or enter 5 to exit:\n");
        scanf("%d", &choice);
    }

    printf("\nThank you for using the Unit Converter!\n");

    return 0;
}