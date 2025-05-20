//FormAI DATASET v1.0 Category: Unit converter ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int choice;
    float amount;

    printf("\n\t=====C CONVERT UNIT PROGRAM=====\n\n");

    do
    {
        printf("\t1. Convert Miles to Kilometers.\n");
        printf("\t2. Convert Pounds to Kilograms.\n");
        printf("\t3. Convert Gallons to Liters.\n");
        printf("\t4. Convert Inches to Centimeters.\n");
        printf("\t5. Convert Fahrenheit to Celsius.\n");
        printf("\t6. Convert Celsius to Fahrenheit.\n");
        printf("\t7. Exit Program.\n\n");

        printf("\tPlease enter your choice (1-7): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n\tEnter the distance in miles: ");
                scanf("%f", &amount);
                printf("\t%.2f miles is equal to %.2f kilometers.\n\n", amount, amount*1.609);
                break;

            case 2:
                printf("\n\tEnter the weight in pounds: ");
                scanf("%f", &amount);
                printf("\t%.2f pounds is equal to %.2f kilograms.\n\n", amount, amount*0.4536);
                break;

            case 3:
                printf("\n\tEnter the volume in gallons: ");
                scanf("%f", &amount);
                printf("\t%.2f gallons is equal to %.2f liters.\n\n", amount, amount*3.785);
                break;

            case 4:
                printf("\n\tEnter the length in inches: ");
                scanf("%f", &amount);
                printf("\t%.2f inches is equal to %.2f centimeters.\n\n", amount, amount*2.54);
                break;

            case 5:
                printf("\n\tEnter the temperature in Fahrenheit: ");
                scanf("%f", &amount);
                printf("\t%.2f Fahrenheit is equal to %.2f Celsius.\n\n", amount, (amount-32)*5/9);
                break;

            case 6:
                printf("\n\tEnter the temperature in Celsius: ");
                scanf("%f", &amount);
                printf("\t%.2f Celsius is equal to %.2f Fahrenheit.\n\n", amount, (amount*9/5)+32);
                break;

            case 7:
                printf("\n\tThanks for using C CONVERT UNIT PROGRAM.\n\tGoodbye!\n\n");
                exit(0);

            default:
                printf("\n\tInvalid choice. Please select a choice from the menu.\n\n");
                break;
        }
    }while(choice!=7);
}