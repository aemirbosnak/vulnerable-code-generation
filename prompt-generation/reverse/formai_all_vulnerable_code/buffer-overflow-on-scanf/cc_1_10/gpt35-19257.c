//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//structure to hold the player info
struct Player{
    char name[50];
    int shield;
    int score;
    int fuel;
};

//function to generate a random number between min and max
int getRandom(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

//function to simulate a battle with an alien spaceship
void battle(struct Player *p){
    int alienShield = getRandom(50, 100);
    printf("\n\nAn alien spaceship with shield %d is attacking you!", alienShield);
    while(alienShield > 0){
        int damage = getRandom(10, 30);
        printf("\nYou attacked the alien spaceship with damage %d", damage);
        alienShield -= damage;
        if(alienShield <= 0){
            printf("\nCongratulations! You destroyed the alien spaceship and earned 10 points!");
            p->score += 10;
        }
        else{
            damage = getRandom(5, 15);
            printf("\nThe alien spaceship attacked you with damage %d", damage);
            p->shield -= damage;
            if(p->shield <= 0){
                printf("\nGame Over! Your spaceship was destroyed by the alien!");
                exit(0);
            }
        }
    }
}

//function to simulate a fuel station where the player can refuel
void fuelStation(struct Player *p){
    int cost = getRandom(10, 20);
    printf("\n\nYou found a fuel station! The cost to refuel is %d", cost);
    if(p->score < cost){
        printf("\nSorry, you don't have enough points to refuel!");
        return;
    }
    p->fuel = 100;
    p->score -= cost;
    printf("\nCongratulations! You refueled your spaceship to 100 fuel!");
}

//function to simulate a shop where the player can buy shields
void shieldShop(struct Player *p){
    int cost = getRandom(30, 50);
    printf("\n\nYou found a shield shop! The cost of a shield is %d", cost);
    if(p->score < cost){
        printf("\nSorry, you don't have enough points to buy a shield!");
        return;
    }
    p->shield += getRandom(20, 30);
    p->score -= cost;
    printf("\nCongratulations! You bought a shield and now your shield strength is %d", p->shield);
}

int main(){
    srand(time(NULL)); //seed the random generator with current time
    struct Player player;
    printf("Welcome to Procedural Space Adventure!\n\nEnter your name: ");
    scanf("%s", player.name);
    player.fuel = 100;
    player.shield = 100;
    player.score = 0;
    printf("\nHello %s! You are starting with a spaceship with %d fuel, %d shield, and %d points.", player.name, player.fuel, player.shield, player.score);
    while(1){
        int choice;
        printf("\n\nWhat do you want to do?\n1. Move to a random planet\n2. Refuel your spaceship\n3. Visit a shield shop\n4. Quit the game\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int random = getRandom(1, 3);
                printf("\n\nMoving to planet %d...\n", random);
                player.fuel -= getRandom(10, 20);
                if(player.fuel <= 0){
                    printf("\nGame Over! Your spaceship ran out of fuel and you got stranded in space!");
                    exit(0);
                }
                if(getRandom(0, 1) == 1){
                    battle(&player);
                }
                else{
                    printf("\nCongratulations! You explored planet %d and earned 5 points!", random);
                    player.score += 5;
                }
                break;
            }
            case 2:{
                fuelStation(&player);
                break;
            }
            case 3:{
                shieldShop(&player);
                break;
            }
            case 4:{
                printf("\n\nThanks for playing %s! Your final score is %d.\n", player.name, player.score);
                exit(0);
            }
            default:{
                printf("\nInvalid choice!");
                break;
            }
        }
    }
    return 0;
}