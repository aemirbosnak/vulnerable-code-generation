//FormAI DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void draw_fighters(int fighters[MAX][MAX],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(fighters[i][j] == 0)
                printf("░░"); //represents empty space
            else if(fighters[i][j] == 1)
                printf(" X"); //represents the player's fighter
            else
                printf(" @"); //represents the enemy's fighter
        }
        printf("\n");
    }
}

int main()
{
    int fighters[MAX][MAX] = {0}; //initializing the fighters matrix with empty spaces (0)
    int player_x,player_y,enemy_x,enemy_y,n;

    printf("Enter the size of the game board: ");
    scanf("%d",&n);

    //randomly placing the player and enemy on the board
    player_x = rand() % n;
    player_y = rand() % n;

    do {
        enemy_x = rand() % n;
        enemy_y = rand() % n;
    } while(enemy_x == player_x && enemy_y == player_y);

    fighters[player_x][player_y] = 1; //marking the player's fighter on the board
    fighters[enemy_x][enemy_y] = 2; //marking the enemy's fighter on the board

    printf("\nINCOMING TRANSMISSION: \nAn enemy fighter has been spotted on your radar. Your mission is to eliminate all enemy fighters and secure the area.\n\n");

    draw_fighters(fighters,n);

    while(1)
    {
        printf("\n\nEnter direction to move (UP[u], DOWN[d], LEFT[l], RIGHT[r]): ");
        char direction;
        scanf(" %c",&direction);

        switch(direction)
        {
            case 'u':
                if(player_x == 0)
                {
                    printf("\nCannot move up!\n");
                    continue;
                }
                fighters[player_x][player_y] = 0;
                player_x--;
                fighters[player_x][player_y] = 1;
                break;
            case 'd':
                if(player_x == n-1)
                {
                    printf("\nCannot move down!\n");
                    continue;
                }
                fighters[player_x][player_y] = 0;
                player_x++;
                fighters[player_x][player_y] = 1;
                break;
            case 'l':
                if(player_y == 0)
                {
                    printf("\nCannot move left!\n");
                    continue;
                }
                fighters[player_x][player_y] = 0;
                player_y--;
                fighters[player_x][player_y] = 1;
                break;
            case 'r':
                if(player_y == n-1)
                {
                    printf("\nCannot move right!\n");
                    continue;
                }
                fighters[player_x][player_y] = 0;
                player_y++;
                fighters[player_x][player_y] = 1;
                break;
            default:
                printf("\nInvalid direction!\n");
                continue;
        }

        //check if player has caught up to enemy
        if(player_x == enemy_x && player_y == enemy_y)
        {
            fighters[enemy_x][enemy_y] = 1;
            printf("\nCONGRATULATIONS SOLDIER! You have successfully eliminated the enemy fighter and secured the area!\n");
            break;
        }

        //random movement of enemy
        fighters[enemy_x][enemy_y] = 0;

        int dx = rand() % 3 - 1; //x direction for enemy movement
        int dy = rand() % 3 - 1; //y direction for enemy movement

        if(enemy_x+dx < 0 || enemy_x+dx >= n) //check if enemy goes out of board
            dx *= -1;
        if(enemy_y+dy < 0 || enemy_y+dy >= n) //check if enemy goes out of board
            dy *= -1;

        enemy_x += dx;
        enemy_y += dy;

        fighters[enemy_x][enemy_y] = 2;

        //check if enemy has caught up to player
        if(player_x == enemy_x && player_y == enemy_y)
        {
            fighters[player_x][player_y] = 2;
            printf("\nGAME OVER! The enemy fighter has eliminated you before you could secure the area.\n");
            break;
        }

        //display current board status
        draw_fighters(fighters,n);
    }

    return 0;
}