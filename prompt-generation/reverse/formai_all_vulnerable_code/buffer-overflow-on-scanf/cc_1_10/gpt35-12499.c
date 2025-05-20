//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice;
    float measurement;
    printf("Welcome to our unit converter!\n\n");
    printf("Please select an option: \n");
    printf("1. Convert inches to centimeters\n");
    printf("2. Convert centimeters to inches\n");
    printf("3. Convert pounds to kilograms\n");
    printf("4. Convert kilograms to pounds\n");
    printf("5. Convert miles to kilometers\n");
    printf("6. Convert kilometers to miles\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the measurement in inches: ");
            scanf("%f", &measurement);
            printf("%.2f inches is equal to %.2f centimeters.\n", measurement, measurement*2.54);
            break;

        case 2:
            printf("Enter the measurement in centimeters: ");
            scanf("%f", &measurement);
            printf("%.2f centimeters is equal to %.2f inches.\n", measurement, measurement/2.54);
            break;

        case 3:
            printf("Enter the weight in pounds: ");
            scanf("%f", &measurement);
            printf("%.2f pounds is equal to %.2f kilograms.\n", measurement, measurement/2.20462);
            break;

        case 4:
            printf("Enter the weight in kilograms: ");
            scanf("%f", &measurement);
            printf("%.2f kilograms is equal to %.2f pounds.\n", measurement, measurement*2.20462);
            break;

        case 5:
            printf("Enter the distance in miles: ");
            scanf("%f", &measurement);
            printf("%.2f miles is equal to %.2f kilometers.\n", measurement, measurement*1.60934);
            break;

        case 6:
            printf("Enter the distance in kilometers: ");
            scanf("%f", &measurement);
            printf("%.2f kilometers is equal to %.2f miles.\n", measurement, measurement/1.60934);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}