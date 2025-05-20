//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed rand with current time
    int player_health = 100;
    int enemy_health = 100;
    
    printf("Welcome to the Quest for the Golden Orb!\n\n");
    printf("You are an adventurer on a dangerous quest to retrieve the fabled Golden Orb!\n\n");
    printf("You find yourself in a dark and creepy forest, and must fight through hordes of enemies to reach your goal.\n\n");
    
    while (player_health > 0 && enemy_health > 0) {
        int player_attack = rand() % 30 + 1; // player can do between 1-30 damage
        int enemy_attack = rand() % 20 + 1; // enemy can do between 1-20 damage
        
        printf("You have %d health.\n", player_health);
        printf("The enemy has %d health.\n", enemy_health);
        
        printf("What do you want to do? (1 for attack, 2 for heal)\n");
        int action;
        scanf("%d", &action);
        
        if (action == 1) { // attack
            enemy_health -= player_attack; // subtract player attack from enemy health
            printf("You hit the enemy for %d damage!\n", player_attack);
        } else if (action == 2) { // heal
            int healing = rand() % 20 + 5; // healing between 5-25
            player_health += healing; // add healing to player health
            printf("You healed yourself for %d points!\n", healing);
        } else { // invalid input
            printf("Sorry, I didn't understand that. Try again.\n");
            continue; // restart while loop
        }
        
        if (enemy_health <= 0) { // enemy defeated
            printf("You defeated the enemy! Congratulations!\n");
            break; // exit while loop
        }
        
        printf("The enemy attacks!\n");
        player_health -= enemy_attack; // subtract enemy attack from player health
        printf("The enemy hits you for %d damage!\n", enemy_attack);

        if (player_health <= 0) { // player defeated
            printf("Oh no! You were defeated! Try again next time.\n");
            break; // exit while loop
        }
    }
    
    printf("Thanks for playing!\n");
    return 0;
}