//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void clearScreen() //function to clear screen
{
    printf("\033[H\033[J");
}

int main()
{
    srand(time(NULL)); //seeding random number generator
    int player_health=20, player_attack=5, player_defense=5; //setting initial player stats
    int enemy_health=rand()%20+1, enemy_attack=rand()%5+1, enemy_defense=rand()%5+1; //generating random enemy stats
    int choice, damage_taken, damage_given;
    
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in a dark forest with no memory of how you got here.\n");
    printf("As you wander, you hear rustling behind you and turn around to see a giant spider!\n");
    printf("Prepare for battle!\n\n");
    
    while(player_health>0 && enemy_health>0) //game loop
    {
        printf("Player Health: %d\n",player_health);
        printf("Enemy Health: %d\n\n",enemy_health);
        
        printf("Action Menu:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        clearScreen();
        
        switch(choice)
        {
            case 1: //player attacks
                damage_given=rand()%player_attack+1;
                damage_taken=rand()%enemy_defense+1;
                enemy_health-=damage_given-damage_taken;
                printf("You attack the spider dealing %d damage.\n",damage_given-damage_taken);
                break;
                
            case 2: //player defends
                damage_taken=rand()%(enemy_attack/2)+1;
                player_health-=damage_taken;
                printf("You defend yourself, taking only %d damage from the spider.\n",damage_taken);
                break;
            
            case 3: //player runs
                printf("You try to run away but the spider is too fast and catches up to you.\n");
                damage_taken=rand()%enemy_attack+1;
                player_health-=damage_taken;
                printf("The spider bites you dealing %d damage.\n",damage_taken);
                break;
            
            default: //invalid choice
                printf("Invalid choice. Try again.\n\n");
        }
        
        if(enemy_health<=0) //enemy is defeated
        {
            printf("You have defeated the giant spider and continue your journey!\n");
            break;
        }
        
        if(player_health<=0) //player is defeated
        {
            printf("The giant spider has defeated you. Game over.\n");
            return 0;
        }
        
        damage_given=rand()%enemy_attack+1;
        damage_taken=rand()%player_defense+1;
        player_health-=damage_given-damage_taken;
        printf("The spider attacks you dealing %d damage.\n\n",damage_given-damage_taken);
        
    }
    
    return 0;
}