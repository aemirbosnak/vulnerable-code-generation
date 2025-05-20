//FormAI DATASET v1.0 Category: Unit converter ; Style: detailed
#include<stdio.h>

int main()
{
    int choice1, choice2;
    float value1, value2;

    printf("Welcome to Unique Unit Converter!\n\n");

    printf("Choose the type of conversion:\n\n");
    printf("1. Length\n2. Mass\n3. Temperature\n4. Speed\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    printf("\nChoose the initial unit:\n\n");

    // Selection for Length conversion
    if(choice1 == 1)
    {
        printf("1. Inches\n2. Feet\n3. Yards\n4. Miles\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice2);

        printf("\nEnter the value to be converted: ");
        scanf("%f", &value1);

        // Conversion of inches to other units
        if(choice2 == 1)
        {
            value2 = value1/12;
            printf("\n%.2f inches is %.2f feet.\n", value1, value2);

            value2 = value1/36;
            printf("%.2f inches is %.2f yards.\n", value1, value2);

            value2 = value1/63360;
            printf("%.2f inches is %.5f miles.\n", value1, value2);
        }

        // Conversion of feet to other units
        else if(choice2 == 2)
        {
            value2 = value1*12;
            printf("\n%.2f feet is %.2f inches.\n", value1, value2);

            value2 = value1/3;
            printf("%.2f feet is %.2f yards.\n", value1, value2);

            value2 = value1/5280;
            printf("%.2f feet is %.5f miles.\n", value1, value2);
        }

        // Conversion of yards to other units
        else if(choice2 == 3)
        {
            value2 = value1*36;
            printf("\n%.2f yards is %.2f inches.\n", value1, value2);

            value2 = value1*3;
            printf("%.2f yards is %.2f feet.\n", value1, value2);

            value2 = value1/1760;
            printf("%.2f yards is %.5f miles.\n", value1, value2);
        }

        // Conversion of miles to other units
        else if(choice2 == 4)
        {
            value2 = value1*63360;
            printf("\n%.2f miles is %.2f inches.\n", value1, value2);

            value2 = value1*5280;
            printf("%.2f miles is %.2f feet.\n", value1, value2);

            value2 = value1*1760;
            printf("%.2f miles is %.2f yards.\n", value1, value2);
        }
    }

    printf("\nThank you for using Unique Unit Converter!\n");

    return 0;
}