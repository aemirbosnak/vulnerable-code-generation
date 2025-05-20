//FormAI DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

/* Function to shuffle the array */
void shuffle(int arr[], int n) 
{ 
    srand(time(NULL));
    for (int i = 0; i < n; i++) { 
        int j = rand() % n; 
        int temp = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = temp; 
    } 
} 

/* Function to display the game board */
void display(int board[], int size) 
{ 
    printf(" ");
    for (int i = 0; i < size; i++) {
        printf(" _____");
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("|     ");
    }
    printf("|\n");
    for (int i = 0; i < size; i++) {
        if (board[i] == 0) {
            printf("|  %c  ", '?');
        } else {
            printf("|  %2d  ", board[i]);
        }
    }
    printf("|\n");
    for (int i = 0; i < size; i++) {
        printf("|_____");
    }
    printf("|\n");
} 

/* Main function */
int main() 
{ 
    int board[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int player1[SIZE] = {0};
    int player2[SIZE] = {0}; 
    int p1Count = 0, p2Count = 0, turn = 1;

    shuffle(board, SIZE);

    while (p1Count < 5 && p2Count < 5) {
        printf("Player%d, it's your turn.\n", turn);

        display(turn == 1 ? player1 : player2, SIZE);
        
        int chosenIndex;
        do {
            printf("Choose an index between 0 and %d: ", SIZE-1);
            scanf("%d", &chosenIndex);
        } while (chosenIndex < 0 || chosenIndex > SIZE-1 || (turn == 1 && player2[chosenIndex] != 0) || (turn == 2 && player1[chosenIndex] != 0));
        
        if (board[chosenIndex] == 7) {
            printf("Oh no! You picked the unlucky number 7!\n");
            if (turn == 1) player1[p1Count++] = board[chosenIndex];
            else if (turn == 2) player2[p2Count++] = board[chosenIndex];
            board[chosenIndex] = 0;
        } else if ((turn == 1 && p1Count == 5) || (turn == 2 && p2Count == 5)) {
            printf("Oops! You have already picked your 5 lucky numbers. Choose another index.\n");
        } else {
            printf("Great choice! You found a lucky number!\n");
            if (turn == 1) player1[p1Count++] = board[chosenIndex];
            else if (turn == 2) player2[p2Count++] = board[chosenIndex];
        }

        /* switch turns */
        if (turn == 1) turn = 2;
        else if (turn == 2) turn = 1;
    }

    /* Display the final scoreboard */
    printf("\n\n");
    printf("Player1's lucky numbers:\n");
    for (int i = 0; i < p1Count; i++) {
        printf("%d ", player1[i]);
    }
    printf("\n\n");
    printf("Player2's lucky numbers:\n");
    for (int i = 0; i < p2Count; i++) {
        printf("%d ", player2[i]);
    }
    printf("\n\n");

    /* Announce the winner */
    if (p1Count > p2Count) {
        printf("Congratulations Player1! You win!\n");
    } else if (p2Count > p1Count) {
        printf("Congratulations Player2! You win!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0; 
}