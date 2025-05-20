//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int health = 100;
    int score = 0;
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nWelcome %s to the Text-Based Adventure Game!\n\n", name);
    srand(time(NULL));
    int randomEnemy = rand() % 3 + 1; // Generates a random enemy between 1 and 3
    switch(randomEnemy) {
        case 1:
            printf("\nYou encounter a giant spider!\n");
            break;
        case 2:
            printf("\nYou encounter a pack of wolves!\n");
            break;
        case 3:
            printf("\nYou encounter a group of bandits!\n");
            break;
    }
    int enemyHealth = rand() % 50 + 1; // Generates a random enemy health between 1 and 50
    while(health > 0 && enemyHealth > 0) {
        printf("\nYour health: %d\n", health);
        printf("Enemy health: %d\n", enemyHealth);
        printf("\nWhat do you want to do?\n1. Attack\n2. Defend\n");
        scanf("%d", &choice);
        if(choice == 1) {
            health -= 10;
            enemyHealth -= rand() % 10 + 1; // Deals random damage between 1 and 10
            printf("\nYou attacked the enemy and dealt %d damage!\n", rand() % 10 + 1);
        }
        else if(choice == 2) {
            health -= 5;
            enemyHealth -= rand() % 5 + 1; // Deals random damage between 1 and 5
            printf("\nYou defended yourself and dealt %d damage!\n", rand() % 5 + 1);
        }
        else {
            printf("\nInvalid choice!\n");
        }
    }
    if(health <= 0) {
        printf("\nYou have been defeated by the enemy!\n");
    }
    else {
        printf("\nYou have defeated the enemy!\n");
        score++;
    }
    printf("\nYour score: %d\n", score);
    return 0;
}