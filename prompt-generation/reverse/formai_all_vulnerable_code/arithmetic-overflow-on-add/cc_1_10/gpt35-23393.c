//FormAI DATASET v1.0 Category: Checkers Game ; Style: safe
#include<stdio.h>
#include<stdlib.h>

int board[8][8] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0}
};

void print_board(){
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i=0; i<8; i++){
        printf("%d ",i);
        for (int j=0; j<8; j++){
            switch(board[i][j]){
                case 1:
                    printf("O ");
                    break;
                case -1:
                    printf("X ");
                    break;
                default:
                    printf("_ ");
                    break;
            }
        }
        printf("\n");   
    }
}

void move(int from_x, int from_y, int to_x, int to_y){
    if(board[from_x][from_y] == 1){
        if(to_x == from_x+1 && (to_y == from_y+1 || to_y == from_y-1) && board[to_x][to_y] == 0){
            board[from_x][from_y] = 0;
            board[to_x][to_y] = 1;
        }
        else if(to_x == from_x+2 && board[from_x+1][(from_y+to_y)/2] == -1){
            board[from_x][from_y] = 0;
            board[from_x+1][(from_y+to_y)/2] = 0;
            board[to_x][to_y] = 1;
        }
    }
    else if(board[from_x][from_y] == -1){
        if(to_x == from_x-1 && (to_y == from_y+1 || to_y == from_y-1) && board[to_x][to_y] == 0){
            board[from_x][from_y] = 0;
            board[to_x][to_y] = -1;
        }
        else if(to_x == from_x-2 && board[from_x-1][(from_y+to_y)/2] == 1){
            board[from_x][from_y] = 0;
            board[from_x-1][(from_y+to_y)/2] = 0;
            board[to_x][to_y] = -1;
        }
    }
}

int main(){
    int cur_player = 1;
    int from_x, from_y, to_x, to_y, n;
    while(1){
        printf("Current Board:\n");
        print_board();
        printf("Player %d's turn.\n", cur_player);
        printf("Enter from_x: ");
        scanf("%d", &from_x);
        printf("Enter from_y: ");
        scanf("%d", &from_y);
        printf("Enter to_x: ");
        scanf("%d", &to_x);
        printf("Enter to_y: ");
        scanf("%d", &to_y);
        move(from_x,from_y,to_x,to_y);
        if(cur_player == 1) cur_player = -1;
        else cur_player = 1;
    }
    return 0;
}