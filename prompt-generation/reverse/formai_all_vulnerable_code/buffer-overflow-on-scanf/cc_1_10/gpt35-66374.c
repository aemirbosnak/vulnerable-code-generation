//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int search(int arr[], int n, int key);

int main()
{
    int arr[SIZE];
    int key, i, found = 0, player_found = 0;

    srand(time(NULL));

    // Generate random array
    printf("The array: ");
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    printf("\n\nLet's play a game! Each player will take turns to guess a number in the array.\n");
    printf("The player who finds the number first wins!\n");

    // Decide who goes first
    int player = rand() % 2 + 1;
    printf("\nPlayer %d goes first!\n", player);

    // Loop until number is found
    while (!found)
    {
        printf("\nPlayer %d's turn: ", player);
        scanf("%d", &key);

        player_found = search(arr, SIZE, key);

        if (player_found)
        {
            printf("Congratulations player %d! You found %d!\n", player, key);
            found = 1;
        }
        else
        {
            printf("Sorry player %d, %d is not in the array.\n", player, key);
        }

        // Switch to other player
        if (player == 1)
            player = 2;
        else
            player = 1;
    }

    return 0;
}

/* Function to search for key in array */
int search(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return 1;
    }

    return 0;
}