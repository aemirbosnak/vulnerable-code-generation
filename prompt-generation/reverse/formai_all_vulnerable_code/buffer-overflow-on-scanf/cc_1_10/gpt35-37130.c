//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Defining Player and Enemy Structure
struct character{
    char name[20];
    int health;
    int attack;
    int defence;
} player, enemy;

//Function Declarations
void setupGame();
void battle();
void gameOver();

int main(){
    //Starting the Game
    printf("Welcome to the Text-Based Adventure Game!\n");
    setupGame();

    //Beginning of the Game
    printf("You are lost in the woods and have to find your way out.\n");
    printf("You are attacked by a wild animal!\n");
    battle();
}

void setupGame(){
    //Player Setup
    printf("Enter your name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.attack = 10;
    player.defence = 5;

    //Enemy Setup
    strcpy(enemy.name, "Wild Animal");
    enemy.health = 50;
    enemy.attack = 15;
    enemy.defence = 3;
}

void battle(){
    //Battle Loop
    int damage;
    while(player.health > 0 && enemy.health > 0){
        printf("\n%s Health: %d\n", player.name, player.health);
        printf("%s Health: %d\n\n", enemy.name, enemy.health);

        //Player Attack
        printf("It's your turn! Enter attack(1) or defend(2): ");
        int choice;
        scanf("%d", &choice);
        if(choice == 1){
            printf("\nYou attack %s!\n", enemy.name);
            damage = player.attack - enemy.defence;
            if(damage < 0) 
                damage = 0;
            printf("You deal %d damage!\n", damage);
            enemy.health -= damage;
        }
        else if(choice == 2){
            printf("\nYou defend yourself!\n");
            player.defence += 5;
        }

        //Enemy Attack
        if(enemy.health > 0){
            printf("\n%s attacks you!\n", enemy.name);
            damage = enemy.attack - player.defence;
            if(damage < 0) 
                damage = 0;
            printf("%s deals %d damage!\n", enemy.name, damage);
            player.health -= damage;
        }
    }
    //Game Over
    gameOver();
}

void gameOver(){
    if(player.health <= 0){
        printf("\nGame Over!\n");
        printf("You were defeated by %s.\n", enemy.name);
    }
    else if(enemy.health <= 0){
        printf("\nCongratulations! You Won!\n");
        printf("You have successfully escaped the woods.\n");
    }
}