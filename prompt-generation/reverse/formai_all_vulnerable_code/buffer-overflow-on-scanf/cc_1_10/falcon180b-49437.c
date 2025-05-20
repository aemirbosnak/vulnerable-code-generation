//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave warrior on a quest to defeat the evil dragon.\n");
    printf("Will you emerge victorious or meet your doom?\n\n");

    int choice;
    while(1) {
        system("clear");
        printf("You are in a dark forest. The air is thick with mist.\n");
        printf("What would you like to do?\n");
        printf("1. Attack the dragon\n");
        printf("2. Defend yourself\n");
        printf("3. Run away\n");
        printf("4. Use a potion\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You charge towards the dragon with your sword raised high.\n");
                if(player_health > enemy_health) {
                    printf("You have defeated the dragon! Congratulations!\n");
                    break;
                } else {
                    printf("The dragon breathes fire at you, reducing your health to 0.\n");
                    printf("Game Over.\n");
                    break;
                }
            case 2:
                printf("You raise your shield to protect yourself from the dragon's attacks.\n");
                if(player_health > enemy_health) {
                    printf("You have defeated the dragon! Congratulations!\n");
                    break;
                } else {
                    printf("The dragon's claws slash at you, reducing your health to 0.\n");
                    printf("Game Over.\n");
                    break;
                }
            case 3:
                printf("You turn and run as fast as you can through the forest.\n");
                printf("The dragon chases after you, breathing fire and swiping with its claws.\n");
                if(player_health > enemy_health) {
                    printf("You manage to outrun the dragon and escape!\n");
                    break;
                } else {
                    printf("The dragon catches up to you and defeats you.\n");
                    printf("Game Over.\n");
                    break;
                }
            case 4:
                printf("You reach into your bag and pull out a healing potion.\n");
                printf("You drink the potion, feeling your wounds heal and your strength return.\n");
                player_health += 50;
                if(player_health > 100) {
                    player_health = 100;
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}