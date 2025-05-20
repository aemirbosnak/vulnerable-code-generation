//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>

int main()
{
    // Function prototypes
    float convertWeight(float grams);
    float convertLength(float meters);
    float convertVolume(float liters);

    // Main program
    int choice;
    do
    {
        printf("\n\nWelcome to the Unit Converter!\n");
        printf("1. Convert weight\n");
        printf("2. Convert length\n");
        printf("3. Convert volume\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the weight in grams: ");
            float grams;
            scanf("%f", &grams);
            printf("\nThe weight in kilograms is %f.\n", convertWeight(grams));
            break;

        case 2:
            printf("Enter the length in meters: ");
            float meters;
            scanf("%f", &meters);
            printf("\nThe length in centimeters is %f.\n", convertLength(meters));
            break;

        case 3:
            printf("Enter the volume in liters: ");
            float liters;
            scanf("%f", &liters);
            printf("\nThe volume in milliliters is %f.\n", convertVolume(liters));
            break;

        case 4:
            printf("\n\nGoodbye!\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice!= 4);

    return 0;
}

// Function to convert weight from grams to kilograms
float convertWeight(float grams)
{
    return grams / 1000;
}

// Function to convert length from meters to centimeters
float convertLength(float meters)
{
    return meters * 100;
}

// Function to convert volume from liters to milliliters
float convertVolume(float liters)
{
    return liters * 1000;
}