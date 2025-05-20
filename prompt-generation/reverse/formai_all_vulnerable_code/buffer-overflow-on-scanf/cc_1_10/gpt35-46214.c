//FormAI DATASET v1.0 Category: Unit converter ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int menu(void);
void feet_meters(void);
void celsius_fahrenheit(void);
void toonies_to_dollars();

int main()
{
    printf("\t\tWelcome to the Wacky Conversion Program!\n");
    printf("**********************************************************************\n\n");
    while (1)
    {
        switch (menu())
        {
            case 1: feet_meters(); break;
            case 2: celsius_fahrenheit(); break;
            case 3: toonies_to_dollars(); break;
            case 4: printf("Thanks for using the Wacky Conversion Program! Goodbye!"); exit(0);
            default: printf("Invalid input. Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

int menu(void)
{
    int choice;
    printf("\nPlease choose from the following conversion options:\n");
    printf("\t1. Feet to Meters\n");
    printf("\t2. Celsius to Fahrenheit\n");
    printf("\t3. Canadian Toonies to US Dollars\n");
    printf("\t4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void feet_meters(void)
{
    float feet, meters;
    printf("Enter the number of feet: ");
    scanf("%f", &feet);
    meters = feet * 0.3048;
    printf("%0.2f feet is equal to %0.2f meters.\n\n", feet, meters);
}

void celsius_fahrenheit(void)
{
    float celsius, fahrenheit;
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%0.2f degrees Celsius is equal to %0.2f degrees Fahrenheit.\n\n", celsius, fahrenheit);
}

void toonies_to_dollars()
{
    float toonies, dollars;
    printf("Enter the number of Canadian Toonies: ");
    scanf("%f", &toonies);
    dollars = toonies * 0.78;
    printf("%0.2f Canadian Toonies is equal to $%0.2f US Dollars.\n\n", toonies, dollars);
}