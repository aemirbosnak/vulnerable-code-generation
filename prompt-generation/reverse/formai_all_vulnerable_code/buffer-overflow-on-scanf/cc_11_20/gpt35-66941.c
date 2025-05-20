//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //game initialization
    srand(time(0)); //to get random numbers
    int player_hp = 100; //initial player hp
    int enemy_hp = 50; //initial enemy hp
    int player_attack; 
    int enemy_attack;
    int item; //random item that can be obtained via loot
    
    //gameplay loop
    while(player_hp > 0 && enemy_hp > 0){
        printf("Your HP: %d\n", player_hp);
        printf("Enemy HP: %d\n", enemy_hp);
        printf("Choose an attack: \n");
        printf("1. Sword Slash\n2. Bow Shoot\n3. Magic Blast\n");
        scanf("%d", &player_attack);
        
        //generate enemy attack
        enemy_attack = rand() % 3 + 1;
        
        //determine damage dealt
        switch(player_attack){
            case 1: //sword slash
                enemy_hp -= 20; //20 damage
                printf("You dealt 20 damage to the enemy.\n");
                break;
            case 2: //bow shoot
                enemy_hp -= 15; //15 damage
                printf("You dealt 15 damage to the enemy.\n");
                break;
            case 3: //magic blast
                enemy_hp -= 30; //30 damage
                printf("You dealt 30 damage to the enemy.\n");
                break;
            default: //invalid input
                printf("Invalid input. Please try again.\n");
                continue; //restart loop
        }
        
        //check if enemy is defeated
        if(enemy_hp <= 0){
            printf("Congratulations! You defeated the enemy.\n");
            item = rand() % 2; //50% chance of obtaining an item
            if(item == 1){
                printf("You obtained a health potion.\n");
            }
            break; //exit loop
        }
        
        //generate enemy attack
        switch(enemy_attack){
            case 1: //sword slash
                player_hp -= 15; //15 damage
                printf("The enemy dealt 15 damage to you.\n");
                break;
            case 2: //bow shoot
                player_hp -= 10; //10 damage
                printf("The enemy dealt 10 damage to you.\n");
                break;
            case 3: //magic blast
                player_hp -= 20; //20 damage
                printf("The enemy dealt 20 damage to you.\n");
                break;
            default: //invalid input (should never happen)
                printf("An error occured. Ending game...\n");
                return -1; //exit game
        }
        
        //check if player is defeated
        if(player_hp <= 0){
            printf("Game over. You were defeated by the enemy.\n");
            break; //exit loop
        }
    }
    
    printf("Thank you for playing.\n");
    return 0; //end game
}