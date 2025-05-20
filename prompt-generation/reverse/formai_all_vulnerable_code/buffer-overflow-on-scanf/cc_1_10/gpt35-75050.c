//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>

char grid[3][3];

// This function prints the Tic Tac Toe grid.
void print_grid() {
    printf("Player 1: X | Player 2: O\n");
    printf("-------------\n");
    printf("| %c | %c | %c |\n", grid[0][0], grid[0][1], grid[0][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", grid[1][0], grid[1][1], grid[1][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", grid[2][0], grid[2][1], grid[2][2]);
    printf("-------------\n");
}

// This function checks if any player has won.
int check_win() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
            return 1;
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
            return 1;
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
        return 1;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        return 1;
    return 0;
}

// This function checks if the grid is full.
int check_tie() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    int player = 1, i, choice;
    char mark;
    for (i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = ' ';
    do {
        print_grid();
        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter a cell number: ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && grid[0][0] == ' ')
            grid[0][0] = mark;
        else if (choice == 2 && grid[0][1] == ' ')
            grid[0][1] = mark;
        else if (choice == 3 && grid[0][2] == ' ')
            grid[0][2] = mark;
        else if (choice == 4 && grid[1][0] == ' ')
            grid[1][0] = mark;
        else if (choice == 5 && grid[1][1] == ' ')
            grid[1][1] = mark;
        else if (choice == 6 && grid[1][2] == ' ')
            grid[1][2] = mark;
        else if (choice == 7 && grid[2][0] == ' ')
            grid[2][0] = mark;
        else if (choice == 8 && grid[2][1] == ' ')
            grid[2][1] = mark;
        else if (choice == 9 && grid[2][2] == ' ')
            grid[2][2] = mark;
        else {
            printf("Invalid move\n");
            player--;
            getchar();
        }
        i = check_win();
        player++;
    } while (i == -1);
    print_grid();
    if (i == 1)
        printf("==>\aPlayer %d wins\n", --player);
    else
        printf("==>\aGame draw\n");
    return 0;
}