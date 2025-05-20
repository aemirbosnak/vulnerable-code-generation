//FormAI DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAX_GUESSES 5

int main()
{
    int number, guess, guesses_left = MAX_GUESSES;
    int i, j, k;
    int row, column, direction;
    int table[SIZE][SIZE] = {0};
    char paranoia[SIZE][SIZE] = {'?'};

    // Seed the random number generator based on current time
    srand(time(NULL));

    // Generate a random number to be guessed
    number = rand() % 100 + 1;

    // Generate a table with random numbers from 1 to 9 with one of them being the actual number
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if(rand() % 3 == 0) // 33% of cells will be randomly filled
            {
                table[i][j] = rand() % 9 + 1;
            }
            if(table[i][j] == number) // place the actual number in the table
            {
                row = i;
                column = j;
            }
        }
    }

    // Place the hints for players based on the position of the actual number in the table
    paranoia[row][column] = '+';

    // True paranoia: add fake hints in random locations
    for(k = 0; k < 2; k++)
    {
        i = rand() % SIZE;
        j = rand() % SIZE;

        if(paranoia[i][j] != '+')
        {
            paranoia[i][j] = '-';
        }
        else // if the fake hint is on the actual number, move it to a new location
        {
            direction = rand() % 4;

            switch(direction)
            {
                case 0: // move left
                    if(column > 0)
                    {
                        column--;
                    }
                    break;
                case 1: // move right
                    if(column < SIZE - 1)
                    {
                        column++;
                    }
                    break;
                case 2: // move up
                    if(row > 0)
                    {
                        row--;
                    }
                    break;
                case 3: // move down
                    if(row < SIZE - 1)
                    {
                        row++;
                    }
                    break;
            }

            paranoia[row][column] = '-';
        }
    }

    // Print the table and hints
    printf("Find the hidden number!\n");
    printf("You have %d guesses left.\n", guesses_left);

    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if(paranoia[i][j] == '?')
            {
                printf("?");
            }
            else
            {
                printf("%c", paranoia[i][j]);
            }
        }
        printf("\n");
    }

    // Ask the user to guess the number
    while(guesses_left > 0)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guesses_left--;

        if(guess == number)
        {
            printf("Congratulations, you found the hidden number!\n");
            return 0;
        }
        else if(guess > number)
        {
            printf("Your guess is too high. ");
        }
        else
        {
            printf("Your guess is too low. ");
        }

        if(guesses_left == 0)
        {
            printf("Game over. The hidden number was %d\n", number);
        }
        else
        {
            printf("You have %d guesses left.\n", guesses_left);
        }
    }

    return 0;
}