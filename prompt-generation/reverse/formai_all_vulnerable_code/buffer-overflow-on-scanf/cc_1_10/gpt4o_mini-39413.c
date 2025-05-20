//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 5
#define MAX_TREASURE 3
#define MAX_MONSTERS 3

typedef struct {
    int id;
    int treasure;
    int monster_present;
} Room;

typedef struct {
    int health;
    int treasure_collected;
} Player;

void initialize_rooms(Room rooms[]) {
    for (int i = 0; i < MAX_ROOM; i++) {
        rooms[i].id = i + 1;
        rooms[i].treasure = rand() % (MAX_TREASURE + 1);
        rooms[i].monster_present = rand() % 2;
    }
}

void display_room_info(Room current_room) {
    printf("You are in Room %d.\n", current_room.id);
    if (current_room.monster_present) {
        printf("A monster is lurking here!\n");
    } else {
        printf("This room is safe.\n");
    }
    printf("You can see %d treasures here.\n", current_room.treasure);
}

void fight_monster(Player *player) {
    printf("You have encountered a monster!\n");
    player->health -= 10;
    printf("You fought bravely but lost some health. Current health: %d\n", player->health);
}

void collect_treasure(Player *player, Room *current_room) {
    player->treasure_collected += current_room->treasure;
    printf("You collected %d treasures!\n", current_room->treasure);
    current_room->treasure = 0; // All treasures collected
}

int main() {
    srand(time(NULL));
    Room rooms[MAX_ROOM];
    Player player = {100, 0};
    int current_room_index = 0;
    char command[10];

    initialize_rooms(rooms);

    printf("Welcome to the Dungeon Adventure Game!\n");
    printf("Your goal is to collect treasures and escape the dungeon.\n");
    
    while (player.health > 0 && current_room_index < MAX_ROOM) {
        display_room_info(rooms[current_room_index]);
        
        printf("Enter a command (explore, collect, fight, exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "explore") == 0) {
            if (rooms[current_room_index].monster_present) {
                fight_monster(&player);
            } else {
                printf("The room is safe to explore.\n");
            }
            current_room_index++;
            if (current_room_index >= MAX_ROOM) {
                printf("You have explored all available rooms!\n");
                break;
            }
        } else if (strcmp(command, "collect") == 0) {
            if (rooms[current_room_index].treasure > 0) {
                collect_treasure(&player, &rooms[current_room_index]);
            } else {
                printf("There's no treasure left in this room to collect.\n");
            }
        } else if (strcmp(command, "fight") == 0) {
            if (rooms[current_room_index].monster_present) {
                fight_monster(&player);
            } else {
                printf("There's no monster here to fight.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the game. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }

        if (player.health <= 0) {
            printf("You have been defeated! Game over.\n");
        }
    }

    if (player.health > 0) {
        printf("Congratulations! You collected %d treasures and escaped the dungeon safely!\n", player.treasure_collected);
    }

    return 0;
}