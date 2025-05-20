//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void spaceAdventure(int level); //prototype

int main(){
    srand(time(NULL)); //initialize random seed

    printf("Welcome to Space Adventure!\n");
    printf("============================\n");

    spaceAdventure(1); //start the game at level 1

    return 0;
}

void spaceAdventure(int level){
    printf("\nLevel %d\n", level);

    int health = 100; //player's health at the start of each level
    int damage = rand()%11 + 10; //enemy's potential damage

    printf("Your health: %d\n", health);
    printf("Enemy's damage: %d\n", damage);

    //recursive base case
    if(level == 5){
        printf("\nCongratulations! You have reached the end of the space adventure!\n");
        return;
    }

    printf("Do you wish to proceed to level %d? (y/n)\n", level+1);

    char choice;
    scanf(" %c", &choice);

    if(choice == 'y'){
        printf("You have chosen to proceed to level %d.\n", level+1);
        health -= damage; //player's health decrease based on enemy's potential damage
        printf("Your health after level %d: %d\n", level, health);

        //recursive call if player's health is still above 0
        if(health > 0){
            spaceAdventure(level+1);
        }else{
            printf("\nGame over! You have been defeated.\n");
        }
    }else{
        printf("You have decided to stay at level %d.\n", level);
    }
}