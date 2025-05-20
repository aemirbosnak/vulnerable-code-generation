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

    while (1)
    {
        // Calculate the next level's score based on the current level.
        int next_score = level * 10 + 50;

        // Overflow the integer variable 'score'.
        score = next_score + 1;

        // Print the score and level.
        printf("Score: %d\n", score);
        printf("Level: %d\n", level);

        // Increment the level if the score reaches the next level's score.
        if (score >= next_score)
        {
            level++;
        }

        // Break out of the loop when the score reaches the maximum score.
        if (score >= 100)
        {
            break;
        }
    }

    return 0;
}
