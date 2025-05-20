//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_ITEMS 3
#define MAX_MONSTERS 2

typedef struct {
    char *name;
    int health;
} Monster;

typedef struct {
    char *name;
    int health;
} Player;

typedef struct {
    char *description;
    int has_item;
    int monster_present;
} Room;

void init_rooms(Room rooms[]) {
    rooms[0] = (Room){"You are in a dark dungeon room. There's a flickering light.", 0, 0};
    rooms[1] = (Room){"You find yourself in a room with ancient walls. A treasure chest is here.", 1, 1};
    rooms[2] = (Room){"This room is empty but you feel a chill in the air. A ghost lurks.", 0, 1};
    rooms[3] = (Room){"You enter a room filled with eerie sounds. It's quite ominous.", 0, 0};
    rooms[4] = (Room){"You've reached the treasure room! You can taste the victory!", 0, 0};
}

void print_room_info(Room room) {
    printf("%s\n", room.description);
    if (room.has_item) {
        printf("You see a shiny item!\n");
    }
    if (room.monster_present) {
        printf("Be careful! A monster is lurking here!\n");
    }
}

int main() {
    srand(time(NULL));

    Player player = {"Hero", 100};
    Monster monsters[MAX_MONSTERS] = {
        {"Goblin", 30},
        {"Skeleton", 40}
    };

    Room rooms[MAX_ROOMS];
    init_rooms(rooms);

    int current_room = 0;
    char action[20];

    printf("Welcome to the Mystery Dungeon!\n");
    printf("Your goal is to find the treasure while avoiding monsters and collecting items.\n");

    while (1) {
        print_room_info(rooms[current_room]);

        if (rooms[current_room].monster_present) {
            printf("A monster appears! You must fight!\n");
            int monster_index = rand() % MAX_MONSTERS;
            Monster current_monster = monsters[monster_index];

            while (current_monster.health > 0 && player.health > 0) {
                printf("You attack the %s!\n", current_monster.name);
                current_monster.health -= rand() % 20;

                if (current_monster.health <= 0) {
                    printf("You defeated the %s!\n", current_monster.name);
                } else {
                    player.health -= rand() % 15;
                    printf("The %s strikes back! You have %d health left.\n", current_monster.name, player.health);
                }
            }
            if (player.health <= 0) {
                printf("You have been defeated! Game Over.\n");
                break;
            }
        }

        if (rooms[current_room].has_item) {
            printf("You found an item! You can collect it (y/n)? ");
            scanf("%s", action);
            if (action[0] == 'y') {
                printf("Item collected!\n");
                rooms[current_room].has_item = 0;
            }
        }

        printf("Where do you want to go? (0-%d): ", MAX_ROOMS - 1);
        scanf("%d", &current_room);
        if (current_room < 0 || current_room >= MAX_ROOMS) {
            printf("Invalid room! Try again.\n");
            current_room = 0; // Reset to starting room
        }

        if (current_room == 4) {
            printf("Congratulations! You've found the treasure! You win!\n");
            break;
        }
    }

    return 0;
}