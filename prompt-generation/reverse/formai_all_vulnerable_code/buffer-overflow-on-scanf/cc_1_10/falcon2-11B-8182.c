//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_NUM 10

// Structure to represent rooms
typedef struct {
    char name[20];
    char description[200];
    char next_room[20];
} Room;

// Structure to represent player
typedef struct {
    char name[20];
    int health;
    char inventory[100];
    int room_number;
} Player;

Room rooms[ROOM_NUM];
Player player;

void print_room_description(Room room) {
    printf("You are in the %s\n", room.name);
    printf("%s\n", room.description);
}

void print_player_status() {
    printf("Your health is %d.\n", player.health);
    printf("Your inventory contains:\n");
    for (int i = 0; i < strlen(player.inventory); i++) {
        printf("%s ", player.inventory + i);
    }
    printf("\n");
}

void move_to_next_room(Room* next_room) {
    printf("You move to the next room.\n");
    printf("You are in the %s\n", next_room->name);
    printf("%s\n", next_room->description);
}

void process_input(char* input) {
    if (strcmp(input, "north") == 0) {
        if (strcmp(rooms[player.room_number].next_room, "south")!= 0) {
            player.room_number = atoi(rooms[player.room_number].next_room);
            print_room_description(rooms[player.room_number]);
        } else {
            printf("You can't go north from here.\n");
        }
    } else if (strcmp(input, "south") == 0) {
        if (strcmp(rooms[player.room_number].next_room, "north")!= 0) {
            player.room_number = atoi(rooms[player.room_number].next_room);
            print_room_description(rooms[player.room_number]);
        } else {
            printf("You can't go south from here.\n");
        }
    } else if (strcmp(input, "east") == 0) {
        if (strcmp(rooms[player.room_number].next_room, "west")!= 0) {
            player.room_number = atoi(rooms[player.room_number].next_room);
            print_room_description(rooms[player.room_number]);
        } else {
            printf("You can't go east from here.\n");
        }
    } else if (strcmp(input, "west") == 0) {
        if (strcmp(rooms[player.room_number].next_room, "east")!= 0) {
            player.room_number = atoi(rooms[player.room_number].next_room);
            print_room_description(rooms[player.room_number]);
        } else {
            printf("You can't go west from here.\n");
        }
    } else if (strcmp(input, "take") == 0) {
        char item[100];
        printf("What would you like to take?\n");
        scanf("%s", item);
        strcpy(player.inventory, item);
        printf("You took %s.\n", item);
    } else {
        printf("I don't understand that command.\n");
    }
}

void main() {
    printf("Welcome to the Adventure Game!\n");
    printf("You are in the starting room.\n");
    print_room_description(rooms[0]);
    printf("You have %s in your inventory.\n", player.inventory);
    print_player_status();

    while (1) {
        char input[100];
        printf("What would you like to do? (north, south, east, west, take)\n");
        scanf("%s", input);
        process_input(input);

        if (strcmp(input, "quit") == 0) {
            printf("Thank you for playing.\n");
            break;
        }
    }
}