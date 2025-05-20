//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>

int main()
{
    float length_meter, length_centimeter, length_foot, length_inch;
    int option, repeat;

    do
    {
        printf("Welcome to the UltraPrecise Unit Converter! \n");
        printf("Please choose the conversion option: \n");
        printf("1 - Meters to Centimeters \n");
        printf("2 - Centimeters to Meters \n");
        printf("3 - Feet to Inches \n");
        printf("4 - Inches to Feet \n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter length in Meters: \n");
            scanf("%f", &length_meter);
            length_centimeter = length_meter * 100;
            printf("%.20f Meters equal to %.20f Centimeters \n", length_meter, length_centimeter);
            break;

        case 2:
            printf("Enter length in Centimeters: \n");
            scanf("%f", &length_centimeter);
            length_meter = length_centimeter / 100;
            printf("%.20f Centimeters equal to %.20f Meters \n", length_centimeter, length_meter);
            break;

        case 3:
            printf("Enter length in Feet: \n");
            scanf("%f", &length_foot);
            length_inch = length_foot * 12;
            printf("%.20f Feet equal to %.20f Inches \n", length_foot, length_inch);
            break;

        case 4:
            printf("Enter length in Inches: \n");
            scanf("%f", &length_inch);
            length_foot = length_inch / 12;
            printf("%.20f Inches equal to %.20f Feet \n", length_inch, length_foot);
            break;

        default:
            printf("Invalid input. Please try again. \n");
            break;
        }

        printf("Do you want to convert another unit? (1 for Yes, 0 for No) ");
        scanf("%d", &repeat);

    } while (repeat);

    printf("Thank you for using UltraPrecise Unit Converter! \n");

    return 0;
}