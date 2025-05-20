//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int health = 100;
int sword = 0;
int potion = 0;

void start_game();
void game_over();

int main() {
    start_game();
    return 0;
} 

void start_game() {
    char name[15];
    printf("Welcome to Brave Adventure!\n");
    printf("What is your name, brave adventurer?\n");
    scanf("%s", name);
    printf("\nWelcome, %s! Your quest begins now!\n", name);
    printf("You find yourself in a dark and spooky dungeon. You have no weapons or items.\n");
    printf("You see three paths to take: left, middle, or right.\n");
    char path[10];
    scanf("%s", path);
    if (strcmp(path, "left") == 0) {
        printf("You have encountered a goblin!\n");
        printf("The goblin throws a rock at you and you lose 10 health.\n");
        health -= 10;
        printf("You have %d health remaining.\n", health);
        printf("You have two options: fight or run.\n");
        char choice[10];
        scanf("%s", choice);
        if (strcmp(choice, "fight") == 0) {
            printf("You attack the goblin with your bare hands.\n");
            printf("The goblin counterattacks and you take 5 damage.\n");
            health -= 5;
            printf("You have %d health remaining.\n", health);
            printf("You defeat the goblin and find a sword on the ground.\n");
            sword = 1;
            printf("You pick up the sword and continue on your way.\n");
        } else {
            printf("You run away from the goblin.\n");
        }
    } else if (strcmp(path, "middle") == 0) {
        printf("You find a potion on the ground.\n");
        potion = 1;
        printf("You pick up the potion and continue on your way.\n");
    } else {
        printf("You have encountered a giant spider.\n");
        printf("The spider attacks you and you lose 20 health.\n");
        health -= 20;
        printf("You have %d health remaining.\n", health);
        if (sword == 1) {
            printf("You use your sword to defeat the spider.\n");
        } else {
            printf("You attack the spider with your bare hands.\n");
            printf("The spider bites you and you take 10 damage.\n");
            health -= 10;
            printf("You have %d health remaining.\n", health);
            printf("You defeat the spider and continue on your way.\n");
        }
    }
    printf("You see a door at the end of the hallway.\n");
    printf("Do you want to open the door? (yes or no)\n");
    char answer[10];
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 0) {
        if (potion == 1) {
            printf("You use the potion to heal yourself.\n");
            health += 30;
            potion = 0;
            printf("You have %d health remaining.\n", health);
        }
        printf("You open the door and see the treasure chest.\n");
        printf("You open the chest and find a magical amulet.\n");
        printf("You put on the amulet and feel invincible!\n");
        printf("Congratulations, you have completed the game!\n");
    } else {
        game_over();
    }
}

void game_over() {
    printf("Game Over! You failed to complete your quest.\n");
    exit(0);
}