//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void summonKnight(int knight_count, int knight_strength[]);
void calculateBattlePower(int knight_count, int knight_strength[]);
void distributeTreasures(int treasure_count, int knights, int treasures[]);

int main() {
    int knights = 5; // Number of gallant knights
    int knight_strength[5];
    int treasures[5] = {100, 200, 300, 400, 500}; // Treasures to be distributed

    printf("Pray, noble squire! As the dawn breaks over the kingdom,\n");
    printf("It is time to summon our brave knights!\n");

    summonKnight(knights, knight_strength);
    calculateBattlePower(knights, knight_strength);
    distributeTreasures(5, knights, treasures);

    return 0;
}

// This noble function summons the knights and assigns them strength
void summonKnight(int knight_count, int knight_strength[]) {
    for (int i = 0; i < knight_count; i++) {
        printf("Summoning Knight %d!\n", i + 1);
        printf("Bestow upon him a strength of valor (1-100): ");
        scanf("%d", &knight_strength[i]);

        // Validating the knight's strength
        if (knight_strength[i] < 1 || knight_strength[i] > 100) {
            printf("Alas! The strength must be between 1 and 100!\n");
            printf("Bestow a new strength upon Knight %d: ", i + 1);
            scanf("%d", &knight_strength[i]);
        }
    }
}

// This stately function calculates the battle power of knights
void calculateBattlePower(int knight_count, int knight_strength[]) {
    int total_power = 0;

    printf("\nVerily, let us compute the collective battle power of our knights!\n");
    for (int i = 0; i < knight_count; i++) {
        total_power += knight_strength[i];
        printf("Knight %d contributes a valiant strength of %d\n", i + 1, knight_strength[i]);
    }
    
    printf("Total battle power of the knights is: %d\n", total_power);
}

// This august function distributes treasures amongst the knights
void distributeTreasures(int treasure_count, int knights, int treasures[]) {
    printf("\nHark! Let us now distribute the bountiful treasures to our gallant knights!\n");
    
    for (int i = 0; i < knights; i++) {
        if (i < treasure_count) {
            printf("Knight %d receives a treasure of %d gold coins!\n", i + 1, treasures[i]);
        } else {
            printf("Knight %d receives no treasures, but his valor is immeasurable!\n", i + 1);
        }
    }

    printf("\nAll knights have been bestowed their treasures as per the decree of the crown!\n");
}