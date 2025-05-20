//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayIntro();
void choosePath();
void fightMonster();
int getRandomNumber(int min, int max);

int main() {
    displayIntro();
    choosePath();
    return 0;
}

/* Function to display the game introduction */
void displayIntro() {
    printf("\n\nWelcome to the Text-Based Adventure Game!\n\n");
    printf("You are in a dark forest surrounded by trees on all sides.\n");
    printf("You can hear strange noises in the distance.\n");
    printf("You have to find your way out of the forest.\n");
    printf("You can choose to go left or right.\n\n");
}

/* Function to choose the path and proceed with the game */
void choosePath() {
    char path[10];
    printf("Which path will you choose? (left/right): ");
    scanf("%s", path);
    
    if (strcmp(path, "left") == 0) {
        printf("\nYou have chosen the left path.\n");
        fightMonster();
    } else if (strcmp(path, "right") == 0) {
        printf("\nYou have chosen the right path.\n");
        printf("You are walking for some time and you see a river.\n");
        printf("Would you like to swim across the river? (yes/no): ");
        scanf("%s", path);
        if (strcmp(path, "yes") == 0) {
            printf("\nYou swim across the river and reach the other side safely.\n");
            printf("You see a cave in front of you.\n");
            printf("Do you want to enter the cave? (yes/no): ");
            scanf("%s", path);
            if (strcmp(path, "yes") == 0) {
              printf("\nYou enter the cave and find a treasure chest filled with gold!\n");
              printf("Congratulations, you have won the game!\n");
            } else {
              printf("\nYou decide not to enter the cave and return to the forest.\n");
              choosePath();
            }
        } else {
            printf("\nYou decide not to swim across the river and return to the forest.\n");
            choosePath();
        }
    } else {
        printf("Invalid selection. Please choose again.\n");
        choosePath();
    }
}

/* Function to start the monster fight */
void fightMonster() {
    printf("\nYou are walking on the left path and suddenly you hear a loud growl.\n");
    printf("A huge monster appears in front of you.\n");
    printf("You have to fight the monster to proceed with the game.\n");
    
    int playerHealth = 100;
    int monsterHealth = 100;
    int turn = 1;
    
    while (playerHealth > 0 && monsterHealth > 0) {
        printf("\n-- Turn %d --\n", turn);
        printf("Your health: %d\n", playerHealth);
        printf("Monster health: %d\n", monsterHealth);
        printf("Choose your move (1 - attack, 2 - defend): ");
        
        int playerMove;
        scanf("%d", &playerMove);
        
        /* Player attack */
        if (playerMove == 1) {
            int damage = getRandomNumber(10, 20);
            printf("\nYou attack the monster and deal %d damage.\n", damage);
            monsterHealth -= damage;
            if (monsterHealth <= 0) {
                printf("You killed the monster!\n");
                choosePath();
            }
        } else if (playerMove == 2) { /* Player defend */
            int defense = getRandomNumber(5, 10);
            printf("\nYou defend against the monster's attack and reduce its damage by %d.\n", defense);
            playerHealth -= (10 - defense);
            if (playerHealth <= 0) {
                printf("You were killed by the monster!\n");
                return;
            }
        } else {
            printf("Invalid move. Please choose again.\n");
        }

        /* Monster attack */
        int monsterMove = getRandomNumber(1, 2);
        if (monsterMove == 1) {
            int damage = getRandomNumber(5, 15);
            printf("The monster attacks you and deals %d damage.\n", damage);
            playerHealth -= damage;
            if (playerHealth <= 0) {
                printf("You were killed by the monster!\n");
                return;
            }
        } else { /* Monster defend */
            int defense = getRandomNumber(5, 10);
            printf("The monster defends against your attack and reduces your damage by %d.\n", defense);
            monsterHealth -= (10 - defense);
            if (monsterHealth <= 0) {
                printf("You killed the monster!\n");
                choosePath();
            }
        }
        turn++;
    }
}

/* Function to generate a random number between min and max */
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}