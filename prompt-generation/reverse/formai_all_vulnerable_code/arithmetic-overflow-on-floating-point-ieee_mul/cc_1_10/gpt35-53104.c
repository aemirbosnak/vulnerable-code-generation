//FormAI DATASET v1.0 Category: Unit converter ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice1, choice2;
    float value, result;

    printf("Welcome to the Intelligent Unit Converter Program!\n");

    printf("\nHere are the options to choose:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Miles to Kilometers\n4. Kilometers to Miles\n");

    printf("\nEnter your first choice: ");
    scanf("%d",&choice1);

    printf("\nEnter your second choice: ");
    scanf("%d",&choice2);

    printf("\nEnter the value to be converted: ");
    scanf("%f", &value);

    if(choice1 == choice2)
    {
        printf("\nInvalid selection! Please select different units to convert.\n");

        exit(0);
    }

    switch(choice1)
    {
        case 1:
            if(choice2 == 2)
            {
                result = ((value*9)/5)+32;

                printf("\n%.2f Celsius is %.2f Fahrenheit.", value, result);
            }
            else
            {
                printf("\nInvalid selection! Please select different units to convert.\n");

                exit(0);
            }
            break;

        case 2:
            if(choice2 == 1)
            {
                result = ((value-32)*5)/9;

                printf("\n%.2f Fahrenheit is %.2f Celsius.", value, result);
            }
            else
            {
                printf("\nInvalid selection! Please select different units to convert.\n");

                exit(0);
            }
            break;

        case 3:
            if(choice2 == 4)
            {
                result = value * 1.60934;

                printf("\n%.2f Miles is %.2f Kilometers.", value, result);
            }
            else
            {
                printf("\nInvalid selection! Please select different units to convert.\n");

                exit(0);
            }
            break;

        case 4:
            if(choice2 == 3)
            {
                result = value * 0.621371;

                printf("\n%.2f Kilometers is %.2f Miles.", value, result);
            }
            else
            {
                printf("\nInvalid selection! Please select different units to convert.\n");

                exit(0);
            }
            break;

        default:
            printf("\nInvalid selection! Please select a valid option.\n");

            exit(0);
            break;
    }

    printf("\nThank you for using the Intelligent Unit Converter Program!\n");

    return 0;
}