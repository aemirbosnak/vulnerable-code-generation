//FormAI DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
// C Program to convert between various units
// Inspired by Ada Lovelace, the world’s first computer programmer

#include<stdio.h>

int main()
{
    int choice;
    float value;
    printf("Hello! I am Ada, let me help you convert between various units\n");
    printf("Please choose the conversion type:\n");
    printf("1. Length Conversion\n");
    printf("2. Temperature Conversion\n");
    printf("3. Mass Conversion\n");
    printf("4. Volume Conversion\n");
    scanf("%d", &choice);

    // Length Conversion
    if(choice == 1)
    {
        int subChoice;
        printf("You have selected Length Conversion\n");
        printf("Please choose the sub-type:\n");
        printf("1. Kilometres to Metres\n");
        printf("2. Metres to Kilometres\n");
        printf("3. Feet to Inches\n");
        printf("4. Inches to Feet\n");
        scanf("%d", &subChoice);

        if(subChoice == 1)
        {
            printf("Enter the value in Kilometres: ");
            scanf("%f", &value);
            printf("The value in Metres is: %f\n", value * 1000);
        }
        else if(subChoice == 2)
        {
            printf("Enter the value in Metres: ");
            scanf("%f", &value);
            printf("The value in Kilometres is: %f\n", value / 1000);
        }
        else if(subChoice == 3)
        {
            printf("Enter the value in Feet: ");
            scanf("%f", &value);
            printf("The value in Inches is: %f\n", value * 12);
        }
        else if(subChoice == 4)
        {
            printf("Enter the value in Inches: ");
            scanf("%f", &value);
            printf("The value in Feet is: %f\n", value / 12);
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    // Temperature Conversion
    else if(choice == 2)
    {
        int subChoice;
        printf("You have selected Temperature Conversion\n");
        printf("Please choose the sub-type:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        scanf("%d", &subChoice);

        if(subChoice == 1)
        {
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            printf("The temperature in Fahrenheit is: %f\n", (value * 9/5) + 32);
        }
        else if(subChoice == 2)
        {
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            printf("The temperature in Celsius is: %f\n", (value - 32) * 5/9);
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    // Mass Conversion
    else if(choice == 3)
    {
        int subChoice;
        printf("You have selected Mass Conversion\n");
        printf("Please choose the sub-type:\n");
        printf("1. Kilograms to Grams\n");
        printf("2. Grams to Kilograms\n");
        printf("3. Pounds to Ounces\n");
        printf("4. Ounces to Pounds\n");
        scanf("%d", &subChoice);

        if(subChoice == 1)
        {
            printf("Enter the mass in Kilograms: ");
            scanf("%f", &value);
            printf("The mass in Grams is: %f\n", value * 1000);
        }
        else if(subChoice == 2)
        {
            printf("Enter the mass in Grams: ");
            scanf("%f", &value);
            printf("The mass in Kilograms is: %f\n", value / 1000);
        }
        else if(subChoice == 3)
        {
            printf("Enter the mass in Pounds: ");
            scanf("%f", &value);
            printf("The mass in Ounces is: %f\n", value * 16);
        }
        else if(subChoice == 4)
        {
            printf("Enter the mass in Ounces: ");
            scanf("%f", &value);
            printf("The mass in Pounds is: %f\n", value / 16);
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    // Volume Conversion
    else if(choice == 4)
    {
        int subChoice;
        printf("You have selected Volume Conversion\n");
        printf("Please choose the sub-type:\n");
        printf("1. Litres to Millilitres\n");
        printf("2. Millilitres to Litres\n");
        printf("3. Gallons to Quarts\n");
        printf("4. Quarts to Gallons\n");
        scanf("%d", &subChoice);

        if(subChoice == 1)
        {
            printf("Enter the volume in Litres: ");
            scanf("%f", &value);
            printf("The volume in Millilitres is: %f\n", value * 1000);
        }
        else if(subChoice == 2)
        {
            printf("Enter the volume in Millilitres: ");
            scanf("%f", &value);
            printf("The volume in Litres is: %f\n", value / 1000);
        }
        else if(subChoice == 3)
        {
            printf("Enter the volume in Gallons: ");
            scanf("%f", &value);
            printf("The volume in Quarts is: %f\n", value * 4);
        }
        else if(subChoice == 4)
        {
            printf("Enter the volume in Quarts: ");
            scanf("%f", &value);
            printf("The volume in Gallons is: %f\n", value / 4);
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    else
    {
        printf("Invalid Choice\n");
    }
    return 0;
}