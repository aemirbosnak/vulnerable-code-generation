//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Seed for random number generation
    int player_health = 100; //Initialize player health to 100
    printf("Welcome to The Quest!\n");
    printf("----------------------\n");
    printf("You find yourself outside a dark cave, do you want to enter? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if(choice == 'n') {
        printf("You decide not to enter the cave.\nGoodbye!\n");
        return 0;
    } else if (choice != 'y') {
        printf("Invalid choice. Please choose 'y' or 'n'.\n");
        return 0;
    }
    printf("You enter the cave and find yourself in a dark tunnel.\n");
    printf("As you move deeper, the air becomes more humid and stinky.\n");
    printf("Suddenly, a goblin jumps out in front of you!\n");
    int goblin_health = rand() % 50 + 50; //Random health between 50-99
    printf("The goblin has %d health.\n", goblin_health);
    while(player_health > 0 && goblin_health > 0) { //Battle loop
        printf("Attack or run? (a/r): ");
        char action;
        scanf(" %c", &action); //Space before %c to ignore any newline character
        if(action == 'r') {
            printf("You try to run but the goblin catches up and attacks you.\n");
            player_health -= rand() % 10 + 5; //Random damage between 5-14
            printf("You now have %d health.\n", player_health);
        } else if (action != 'a') {
            printf("Invalid choice. Please choose 'a' or 'r'.\n");
        } else {
            int damage = rand() % 20 + 10; //Random damage between 10-29
            printf("You attack the goblin for %d damage!\n", damage);
            goblin_health -= damage;
            printf("The goblin now has %d health.\n", goblin_health);
            if(goblin_health <= 0) {
                printf("You have defeated the goblin!\n");
                break; //Exit battle loop
            }
            printf("The goblin retaliates and attacks you.\n");
            player_health -= rand() % 15 + 10; //Random damage between 10-24
            printf("You now have %d health.\n", player_health);
        }
    }
    if(player_health > 0) { //Player won
        printf("You have emerged victorious from the cave!\nCongratulations!\n");
    } else { //Goblin won
        printf("You have been defeated by the goblin.\nBetter luck next time!\n");
    }
    return 0;
}