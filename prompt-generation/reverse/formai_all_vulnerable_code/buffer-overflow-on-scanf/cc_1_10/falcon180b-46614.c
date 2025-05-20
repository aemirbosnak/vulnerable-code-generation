//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define NUM_BALLS 75

//Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

//Function to print the BINGO card
void print_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for(i=0; i<MAX_ROWS; i++) {
        for(j=0; j<MAX_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

//Function to check if a card has won
int check_win(int card[MAX_ROWS][MAX_COLS]) {
    int i, j, count;
    for(i=0; i<MAX_ROWS; i++) {
        count = 0;
        for(j=0; j<MAX_COLS; j++) {
            if(card[i][j]!= 0) {
                count++;
            }
        }
        if(count == 5) {
            return 1;
        }
    }
    for(i=0; i<MAX_COLS; i++) {
        count = 0;
        for(j=0; j<MAX_ROWS; j++) {
            if(card[j][i]!= 0) {
                count++;
            }
        }
        if(count == 5) {
            return 1;
        }
    }
    if(card[0][0]!= 0 && card[1][1]!= 0 && card[2][2]!= 0 && card[3][3]!= 0 && card[4][4]!= 0) {
        return 1;
    }
    if(card[0][4]!= 0 && card[1][3]!= 0 && card[2][2]!= 0 && card[3][1]!= 0 && card[4][0]!= 0) {
        return 1;
    }
    return 0;
}

//Function to mark a number on the card
void mark_number(int card[MAX_ROWS][MAX_COLS], int row, int col, int num) {
    card[row][col] = num;
}

//Function to generate a BINGO card
void generate_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for(i=0; i<MAX_ROWS; i++) {
        for(j=0; j<MAX_COLS; j++) {
            card[i][j] = rand_num(1, NUM_BALLS);
        }
    }
}

int main() {
    int card[MAX_ROWS][MAX_COLS];
    int i, j;
    srand(time(NULL));
    generate_card(card);
    print_card(card);
    int win = 0;
    int num;
    while(win == 0) {
        printf("Enter a number: ");
        scanf("%d", &num);
        int row = rand_num(0, MAX_ROWS-1);
        int col = rand_num(0, MAX_COLS-1);
        mark_number(card, row, col, num);
        print_card(card);
        win = check_win(card);
    }
    return 0;
}