//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the array
void shuffle(int *array, int size)
{
    int temp, random_index;
    for (int i = 0; i < size; i++)
    {
        random_index = rand() % size;
        temp = array[i];
        array[i] = array[random_index];
        array[random_index] = temp;
    }
}

int main()
{
    int size;
    printf("Enter the size of the memory game (even number): ");
    scanf("%d", &size);
    if (size % 2 != 0)
    {
        printf("Error: Please enter an even number.\n");
        return 0;
    }

    // Creating the cards
    int cards[size];
    for (int i = 0; i < size; i += 2)
    {
        cards[i] = i / 2 + 1;
        cards[i+1] = i / 2 + 1;
    }

    // Shuffling the cards
    srand(time(NULL));
    shuffle(cards, size);

    // Creating the game board
    int board[size];
    for (int i = 0; i < size; i++)
    {
        board[i] = 0;
    }

    printf("Let's start the game!\n");

    int first_card, second_card, pairs_found = 0;
    while (pairs_found < size/2)
    {
        printf("Enter the index of the first card: ");
        scanf("%d", &first_card);
        printf("Enter the index of the second card: ");
        scanf("%d", &second_card);

        // Checking if the cards are a match
        if (cards[first_card] == cards[second_card])
        {
            printf("You found a matching pair!\n");
            board[first_card] = 1;
            board[second_card] = 1;
            pairs_found++;
        }
        else
        {
            printf("There is no match.\n");
        }

        // Printing the current state of the game board
        printf("Current state of the game board:\n");
        for (int i = 0; i < size; i++)
        {
            if (board[i] == 0)
            {
                printf("X ");
            }
            else
            {
                printf("%d ", cards[i]);
            }
        }
        printf("\n\n");
    }

    printf("Congratulations! You won the game!\n");

    return 0;
}