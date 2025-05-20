//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loveGame(int player1, int player2);

int main() {
    int players[2];
    srand(time(0));
    for (int i = 0; i < 2; i++) {
        players[i] = rand() % 100 + 1;
    }
    printf("Welcome to the game of love!\n");
    printf("Player 1 has %d love points and Player 2 has %d love points.\n", players[0], players[1]);
    loveGame(players[0], players[1]);
    return 0;
}

void loveGame(int player1, int player2) {
    while (player1 > 0 && player2 > 0) {
        int choice;
        printf("It's your turn, Player 1. What do you choose?\n");
        printf("1. Send a love letter\n");
        printf("2. Give a bouquet of flowers\n");
        printf("3. Sing a love song\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                player1 -= 10;
                player2 += 5;
                printf("Player 1 sends a love letter to Player 2, increasing their love points by 5.\n");
                break;
            case 2:
                player1 -= 15;
                player2 += 10;
                printf("Player 1 gives a bouquet of flowers to Player 2, increasing their love points by 10.\n");
                break;
            case 3:
                player1 -= 20;
                player2 += 15;
                printf("Player 1 sings a love song to Player 2, increasing their love points by 15.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        if (player1 <= 0) {
            printf("Player 1 runs out of love points. Player 2 wins!\n");
            break;
        }
    }
    if (player2 <= 0) {
        printf("Player 2 runs out of love points. Player 1 wins!\n");
    }
}