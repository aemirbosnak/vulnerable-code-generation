//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int playerHP = 100;
    int enemyHP = 50;
    int attack = 0;
    int defense = 0;
    int choice;
    int randomEnemyAttack = rand()%10 + 1;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space warrior with %d HP.\n",playerHP);
    printf("You encounter an alien with %d HP.\n",enemyHP);

    while(playerHP > 0 && enemyHP > 0){
        printf("What would you like to do?\n");
        printf("1. Attack\n2. Defend\n");
        scanf("%d",&choice);

        if(choice == 1){
            attack = rand()%10 + 1;
            printf("You attack the alien with %d damage!\n",attack);
            enemyHP -= attack;
        }
        else if(choice == 2){
            defense = rand()%10 + 1;
            printf("You defend yourself with %d defense!\n",defense);
            playerHP += defense;
        }
        else{
            printf("Invalid choice.\n");
        }

        if(enemyHP <= 0){
            printf("You defeated the alien!\n");
            break;
        }
        else if(playerHP <= 0){
            printf("You were defeated by the alien.\n");
            break;
        }

        randomEnemyAttack = rand()%10 + 1;
        printf("The alien attacks you with %d damage!\n",randomEnemyAttack);
        playerHP -= randomEnemyAttack;
    }

    return 0;
}