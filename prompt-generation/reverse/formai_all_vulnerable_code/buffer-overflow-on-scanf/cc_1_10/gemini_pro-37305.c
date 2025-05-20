//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
// The desolate wastelands echo with the remnants of a once-vibrant civilization, where mathematics now serves as a lifeline for the survivors.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Provisions for our weary souls
int rations;
int water;
int first_aid;

// The unforgiving terrain
int wasteland[10][10];

// Coordinates of our abode
int bunker_x;
int bunker_y;

// The dreaded raiders
int raiders[5];

void generate_wasteland() {
    // Seeds the wasteland with chaos
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            wasteland[i][j] = rand() % 10;
        }
    }
}

void generate_bunker() {
    // Establishes our sanctuary amidst the desolation
    bunker_x = rand() % 10;
    bunker_y = rand() % 10;
}

void generate_raiders() {
    // Roving scavengers seeking our meager supplies
    for (int i = 0; i < 5; i++) {
        raiders[i] = rand() % 100;
    }
}

void update_resources() {
    // Calculating our dwindling supplies
    rations -= 1;
    water -= 2;
    first_aid -= 1;
}

void move_raiders() {
    // The relentless raiders stalk us
    for (int i = 0; i < 5; i++) {
        int dx = bunker_x - raiders[i] % 10;
        int dy = bunker_y - raiders[i] / 10;
        raiders[i] += (dx + dy) * 10;
    }
}

int main() {
    generate_wasteland();
    generate_bunker();
    generate_raiders();

    int days_survived = 0;
    int game_over = 0;

    while (!game_over) {
        // Each sunrise brings new challenges
        update_resources();
        move_raiders();

        // Inventory check
        printf("Rations: %d, Water: %d, First Aid: %d\n", rations, water, first_aid);

        // The cruel hand of fate
        if (rations <= 0) {
            printf("Starvation consumes you.\n");
            game_over = 1;
        } else if (water <= 0) {
            printf("Dehydration claims your life.\n");
            game_over = 1;
        } else if (first_aid <= 0) {
            printf("Untreated wounds seal your fate.\n");
            game_over = 1;
        }

        // Encounter with raiders
        for (int i = 0; i < 5; i++) {
            if (raiders[i] == bunker_x + bunker_y * 10) {
                printf("Raiders attack! Repel them with your might!\n");
                int choice = 0;
                while (choice != 1 && choice != 2) {
                    printf("1. Fight (Lose 1 first aid)\n2. Negotiate (Lose 10 rations, 5 water, 1 first aid)\n");
                    scanf("%d", &choice);
                }
                if (choice == 1) {
                    first_aid--;
                } else {
                    rations -= 10;
                    water -= 5;
                    first_aid--;
                }
            }
        }

        // The wasteland's unforgiving embrace
        int current_zone = wasteland[bunker_x][bunker_y];
        rations -= current_zone;
        water -= current_zone;
        first_aid -= current_zone;

        if (current_zone == 9) {
            printf("You stumble upon a rare oasis! Resupply your provisions.\n");
            rations += 10;
            water += 10;
            first_aid += 5;
        }

        days_survived++;
    }

    printf("You survived %d days in the bleak wasteland.\n", days_survived);

    return 0;
}