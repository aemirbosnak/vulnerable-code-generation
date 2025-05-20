//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 4  // Size of board
#define MAX_ATTEMPTS 10  // Number of attempts allowed
#define CARD_PAIRS BOARD_SIZE*BOARD_SIZE/2  // Number of card pairs

void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void shuffle(int board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(int board[BOARD_SIZE][BOARD_SIZE], int attempts);
int checkGame(int board[BOARD_SIZE][BOARD_SIZE]);

int main(){
    int board[BOARD_SIZE][BOARD_SIZE];
    int i, j, card1, card2, row1, col1, row2, col2, win, attempts;

    srand(time(0));  // Seed random number generator

    printf("Welcome to the Romantic Memory Game!\n");
    printf("Match the pairs of cards to show your love for your partner!\n");

    initializeBoard(board);
    shuffle(board);  // Shuffle cards

    attempts = 0;
    win = 0;  // Set win to 0

    while(attempts < MAX_ATTEMPTS && !win){
        printBoard(board, attempts);  // Print board
        printf("Choose two cards to flip (row column): ");
        scanf("%d %d", &row1, &col1);  // Get first card choice
        while(board[row1][col1] == -1){  // Check if card has already been flipped
            printf("This card has already been flipped. Choose another (row column): ");
            scanf("%d %d", &row1, &col1);  // Get new card choice
        }
        card1 = board[row1][col1];  // Get value of first card
        
        printf("Choose another card to flip (row column): ");
        scanf("%d %d", &row2, &col2);  // Get second card choice
        while(board[row2][col2] == -1){  // Check if card has already been flipped
            printf("This card has already been flipped. Choose another (row column): ");
            scanf("%d %d", &row2, &col2);  // Get new card choice
        }
        card2 = board[row2][col2];  // Get value of second card

        board[row1][col1] = -1;  // Flip first card
        board[row2][col2] = -1;  // Flip second card

        printBoard(board, attempts);  // Print board with flipped cards

        if(card1 == card2){
            printf("Matched!\n");
            win = checkGame(board);  // Check if game is won
        }
        else{
            printf("Not a match. Try again.\n");
            board[row1][col1] = card1;  // Flip first card back over
            board[row2][col2] = card2;  // Flip second card back over
        }

        attempts++;  // Increment attempts
    }

    if(win){
        printf("Congratulations, you have completed the Romantic Memory Game and shown your love for your partner!\n");
    }
    else{
        printf("Sorry, you have exceeded the maximum number of attempts. Better luck next time!\n");
    }

    return 0;
}

// Function to initialize board with pairs of cards
void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]){
    int pairs[CARD_PAIRS];
    int i, j, k;

    // Populate array with pairs of cards
    for(i = 0; i < CARD_PAIRS; i++){
        pairs[i] = i;
        pairs[i+CARD_PAIRS] = i;
    }

    // Shuffle card pairs
    for(i = 0; i < CARD_PAIRS*2; i++){
        j = rand()%(CARD_PAIRS*2);
        k = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = k;
    }

    // Initialize board with shuffled card pairs
    k = 0;
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            board[i][j] = pairs[k];
            k++;
        }
    }
}

// Function to shuffle cards
void shuffle(int board[BOARD_SIZE][BOARD_SIZE]){
    int i, j, k, l, temp;

    // Perform multiple swaps to shuffle cards
    for(k = 0; k < BOARD_SIZE*BOARD_SIZE; k++){
        i = rand()%BOARD_SIZE;
        j = rand()%BOARD_SIZE;

        l = rand()%BOARD_SIZE;
        while(l == i){
            l = rand()%BOARD_SIZE;
        }
        temp = board[i][j];
        board[i][j] = board[l][j];
        board[l][j] = temp;
    }
}

// Function to print board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE], int attempts){
    int i, j;

    printf("Attempts: %d\n\n", attempts);
    printf("   ");
    for(i = 0; i < BOARD_SIZE; i++){
        printf("%d ", i);
    }
    printf("\n");
    printf("  ------------\n");
    for(i = 0; i < BOARD_SIZE; i++){
        printf("%d | ", i);
        for(j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] == -1){
                printf("* ");
            }
            else{
                printf("%d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("  ------------\n\n");
}

// Function to check if game is won
int checkGame(int board[BOARD_SIZE][BOARD_SIZE]){
    int i, j, win;

    win = 1;  // Set win to 1

    // Check if any cards are still face down
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] != -1){
                win = 0;
            }
        }
    }

    return win;
}