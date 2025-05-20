//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void enemyEncounter(int playerHealth, int enemyHealth);

int main(){
    int playerHealth = 100, enemyHealth = 50, randNum, input, score = 0;
    char playerName[20];
    printf("Welcome to Procedural Space Adventure\n");
    printf("What is your name, adventurer?\n");
    scanf("%s", playerName);
    printf("%s, you have been hired to explore a newly discovered planet in the Andromeda galaxy.\n", playerName);
    printf("You are equipped with a laser gun and a jetpack to navigate through the planet's terrain.\n");
    printf("As you start to land on the planet's surface, your radar picks up a nearby enemy ship.\n");
    srand(time(NULL));
    randNum = rand() % 3 + 1;
    switch (randNum){
        case 1:
            printf("The enemy ship is equipped with lasers!\n");
            break;
        case 2:
            printf("The enemy ship has sent drones to attack you!\n");
            break;
        case 3:
            printf("The enemy ship is charging up a missile!\n");
            break;
    }
    printf("You have encountered an enemy ship!\n");
    printf("You have %d health points remaining.\n", playerHealth);
    printf("The enemy ship has %d health points.\n", enemyHealth);
    printf("What do you want to do?\n");
    printf("1. Attack\n");
    printf("2. Use Jetpack to Dodge\n");
    scanf("%d", &input);
    switch (input){
        case 1:
            enemyHealth -= 30;
            printf("You used your laser gun to attack and caused 30 damage to the enemy ship.\n");
            break;
        case 2:
            printf("You used your jetpack to successfully dodge the enemy's attack.\n");
            break;
    }
    if (enemyHealth > 0){
        playerHealth -= 20;
        printf("The enemy ship attacked you and caused 20 damage.\n");
    }
    if (playerHealth > 0 && enemyHealth > 0){
        enemyEncounter(playerHealth, enemyHealth);
    }
    else if (playerHealth <= 0){
        printf("You have lost all your health points and have been defeated.\n");
    }
    else if (enemyHealth <= 0){
        score += 50;
        printf("Congratulations! You have defeated the enemy ship and gained 50 points.\n");
    }
    printf("Your final score is %d.\n", score);
    printf("Thank you for playing Procedural Space Adventure!\n");
    return 0;
}

void enemyEncounter(int playerHealth, int enemyHealth){
    int input, randNum;
    printf("You have %d health points remaining.\n", playerHealth);
    printf("The enemy ship has %d health points.\n", enemyHealth);
    printf("What do you want to do?\n");
    printf("1. Attack\n");
    printf("2. Use Jetpack to Dodge\n");
    scanf("%d", &input);
    switch (input){
        case 1:
            enemyHealth -= 30;
            printf("You used your laser gun to attack and caused 30 damage to the enemy ship.\n");
            break;
        case 2:
            printf("You used your jetpack to successfully dodge the enemy's attack.\n");
            break;
    }
    if (enemyHealth > 0){
        srand(time(NULL));
        randNum = rand() % 3 + 1;
        switch (randNum){
            case 1:
                printf("The enemy ship is equipped with lasers!\n");
                break;
            case 2:
                printf("The enemy ship has sent drones to attack you!\n");
                break;
            case 3:
                printf("The enemy ship is charging up a missile!\n");
                break;
        }
        playerHealth -= 20;
        printf("The enemy ship attacked you and caused 20 damage.\n");
    }
    if (playerHealth > 0 && enemyHealth > 0){
        enemyEncounter(playerHealth, enemyHealth);
    }
    else if (playerHealth <= 0){
        printf("You have lost all your health points and have been defeated.\n");
    }
    else if (enemyHealth <= 0){
        printf("Congratulations! You have defeated the enemy ship and gained 50 points.\n");
    }
}