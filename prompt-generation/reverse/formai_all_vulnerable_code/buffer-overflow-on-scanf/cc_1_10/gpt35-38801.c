//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Player struct to store players information
struct player{
    char name[20];
    int score;
    int health;
};

//Function to generate random number of enemies
int getNumEnemies(){
    int numEnemies = rand()%4 + 1;
    return numEnemies;
}

//Function to check if player's health is greater than 0
int isAlive(struct player p){
    if(p.health > 0){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to play the game
void playGame(struct player p){

    int numEnemies;
    int enemyHealth;
    int enemyDamage;
    int playerDamage;
    int i;
    int choice;

    printf("\nWelcome %s to the Game\n", p.name);
    printf("Your current score is %d\n", p.score);
    printf("Your current health is %d\n\n", p.health);

    //Loop until player's health is greater than 0 
    while(isAlive(p)){
        numEnemies = getNumEnemies();
        printf("You are being attacked by %d enemies\n", numEnemies);

        //Loop through each enemy
        for(i=1; i<=numEnemies; i++){
            enemyHealth = rand()%50 + 50;
            enemyDamage = rand()%10 + 10;
            printf("Enemy %d has %d health\n", i, enemyHealth);
            while(enemyHealth > 0 && p.health > 0){
                //Player turn
                printf("\n%s's turn:\n", p.name);
                printf("Enter 1 to attack and 2 to defend: ");
                scanf("%d", &choice);
                if(choice == 1){
                    playerDamage = rand()%20 + 10;
                    enemyHealth -= playerDamage;
                    printf("\n%s did %d damage to Enemy %d\n", p.name, playerDamage, i);
                    printf("Enemy %d's health is now %d\n", i, enemyHealth);
                }
                else{
                    printf("\n%s is defending\n", p.name);
                }

                //Enemy turn
                if(enemyHealth > 0){
                    printf("\nEnemy %d's turn:\n", i);
                    playerDamage = rand()%15 + 5;
                    p.health -= playerDamage;
                    printf("Enemy %d did %d damage to %s\n", i, playerDamage, p.name);
                    printf("%s's health is now %d\n", p.name, p.health);
                }
            }
            if(p.health <= 0){
                printf("\nGAME OVER!\n");
                return;
            }
            else{
                printf("\n%s defeated Enemy %d\n", p.name, i);
                p.score += 10;
                printf("Your score is now %d\n", p.score);
                printf("Your current health is %d\n\n", p.health);
            }
        }
    }
}

//Main function
int main(){

    struct player p;

    printf("Enter your name: ");
    scanf("%s", p.name);
    
    //Set player's starting score and health
    p.score = 0;
    p.health = 100;

    //Seed the random number generator
    srand(time(0));

    //Call the playGame function
    playGame(p);

    return 0;
}