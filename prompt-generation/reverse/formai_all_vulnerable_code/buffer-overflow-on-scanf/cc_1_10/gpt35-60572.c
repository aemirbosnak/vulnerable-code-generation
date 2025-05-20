//FormAI DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>

// Conversion functions
float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

float kilometers_to_miles(float kilometers)
{
    return kilometers / 1.609;
}

float miles_to_kilometers(float miles)
{
    return miles * 1.609;
}

// Main function to display options and handle user input
int main()
{
    printf("Welcome to Unit Converter - Multiplayer Edition!\n\nSelect your player:\n(1) Player 1\n(2) Player 2\nEnter choice: ");

    int player;
    scanf("%d", &player);

    switch(player)
    {
        case 1:
        {
            printf("\nPlayer 1 - Select a conversion:\n(1) Celsius to Fahrenheit\n(2) Kilometers to Miles\n");
            int choice;
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                {
                    float celsius;
                    printf("Enter temperature in Celsius: ");
                    scanf("%f", &celsius);

                    float fahrenheit = celsius_to_fahrenheit(celsius);
                    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
                    break;
                }
                case 2:
                {
                    float kilometers;
                    printf("Enter distance in Kilometers: ");
                    scanf("%f", &kilometers);

                    float miles = kilometers_to_miles(kilometers);
                    printf("%.2f Kilometers = %.2f Miles\n", kilometers, miles);
                    break;
                }
                default:
                    printf("Invalid choice\n");
            }
            break;
        }
        case 2:
        {
            printf("\nPlayer 2 - Select a conversion:\n(1) Fahrenheit to Celsius\n(2) Miles to Kilometers\n");
            int choice;
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                {
                    float fahrenheit;
                    printf("Enter temperature in Fahrenheit: ");
                    scanf("%f", &fahrenheit);

                    float celsius = fahrenheit_to_celsius(fahrenheit);
                    printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
                    break;
                }
                case 2:
                {
                    float miles;
                    printf("Enter distance in Miles: ");
                    scanf("%f", &miles);

                    float kilometers = miles_to_kilometers(miles);
                    printf("%.2f Miles = %.2f Kilometers\n", miles, kilometers);
                    break;
                }
                default:
                    printf("Invalid choice\n");
            }
            break;
        }
        default:
            printf("Invalid player\n");
    }

    return 0;
}