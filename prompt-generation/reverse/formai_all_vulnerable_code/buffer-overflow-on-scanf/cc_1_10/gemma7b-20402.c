//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Variables
    int age, height, weight, year_of_birth, number_of_pets, favorite_color;

    // Get the user's input
    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your height (in inches): ");
    scanf("%d", &height);

    printf("Please enter your weight (in pounds): ");
    scanf("%d", &weight);

    printf("Please enter the year of your birth: ");
    scanf("%d", &year_of_birth);

    printf("Please enter the number of pets you have: ");
    scanf("%d", &number_of_pets);

    printf("Please enter your favorite color: ");
    scanf("%s", &favorite_color);

    // Calculate the user's age in years
    int age_in_years = age;

    // Calculate the user's age in months
    int age_in_months = 12 * age_in_years + age % 12;

    // Calculate the user's height in centimeters
    int height_in_centimeters = height * 2.54;

    // Calculate the user's weight in kilograms
    int weight_in_kilograms = weight * 0.45359;

    // Print the user's information
    printf("Your name is: ");
    printf("Your age is: %d years, %d months", age_in_years, age_in_months);
    printf("Your height is: %d centimeters", height_in_centimeters);
    printf("Your weight is: %d kilograms", weight_in_kilograms);
    printf("Your year of birth is: %d", year_of_birth);
    printf("You have %d pets.", number_of_pets);
    printf("Your favorite color is: %s", favorite_color);

    return 0;
}