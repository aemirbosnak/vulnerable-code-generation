//FormAI DATASET v1.0 Category: Table Game ; Style: standalone
// A unique C Table Game example program - "Guess the Number Duel"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting up the random number generator
    srand(time(NULL));

    // Displaying the game title and rules
    printf("=== Guess the Number Duel ===\n");
    printf("In this game, you and your opponent will each choose a number between 1 and 100.\n");
    printf("The first player to correctly guess the other player's number wins the game!\n");

    // Asking for player names
    char name1[20], name2[20];
    printf("Player 1, enter your name: ");
    scanf("%s", name1);
    printf("Player 2, enter your name: ");
    scanf("%s", name2);
    printf("Let the game begin!\n");

    // Generating the secret numbers
    int secret1 = rand() % 100 + 1;
    int secret2 = rand() % 100 + 1;

    // The game loop
    while (1) {
        // Player 1's turn
        printf("%s, guess Player 2's number: ", name1);
        int guess1;
        scanf("%d", &guess1);
        if (guess1 == secret2) {
            printf("Congratulations, %s! You have correctly guessed %s's number.\n", name1, name2);
            printf("%s wins!", name1);
            break;
        } else if (guess1 < secret2) {
            printf("%d is too low.\n", guess1);
        } else {
            printf("%d is too high.\n", guess1);
        }

        // Player 2's turn
        printf("%s, guess Player 1's number: ", name2);
        int guess2;
        scanf("%d", &guess2);
        if (guess2 == secret1) {
            printf("Congratulations, %s! You have correctly guessed %s's number.\n", name2, name1);
            printf("%s wins!", name2);
            break;
        } else if (guess2 < secret1) {
            printf("%d is too low.\n", guess2);
        } else {
            printf("%d is too high.\n", guess2);
        }
    }

    return 0;
}