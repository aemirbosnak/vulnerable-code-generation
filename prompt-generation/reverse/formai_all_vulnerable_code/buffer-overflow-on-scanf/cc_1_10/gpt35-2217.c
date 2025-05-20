//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to clear the screen in the terminal
void clear_screen()
{
    system("clear");
}

// function to generate a random number within a range
int generate_random_number(int start, int end)
{
    int num;
    srand(time(NULL));
    num = (rand() % (end - start + 1)) + start;
    return num;
}

int main()
{
    int score = 0; // initialize score to 0
    int level = 1; // initialize level to 1
    int lives = 3; // initialize lives to 3
    int num, guess;
    char play_again = 'y';

    while (play_again == 'y')
    {
        // clear the screen and display the game information
        clear_screen();
        printf("Level: %d\tScore: %d\tLives: %d\n", level, score, lives);
        printf("Guess the number between 1 and %d\n\n", level * 10);
        
        // generate the random number for the current level
        num = generate_random_number(1, level * 10);

        // loop to give the user three chances to guess the number
        for (int i = 1; i <= 3; i++)
        {
            printf("Guess %d: ", i);
            scanf("%d", &guess); // take the user's guess

            // check if the guess is correct
            if (guess == num)
            {
                printf("You guessed it right!\n");
                score += (level * 10) + (lives * 10); // update the score
                break; // exit the loop
            }
            else
            {
                printf("Wrong answer!\n");
                lives--; // reduce the number of lives
                if (lives == 0)
                {
                    printf("Game Over!\nFinal Score: %d\n", score);
                    printf("Do you want to play again? (y/n)");
                    scanf(" %c", &play_again);
                    score = 0; // reset the score
                    level = 1; // reset the level
                    lives = 3; // reset the lives
                    break; // exit the loop
                }
                else
                {
                    printf("You have %d lives left.\n", lives);
                }
            }
        }

        // check if the user has guessed the number in all three chances
        if (lives > 0 && score >= (level * 100))
        {
            printf("Congratulations! You have completed level %d!\n", level);
            level++; // increase the level
            lives = 3; // reset the lives for the next level
        }
    }

    return 0;
}