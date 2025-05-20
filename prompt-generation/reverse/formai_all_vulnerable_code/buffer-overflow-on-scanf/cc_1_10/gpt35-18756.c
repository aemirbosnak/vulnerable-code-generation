//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 25 //height of play area
#define WIDTH 80 //width of play area
#define PADDLE_SIZE 5 //size of paddle

typedef struct paddle { //struct to keep track of the paddle's properties
    int x, y; //coordinates of paddle's top left corner
    int size; //size of paddle
} Paddle;

typedef struct ball { //struct to keep track of the ball's properties
    int x, y; //coordinates of ball's center
    int direction_x, direction_y; //direction of ball's movement
} Ball;

//function to initialize the paddle
void init_paddle(Paddle *paddle) {
    paddle->x = WIDTH/2 - PADDLE_SIZE/2;
    paddle->y = HEIGHT - 2;
    paddle->size = PADDLE_SIZE;
}

//function to initialize the ball
void init_ball(Ball *ball) {
    ball->x = WIDTH/2;
    ball->y = HEIGHT/2;
    ball->direction_x = (rand() % 2 == 0) ? -1 : 1; //randomly choose initial x direction
    ball->direction_y = (rand() % 2 == 0) ? -1 : 1; //randomly choose initial y direction
}

//function to move the paddle left or right based on user input
void move_paddle(Paddle *paddle, char input) {
    switch(input) {
        case 'a':
            if(paddle->x > 0) {
                paddle->x--;
            }
            break;
        case 'd':
            if(paddle->x + paddle->size < WIDTH) {
                paddle->x++;
            }
            break;
        default: //if invalid input, do nothing
            break;
    }
}

//function to move the ball
void move_ball(Ball *ball, Paddle *paddle) {
    //update ball's coordinates based on its direction
    ball->x += ball->direction_x;
    ball->y += ball->direction_y;
    
    //if ball hits left or right wall, reverse x direction
    if(ball->x == 0 || ball->x == WIDTH - 1) {
        ball->direction_x *= -1;
    }
    
    //if ball hits top wall, reverse y direction
    if(ball->y == 0) {
        ball->direction_y *= -1;
    }
    
    //if ball hits bottom wall, reset ball and paddle
    if(ball->y == HEIGHT - 1) {
        printf("You lose!\n");
        init_paddle(paddle);
        init_ball(ball);
        return;
    }
    
    //if ball hits paddle, reverse y direction
    if(ball->y == paddle->y && ball->x >= paddle->x && ball->x < paddle->x + paddle->size) {
        ball->direction_y *= -1;
    }
}

//function to move the AI paddle
void move_ai_paddle(Paddle *ai_paddle, Ball *ball) {
    //if ball is to the left of AI paddle, move left
    if(ball->x < ai_paddle->x + ai_paddle->size/2) {
        if(ai_paddle->x > 0) {
            ai_paddle->x--;
        }
    }
    //if ball is to the right of AI paddle, move right
    else {
        if(ai_paddle->x + ai_paddle->size < WIDTH) {
            ai_paddle->x++;
        }
    }
}

//function to print the playing area with the paddle and ball
void print_area(Paddle *paddle, Paddle *ai_paddle, Ball *ball) {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(i == 0 || i == HEIGHT - 1) { //top and bottom walls
                printf("-");
            }
            else if(j == 0 || j == WIDTH - 1) { //left and right walls
                printf("|");
            }
            else if(i == paddle->y && j >= paddle->x && j < paddle->x + paddle->size) { //player paddle
                printf("=");
            }
            else if(i == ai_paddle->y && j >= ai_paddle->x && j < ai_paddle->x + ai_paddle->size) { //AI paddle
                printf("=");
            }
            else if(i == ball->y && j == ball->x) { //ball
                printf("o");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); //seed random number generator
    
    Paddle player_paddle, ai_paddle;
    Ball ball;
    
    init_paddle(&player_paddle);
    init_paddle(&ai_paddle);
    init_ball(&ball);
    
    char input;
    while(1) {
        //get user input
        scanf(" %c", &input);
        move_paddle(&player_paddle, input);
        
        //move the AI paddle
        move_ai_paddle(&ai_paddle, &ball);
        
        //move the ball
        move_ball(&ball, &player_paddle);
        
        //print the playing area
        system("clear"); //clear the console
        print_area(&player_paddle, &ai_paddle, &ball);
    }
    
    return 0;
}