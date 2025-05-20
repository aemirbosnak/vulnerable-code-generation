//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    float fahrenheit, celsius;
    char choice;
    int valid_input = 0;

    do
    {
        printf("Welcome to the Temperature Converter!\n");
        printf("Please enter your choice:\n");
        printf("1. Convert Fahrenheit to Celsius\n");
        printf("2. Convert Celsius to Fahrenheit\n");
        printf("3. Exit\n");

        scanf("%c", &choice);

        switch(choice)
        {
            case '1':
                printf("Please enter the temperature in Fahrenheit:\n");
                if(scanf("%f", &fahrenheit) == 1)
                {
                    valid_input = 1;
                }
                else
                {
                    printf("Invalid input. Please enter a number.\n");
                }
                break;

            case '2':
                printf("Please enter the temperature in Celsius:\n");
                if(scanf("%f", &celsius) == 1)
                {
                    valid_input = 1;
                }
                else
                {
                    printf("Invalid input. Please enter a number.\n");
                }
                break;

            case '3':
                printf("Thank you for using the Temperature Converter!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while(choice!= '3');

    if(valid_input)
    {
        if(choice == '1')
        {
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, (fahrenheit - 32) * 5/9);
        }
        else if(choice == '2')
        {
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, celsius * 9/5 + 32);
        }
    }

    return 0;
}