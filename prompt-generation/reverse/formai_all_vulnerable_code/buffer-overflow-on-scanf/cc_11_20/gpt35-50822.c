//FormAI DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main()
{
    char input[MAX_WORD_LENGTH];
    char words[MAX_PLAYERS][MAX_WORDS][MAX_WORD_LENGTH];
    int unique_words[MAX_PLAYERS][MAX_WORDS];
    int num_players = 0, num_words[MAX_PLAYERS] = {0}, i = 0, j = 0, k = 0, max = 0, max_player = 0, count = 0;

    printf("Welcome to the Word Counting Game!\n");
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    while (num_players < 1 || num_players > MAX_PLAYERS)
    {
        printf("Invalid number of players. Enter the number of players (max %d): ", MAX_PLAYERS);
        scanf("%d", &num_players);
    }

    printf("You have %d players.\n", num_players);

    // Input loop
    for (i = 0; i < MAX_WORDS && count < num_players; i++)
    {
        printf("Player %d, enter a word (max length %d): ", count + 1, MAX_WORD_LENGTH - 1);
        scanf("%s", input);

        if (strcmp(input, "done") == 0 && i != 0)
        {
            count++;
        }
        else if (strlen(input) > MAX_WORD_LENGTH - 1)
        {
            printf("Invalid word. Try again.\n");
            i--;
        }
        else
        {
            int unique = 1;

            // Check if word is already used by this player
            for (j = 0; j < num_words[count]; j++)
            {
                if (strcmp(input, words[count][j]) == 0)
                {
                    unique_words[count][j]++;
                    unique = 0;
                    break;
                }
            }

            // Add new word
            if (unique)
            {
                strcpy(words[count][num_words[count]], input);
                unique_words[count][num_words[count]] = 1;
                num_words[count]++;
            }
        }
    }

    // Print word counts
    for (i = 0; i < num_players; i++)
    {
        int total_unique = 0;
        printf("Player %d words: ", i + 1);

        for (j = 0; j < num_words[i]; j++)
        {
            printf("%s(%d) ", words[i][j], unique_words[i][j]);
            total_unique += unique_words[i][j];
        }

        printf("\nTotal unique words: %d\n\n", total_unique);

        if (total_unique > max)
        {
            max = total_unique;
            max_player = i + 1;
        }
    }

    printf("Player %d wins with %d unique words!\n", max_player, max);

    return 0;
}