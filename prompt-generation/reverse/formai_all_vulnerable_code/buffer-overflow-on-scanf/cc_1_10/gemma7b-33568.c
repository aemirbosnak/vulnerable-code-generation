//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    char name[20];
    int age;
    char sign[12];
    int num;

    // Get user input
    printf("What is your name? ");
    scanf("%s", name);

    printf("How old are you? ");
    scanf("%d", &age);

    // Calculate zodiac sign
    if (age >= 21)
    {
        sign[0] = 'A';
        sign[1] = 'G';
    }
    else if (age >= 19)
    {
        sign[0] = 'C';
        sign[1] = 'F';
    }
    else if (age >= 17)
    {
        sign[0] = 'E';
        sign[1] = 'H';
    }
    else if (age >= 15)
    {
        sign[0] = 'B';
        sign[1] = 'D';
    }
    else
    {
        sign[0] = 'D';
        sign[1] = 'C';
    }

    // Get lucky number
    num = rand() % 11;

    // Display results
    printf("Your name is: %s\n", name);
    printf("You are %d years old.\n", age);
    printf("Your zodiac sign is: %c%c\n", sign[0], sign[1]);
    printf("Your lucky number is: %d\n", num);

    return 0;
}