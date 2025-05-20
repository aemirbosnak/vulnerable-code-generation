//GEMINI-pro DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Get ready for an epic journey of battles and plunder!
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define NUM_PLAYERS 5

// Define the brave heroes and their stats
typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Player;

// Initialize the game map with lush forests and treacherous mountains
char game_map[MAP_HEIGHT][MAP_WIDTH] = {
    {'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F'},
    {'F', 'F', 'F', 'F', 'M', 'M', 'F', 'F', 'F', 'F'},
    {'F', 'F', 'F', 'F', 'M', 'M', 'F', 'F', 'F', 'F'},
    {'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F'},
    {'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F'},
    {'F', 'F', 'F', 'F', 'M', 'M', 'F', 'F', 'F', 'F'},
    {'F', 'F', 'F', 'F', 'M', 'M', 'F', 'F', 'F', 'F'},
    {'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F'},
    {'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F'},
    {'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F'},
};

// Array of valiant warriors, ready to conquer the realm
Player players[NUM_PLAYERS] = {
    {"Sir Percival", 100, 20, 15},
    {"Lady Guinevere", 120, 18, 16},
    {"King Arthur", 150, 22, 18},
    {"Merlin", 100, 16, 14},
    {"Morgana le Fay", 110, 19, 15},
};

// Welcome to the realm of adventure, brave adventurer!
int main() {
    srand(time(NULL));  // Prepare for unpredictable encounters and epic battles!

    printf("\nWelcome to the wondrous realm of Valor, where legends are forged!\n");

    // Let the players choose their valiant heroes to embark on this grand quest
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("\nChoose your champion, valiant adventurer:\n");
        for (int j = 0; j < NUM_PLAYERS; j++) {
            printf("%d. %s\n", j + 1, players[j].name);
        }
        int choice;
        printf("Enter your choice (1-%d): ", NUM_PLAYERS);
        scanf("%d", &choice);
        printf("\nYou have chosen the mighty %s!\n", players[choice - 1].name);
    }

    // The thrilling journey begins!
    printf("\nYour heroes embark on an epic quest, traversing the treacherous map.\n");
    int current_player = 0;  // The first brave soul leads the charge!

    while (current_player < NUM_PLAYERS) {  // Until all heroes have fallen or triumphed
        Player* player = &players[current_player];  // Current player steps into the spotlight

        int x = rand() % MAP_WIDTH;  // Destiny awaits in uncharted lands
        int y = rand() % MAP_HEIGHT;

        // Fate unfolds as the player encounters the map's challenges
        switch (game_map[y][x]) {
            case 'F':  // Serene forests offer respite and renewal
                printf("\n%s strolls through a tranquil forest, restoring their weary body and spirit.\n", player->name);
                player->health += 10;
                break;
            case 'M':  // Treacherous mountains test the limits of bravery and skill
                printf("\n%s ascends a towering mountain, their resolve unwavering.\n", player->name);
                int damage = rand() % 10;  // Perilous terrain exacts its toll
                player->health -= damage;
                printf("%s takes %d damage from treacherous slopes.\n", player->name, damage);
                break;
        }

        // The player's health dwindles, but their spirit remains unyielding
        if (player->health <= 0) {
            printf("\nTragedy strikes! %s falls in battle, their valiant journey cut short.\n", player->name);
        } else {
            printf("\n%s stands victorious, their health at %d.\n", player->name, player->health);
        }

        current_player++;  // The next hero takes up the mantle of adventure
    }

    // The epic saga concludes, leaving an indelible mark on the realm of Valor
    printf("\nThe realm of Valor echoes with tales of your heroes' triumphs and sacrifices.\n");
    printf("May their legacy inspire generations to come!\n");

    return 0;
}