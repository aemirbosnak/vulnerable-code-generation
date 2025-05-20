//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include<stdio.h>
#include<stdlib.h>

/* Function to display the game board */
void display(char arr[]) {
    printf("\n\n\tBATTLESHIP GAME\n\n");
    printf("\t  1   2   3   4   5   6   7   8   9   10\n");
    printf("\t _____________________________________\n");
    for(int i = 0; i < 100; i++) {
        if(i % 10 == 0) {
            printf("\t|%c", arr[i]);
        } else if(i % 10 == 9) {
            printf(" %c|\n", arr[i]);
        } else {
            printf(" %c", arr[i]);
        }
    }
    printf("\t -------------------------------------\n");
}

/* Function to check if the player has hit the ship*/
int is_hit(int choice, char arr[]) {
    if(arr[choice - 1] == '#') {
        return 1;
    }
    return 0;
}

/*Main function*/
int main() {
    char player1[100] = {0}, player2[100] = {0};
    int ship1[5] = {0}, ship2[5] = {0}, choice;
    int p1_hits = 0, p2_hits = 0;
    int turn = 0, flag = 0;

    /* Set up the ships */
    printf("\tWelcome to Battleship Game\n\n");
    printf("Set up your battleship by choosing position of 5 ships.\n");

    int temp;
    for(int i = 0; i < 5; i++) {
        printf("Enter position of ship%d: ", i + 1);
        scanf("%d", &temp);
        while(temp < 0 || temp > 100) {
            printf("Invalid input! Enter again: ");
            scanf("%d", &temp);
        }
        ship1[i] = temp - 1;
        player1[ship1[i]] = '#';
    }
    system("clear");

    /* Set up the second player's board */
    printf("Player 1's board has been set up!\n");
    printf("Player 2: Set up your battleship by choosing position of 5 ships.\n");

    for(int i = 0; i < 5; i++) {
        printf("Enter position of ship%d: ", i + 1);
        scanf("%d", &temp);
        while(temp < 0 || temp > 100) {
            printf("Invalid input! Enter again: ");
            scanf("%d", &temp);
        }
        ship2[i] = temp - 1;
        player2[ship2[i]] = '#';
    }
    system("clear");

    /* Start the game */
    while(p1_hits < 5 && p2_hits < 5) {
        if(turn % 2 == 0) {
            printf("Player 1's turn:\n");
        } else {
            printf("Player 2's turn:\n");
        }

        if(turn % 2 == 0) {
            display(player2);
            printf("Enter a number between 1 and 100 to fire at: ");
            scanf("%d", &choice);
            while(choice < 0 || choice > 100) {
                printf("Invalid input! Enter again: ");
                scanf("%d", &choice);
            }
            if(is_hit(choice, player2)) {
                printf("You hit the target!!!\n\n");
                player2[choice - 1] = 'X';
                p1_hits++;
            } else {
                printf("You missed!\n\n");
                player2[choice - 1] = 'O';
            }
        } else {
            display(player1);
            printf("Enter a number between 1 and 100 to fire at: ");
            scanf("%d", &choice);
            while(choice < 0 || choice > 100) {
                printf("Invalid input! Enter again: ");
                scanf("%d", &choice);
            }
            if(is_hit(choice, player1)) {
                printf("You hit the target!!!\n\n");
                player1[choice - 1] = 'X';
                p2_hits++;
            } else {
                printf("You missed!\n\n");
                player1[choice - 1] = 'O';
            }
        }

        turn++;
        system("clear");
    }

    /* Display the winner */
    if(p1_hits == 5) {
        printf("Player 1 wins!!!\n");
    } else {
        printf("Player 2 wins!!!\n");
    }

    return 0;
}