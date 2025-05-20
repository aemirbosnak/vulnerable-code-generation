#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0;
    int level = 1;

    printf("Welcome to the Text-Based Game Engine!\n");
    printf("Start your journey by entering 'start'.\n");

    char input[20];
    scanf("%s", input);

    if (strcmp(input, "start") == 0)
    {
        while (level <= 10)
        {
            // Calculate the score multiplier based on the level
            int multiplier = level * 2;

            // Overflow the int variable "score" by adding a large number
            score = score + multiplier * 1000000000;

            // Display the score and level
            printf("Your score: %d\n", score);
            printf("Level: %d\n", level);

            // Increment the level
            level++;
        }
    }

    printf("Thank you for playing! Goodbye.\n");

    return 0;
}
