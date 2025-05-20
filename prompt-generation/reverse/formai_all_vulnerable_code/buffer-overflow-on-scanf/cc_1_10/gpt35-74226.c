//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fuel = 100;
int health = 100;
int score = 0;
int level = 1;

void initialize();
void startGame();
void showDetails();
void levelUp();
void endGame();

int main(){
    initialize();
    startGame();
    endGame();
    return 0;
}

void initialize(){
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are now in Level 1.\n");
    printf("Your spaceship is loaded with 100 units of fuel and 100 points of health.\n");
}

void startGame(){
    srand(time(0));
    int enemyHealth = 50;
    int enemyScore = 50;

    while(health > 0 && fuel > 0){
        int random = rand() % 10 + 1;
        printf("You are travelling through space, a random event occurs...\n");
        if(random == 1 || random == 2){
            printf("You found a wormhole! You jump ahead a level.\n");
            levelUp();
        }
        else if(random == 3 || random == 4 || random == 5){
            printf("You found a fuel station! Refuel your ship.\n");
            fuel += 50;
        }
        else if(random == 6 || random == 7 || random == 8){
            printf("Space pirates attack! Prepare for battle...\n");
            while(enemyHealth > 0 && health > 0){
                printf("Your health: %d Fuel: %d\n", health, fuel);
                printf("Enemy health: %d\n", enemyHealth);
                int choice;
                printf("Select your move: 1) Attack 2) Defend\n");
                scanf("%d", &choice);
                if(choice == 1){
                    int attack = rand() % 20 + 1;
                    enemyHealth -= attack;
                    printf("You attacked the enemy! You dealt %d damage.\n", attack);
                    if(enemyHealth <= 0){
                        printf("You defeated the space pirates!\n");
                        score += enemyScore;
                        break;
                    }
                    int enemyAttack = rand() % 20 + 1;
                    health -= enemyAttack;
                    printf("The enemy attacked you! You took %d damage.\n", enemyAttack);
                }
                else if(choice == 2){
                    printf("You defense ability increased by 50%\n");
                    int enemyAttack = rand() % 20 + 1;
                    health -= (enemyAttack / 2);
                    printf("The enemy attacked you! Your defense ability increased your defense by half. You took %d damage.\n", (enemyAttack / 2));
                }
                else{
                    printf("Invalid choice, choose again.\n");
                }
            }
            if(health <= 0){
                printf("Game Over! You lost...\n");
                endGame();
                break;
            }
        }
        else{
            printf("You encountered space debris and your fuel got depleted by 20.\n");
            fuel -= 20;
        }
        showDetails();
    }

    if(fuel <= 0){
        printf("Game Over! You ran out of fuel...\n");
    }
}

void showDetails(){
    printf("Your health: %d Fuel: %d Score: %d\n", health, fuel, score);
}

void levelUp(){
    level += 1;
    printf("Congratulations! You are now in Level %d.\n", level);
    health += 50;
    fuel += 50;
    score += 100;
}

void endGame(){
    printf("Thank you for playing the Procedural Space Adventure game!\n");
    printf("Your final score is: %d\n", score);
}