//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This C Text-Based Adventure Game will take you on an exciting journey through a mysterious forest, full of dangerous creatures and hidden treasures. Are you ready to begin? */

int main() {
    char name[20];
    int health = 100;
    int gold = 0;
    int choice;

    printf("Welcome adventurer! What is your name?\n");
    scanf("%s", name);
    printf("Hello, %s! You are about to embark on a perilous journey through the Forest of Shadows. Your health is currently at %d, and you have %d gold. Good luck!\n", name, health, gold);

    while (health > 0) {
        printf("You are walking through the dark forest when you come across a fork in the road. Will you go left (1) or right (2)?\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You chose to go left. You walk for a while until you come across a clearing. In the center of the clearing is a chest containing 50 gold. Do you take it (1) or leave it (2)?\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You take the gold, but as you turn to leave, a giant spider appears out of nowhere and attacks you! You lose 20 health.\n");
                health -= 20;
                printf("Your health is now %d.\n", health);
                if (health <= 0) {
                    printf("You have been defeated by the spider. Game over.\n");
                    return 0;
                }
                printf("You continue on through the forest.\n");
            }
            else {
                printf("You leave the gold and continue on through the forest.\n");
            }
        }
        else {
            printf("You chose to go right. You walk for a while when you suddenly come face-to-face with a pack of wolves! Do you run (1) or fight (2)?\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You run as fast as you can, but the wolves are faster. They catch up to you and you lose 30 health.\n");
                health -= 30;
                printf("Your health is now %d.\n", health);
                if (health <= 0) {
                    printf("You have been defeated by the wolves. Game over.\n");
                    return 0;
                }
                printf("You continue on through the forest, cautious of what may come next.\n");
            }
            else {
                printf("You fight the wolves with your trusty sword. After a long and grueling battle, you emerge victorious! You gain 100 gold.\n");
                gold += 100;
                printf("Your gold is now %d.\n", gold);
                printf("You continue on through the forest.\n");
            }
        }
    }
    printf("You have run out of health. Game over.\n");
    return 0;
}