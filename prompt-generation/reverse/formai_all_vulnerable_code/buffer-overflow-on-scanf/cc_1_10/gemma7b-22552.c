//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ANSWERS 5

int main()
{
    char name[20];
    int age, lucky_number, answer;
    char fortune[MAX_ANSWERS][20];

    printf("Welcome to the Enchanted Oracle, %s.\n", name);
    printf("Please provide your age:");
    scanf("%d", &age);
    printf("Enter your lucky number:");
    scanf("%d", &lucky_number);

    // Generate fortune
    switch (age)
    {
        case 18:
            sprintf(fortune[0], "You are on the cusp of greatness, but beware of the pitfalls of youth.");
            break;
        case 21:
            sprintf(fortune[1], "Your star is shining brightly, expect success and fortune.");
            break;
        case 30:
            sprintf(fortune[2], "The tide is turning, bring change and new opportunities.");
            break;
        case 40:
            sprintf(fortune[3], "You have weathered the storms, enjoy the fruits of your labor.");
            break;
        default:
            sprintf(fortune[4], "May the odds be ever in your favor.");
            break;
    }

    // Interpret lucky number
    switch (lucky_number)
    {
        case 1:
            sprintf(fortune[0], "You are favored by the celestial forces, expect great luck.");
            break;
        case 3:
            sprintf(fortune[1], "The odds are in your favor, prepare for success.");
            break;
        case 5:
            sprintf(fortune[2], "Your path is illuminated, expect wealth and prosperity.");
            break;
        case 7:
            sprintf(fortune[3], "The stars align in your favor, prepare for greatness.");
            break;
        default:
            sprintf(fortune[4], "May the odds be ever in your favor.");
            break;
    }

    // Show fortune
    printf("Your fortune is:");
    printf("\n");
    for (answer = 0; answer < MAX_ANSWERS; answer++)
    {
        printf("%s\n", fortune[answer]);
    }

    return 0;
}