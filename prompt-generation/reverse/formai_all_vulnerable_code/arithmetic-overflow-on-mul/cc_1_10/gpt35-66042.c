//FormAI DATASET v1.0 Category: Unit converter ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int option, value;
    float result;

    printf("\nHey there, welcome to the Crazy Converter!\n\n");

    while(1)
    {
        printf("What do you want to convert today?\n");
        printf("1. Meter to Foot\n2. Liter to Gallon\n3. Centimeter to Inch\n4. Celsius to Fahrenheit\n5. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                printf("\nEnter the value in meter: ");
                scanf("%d",&value);
                result = value * 3.2808;
                printf("\n%d meter is equal to %.1f foot\n\n", value, result);
                break;
            case 2:
                printf("\nEnter the value in liter: ");
                scanf("%d",&value);
                result = value * 0.2642;
                printf("\n%d liter is equal to %.1f gallon\n\n", value, result);
                break;
            case 3:
                printf("\nEnter the value in centimeter: ");
                scanf("%d",&value);
                result = value * 0.3937;
                printf("\n%d centimeter is equal to %.1f inch\n\n", value, result);
                break;
            case 4:
                printf("\nEnter the value in Celsius: ");
                scanf("%d",&value);
                result = (value * 9/5) + 32;
                printf("\n%d Celsius is equal to %.1f Fahrenheit\n\n", value, result);
                break;
            case 5:
                printf("\nThanks for using the Crazy Converter!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n\n");
                break;
        }
    }

    return 0;
}