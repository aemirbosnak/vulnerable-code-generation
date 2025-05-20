//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int playerChoice, monsterChoice, numTurns = 0, monsterHealth = 100, playerHealth = 100;
    srand(time(0));
    
    printf("You have entered the haunted house and stumbled upon a vampire monster!\n\n");
    printf("The monster has 100 health points. You have also 100 health points.\n\n");
    
    while(monsterHealth > 0 && playerHealth > 0){
        printf("What would you like to do?\n\n");
        printf("1. Attack the monster!\n");
        printf("2. Run away!\n\n");
        scanf("%d", &playerChoice);

        if(playerChoice == 1){
            printf("You attack the monster with a wooden stake...\n");
            int attack = rand() % 20 + 1;
            if(attack <= 15){
                int damage = rand() % 10 + 1;
                monsterHealth -= damage;
                printf("You hit the monster for %d damage!\n", damage);
            } else {
                printf("You missed the monster!\n");
            }

            int monsterAttack = rand() % 20 + 1;
            if(monsterAttack <= 15){
                int damage = rand() % 10 + 1;
                playerHealth -= damage;
                printf("The monster hits you for %d damage!\n", damage);
            } else {
                printf("The monster missed you!\n");
            }
        } else if(playerChoice == 2){
            printf("You try to run away, but the monster catches you...\n");
            int monsterAttack = rand() % 20 + 1;
            if(monsterAttack <= 10){
                printf("You manage to escape!\n");
                break;
            } else {
                int damage = rand() % 10 + 1;
                playerHealth -= damage;
                printf("The monster hits you for %d damage!\n", damage);
            }
        } else {
            printf("Invalid choice!\n");
            continue;
        }
        numTurns++;
    }

    if(monsterHealth <= 0){
        printf("You have defeated the monster in %d turns! Congratulations!\n", numTurns);
    } else {
        printf("The monster has defeated you! Better luck next time...\n");
    }

    return 0;
}