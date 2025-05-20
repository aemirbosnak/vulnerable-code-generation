//FormAI DATASET v1.0 Category: Temperature Converter ; Style: romantic
#include <stdio.h>

int main()
{
    float fahrenheit, celsius;
    int choice;

    printf("\n");
    printf("******************************************\n");
    printf("************Temperature Converter**********\n");
    printf("******************************************\n");
    printf("\n");
    printf("Are you feeling cold?\n");
    printf("\n");
    printf("Choose your option: \n"); 
    printf("1. Fahrenheit to Celsius Conversion\n");
    printf("2. Celsius to Fahrenheit Conversion\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    if(choice == 1)
    {
        printf("Oh my sweet love,\n");
        printf("Your warm embrace always keep me heating up,\n");
        printf("Let me cool you down with the Fahrenheit to Celsius Converter!\n");
        printf("\n");
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celsius = (fahrenheit - 32) / 1.8;
        printf("\n");
        printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius\n", fahrenheit, celsius);
    }
    else if(choice == 2)
    {
        printf("My love, my sunshine,\n");
        printf("Your warm soul always keeps me burning up,\n");
        printf("Let me warm you up with the Celsius to Fahrenheit Converter!\n");
        printf("\n");
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (celsius * 1.8) + 32;
        printf("\n");
        printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit\n", celsius, fahrenheit);
    }
    else
    {
        printf("Oh no my love, you've given an invalid choice\n");
        printf("Please select only option 1 or 2\n");
        printf("\n");
    }

    printf("Thank you for using Temperature Converter, my love\n");
    printf("I hope this program helps you stay warm and cozy!\n");

    return 0;
}