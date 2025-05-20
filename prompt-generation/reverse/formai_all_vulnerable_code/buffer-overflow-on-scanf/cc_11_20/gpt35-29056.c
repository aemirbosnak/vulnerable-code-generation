//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_health = 100, bear_health = 100;
    int player_attack, bear_attack;
    int first_turn;
    srand(time(0)); // Seed random number generator with current time
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are exploring a dark and creepy haunted house, and suddenly a giant bear attacks you!\n");
    printf("You must fight and defeat the bear with your wits and strength.\n");
    
    do { // Loop until either the player or bear dies
        printf("Current health: Player %d Bear %d\n", player_health, bear_health);
        printf("Enter 1 to attack, 2 to defend, or 3 to flee: ");
        scanf("%d", &player_attack);
        while(player_attack < 1 || player_attack > 3) { // Input validation
            printf("Invalid option. Please enter 1 to attack, 2 to defend, or 3 to flee: ");
            scanf("%d", &player_attack);
        }
        
        bear_attack = rand() % 3 + 1; // Generate random bear attack
        
        switch(player_attack) {
            case 1: // Player attacks
                printf("You attack the bear!\n");
                if(bear_attack == 1) { // Bear attacks
                    printf("The bear attacks you!\n");
                    player_health -= 40;
                    bear_health -= 20;
                } else if(bear_attack == 2) { // Bear defends
                    printf("The bear defends against your attack!\n");
                    bear_health -= 10;
                } else { // Bear flees
                    printf("The bear flees!\n");
                    return 0;
                }
                break;
            case 2: // Player defends
                printf("You defend against the bear's attack!\n");
                if(bear_attack == 1) { // Bear attacks
                    printf("The bear attacks you!\n");
                    player_health -= 20;
                } else if(bear_attack == 2) { // Bear defends
                    printf("The bear defends against your attack!\n");
                } else { // Bear flees
                    printf("The bear flees!\n");
                    return 0;
                }
                break;
            case 3: // Player flees
                printf("You try to flee!\n");
                if(bear_attack == 1 || bear_attack == 2) { // Bear attacks or defends
                    printf("The bear blocks your escape!\n");
                } else { // Bear flees
                    printf("You escape from the bear!\n");
                    return 0;
                }
                break;
        }
        
        if(player_health <= 0) { // Player dies
            printf("You have been killed by the bear!\n");
            return 0;
        } else if(bear_health <= 0) { // Bear dies
            printf("You have defeated the bear!\n");
            return 0;
        }
        
        first_turn = rand() % 2; // Randomize first turn
        
        if(first_turn == 0) { // Bear attacks first
            printf("The bear attacks you first!\n");
            if(player_attack == 1) { // Player attacks
                printf("You attack the bear!\n");
                player_health -= 20;
                bear_health -= 40;
            } else if(player_attack == 2) { // Player defends
                printf("You defend against the bear's attack!\n");
                bear_health -= 20;
            }
        }
    } while(player_health > 0 && bear_health > 0);
    
    return 0;
}