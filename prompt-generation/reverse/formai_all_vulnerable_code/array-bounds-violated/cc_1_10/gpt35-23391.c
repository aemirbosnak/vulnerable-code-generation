//FormAI DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16
#define MAX_VAL 8

/* Function to shuffle the array */
void shuffle(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int random_index = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[random_index];
        array[random_index] = temp;
    }
}

/* Function to print the game board */
void print_board(int *board, int size) {
    for (int i = 0; i < size; i++) {
        if (i % 4 == 0) printf("\n\n");
        printf("%2d ", board[i]);
    }
    printf("\n\n");
}

/* Function to get user input */
int get_input() {
    int input;
    printf("Enter the index of the card you want to flip: ");
    scanf("%d", &input);
    return input;
}

/* Function to check if all cards have been matched */
int is_game_over(int *board, int size) {
    for (int i = 0; i < size; i++) {
        if (board[i] != -1) return 0;
    }
    return 1;
}

int main() {
    /* Initialize game board */
    int board[SIZE];
    for (int i = 0; i < SIZE; i++) board[i] = i / 2;
    
    /* Shuffle the board */
    srand(time(NULL));
    shuffle(board, SIZE);
    
    /* Set all cards to face down */
    int facing_down[SIZE];
    for (int i = 0; i < SIZE; i++) facing_down[i] = 1;
    
    int index1, index2;
    int match_count = 0;
    
    /* Game loop */
    while (!is_game_over(board, SIZE)) {
        print_board(facing_down, SIZE);
        
        /* Get user input */
        index1 = get_input();
        
        /* Make sure selected card is facing down */
        while (!facing_down[index1]) {
            printf("That card is already face up! Try again.\n");
            index1 = get_input();
        }
        
        /* Flip the selected card */
        facing_down[index1] = 0;
        printf("You flipped card %d\n", index1);
        
        /* Wait for a moment */
        for (int i = 0; i < 100000000; i++) {} 
        
        /* Get user input for second card */
        index2 = get_input();
        
        /* Make sure selected card is facing down and not the same as first card */
        while (!facing_down[index2] || index1 == index2) {
            printf("That card is already face up or is the same as the first card! Try again.\n");
            index2 = get_input();
        }
        
        /* Flip the second card */
        facing_down[index2] = 0;
        printf("You flipped card %d\n", index2);
        
        /* Check if the two cards match */
        if (board[index1] == board[index2]) {
            printf("You got a match!\n");
            board[index1] = -1;
            board[index2] = -1;
            match_count++;
            if (match_count == MAX_VAL) break;
        } else {
            /* If not a match, flip cards back over */
            facing_down[index1] = 1;
            facing_down[index2] = 1;
            printf("Not a match.\n");
        }
    }
    
    /* Print victory message */
    printf("Congratulations! You won!\n");
    
    return 0;
}