//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_hp = 100;
    int ghost_hp = 50;
    int player_attack;
    int ghost_attack;
    int choice;
    srand(time(NULL));
    
    printf("You have entered a haunted house. Are you ready to face the ghost?\n");
    
    while(player_hp > 0 && ghost_hp > 0)
    {
        printf("\n*********************************\n");
        printf("Player HP: %d\n", player_hp);
        printf("Ghost HP: %d\n", ghost_hp);
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run away\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                player_attack = rand() % 20 + 1;
                ghost_attack = rand() % 20 + 1;
                printf("\nYou attack the ghost and deal %d damage. The ghost attacks you and deals %d damage.\n", player_attack, ghost_attack);
                ghost_hp -= player_attack;
                player_hp -= ghost_attack;
                break;
                
            case 2:
                ghost_attack = rand() % 10 + 1;
                printf("\nYou defend against the ghost. The ghost attacks you and deals %d damage.\n", ghost_attack / 2);
                player_hp -= (ghost_attack / 2);
                break;
                
            case 3:
                printf("\nYou try to run away but the ghost grabs you and brings you back.\n");
                break;
                
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    
    if(player_hp <= 0)
        printf("\nYou have been killed by the ghost. Game over.\n");
    else if(ghost_hp <= 0)
        printf("\nYou have defeated the ghost and escaped the haunted house. Congratulations!\n");
    
    return 0;
}