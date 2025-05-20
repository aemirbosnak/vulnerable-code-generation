//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char player_name[20], choice[10];
    int health = 100, game_over = 0, enemy_health = 50;
    
    printf("Welcome to Dark Maze!\n");
    printf("Enter your name: ");
    scanf("%s", player_name);
    getchar();
    
    printf("Hello %s. You are at the entrance of a dark maze.\n", player_name);
    printf("You have %d health points.\n", health);
    
    while (!game_over)
    {
        printf("\nYou have reached a crossroad. What do you want to do?\n");
        printf("Enter 'left' to go left or 'right' to go right: ");
        scanf("%s", choice);
        getchar();
        
        if (strcmp(choice, "left") == 0) // if player chooses left
        {
            printf("\nYou have encountered a goblin!\n");
            printf("You have %d health points left.\n", health);
            printf("Enter 'fight' to fight the goblin or 'run' to run away: ");
            scanf("%s", choice);
            getchar();
            
            if (strcmp(choice, "fight") == 0) // if player chooses to fight
            {
                while (health > 0 && enemy_health > 0)
                {
                    printf("\nYou attack the goblin. ");
                    enemy_health -= 10;
                    if (enemy_health <= 0)
                    {
                        printf("You defeated the goblin!\n");
                        break;
                    }
                    printf("The goblin has %d health left.\n", enemy_health);
                    printf("The goblin attacks you. ");
                    health -= 10;
                    if (health <= 0)
                    {
                        printf("You died. Game over.\n");
                        game_over = 1;
                        break;
                    }
                    printf("You have %d health left.\n", health);
                }
                enemy_health = 50;
                if (game_over) break;
            }
            else if (strcmp(choice, "run") == 0) // if player chooses to run away
            {
                printf("\nYou run away from the goblin. You are back at the crossroad.\n");
            } 
            else // if player enters invalid command
            {
                printf("\nInvalid command. Try again.\n");
            }
        }
        else if (strcmp(choice, "right") == 0) // if player chooses right
        {
            printf("\nYou have reached a dead end. You are back at the crossroad.\n");
        }
        else // if player enters invalid command
        {
            printf("\nInvalid command. Try again.\n");
        }
    }
    
    return 0;
}