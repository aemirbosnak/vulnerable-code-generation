//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    
    int choice;
    int hp = 100;
    int enemies_fought = 0;
    int gold = 0;
    int potions = 3;
    
    printf("Welcome to the peaceful adventure game! You find yourself on a beautiful island surrounded by lush green forests and calm waters.\n");
    
    while(hp > 0) {
        printf("\nYou have %d health points, %d gold and %d potions\n", hp, gold, potions);
        printf("What would you like to do?\n");
        printf("[1] Explore the forest \n");
        printf("[2] Go fishing \n");
        printf("[3] Visit the market \n");
        printf("[4] Quit the game \n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("You enter the forest and find a group of friendly woodland animals.\n");
                printf("The animals share some of their food with you and give you directions to a nearby treasure chest.\n");
                printf("You find the treasure chest and gain 50 gold!\n");
                gold += 50;
                break;
            
            case 2:
                printf("You go fishing and catch a delicious fish.\n");
                printf("You cook the fish and enjoy a hearty meal, regaining 10 health points.\n");
                hp += 10;
                break;
            
            case 3:
                printf("You visit the market and find a store selling health potions.\n");
                printf("You purchase a potion for 25 gold.\n");
                if(gold >= 25) {
                    potions += 1;
                    gold -= 25;
                }
                else {
                    printf("You do not have enough gold to purchase a potion.\n");
                }
                break;
                
            case 4:
                printf("Thanks for playing the peaceful adventure game!\n");
                return 0;
                
            default:
                printf("Invalid choice, please choose again.\n");
                continue;
        }
        
        if(enemies_fought < 3) {
            printf("You continue exploring and encounter a group of friendly villagers.\n");
            printf("The villagers tell you about some bandits that have been causing trouble in the area.\n");
            printf("Will you [1] help the villagers fight the bandits or [2] ignore them and keep exploring?\n");
            scanf("%d", &choice);
            
            if(choice == 1) {
                printf("You help the villagers fight the bandits and emerge victorious!\n");
                printf("You gain 75 gold and 25 experience points.\n");
                gold += 75;
                enemies_fought++;
            }
            else {
                printf("You ignore the villagers' plea for help and keep exploring.\n");
            }
        }
        else {
            printf("You explore further and encounter a powerful enemy!\n");
            printf("Will you [1] fight the enemy or [2] use a potion to escape?\n");
            scanf("%d", &choice);
            
            if(choice == 1) {
                srand(time(NULL));
                int enemy_strength = rand() % 101;
                if(enemy_strength > 50) {
                    printf("You fight the enemy but are defeated.\n");
                    printf("Game over.\n");
                    return 0;
                }
                else {
                    printf("You defeat the enemy and gain 100 gold and 50 experience points!\n");
                    gold += 100;
                    enemies_fought++;
                }
            }
            else if(choice == 2) {
                if(potions > 0) {
                    printf("You use a potion to escape the enemy's wrath.\n");
                    hp += 50;
                    potions -= 1;
                }
                else {
                    printf("You do not have any potions to use!\n");
                }
            }
            else {
                printf("Invalid choice, please choose again.\n");
                continue;
            }
        }
        
        if(enemies_fought == 5) {
            printf("Congratulations, you have defeated all the enemies and won the game!\n");
            return 0;
        }
    }
    
    printf("You have run out of health points. Game over.\n");
    return 0;
}