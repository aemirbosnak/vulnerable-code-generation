//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number within limit
int generate_random(int limit)
{
    int num = (rand() % limit) + 1;
    return num;
}

// function to convert English to Alien language
void english_to_alien(char *english, char *alien)
{
    int i;
    for(i = 0; i < strlen(english); i++)
    {
        if(english[i] == ' ')
            alien[i] = ' ';
        else
            alien[i] = generate_random(9) + '0';
    }
    alien[i] = '\0';
}

// function to compare two alien words
int alien_word_compare(char* word_one, char* word_two)
{
    int i, count = 0;
    for(i = 0; i < strlen(word_one); i++)
    {
        if(word_one[i] == word_two[i])
            count++;
    }
    return count;
}

int main()
{
    char english[100], alien[100];
    int players, i, j, k, score[10] = {0}, max_score, winner;
    srand(time(NULL));

    // get number of players from user
    printf("Enter number of players: ");
    scanf("%d", &players);

    // get english word from first player
    printf("Player 1, Enter an English word: ");
    scanf("%s", english);

    // convert to alien word
    english_to_alien(english, alien);

    // game loop for all players
    for(i = 0; i < players; i++)
    {
        printf("\n\n==== Player %d's turn ====\n", i+1);

        // ask player to guess alien word
        printf("Guess the Alien word: ");
        char guess[100];
        scanf("%s", guess);

        // compare guessed word with actual word
        int count = alien_word_compare(alien, guess);

        // update score of current player
        score[i] = count;

        // display score of all players so far
        printf("Current Scores:\n");
        for(j = 0; j < players; j++)
            printf("Player %d: %d\n", j+1, score[j]);

        // check if current player has guessed the word correctly
        if(count == strlen(alien))
        {
            printf("\n\nPlayer %d guessed the word correctly!\n", i+1);
            break;
        }

        // if last player could not guess correctly
        if(i == players-1)
        {
            printf("\n\nAll players have guessed the word.\n");
            printf("The correct Alien word was: %s\n", alien);

            // find winner with max score
            max_score = score[0];
            winner = 1;
            for(k = 1; k < players; k++)
            {
                if(score[k] > max_score)
                {
                    max_score = score[k];
                    winner = k+1;
                }
            }
            printf("The winner is Player %d with a score of %d!\n", winner, max_score);
        }
    }

    return 0;
}