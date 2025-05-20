//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int health = 100;
int ammo = 100;
int credits = 100;

void enemy_attack(int *health){
    int damage = rand() % 11 + 20;
    *health -= damage;
    printf("Enemy attacked you for %d damage!\n", damage);
}

void buy_ammo(){
    int cost = 10;
    if(credits >= cost){
        credits -= cost;
        ammo += 10;
        printf("You bought 10 ammo for %d credits.\n", cost);
    }else{
        printf("You do not have enough credits to buy more ammo.\n");
    }
}

void hack(){
    int success = rand() % 2;
    if(success){
        printf("Hack successful! You gained 50 credits.\n");
        credits += 50;
    }else{
        printf("Hack failed! You were attacked by a virus!\n");
        enemy_attack(&health);
    }
}

int main(){
    srand(time(NULL));
    
    printf("Welcome to Cyberspace!\n");
    printf("You are a hacker trying to steal credits.\n");
    printf("You have 100 health, 100 ammo, and 100 credits.\n");
    printf("You encounter an enemy! What do you do?\n");
    
    while(health > 0){
        char input[10];
        printf("> ");
        scanf("%s", input);
        
        if(strcmp(input, "shoot") == 0){
            if(ammo > 0){
                int hit_chance = rand() % 2;
                if(hit_chance){
                    int damage = rand() % 21 + 10;
                    printf("You hit the enemy for %d damage!\n", damage);
                }else{
                    printf("You missed!\n");
                }
                ammo--;
                enemy_attack(&health);
            }else{
                printf("You do not have any ammo!\n");
            }
        }else if(strcmp(input, "buy") == 0){
            buy_ammo();
        }else if(strcmp(input, "hack") == 0){
            hack();
        }else if(strcmp(input, "status") == 0){
            printf("Health: %d\n", health);
            printf("Ammo: %d\n", ammo);
            printf("Credits: %d\n", credits);
        }else{
            printf("Invalid input!\n");
        }
        
        if(rand() % 2){
            printf("The enemy attacked!\n");
            enemy_attack(&health);
        }
    }
    
    printf("Game over!\n");
    printf("You managed to steal %d credits before dying.\n", credits);
    
    return 0;
}