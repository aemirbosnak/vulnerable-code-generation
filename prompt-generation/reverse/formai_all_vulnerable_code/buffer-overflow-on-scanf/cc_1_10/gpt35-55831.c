//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

char map[ROWS][COLS];
int score = 0;
int playerX, playerY;
int ghostX, ghostY;
int foodX, foodY;

void initialize_map();
void generate_food();
void print_map();
void move_player(char direction);
void move_ghost();
void check_collision();

int main()
{
    srand(time(NULL));
    initialize_map();
    generate_food();
    print_map();

    char direction;
    while (1)
    {
        printf("Current Score: %d\n", score);
        printf("Enter your move (w,a,s,d): ");
        scanf(" %c", &direction);
        move_player(direction);
        move_ghost();
        check_collision();
        print_map();
        if (score == 5)
        {
            printf("Congratulations! You have won!\n");
            return 0;
        }
    }
}

void initialize_map()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            map[i][j] = '.';
        }
    }
    playerX = rand() % ROWS;
    playerY = rand() % COLS;
    map[playerX][playerY] = 'P';
    ghostX = rand() % ROWS;
    ghostY = rand() % COLS;
    while (ghostX == playerX && ghostY == playerY)
    {
        ghostX = rand() % ROWS;
        ghostY = rand() % COLS;
    }
    map[ghostX][ghostY] = 'G';
}

void generate_food()
{
    foodX = rand() % ROWS;
    foodY = rand() % COLS;
    while (foodX == playerX && foodY == playerY)
    {
        foodX = rand() % ROWS;
        foodY = rand() % COLS;
    }
    map[foodX][foodY] = 'F';
}

void print_map()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void move_player(char direction)
{
    map[playerX][playerY] = '.';
    switch (direction)
    {
        case 'w':
            playerX--;
            break;
        case 'a':
            playerY--;
            break;
        case 's':
            playerX++;
            break;
        case 'd':
            playerY++;
            break;
    }
    if (playerX < 0)
    {
        playerX = 0;
    }
    if (playerX > ROWS - 1)
    {
        playerX = ROWS - 1;
    }
    if (playerY < 0)
    {
        playerY = 0;
    }
    if (playerY > COLS - 1)
    {
        playerY = COLS - 1;
    }
    map[playerX][playerY] = 'P';
}

void move_ghost()
{
    map[ghostX][ghostY] = '.';
    int direction = rand() % 4;
    switch (direction)
    {
        case 0:
            ghostX--;
            break;
        case 1:
            ghostY--;
            break;
        case 2:
            ghostX++;
            break;
        case 3:
            ghostY++;
            break;
    }
    if (ghostX < 0)
    {
        ghostX = 0;
    }
    if (ghostX > ROWS - 1)
    {
        ghostX = ROWS - 1;
    }
    if (ghostY < 0)
    {
        ghostY = 0;
    }
    if (ghostY > COLS - 1)
    {
        ghostY = COLS - 1;
    }
    map[ghostX][ghostY] = 'G';
}

void check_collision()
{
    if (playerX == foodX && playerY == foodY)
    {
        score++;
        map[foodX][foodY] = '.';
        generate_food();
    }
    if (playerX == ghostX && playerY == ghostY)
    {
        printf("Game Over! You have been caught by the ghost!\n");
        exit(0);
    }
}