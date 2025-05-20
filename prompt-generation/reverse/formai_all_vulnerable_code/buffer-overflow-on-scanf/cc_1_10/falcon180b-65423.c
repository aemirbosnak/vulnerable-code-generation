//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INVADERS 1000
#define MAX_DEFENDERS 1000
#define MAX_ROUNDS 100

typedef struct {
    int health;
    int attack;
    int defense;
} Invader;

typedef struct {
    int health;
    int attack;
    int defense;
} Defender;

void generateInvaders(Invader invaders[], int numInvaders) {
    for (int i = 0; i < numInvaders; i++) {
        invaders[i].health = (rand() % 100) + 1;
        invaders[i].attack = (rand() % 100) + 1;
        invaders[i].defense = (rand() % 100) + 1;
    }
}

void generateDefenders(Defender defenders[], int numDefenders) {
    for (int i = 0; i < numDefenders; i++) {
        defenders[i].health = (rand() % 100) + 1;
        defenders[i].attack = (rand() % 100) + 1;
        defenders[i].defense = (rand() % 100) + 1;
    }
}

int battle(Invader invader, Defender defender) {
    int attack = invader.attack - defender.defense;
    if (attack > 0) {
        defender.health -= attack;
    } else {
        attack = 0;
    }
    int defense = defender.defense - invader.attack;
    if (defense > 0) {
        invader.health -= defense;
    } else {
        defense = 0;
    }
    return attack + defense;
}

int main() {
    srand(time(NULL));

    int numInvaders, numDefenders;
    printf("Enter the number of invaders: ");
    scanf("%d", &numInvaders);
    Invader invaders[MAX_INVADERS];
    generateInvaders(invaders, numInvaders);

    printf("Enter the number of defenders: ");
    scanf("%d", &numDefenders);
    Defender defenders[MAX_DEFENDERS];
    generateDefenders(defenders, numDefenders);

    int maxRounds = 0;
    for (int i = 0; i < numDefenders; i++) {
        int health = defenders[i].health;
        for (int j = 0; j < numInvaders; j++) {
            if (health <= 0) {
                break;
            }
            Invader invader = invaders[j];
            int result = battle(invader, defenders[i]);
            health -= result;
            if (health <= 0) {
                maxRounds = i + 1;
                break;
            }
        }
    }

    printf("The maximum number of rounds is %d.\n", maxRounds);

    return 0;
}