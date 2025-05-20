//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

int generate_random_number()
{
    srand(time(NULL));
    return rand() % ARRAY_SIZE + 1;
}

int search(int *array, int key, int left, int right)
{
    while (left <= right) {
        int mid = (left + right) / 2;

        if (array[mid] == key) {
            return mid;
        } else if (array[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int array[ARRAY_SIZE], i, j, key, index, player_count, player_turn, winner;

    printf("Enter the number of players (2 - 5): ");
    scanf("%d", &player_count);

    printf("\n");

    // Initialize array with random numbers
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = generate_random_number();
    }

    // Shuffle array
    for (i = 0; i < ARRAY_SIZE; i++) {
        j = rand() % ARRAY_SIZE;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Choose a random number to search
    key = generate_random_number();

    // Game starts
    player_turn = 1;
    winner = -1;

    while (winner == -1) {
        printf("Player %d's turn: ", player_turn);
        scanf("%d", &index);

        if (index < 1 || index > ARRAY_SIZE) {
            printf("Invalid index. Try again.\n");
            continue;
        }

        index--;

        if (array[index] == key) {
            printf("Congratulations, Player %d! You won the game!\n", player_turn);
            winner = player_turn;
        } else if (search(array, key, 0, index - 1) != -1) {
            printf("The key is to the left of index %d. Try again.\n", index + 1);
        } else if (search(array, key, index + 1, ARRAY_SIZE - 1) != -1) {
            printf("The key is to the right of index %d. Try again.\n", index + 1);
        } else {
            printf("Sorry, Player %d. The key is not in the array. Try again.\n", player_turn);
        }

        player_turn = (player_turn % player_count) + 1;
    }

    return 0;
}