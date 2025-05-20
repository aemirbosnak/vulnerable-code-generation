//Gemma-7B DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int age, gender, income, hobby;
    char name[50];

    // Get the user's name, age, gender, income, and hobby
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gender (M/F): ");
    scanf("%c", &gender);

    printf("Enter your income: ");
    scanf("%d", &income);

    printf("Enter your hobby (e.g. reading, dancing, coding): ");
    scanf("%s", hobby);

    // Calculate the user's horoscope sign
    int horoscope_sign = calculate_horoscope_sign(age);

    // Print the user's horoscope sign
    printf("Your horoscope sign is: %c", horoscope_sign);

    // Print a personalized message
    printf("Hello, %s. You are %d years old and your horoscope sign is %c. You have a income of $%d and your hobby is %s.", name, age, horoscope_sign, income, hobby);

    return 0;
}

int calculate_horoscope_sign(int age)
{
    int sign = age / 12;

    switch (sign)
    {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
        case 4:
            return 'E';
        case 5:
            return 'F';
        case 6:
            return 'G';
        case 7:
            return 'H';
        case 8:
            return 'I';
        case 9:
            return 'J';
        default:
            return 'K';
    }
}