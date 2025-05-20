//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the bingo card
void print_card(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
int check_win(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        if (card[i][0] == card[i][1] && card[i][1] == card[i][2] && card[i][2] == card[i][3] && card[i][3] == card[i][4])
            return 1;
        if (card[0][i] == card[1][i] && card[1][i] == card[2][i] && card[2][i] == card[3][i] && card[3][i] == card[4][i])
            return 1;
    }
    if (card[0][0] == card[1][1] && card[1][1] == card[2][2] && card[2][2] == card[3][3] && card[3][3] == card[4][4])
        return 1;
    if (card[0][4] == card[1][3] && card[1][3] == card[2][2] && card[2][2] == card[3][1] && card[3][1] == card[4][0])
        return 1;
    return 0;
}

int main() {
    int i, j, k, l, m;
    int card[5][5];
    int player_card[5][5];
    int bingo = 0;
    int choice;

    srand(time(0));

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            card[i][j] = rand_num(1, 15);
            player_card[i][j] = rand_num(1, 15);
        }
    }

    printf("Welcome to the Bingo Simulator!\n");
    printf("Here is your card:\n");
    print_card(card);
    printf("\n");

    while (!bingo) {
        printf("Enter a number between 1 and 15: ");
        scanf("%d", &choice);
        k = rand_num(0, 4);
        l = rand_num(0, 4);
        if (choice == card[k][l]) {
            player_card[k][l] = -1;
            printf("You got a match!\n");
        } else {
            printf("Sorry, that's not a match.\n");
        }
        bingo = check_win(player_card);
    }

    printf("\nCongratulations! You won!\n");

    return 0;
}