//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEALTH 100 // maximum health points

typedef struct {
    char name[20];
    int health;
    int strength;
    int defense;
} knight;

int main() {
    int num_knights, i, j, round = 1;

    printf("How many knights will fight in the tournament? (1-8): ");
    scanf("%d", &num_knights);

    knight knights[num_knights]; // initialize array of knights

    // set knight properties randomly
    srand(time(NULL));
    for (i = 0; i < num_knights; i++) {
        printf("\nEnter knight %d's name: ", i + 1);
        scanf("%s", knights[i].name);

        knights[i].health = HEALTH;
        knights[i].strength = rand() % 10 + 1;
        knights[i].defense = rand() % 10 + 1;
    }

    while (num_knights > 1) { // fight until one knight remains
        printf("\n\n--- ROUND %d ---\n\n", round);

        for (i = 0; i < num_knights; i++) { // each knight attacks
            printf("\n%s attacks!\n", knights[i].name);

            int damage_dealt = knights[i].strength - knights[(i+1)%num_knights].defense;
            if (damage_dealt < 0) damage_dealt = 0;

            knights[(i+1)%num_knights].health -= damage_dealt;

            printf("%s dealt %d damage to %s, leaving them with %d health points.\n\n", knights[i].name, damage_dealt, knights[(i+1)%num_knights].name, knights[(i+1)%num_knights].health);

            if (knights[(i+1)%num_knights].health <= 0) { // defeat
                printf("%s has been defeated!\n", knights[(i+1)%num_knights].name);

                for (j = (i+1)%num_knights; j < num_knights-1; j++) { // remove defeated knight from array
                    knights[j] = knights[j+1];
                }

                num_knights--;
            }

            if (num_knights == 1) break;
        }

        round++;
    }

    printf("\n\n%s is the champion of the tournament!\n\n", knights[0].name);

    return 0;
}