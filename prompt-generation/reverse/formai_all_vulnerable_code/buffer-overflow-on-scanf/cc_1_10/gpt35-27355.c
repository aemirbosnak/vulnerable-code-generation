//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40

void draw_ball(int y, int x);
void draw_paddle(int pos_y);
void init_board();
void clear_board();

char board[HEIGHT][WIDTH];

int main() {
    int ball_y = HEIGHT/2 - 1, ball_x = WIDTH/2 - 1;
    int paddle_y = HEIGHT/2 - 2, paddle_x = 1;
    int ai_paddle_y = HEIGHT/2 - 2, ai_paddle_x = WIDTH - 2;
    int ball_y_dir = 1, ball_x_dir = 1;
    int ai_move = 0;
    srand(time(NULL));

    init_board();

    while(1){
        // get player input
        char input;
        scanf("%c", &input);

        if(input == 'w' && paddle_y > 0) paddle_y--;
        else if(input == 's' && paddle_y + 4 < HEIGHT) paddle_y++;

        // AI opponent
        if(ball_y > ai_paddle_y + 2 && ai_paddle_y + 4 < HEIGHT) ai_move = 1;
        else if(ball_y < ai_paddle_y + 2 && ai_paddle_y > 0) ai_move = -1;
        else ai_move = 0;

        if(ai_move == 1 && ai_paddle_y + 4 < HEIGHT) ai_paddle_y++;
        else if(ai_move == -1 && ai_paddle_y > 0) ai_paddle_y--;

        // move ball
        ball_y += ball_y_dir;
        ball_x += ball_x_dir;

        // ball bouncing off paddle
        if(ball_y >= paddle_y && ball_y <= paddle_y + 4 && ball_x == paddle_x + 1){
            ball_x_dir = 1;
        }
        if(ball_y >= ai_paddle_y && ball_y <= ai_paddle_y + 4 && ball_x == ai_paddle_x - 1){
            ball_x_dir = -1;
        }

        // ball bouncing off walls
        if(ball_y == 0 || ball_y == HEIGHT - 1) ball_y_dir *= -1;
        if(ball_x == 0 || ball_x == WIDTH - 1){
            printf("Game Over\n");
            break;
        }

        // clear and redraw board
        clear_board();
        draw_ball(ball_y, ball_x);
        draw_paddle(paddle_y);
        draw_paddle(ai_paddle_y);

        for(int row = 0; row < HEIGHT; row++){
            for(int col = 0; col < WIDTH; col++){
                printf("%c", board[row][col]);
            }
            printf("\n");
        }
        printf("\n");

        // wait for a moment
        for(long int i = 0; i < 100000000; i++);
    
    }
    return 0;
}

void draw_ball(int y, int x){
    board[y][x] = 'O';
}

void draw_paddle(int pos_y){
    for(int i = 0; i < 5; i++){
        board[pos_y + i][1] = '|';
        board[pos_y + i][0] = '|';
    }
}

void init_board(){
    for(int row = 0; row < HEIGHT; row++){
        for(int col = 0; col < WIDTH; col++){
            if((row == 0 || row == HEIGHT - 1) && (col > 0 && col < WIDTH - 1)){
                board[row][col] = '-';
            }else{
                board[row][col] = ' ';
            }
        }
    }
}

void clear_board(){
    system("cls || clear");
}