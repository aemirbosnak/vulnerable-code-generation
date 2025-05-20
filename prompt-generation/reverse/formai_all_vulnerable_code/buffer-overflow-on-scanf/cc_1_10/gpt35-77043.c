//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int health = 100;
int ammo = 20;
int enemies = 5;
int weapon = 1;

void fight() { 
    printf("You have encountered %d enemies\n", enemies);
    while (enemies > 0 && health > 0 && ammo > 0) {
        int damage = (rand() % 10) + weapon * 5;
        health -= damage;
        ammo--;
        printf("You dealt %d damage to an enemy. Your health is now %d and you have %d ammo left\n", damage, health, ammo);
        enemies--;
        if (enemies > 0) {
            damage = rand() % 10 + 2;
            health -= damage;
            printf("An enemy dealt %d damage to you. Your health is now %d\n", damage, health);
        }
    }
    if (health <= 0)
        printf("You died. Game over\n");
    else if (enemies <= 0)
        printf("Congratulations! You have won the battle!\n");
    else
        printf("You ran out of ammo and enemies are still alive. Game over.\n");
}

void explore() {
    int found = rand() % 3;
    if (found == 0) {
        printf("You found a health pack!\n");
        health += 10;
        if (health > 100) health = 100;
    }
    else if (found == 1) {
        printf("You found some ammo!\n");
        ammo += 10;
        if (ammo > 20) ammo = 20;
    } else {
        printf("You found a new weapon!\n");
        weapon++;
    }
}

void status() {
    printf("Your health is %d\n", health);
    printf("Your ammo is %d\n", ammo);
    printf("Your weapon level is %d\n", weapon);
    printf("There are %d enemies left\n", enemies);
}

int main() {
    printf("Welcome to the Adventure Game!\n");
    printf("You are now exploring the jungle. Your task is to defeat all enemies.\n");
    printf("Type 'fight' to engage in battle\n");
    printf("Type 'explore' to look for items\n");
    printf("Type 'status' to check your status\n");
    printf("Type 'quit' to exit the game\n");
    while (1) {
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "fight") == 0) {
            fight();
            if (health <= 0) break;
        }
        else if (strcmp(input, "explore") == 0)
            explore();
        else if (strcmp(input, "status") == 0)
            status();
        else if (strcmp(input, "quit") == 0)
            break;
        else
            printf("Invalid command. Please try again\n");
    }
    printf("Thanks for playing!\n");
    return 0;
}