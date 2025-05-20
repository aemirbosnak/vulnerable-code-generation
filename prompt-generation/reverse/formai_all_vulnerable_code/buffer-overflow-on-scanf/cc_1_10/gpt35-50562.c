//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to generate random number
int generateRandomNumber(int min, int max){
    srand(time(NULL));
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main(){
    char name[20];
    int age, health = 100, coins = 50;
    printf("Welcome to the Cheerful Adventure Game!!!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("How old are you?\n");
    scanf("%d", &age);
    printf("Hello %s! Your adventure starts now!\n", name);
    
    while(health > 0 && coins > 0){
        printf("\n%s, you have %d health and %d coins.\n", name, health, coins);
        printf("What would you like to do?\n");
        printf("1. Explore the jungle\n");
        printf("2. Visit the market\n");
        printf("3. Rest and recover\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("You are exploring the jungle...\n");
                int randomNum = generateRandomNumber(1, 3);
                switch(randomNum){
                    case 1:
                        printf("You found a chest with 20 coins inside!\n");
                        coins += 20;
                        break;
                    case 2:
                        printf("You encountered a dangerous animal!\n");
                        int animalHealth = generateRandomNumber(20, 50);
                        while(animalHealth > 0 && health > 0){
                            int hit = generateRandomNumber(5, 15);
                            int animalHit = generateRandomNumber(10, 20);
                            printf("You hit the animal with %d damage!\n", hit);
                            animalHealth -= hit;
                            printf("The animal hit you with %d damage!\n", animalHit);
                            health -= animalHit;
                        }
                        if(health <= 0){
                            printf("Game over! You died...\n");
                            break;
                        }
                        printf("You defeated the animal! You gained 30 coins!\n");
                        coins += 30;
                        break;
                    case 3:
                        printf("You found a rare item! You gained 50 health!\n");
                        health += 50;
                        break;
                }
                break;
            case 2:
                printf("You are visiting the market...\n");
                printf("What would you like to buy?\n");
                printf("1. Health potion (20 coins, +30 health)\n");
                printf("2. Sword (40 coins, +20 hit damage)\n");
                printf("3. Shield (30 coins, -10 enemy hit damage)\n");
                int buyChoice;
                scanf("%d", &buyChoice);
                switch(buyChoice){
                    case 1:
                        if(coins >= 20){
                            coins -= 20;
                            health += 30;
                            printf("You bought a health potion! You gained 30 health!\n");
                        }else{
                            printf("Sorry, you don't have enough coins!\n");
                        }
                        break;
                    case 2:
                        if(coins >= 40){
                            coins -= 40;
                            printf("You bought a sword! Your hit damage increased by 20!\n");
                        }else{
                            printf("Sorry, you don't have enough coins!\n");
                        }
                        break;
                    case 3:
                        if(coins >= 30){
                            coins -= 30;
                            printf("You bought a shield! Enemy hit damage decreased by 10!\n");
                        }else{
                            printf("Sorry, you don't have enough coins!\n");
                        }
                        break;
                }
                break;
            case 3:
                printf("You are resting and recovering...\n");
                int recover = generateRandomNumber(10, 30);
                health += recover;
                printf("You gained %d health!\n", recover);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    if(health <= 0){
        printf("Game over! You died...\n");
    }else{
        printf("Congratulations %s! You finished the game with %d health and %d coins!\n", name, health, coins);
    }

    return 0;
}