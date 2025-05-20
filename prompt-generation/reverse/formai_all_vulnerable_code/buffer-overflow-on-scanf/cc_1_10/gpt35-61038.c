//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// define player data structure
typedef struct player{
    char name[20];
    int health;
    int strength;
}Player;

void updateHealth(Player* p, int damage){
    p->health -= damage;
    if(p->health < 0){
        p->health = 0;
    }
}

void displayPlayer(Player p){
    printf("Player Name: %s\n", p.name);
    printf("Player Health: %d\n", p.health);
    printf("Player Strength: %d\n", p.strength);
}

int main(){
    srand(time(NULL));

    // initialize player array
    Player players[10];

    // prompt each player for name and starting health
    for(int i=0; i<10; i++){
        printf("Enter name for Player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].health = rand() % 101 + 100;
        players[i].strength = rand() % 11 + 10;
    }

    // display all players
    printf("\n--- All Players ---\n");
    for(int i=0; i<10; i++){
        displayPlayer(players[i]);
    }

    // randomly select players for battle
    int player1, player2;
    while(1){
        player1 = rand() % 10;
        player2 = rand() % 10;
        if(player1 != player2){
            break;
        }
    }

    printf("\n--- Battle ---\n");
    printf("Player 1: %s\n", players[player1].name);
    printf("Player 2: %s\n", players[player2].name);

    // simulate battle
    while(players[player1].health > 0 && players[player2].health > 0){
        // player 1 attacks player 2
        int damage = players[player1].strength + rand() % 11 - 5;
        printf("%s attacks %s for %d damage\n", players[player1].name, players[player2].name, damage);
        updateHealth(&players[player2], damage);
        printf("%s's health is now %d\n", players[player2].name, players[player2].health);
        if(players[player2].health <= 0){
            break;
        }

        // player 2 attacks player 1
        damage = players[player2].strength + rand() % 11 - 5;
        printf("%s attacks %s for %d damage\n", players[player2].name, players[player1].name, damage);
        updateHealth(&players[player1], damage);
        printf("%s's health is now %d\n", players[player1].name, players[player1].health);
    }

    // display winner
    if(players[player1].health > 0){
        printf("\n%s wins!\n", players[player1].name);
    }
    else{
        printf("\n%s wins!\n", players[player2].name);
    }

    return 0;
}