//FormAI DATASET v1.0 Category: Memory Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the deck
void shuffle(int *arr, int n)
{
    int temp, j;
    for (int i = n - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to check if the card has already been selected
int is_selected(int *arr, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (arr[i] == arr[index])
            return 1;
    }
    return 0;
}

int main()
{
    int n = 10; // Number of cards
    int cards[n];
    int selected[n];
    srand(time(0));

    // Initialize the deck
    for (int i = 0; i < n; i++)
    {
        cards[i] = i + 1;
        selected[i] = 0;
    }

    // Shuffle the deck
    shuffle(cards, n);

    // Main game loop
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        int choice;
        printf("Choose a card: ");
        scanf("%d", &choice);

        // Check if the card has already been selected
        if (is_selected(selected, choice - 1))
        {
            printf("You have already selected that card. Please choose again.\n");
            i--; // Decrement the loop counter
            continue;
        }

        // Check if the choice is valid
        if (choice < 1 || choice > n)
        {
            printf("Invalid choice. Please choose again.\n");
            i--; // Decrement the loop counter
            continue;
        }

        // Mark the card as selected
        selected[choice - 1] = 1;

        // Check if the choice matches the card
        if (cards[choice - 1] == choice)
        {
            printf("Congratulations! You have matched the card!\n");
            score++;
        }
        else
        {
            printf("Sorry, that card does not match.\n");
        }

        printf("Score: %d\n", score);

        // Check if the game has ended
        if (score == n / 2)
        {
            printf("You have won the game!");
            break;
        }
    }

    return 0;
}