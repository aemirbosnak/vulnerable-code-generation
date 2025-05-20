//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAP_SIZE 20
#define MAX_NAME_LENGTH 20

char map[MAP_SIZE][MAP_SIZE];
int pac_x, pac_y, ghost_x, ghost_y, score, lives;
char name[MAX_NAME_LENGTH];

void set_up_map();
void print_map();
void move_pac_man(char);
void move_ghost();
void new_game();
void game_over();
void you_win();

int main()
{
    srand(time(NULL)); // generates random seed for random ghost placement
    printf("Welcome to Pac-Man! Enter your name: ");
    scanf("%s", name);
    new_game();
    while (1)
    {
        printf("Score: %d   Lives: %d\n", score, lives);
        print_map();
        char move;
        printf("Move (w,a,s,d): ");
        scanf(" %c", &move);
        move_pac_man(move);
        if (lives == 0)
        {
            game_over();
            break;
        }
        if (score == (MAP_SIZE-2)*(MAP_SIZE-2))
        {
            you_win();
            break;
        }
        move_ghost();
        if (pac_x == ghost_x && pac_y == ghost_y)
        {
            lives--;
            printf("You got caught by a ghost! You have %d lives left.\n", lives);
            if (lives == 0)
            {
                game_over();
                break;
            }
            pac_x = 1;
            pac_y = 1;
            ghost_x = rand() % (MAP_SIZE-2) + 1;
            ghost_y = rand() % (MAP_SIZE-2) + 1;
        }
    }
    return 0;
}

void set_up_map()
{
    memset(map, '.', sizeof(map)); // fills entire map with dots
    for (int i = 0; i < MAP_SIZE; i++) // sets up walls
    {
        map[i][0] = '#';
        map[i][MAP_SIZE-1] = '#';
        map[0][i] = '#';
        map[MAP_SIZE-1][i] = '#';
    }
    // sets up pac-man and ghost starting positions
    pac_x = 1;
    pac_y = 1;
    ghost_x = rand() % (MAP_SIZE-2) + 1;
    ghost_y = rand() % (MAP_SIZE-2) + 1;
    map[pac_x][pac_y] = 'P';
    map[ghost_x][ghost_y] = 'G';
    // sets up pellets
    for (int i = 1; i < MAP_SIZE-1; i++)
    {
        for (int j = 1; j < MAP_SIZE-1; j++)
        {
            if (map[i][j] != 'P' && map[i][j] != 'G' && rand() % 4 == 0)
            {
                map[i][j] = '*';
            }
        }
    }
    // sets up power pellets
    for (int i = 0; i < 4; i++)
    {
        int x = rand() % (MAP_SIZE-2) + 1;
        int y = rand() % (MAP_SIZE-2) + 1;
        while (map[x][y] != '.')
        {
            x = rand() % (MAP_SIZE-2) + 1;
            y = rand() % (MAP_SIZE-2) + 1;
        }
        map[x][y] = 'O';
    }
}

void print_map()
{
    printf("\n");
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void move_pac_man(char direction)
{
    int new_x = pac_x;
    int new_y = pac_y;
    if (direction == 'w')
    {
        if (map[pac_x-1][pac_y] != '#')
        {
            new_x--;
        }
    }
    else if (direction == 'a')
    {
        if (map[pac_x][pac_y-1] != '#')
        {
            new_y--;
        }
    }
    else if (direction == 's')
    {
        if (map[pac_x+1][pac_y] != '#')
        {
            new_x++;
        }
    }
    else if (direction == 'd')
    {
        if (map[pac_x][pac_y+1] != '#')
        {
            new_y++;
        }
    }
    if (map[new_x][new_y] == '*')
    {
        score++;
    }
    else if (map[new_x][new_y] == 'O')
    {
        score += 10;
    }
    map[pac_x][pac_y] = '.';
    pac_x = new_x;
    pac_y = new_y;
    map[pac_x][pac_y] = 'P';
}

void move_ghost()
{
    int horizontal_distance = pac_x - ghost_x;
    int vertical_distance = pac_y - ghost_y;
    if (abs(horizontal_distance) > abs(vertical_distance))
    {
        if (horizontal_distance > 0)
        {
            if (map[ghost_x+1][ghost_y] != '#')
            {
                ghost_x++;
            }
            else if (map[ghost_x][ghost_y+1] != '#')
            {
                ghost_y++;
            }
            else if (map[ghost_x][ghost_y-1] != '#')
            {
                ghost_y--;
            }
        }
        else
        {
            if (map[ghost_x-1][ghost_y] != '#')
            {
                ghost_x--;
            }
            else if (map[ghost_x][ghost_y+1] != '#')
            {
                ghost_y++;
            }
            else if (map[ghost_x][ghost_y-1] != '#')
            {
                ghost_y--;
            }
        }
    }
    else
    {
        if (vertical_distance > 0)
        {
            if (map[ghost_x][ghost_y+1] != '#')
            {
                ghost_y++;
            }
            else if (map[ghost_x+1][ghost_y] != '#')
            {
                ghost_x++;
            }
            else if (map[ghost_x-1][ghost_y] != '#')
            {
                ghost_x--;
            }
        }
        else
        {
            if (map[ghost_x][ghost_y-1] != '#')
            {
                ghost_y--;
            }
            else if (map[ghost_x+1][ghost_y] != '#')
            {
                ghost_x++;
            }
            else if (map[ghost_x-1][ghost_y] != '#')
            {
                ghost_x--;
            }
        }
    }
}

void new_game()
{
    set_up_map();
    score = 0;
    lives = 3;
}

void game_over()
{
    printf("\nGame over, %s! Your final score is %d.\n", name, score);
}

void you_win()
{
    printf("\nCongratulations, %s! You win with a score of %d!\n", name, score);
}