//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the bingo card
#define CARD_SIZE 5

// Define the number of rows and columns in the bingo card
#define ROWS 5
#define COLS 5

// Create a bingo card
int card[ROWS][COLS];

// Create a list of possible numbers for the bingo card
int numbers[75];

// Initialize the bingo card
void init_card()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            card[i][j] = 0;
        }
    }
}

// Generate a random number for the bingo card
int get_random_number()
{
    int number = rand() % 75 + 1;
    return number;
}

// Fill the bingo card with random numbers
void fill_card()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int number = get_random_number();
            while (card[i][j] != 0)
            {
                number = get_random_number();
            }
            card[i][j] = number;
        }
    }
}

// Print the bingo card
void print_card()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Check if the bingo card has won
int check_card()
{
    // Check rows
    for (int i = 0; i < ROWS; i++)
    {
        int count = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (card[i][j] == 0)
            {
                count++;
            }
        }
        if (count == COLS)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++)
    {
        int count = 0;
        for (int i = 0; i < ROWS; i++)
        {
            if (card[i][j] == 0)
            {
                count++;
            }
        }
        if (count == ROWS)
        {
            return 1;
        }
    }

    // Check diagonals
    int count1 = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (card[i][i] == 0)
        {
            count1++;
        }
    }
    if (count1 == ROWS)
    {
        return 1;
    }
    int count2 = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (card[i][ROWS - 1 - i] == 0)
        {
            count2++;
        }
    }
    if (count2 == ROWS)
    {
        return 1;
    }

    // No win
    return 0;
}

// Play the bingo game
void play_game()
{
    // Initialize the bingo card
    init_card();

    // Fill the bingo card with random numbers
    fill_card();

    // Print the bingo card
    print_card();

    // Get the input from the user
    int number = 0;
    while (number != -1)
    {
        printf("Enter a number (-1 to quit): ");
        scanf("%d", &number);

        // Check if the number is valid
        if (number < 1 || number > 75)
        {
            printf("Invalid number. Please enter a number between 1 and 75.\n");
            continue;
        }

        // Check if the number is on the bingo card
        int found = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (card[i][j] == number)
                {
                    card[i][j] = 0;
                    found = 1;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }

        // Print the bingo card
        print_card();

        // Check if the bingo card has won
        int win = check_card();
        if (win)
        {
            printf("Bingo! You won!\n");
            break;
        }
    }
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Play the bingo game
    play_game();

    return 0;
}