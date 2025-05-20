//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define WORDS_PER_ROW 5

int main()
{

    char **words = (char**)malloc(MAX_WORDS * sizeof(char*));
    for (int i = 0; i < MAX_WORDS; i++)
    {
        words[i] = (char*)malloc(WORDS_PER_ROW * sizeof(char));
    }

    // Fill the words with random text
    srand(time(NULL));
    for (int i = 0; i < MAX_WORDS; i++)
    {
        for (int j = 0; j < WORDS_PER_ROW; j++)
        {
            words[i][j] = (char)rand() % 26 + 'a';
        }
    }

    // Create the memory game grid
    int gridSize = MAX_WORDS * WORDS_PER_ROW;
    int **grid = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++)
    {
        grid[i] = (int*)malloc(WORDS_PER_ROW * sizeof(int));
    }

    // Shuffle the grid
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < WORDS_PER_ROW; j++)
        {
            grid[i][j] = rand() % MAX_WORDS;
        }
    }

    // Play the game
    int score = 0;
    char guessWord[WORDS_PER_ROW];
    for (int round = 0; round < 5; round++)
    {
        // Get the guess word
        printf("Enter your guess word: ");
        scanf("%s", guessWord);

        // Check if the guess word is correct
        int isWordCorrect = 1;
        for (int i = 0; i < WORDS_PER_ROW; i++)
        {
            if (guessWord[i] != words[grid[round][i]][0])
            {
                isWordCorrect = 0;
            }
        }

        // Award points if the word is correct
        if (isWordCorrect)
        {
            score++;
            printf("Congratulations! You won a point!\n");
        }
        else
        {
            printf("Sorry, your guess word is incorrect.\n");
        }
    }

    // Print the final score
    printf("Your final score is: %d\n", score);

    // Free the memory
    for (int i = 0; i < MAX_WORDS; i++)
    {
        free(words[i]);
    }
    free(words);

    for (int i = 0; i < gridSize; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}