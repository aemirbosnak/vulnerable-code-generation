//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAP_SIZE 5
#define MAX_ITEMS 5

typedef struct {
    char name[20];
    int strength;
} Item;

typedef struct {
    int x;
    int y;
} Position;

char *map[MAP_SIZE][MAP_SIZE] = {
    {"[H]", "[C]", "[E]", "[S]", "[D]"},
    {"[D]", "[C]", "[H]", "[N]", "[A]"},
    {"[C]", "[S]", "[R]", "[C]", "[P]"},
    {"[A]", "[E]", "[H]", "[C]", "[V]"},
    {"[R]", "[H]", "[N]", "[A]", "[M]"}
};

Item items[MAX_ITEMS] = {
    {"Smoke Bomb", 2},
    {"Hacker Device", 5},
    {"Neural Enhancer", 3},
    {"Stealth Cloak", 4},
    {"Cyber Sword", 7}
};

Position playerPosition = {0, 0};
int playerStrength = 0;

void welcome() {
    printf("Welcome to Cyberpunk City! Navigate through the city\n");
    printf("to find the Hacker Device and avoid corporate security.\n\n");
}

void displayMap() {
    printf("Current Map Location:\n");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == playerPosition.x && j == playerPosition.y) {
                printf("[P] ");
            } else {
                printf("%s ", map[i][j]);
            }
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    switch (direction) {
        case 'w':
            if (playerPosition.x > 0) playerPosition.x--;
            break;
        case 's':
            if (playerPosition.x < MAP_SIZE - 1) playerPosition.x++;
            break;
        case 'a':
            if (playerPosition.y > 0) playerPosition.y--;
            break;
        case 'd':
            if (playerPosition.y < MAP_SIZE - 1) playerPosition.y++;
            break;
        default:
            printf("Invalid move. Use 'w', 'a', 's', 'd' to move.\n");
            break;
    }
}

void searchItem() {
    if (rand() % 10 < 5) { // 50% chance to find an item
        int itemIndex = rand() % MAX_ITEMS;
        playerStrength += items[itemIndex].strength;
        printf("You found a %s! Strength increased by %d.\n", items[itemIndex].name, items[itemIndex].strength);
    } else {
        printf("Nothing was found. Keep searching!\n");
    }
}

void corporateEncounter() {
    printf("You've encountered corporate security!\n");
    printf("Current Strength: %d\n", playerStrength);
    if (playerStrength >= 3) {
        printf("You use your skills to evade them! You escape unharmed.\n");
    } else {
        printf("You were caught! Game over.\n");
        exit(0);
    }
}

int main() {
    srand(time(NULL));
    welcome();
    char command[10];

    while (1) {
        displayMap();
        printf("Enter your command (move/search/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            printf("Thanks for playing! Exiting game.\n");
            break;
        } else if (strcmp(command, "search") == 0) {
            searchItem();
        } else if (strcmp(command, "move") == 0) {
            char direction;
            printf("Enter direction (w/a/s/d): ");
            scanf(" %c", &direction);
            movePlayer(direction);
            if (rand() % 10 < 4) { // 40% chance to encounter corporate
                corporateEncounter();
            }
        } else {
            printf("Unknown command. Try again.\n");
        }
        printf("\n");
        sleep(1); // Adding delay for better game flow
    }
    return 0;
}