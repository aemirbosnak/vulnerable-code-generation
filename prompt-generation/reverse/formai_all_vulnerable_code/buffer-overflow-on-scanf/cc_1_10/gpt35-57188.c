//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the grid
void print_grid(char grid[3][3]) {
    printf("  0 1 2\n");
    for(int i=0; i<3; i++) {
        printf("%d ", i);
        for(int j=0; j<3;j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if there is a winner
char check_winner(char grid[3][3]) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return grid[i][0];
        }
    }
    // Check columns
    for(int i=0; i<3; i++) {
        if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return grid[0][i];
        }
    }
    // Check diagonals
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return grid[0][0];
    }
    if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return grid[0][2];
    }
    return '\0';
}

// Function to check if the game ends in a draw
int check_draw(char grid[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3;j++) {
            if(grid[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    char grid[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    print_grid(grid);
    int x, y;
    char player = 'X';
    srand(time(NULL));
    int computer_turn = rand()%2; // randomly decides who goes first
    while(1) {
        // Player's turn
        if(computer_turn == 0) {
            printf("\nPlayer %c's turn\n", player);
            printf("Enter the row of your move: ");
            scanf("%d", &x);
            printf("Enter the column of your move: ");
            scanf("%d", &y);
            if(x<0 || x >=3 || y<0 || y>=3 || grid[x][y]!=' ') {
                printf("Invalid move!\n");
                continue;
            }
            grid[x][y] = player;
            print_grid(grid);
            char winner = check_winner(grid);
            if(winner == player) {
                printf("Player %c wins!\n", player);
                break;
            }
            if(check_draw(grid)) {
                printf("It's a draw!\n");
                break;
            }
            player = (player=='X') ? 'O' : 'X';
        }
        // Computer's turn (realistic AI)
        else {
            printf("\nComputer's turn\n");
            int num_turns = 0;
            while(1) {
                printf("Thinking...\n");
                num_turns++;
                if(num_turns>10) { // The computer gives up after 10 turns
                    printf("Computer gives up!\n");
                    break;
                }
                int x = rand()%3;
                int y = rand()%3;
                if(grid[x][y]==' ') {
                    grid[x][y] = player;
                    print_grid(grid);
                    char winner = check_winner(grid);
                    if(winner == player) {
                        printf("Player %c wins!\n", player);
                        break;
                    }
                    if(check_draw(grid)) {
                        printf("It's a draw!\n");
                        break;
                    }
                    player = (player=='X') ? 'O' : 'X';
                    break;
                }
            }
        }
        // Switch who goes first
        computer_turn = (computer_turn==0) ? 1 : 0;
    }
    return 0;
}