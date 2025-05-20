//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Knight {
    char name[50];
    int valor; // Valor of the knight
    int strength; // Strength level of the knight
} Knight;

typedef struct Battle {
    Knight *knights;
    int count;
} Battle;

void summon_knights(Battle *battle, int number) {
    battle->knights = (Knight *)malloc(sizeof(Knight) * number);
    battle->count = number;

    for (int i = 0; i < number; i++) {
        printf("Enter the name of Knight %d: ", i + 1);
        scanf("%s", battle->knights[i].name);
        printf("Enter valor for Knight %s: ", battle->knights[i].name);
        scanf("%d", &battle->knights[i].valor);
        printf("Enter strength for Knight %s: ", battle->knights[i].name);
        scanf("%d", &battle->knights[i].strength);
    }
}

void commence_battle(Battle *battle) {
    printf("\nThe battle of the valiant knights hath begun!\n");
    for (int i = 0; i < battle->count; i++) {
        printf("Knight %s rides into battle with valor %d and strength %d!\n", 
               battle->knights[i].name, 
               battle->knights[i].valor, 
               battle->knights[i].strength);
    }
}

void victorious_knight(Battle *battle) {
    int max_strength = 0;
    Knight *winner = NULL;

    for (int i = 0; i < battle->count; i++) {
        if (battle->knights[i].strength > max_strength) {
            max_strength = battle->knights[i].strength;
            winner = &battle->knights[i];
        }
    }

    if (winner != NULL) {
        printf("\nThe victor of the battle is Knight %s with valor %d and strength %d!\n",
               winner->name,
               winner->valor,
               winner->strength);
    }
}

void release_knights(Battle *battle) {
    free(battle->knights);
    battle->knights = NULL;
    battle->count = 0;
}

int main() {
    fprintf(stdout, "Hark! A program to summon valiant knights for battle!\n");
    int num_knights;

    printf("How many noble knights dost thou wish to summon? ");
    scanf("%d", &num_knights);

    Battle medieval_battle;
    summon_knights(&medieval_battle, num_knights);
    commence_battle(&medieval_battle);
    victorious_knight(&medieval_battle);
    release_knights(&medieval_battle);

    fprintf(stdout, "Thus endeth the program of knightly valor! Fare thee well!\n");
    return 0;
}