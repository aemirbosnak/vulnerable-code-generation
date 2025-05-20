//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a bingo card
void print_card(int card[5][5]) {
    int i, j;
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random number between 1 and 75
int rand_num() {
    return rand() % 75 + 1;
}

// Function to check if a line is marked on the card
int check_line(int card[5][5], int line) {
    int i;
    for(i=0; i<5; i++) {
        if(card[i][line] == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to check if all lines are marked on the card
int check_bingo(int card[5][5]) {
    int i, j;
    for(i=0; i<5; i++) {
        if(!check_line(card, i)) {
            return 0;
        }
    }
    for(i=0; i<5; i++) {
        for(j=0; j<4; j++) {
            if(card[i][j] == 0 && card[i][j+1] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to play a game of bingo
void play_game() {
    int card[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    int i, j, num, count=0;
    srand(time(0));
    printf("Let's play Bingo!\n");
    while(1) {
        print_card(card);
        printf("Press enter to draw a number...\n");
        scanf("%d", &num);
        if(check_bingo(card)) {
            printf("Bingo! You win!\n");
            break;
        }
        for(i=0; i<5; i++) {
            for(j=0; j<5; j++) {
                if(card[i][j] == 0 && num <= 75) {
                    card[i][j] = num;
                    count++;
                    break;
                }
            }
        }
        if(count == 0) {
            printf("Invalid move. Try again.\n");
            count = 0;
        }
    }
}

int main() {
    play_game();
    return 0;
}