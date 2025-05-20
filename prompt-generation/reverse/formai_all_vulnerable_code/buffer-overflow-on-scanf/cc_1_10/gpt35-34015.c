//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PLAYERS 4
#define MAX_SHAPES 3

typedef struct {
    int x;
    int y;
} Point;

int rand_range(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int check_collision(Point* shape1, Point* shape2, int shape1_size, int shape2_size) {
    for(int i=0;i<shape1_size;i++) {
        for(int j=0;j<shape2_size;j++) {
            if(shape1[i].x == shape2[j].x && shape1[i].y == shape2[j].y) {
                return 1;
            }
        }
    }
    return 0;
}

void print_board(int board[10][10], int num_players, Point shapes[]) {
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            int player_id = 0;
            for(int k=0;k<num_players;k++) {
                if(board[i][j] == k+1) {
                    printf("%d", k+1);
                    player_id = k+1;
                    break;
                }
            }
            if(player_id == 0) {
                for(int k=0;k<MAX_SHAPES;k++) {
                    if(shapes[player_id * MAX_SHAPES + k].x == j && shapes[player_id * MAX_SHAPES + k].y == i) {
                        printf("*");
                        break;
                    }
                    if(k == MAX_SHAPES - 1) {
                        printf(".");
                    }
                }
            }
            if(j == 9) {
                printf("\n");
            }
        }
    }
}

int main() {
    int board[10][10] = {0};
    int num_players = 0;
    Point player_shapes[MAX_PLAYERS * MAX_SHAPES] = {{0}};
    srand(time(NULL));
    printf("Enter number of players(max 4):\n");
    scanf("%d", &num_players);
    if(num_players > MAX_PLAYERS) {
        printf("Only up to 4 players allowed\n");
        return 0;
    }
    else {
        for(int i=0;i<num_players;i++) {
            int shape_selection = rand_range(0,2);
            if(shape_selection == 0) { // Square
                player_shapes[i*MAX_SHAPES].x = 0 + i;
                player_shapes[i*MAX_SHAPES].y = 0;
                player_shapes[i*MAX_SHAPES + 1].x = 0 + i;
                player_shapes[i*MAX_SHAPES + 1].y = 1;
                player_shapes[i*MAX_SHAPES + 2].x = 1 + i;
                player_shapes[i*MAX_SHAPES + 2].y = 0;
                player_shapes[i*MAX_SHAPES + 3].x = 1 + i;
                player_shapes[i*MAX_SHAPES + 3].y = 1;
            } else if(shape_selection == 1) { // L-Shape
                player_shapes[i*MAX_SHAPES].x = 0 + i;
                player_shapes[i*MAX_SHAPES].y = 0;
                player_shapes[i*MAX_SHAPES + 1].x = 1 + i;
                player_shapes[i*MAX_SHAPES + 1].y = 0;
                player_shapes[i*MAX_SHAPES + 2].x = 2 + i;
                player_shapes[i*MAX_SHAPES + 2].y = 0;
                player_shapes[i*MAX_SHAPES + 3].x = 2 + i;
                player_shapes[i*MAX_SHAPES + 3].y = 1;
            } else { //T-Shape
                player_shapes[i*MAX_SHAPES].x = 0 + i;
                player_shapes[i*MAX_SHAPES].y = 0;
                player_shapes[i*MAX_SHAPES + 1].x = 1 + i;
                player_shapes[i*MAX_SHAPES + 1].y = 0;
                player_shapes[i*MAX_SHAPES + 2].x = 2 + i;
                player_shapes[i*MAX_SHAPES + 2].y = 0;
                player_shapes[i*MAX_SHAPES + 3].x = 1 + i;
                player_shapes[i*MAX_SHAPES + 3].y = 1;
            }
            for(int j=0;j<MAX_SHAPES;j++) {
                board[player_shapes[i*MAX_SHAPES + j].y][player_shapes[i*MAX_SHAPES + j].x] = i+1;
            }
        }
    }
    int game_over = 0;
    while(!game_over) {
        system("clear");
        print_board(board, num_players, player_shapes);
        for(int i=0;i<num_players;i++) {
            int row_diff, col_diff;
            int valid_move = 0;
            while(!valid_move) {
                printf("Player %d's turn: ", i+1);
                scanf("%d %d", &col_diff, &row_diff);
                Point temp_shapes[MAX_SHAPES];
                for(int k=0;k<MAX_SHAPES;k++) {
                    temp_shapes[k].x = player_shapes[i*MAX_SHAPES + k].x + col_diff;
                    temp_shapes[k].y = player_shapes[i*MAX_SHAPES + k].y + row_diff;
                    if(temp_shapes[k].x < 0 || temp_shapes[k].x > 9 || temp_shapes[k].y < 0 || temp_shapes[k].y > 9) {
                        printf("Can't move outside board\n");
                        break;
                    } else if(board[temp_shapes[k].y][temp_shapes[k].x] != 0 && board[temp_shapes[k].y][temp_shapes[k].x] != i+1) {
                        printf("Can't move on top of other player\n");
                        break;
                    } else {
                        valid_move = 1;
                    }
                }
            }
            for(int k=0;k<MAX_SHAPES;k++) {
                board[player_shapes[i*MAX_SHAPES + k].y][player_shapes[i*MAX_SHAPES + k].x] = 0;
                player_shapes[i*MAX_SHAPES + k].x += col_diff;
                player_shapes[i*MAX_SHAPES + k].y += row_diff;
                board[player_shapes[i*MAX_SHAPES + k].y][player_shapes[i*MAX_SHAPES + k].x] = i+1;
            }
            if(i == num_players - 1) {
                game_over = 1;
                for(int j=0;j<num_players;j++) {
                    for(int k=0;k<num_players;k++) {
                        if(j == k) {
                            continue;
                        }
                        if(check_collision(player_shapes+j*MAX_SHAPES, player_shapes+k*MAX_SHAPES, MAX_SHAPES, MAX_SHAPES)) {
                            printf("Player %d wins!\n", j+1);
                            game_over = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}