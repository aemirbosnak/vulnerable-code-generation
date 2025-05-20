//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    // Introduction
    printf("\t\tWelcome to the Text-Based Adventure Game!\n");
    printf("\tYou are lost in a forest and need to find your way out.\n");
    printf("\tYou have four directions to choose from: North, South, East and West.\n");
    printf("\tBut beware, danger is lurking around every corner!\n");

    // Variables
    int player_hp = 100; // player health points
    int player_gold = 0; // player gold coins
    int choice; // player choice for direction
    int monster_hp; // monster health points
    int monster_damage; // monster damage points
    
    // Random seed for monsters
    srand(time(NULL));

    // Game Loop
    while(player_hp > 0){

        // Player Menu
        printf("\nYou have %d health points and %d gold coins.\n", player_hp, player_gold);
        printf("Which direction do you want to go?\n");
        printf("1. North\n");
        printf("2. South\n");
        printf("3. East\n");
        printf("4. West\n");
        scanf("%d", &choice);

        // Monster Encounter
        if(rand() % 3 == 0){ // 33% chance of encountering a monster
            printf("\nOh no! You have encountered a monster!\n");
            monster_hp = rand() % 50 + 50; // monster health points between 50-99
            while(monster_hp > 0){ // monster fight loop
                printf("\nYou have %d health points and the monster has %d health points.\n", player_hp, monster_hp);
                printf("What do you want to do?\n");
                printf("1. Attack\n");
                printf("2. Flee\n");
                scanf("%d", &choice);
                if(choice == 1){ // player attacks monster
                    monster_damage = rand() % 20 + 10; // monster damage points between 10-29
                    printf("\nYou deal %d damage to the monster.\n", monster_damage);
                    monster_hp -= monster_damage;
                    if(monster_hp <= 0){ // monster defeated
                        printf("\nYou have defeated the monster and gained 50 gold coins!\n");
                        player_gold += 50;
                        break;
                    }
                } else if(choice == 2){ // player flees
                    printf("\nYou have fled from the monster.\n");
                    break;
                } else { // player inputs invalid option
                    printf("\nInvalid option, try again.\n");
                }
                // Monster attacks player
                monster_damage = rand() % 30 + 20; // monster damage points between 20-49
                printf("\nThe monster deals %d damage to you.\n", monster_damage);
                player_hp -= monster_damage;
                if(player_hp <= 0){ // player defeated
                    printf("\nYou have been defeated by the monster...\n");
                    break;
                }
            }
        } else { // no monster encounter
            printf("\nYou travel for a while but encounter nothing of interest.\n");
            player_hp -= 10; // player health decreases by 10 due to fatigue
        }

        // Check for Game Over
        if(player_hp <= 0){
            printf("\nGAME OVER!\n");
            printf("You have lost all your health points...\n");
            break;
        } else if(player_gold >= 500){ // player wins if they collect 500 gold coins
            printf("\nCONGRATULATIONS!\n");
            printf("You have collected 500 gold coins and found your way out of the forest!\n");
            break;
        }

    }

    // End of Program
    printf("\nThanks for playing the Text-Based Adventure Game!\n");
    return 0;
}