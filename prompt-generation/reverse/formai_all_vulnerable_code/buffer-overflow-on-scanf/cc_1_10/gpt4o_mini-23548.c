//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ROOMS 5
#define MAX_ITEM_NAME_LENGTH 20

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int value;
} Item;

typedef struct {
    char description[100];
    Item *item;
    int monster_present;
} Room;

typedef struct {
    char name[20];
    int health;
    int score;
} Player;

Room rooms[NUM_ROOMS];
Player player;

void initializeRooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        snprintf(rooms[i].description, sizeof(rooms[i].description), "You are in room %d.", i + 1);
        rooms[i].item = NULL;
        rooms[i].monster_present = rand() % 2; // Randomly place a monster in room
    }
    
    // Assign items
    rooms[1].item = malloc(sizeof(Item));
    strcpy(rooms[1].item->name, "Gold Coin");
    rooms[1].item->value = 10;

    rooms[3].item = malloc(sizeof(Item));
    strcpy(rooms[3].item->name, "Silver Shield");
    rooms[3].item->value = 20;
}

void freeRooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (rooms[i].item != NULL) {
            free(rooms[i].item);
        }
    }
}

void printGameIntro() {
    printf("Welcome to the Dungeon Adventure!\n");
    printf("Explore, collect treasures, and defeat monsters!\n");
    printf("Your objective is to survive and achieve the highest score.\n\n");
}

void printPlayerStatus() {
    printf("Player Status:\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Score: %d\n", player.score);
    printf("------------------------------\n");
}

void treasureFound(Item *item) {
    printf("You found a %s worth %d points!\n", item->name, item->value);
    player.score += item->value;
}

void encounterMonster() {
    printf("A monster appears!\n");
    int damage = rand() % 10 + 1; // Random damage between 1 to 10
    printf("You take %d damage!\n", damage);
    player.health -= damage;

    if (player.health <= 0) {
        printf("You have been defeated by the monster... Game Over!\n");
        exit(0);
    } else {
        printf("You defeated the monster!\n");
    }
}

void gameLoop() {
    char command[20];
    int current_room = 0;

    while (1) {
        printf("\n%s\n", rooms[current_room].description);
        printPlayerStatus();

        if (rooms[current_room].monster_present) {
            encounterMonster();
        }

        if (rooms[current_room].item != NULL) {
            treasureFound(rooms[current_room].item);
            rooms[current_room].item = NULL; // Item is collected
        }

        printf("What do you want to do? (move [1-5] / exit): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Thanks for playing! Your final score is %d.\n", player.score);
            break;
        } else if (strcmp(command, "move") == 0) {
            int room_num;
            scanf("%d", &room_num);
            if (room_num >= 1 && room_num <= NUM_ROOMS) {
                current_room = room_num - 1; // Adjusting for zero index
            } else {
                printf("Invalid room number. Please try again.\n");
            }
        } else {
            printf("Invalid command. Please use 'move [1-5]' or 'exit'.\n");
        }
    }
}

int main() {
    srand(time(0));

    printf("Enter your player's name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.score = 0;

    printGameIntro();
    initializeRooms();
    gameLoop();
    freeRooms();
    
    return 0;
}