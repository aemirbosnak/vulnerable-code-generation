//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to print game title and rules
void printGameTitle(){
    printf("\t\t------------------------------------\n");
    printf("\t\t Welcome to Cyberpunk Terminal Game\n");
    printf("\t\t------------------------------------\n");
    printf("\n");
    printf("\t\t>>>Instructions<<<\n");
    printf("\t\t1. Player has 5 health points to start with.\n");
    printf("\t\t2. Player will face 4 opponents.\n");
    printf("\t\t3. Each opponent has different strength and attack points.\n");
    printf("\t\t4. Player can choose to attack or defend in each round.\n");
    printf("\t\t5. If the player's health reaches 0, the game ends and the player loses.\n");
    printf("\t\t6. If all opponents are defeated, the player wins!\n\n");
}

//function to get a random number between min and max
int getRandomNumber(int min, int max){
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

//function to print player's health and opponent's health
void printHealth(int playerHealth, int opponentHealth){
    printf("\n");
    printf("\t\tPlayer Health: %d\n", playerHealth);
    printf("\t\tOpponent Health: %d\n", opponentHealth);
    printf("\n");
}

//function to simulate player's attack
int playerAttack(int min, int max){
    int attackPoints = getRandomNumber(min, max);
    printf("\t\tYou attack with %d points of damage!\n", attackPoints);
    return attackPoints;
}

//function to simulate player's defend
int playerDefend(){
    printf("\t\tYou defend this round.\n");
    return 0;
}

//function to simulate opponent's attack
int opponentAttack(int opponentStrength, int min, int max){
    int attackPoints = getRandomNumber(min, max) * opponentStrength;
    printf("\t\tOpponent attacks with %d points of damage!\n", attackPoints);
    return attackPoints;
}

//function to simulate opponent's defend
int opponentDefend(int opponentStrength){
    printf("\t\tOpponent defends this round.\n");
    return opponentStrength;
}

//function to simulate the game
void startGame(){
    int playerHealth = 5;
    int opponentStrength[] = {1, 2, 3, 4};
    int opponentHealth[] = {5, 7, 10, 15};
    int opponentMaxAttackPoints[] = {1, 2, 3, 4};
    int opponentMaxDefendPoints[] = {1, 2, 2, 3};
    int currentPlayer = 0;
    int currentOpponent = 0;

    printGameTitle();

    while(currentOpponent < 4){
        printf("\t\tYou are facing Opponent %d\n", (currentOpponent + 1));
        printf("\n");

        //get player's choice
        printf("\t\tWhat do you want to do?\n");
        printf("\t\t1. Attack (press 1)\n");
        printf("\t\t2. Defend (press 2)\n");
        int choice;
        scanf("%d", &choice);

        //simulate player's turn
        int playerPoints;
        if(choice == 1){
            playerPoints = playerAttack(1, 3);
            opponentHealth[currentOpponent] -= playerPoints;
        }
        else{
            playerDefend();
        }

        //check if opponent is already defeated
        if(opponentHealth[currentOpponent] <= 0){
            printf("\t\tYou have defeated Opponent %d!\n", (currentOpponent + 1));
            printHealth(playerHealth, 0);
            currentOpponent++;
            continue;
        }

        //simulate opponent's turn
        int opponentPoints;
        if(getRandomNumber(0, 1)){
            //opponent attacks
            opponentPoints = opponentAttack(opponentStrength[currentOpponent], 1, opponentMaxAttackPoints[currentOpponent]);
            playerHealth -= opponentPoints;
        }
        else{
            //opponent defends
            opponentPoints = opponentDefend(opponentStrength[currentOpponent]);
        }

        //print health status
        printHealth(playerHealth, opponentHealth[currentOpponent]);

        //check if player is already defeated
        if(playerHealth <= 0){
            printf("\t\tYou have been defeated!\n");
            return;
        }
    }

    printf("\t\tYou have won the game!\n");
}

int main(){
    srand(time(NULL));
    startGame();
    return 0;
}