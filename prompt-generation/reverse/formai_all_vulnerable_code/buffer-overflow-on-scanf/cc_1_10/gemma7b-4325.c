//Gemma-7B DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int score = 0, lives = 5, game_state = 0, current_level = 1;
    char character = 'a';

    // Game loop
    while (lives > 0)
    {
        // Display current level and score
        printf("Level: %d, Score: %d\n", current_level, score);

        // Get user input
        printf("Enter move (a-d): ");
        scanf("%c", &character);

        // Validate input
        if (character < 'a' || character > 'd')
        {
            printf("Invalid input.\n");
            continue;
        }

        // Update game state based on character input
        switch (character)
        {
            case 'a':
                character = 'A';
                break;
            case 'b':
                character = 'B';
                break;
            case 'c':
                character = 'C';
                break;
            case 'd':
                character = 'D';
                break;
        }

        // Check if character has reached the end of the level
        if (character == 'D')
        {
            // Level complete, increase score and level
            score++;
            current_level++;

            // Display level complete message
            printf("Congratulations! You completed level %d!\n", current_level);
        }
        else
        {
            // Move character forward, update game state
            character++;
            game_state = 1;
        }

        // Check if game state is changed
        if (game_state)
        {
            // Display character position
            printf("Character: %c\n", character);

            // Update game state
            game_state = 0;
        }
    }

    // Game over, display final score
    printf("Game Over! Your final score is: %d\n", score);
}