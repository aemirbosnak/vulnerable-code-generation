//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Let's get silly with our data structures!
typedef struct {
    int value;  // The secret squirrel hiding behind the card
    int revealed;  // Is our squirrel trying to play peek-a-boo?
} SquirrelCard;

int main() {
    srand(time(NULL));  // Let's let destiny shuffle our deck!

    // Okay, time to set up the grid of squirrels!
    SquirrelCard grid[4][4];
    int squirrels[8] = {1, 1, 2, 2, 3, 3, 4, 4};  // Our furry little matchmakers

    // Let's scatter our squirrels randomly across the grid
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int index = rand() % 8;  // Picking a random squirrel from our bag of nuts
            grid[i][j].value = squirrels[index];
            grid[i][j].revealed = 0;  // Shhh, keep our squirrels hidden!
            squirrels[index] = squirrels[7 - index];  // Swapping our squirrels to keep them on their toes
        }
    }

    // Time for the big reveal!
    int matches = 0;  // Let's keep track of our matchmaking progress
    int firstRow, firstCol, secondRow, secondCol;  // Squirrel detectives on the case!

    while (matches < 8) {
        // Player 1, take your turn!
        printf("Player 1, pick a card, any card: ");
        scanf("%d %d", &firstRow, &firstCol);
        grid[firstRow][firstCol].revealed = 1;  // Let's see what's peeking out!
        printf("Ta-da! You found a squirrel with value %d\n", grid[firstRow][firstCol].value);

        // Player 2, your turn to impress!
        printf("Player 2, now it's your turn: ");
        scanf("%d %d", &secondRow, &secondCol);
        grid[secondRow][secondCol].revealed = 1;  // Time to uncover another secret!
        printf("Oh my, another squirrel! This one's value is %d\n", grid[secondRow][secondCol].value);

        // Did our players find a love match?
        if (grid[firstRow][firstCol].value == grid[secondRow][secondCol].value) {
            printf("Huzzah! You found a matching pair!\n");
            matches += 2;  // Two squirrels found a soulmate!
            grid[firstRow][firstCol].revealed = 0;  // Time for a makeover, squirrel!
            grid[secondRow][secondCol].revealed = 0;  // New outfit, new adventure!
        } else {
            printf("Aww, no match this time. Better luck next turn!\n");
            grid[firstRow][firstCol].revealed = 0;  // Looks like our squirrel is playing hard to get
            grid[secondRow][secondCol].revealed = 0;  // And so is this one!
        }
    }

    // Congratulations to our squirrel matchmakers!
    printf("Congratulations! You've found all the matching pairs!\n");

    return 0;
}