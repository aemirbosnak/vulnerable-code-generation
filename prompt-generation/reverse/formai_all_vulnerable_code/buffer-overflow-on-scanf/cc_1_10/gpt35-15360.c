//FormAI DATASET v1.0 Category: Game ; Style: Donald Knuth
/* Donald Knuth Style C Game Example */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5

/* Function to print the game board */
void print_board(int board[][BOARD_SIZE]) {
    int i, j;
    for(i=0;i<BOARD_SIZE;i++) {
        for(j=0;j<BOARD_SIZE;j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

/* Function to initialize the game board */
void initialize_board(int board[][BOARD_SIZE]) {
    int i, j;
    for(i=0;i<BOARD_SIZE;i++) {
        for(j=0;j<BOARD_SIZE;j++) {
            board[i][j] = 0;
        }
    }
}

/* Function to generate random number between a range */
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Main function */
int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    int player_x, player_y;
    int food_x, food_y;
    char move;

    /* Seed random number generator */
    srand(time(NULL));

    /* Initialize game board */
    initialize_board(board);

    /* Initialize player and food positions */
    player_x = get_random_number(0, BOARD_SIZE-1);
    player_y = get_random_number(0, BOARD_SIZE-1);
    board[player_x][player_y] = 1;

    food_x = get_random_number(0, BOARD_SIZE-1);
    food_y = get_random_number(0, BOARD_SIZE-1);
    board[food_x][food_y] = 2;

    /* Print initial game board */
    print_board(board);

    /* Game loop */
    while(1) {
        printf("Enter move (w,a,s,d): ");
        scanf(" %c", &move);

        /* Update player position based on move */
        switch(move) {
            case 'w': // Move player up
                if(player_x == 0) {
                    printf("Cannot move up any further!\n");
                }
                else {
                    player_x--;
                }
                break;

            case 'a': // Move player left
                if(player_y == 0) {
                    printf("Cannot move left any further!\n");
                }
                else {
                    player_y--;
                }
                break;

            case 's': // Move player down
                if(player_x == BOARD_SIZE-1) {
                    printf("Cannot move down any further!\n");
                }
                else {
                    player_x++;
                }
                break;

            case 'd': // Move player right
                if(player_y == BOARD_SIZE-1) {
                    printf("Cannot move right any further!\n");
                }
                else {
                    player_y++;
                }
                break;

            default:
                printf("Invalid move! Please enter a valid move (w,a,s,d).\n");
                continue;
        }

        /* Update game board */
        initialize_board(board);
        board[player_x][player_y] = 1;
        board[food_x][food_y] = 2;

        /* Check if player has reached food */
        if(player_x == food_x && player_y == food_y) {
            printf("Congratulations! You have reached the food!\n");
            break;
        }

        /* Print updated game board */
        print_board(board);
    }

    return 0;
}