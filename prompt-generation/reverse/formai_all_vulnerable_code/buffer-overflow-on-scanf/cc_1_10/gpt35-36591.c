//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int health;
    int attack_points;
    int defense_points;
} character;

int main() {
    srand(time(NULL)); //Seed the random number generator
    
    printf("Welcome to the medieval space journey game!\n");
    
    //Create our player character
    character player;
    printf("\nPlease enter your character's name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.attack_points = 10;
    player.defense_points = 5;
    
    //Create our enemy character
    character enemy;
    enemy.health = rand() % 50 + 50; //Enemy health will be between 50 and 99
    enemy.attack_points = rand() % 5 + 10; //Enemy attack points will be between 10 and 14
    enemy.defense_points = rand() % 5 + 5; //Enemy defense points will be between 5 and 9
    
    printf("\nYou encounter a fearsome dragon in space!\n");
    printf("The dragon has %d health, %d attack points, and %d defense points.\n", enemy.health, enemy.attack_points, enemy.defense_points);
    
    //Battle sequence
    int turn = 1;
    while(player.health > 0 && enemy.health > 0) {
        printf("\nTurn %d\n", turn);
        
        //Player attack
        int player_damage = player.attack_points - enemy.defense_points;
        if(player_damage < 0) player_damage = 0; //Ensure damage is positive
        enemy.health -= player_damage;
        if(enemy.health <= 0) break; //Enemy has been defeated, end battle
        printf("You deal %d damage to the dragon!\n", player_damage);
        
        //Enemy attack
        int enemy_damage = enemy.attack_points - player.defense_points;
        if(enemy_damage < 0) enemy_damage = 0; //Ensure damage is positive
        player.health -= enemy_damage;
        if(player.health <= 0) break; //Player has been defeated, end battle
        printf("The dragon deals %d damage to you!\n", enemy_damage);
        
        turn++;
    }
    
    //Battle has ended
    if(player.health > 0) {
        printf("\nCongratulations! You have defeated the dragon and completed your space journey!\n");
    }
    else {
        printf("\nGame over. The dragon has defeated you.\n");
    }
    
    return 0;
}