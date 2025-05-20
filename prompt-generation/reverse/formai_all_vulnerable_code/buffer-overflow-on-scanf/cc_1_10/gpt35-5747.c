//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds){
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while(clock() < endwait);
}

int main(){
    printf("\nWelcome adventurer, you have been chosen to embark on a mission to explore a distant planet!\n");
    delay(2);
    printf("\nYour spaceship is ready and waiting for you, are you ready to launch? (y/n)\n");
    char choice;
    scanf("%c", &choice);
    
    if(choice == 'y'){
        printf("\nGreat, let's get started!\n");
        delay(2);
    }else{
        printf("\nOh no! Come back when you're ready to explore the unknown.\n");
        exit(0);
    }
    
    printf("\nAs we get closer to the planet, we're picking up some strange readings. It's up to you to investigate.\n");
    delay(2);
    
    printf("\nWe've landed, let's go explore!\n");
    delay(2);
    
    printf("\nYou step out of the spaceship and onto the surface of the planet. As you take your first steps, you notice that the terrain is rocky and uneven.\n");
    delay(3);
    
    printf("\nYou take a few steps and suddenly, a group of strange creatures appear from behind a large rock formation. They don't look friendly...\n");
    delay(3);
    
    int health = 100;
    int attack = 10;
    int enemyHealth = 50;
    int enemyAttack = 5;
    
    while(health > 0 && enemyHealth > 0){
        printf("\nYour health: %d\n", health);
        printf("Enemy health: %d\n", enemyHealth);
        printf("\nWhat do you want to do? (1 for attack/ 2 for run)\n");
        int choice;
        scanf("%d", &choice);
        
        if(choice == 1){
            printf("\nYou attack the enemy with your laser gun.\n");
            enemyHealth -= attack;
            printf("The enemy loses %d health points.\n", attack);
            if(enemyHealth <= 0){
                printf("\nCongratulations, you have defeated the enemy and survived the encounter!\n");
                delay(2);
                printf("\nAs you continue your exploration, you discover a rare element that will revolutionize space travel. You have fulfilled your mission, well done adventurer!\n");
                exit(0);
            }
            
            printf("\nThe enemy attacks you.\n");
            health -= enemyAttack;
            printf("You lose %d health points.\n", enemyAttack);
            if(health <= 0){
                printf("\nOh no! You have been defeated by the enemy. Game Over.\n");
                exit(0);
            }
            
        }else{
            printf("\nYou try to run away from the enemy but they catch up to you and attack.\n");
            health -= enemyAttack;
            printf("You lose %d health points.\n", enemyAttack);
            if(health <= 0){
                printf("\nOh no! You have been defeated by the enemy. Game Over.\n");
                exit(0);
            }
        }
    }
    
    return 0;
}