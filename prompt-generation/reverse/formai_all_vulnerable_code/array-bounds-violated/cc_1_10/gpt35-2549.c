//FormAI DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    int num_choices[BOARD_SIZE*BOARD_SIZE/2];
    int num_choices_cnt = 0;
    
    for (int i = 1; i <= BOARD_SIZE*BOARD_SIZE/2; i++) {
        num_choices[num_choices_cnt++] = i;
        num_choices[num_choices_cnt++] = i;
    }
    
    srand(time(NULL));
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int random_index = rand() % num_choices_cnt;
            board[i][j] = num_choices[random_index];
            // remove chosen number from choices array
            for (int k = random_index; k < num_choices_cnt-1; k++) {
                num_choices[k] = num_choices[k+1];
            }
            num_choices_cnt--;
        }
    }
}

void display_board() {
    printf("\n");
    for (int i = 0; i< BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1)
                printf(" -");
            else
                printf(" %d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int c1x, c1y, c2x, c2y;
    init_board();
    int num_attempts = 0;
    while (1) {
        num_attempts++;
        display_board();
        
        printf("Enter two coordinates to flip over (e.g. 0 0 1 0): ");
        scanf("%d%d%d%d", &c1x, &c1y, &c2x, &c2y);
        
        if (c1x == -1 && c1y == -1)
            break;
        
        if (board[c1x][c1y] == -1 || board[c2x][c2y] == -1) {
            printf("Invalid coordinates! Try again.\n");
            continue;
        }
        
        if (board[c1x][c1y] == board[c2x][c2y]) {
            board[c1x][c1y] = -1;
            board[c2x][c2y] = -1;
        }
        else {
            printf("Not a match! Try again.\n");
        }
        
        int num_found = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != -1) {
                    num_found++;
                }
            }
        }
        
        if (num_found == 0) {
            printf("Congratulations! You won in %d attempts.\n", num_attempts);
            return 0;
        }
    }
    
    printf("Game terminated by user.\n");
    
    return 0;
}