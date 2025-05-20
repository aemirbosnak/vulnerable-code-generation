//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_DOORS 4

typedef struct Room {
    struct Room* doors[MAX_DOORS];
    int num_doors;
    int haunted;
} Room;

Room rooms[MAX_ROOMS];
int current_room_index;

void create_rooms() {
    int i, j;
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].num_doors = rand() % MAX_DOORS;
        for (j = 0; j < rooms[i].num_doors; j++) {
            int random_room_index = rand() % MAX_ROOMS;
            while (random_room_index == i || rooms[i].doors[random_room_index]) {
                random_room_index = rand() % MAX_ROOMS;
            }
            rooms[i].doors[j] = &rooms[random_room_index];
        }
        rooms[i].haunted = rand() % 2;
    }
}

void print_room(Room* room) {
    printf("You are in a room with %d doors.\n", room->num_doors);
    if (room->haunted) {
        printf("This room is haunted... you feel uneasy.\n");
    }
}

void print_doors(Room* room) {
    int i;
    for (i = 0; i < room->num_doors; i++) {
        printf("Door %d leads to another room.\n", i + 1);
    }
    if (!room->num_doors) {
        printf("There are no doors in this room!\n");
    }
}

int main() {
    srand(time(NULL));
    create_rooms();
    current_room_index = rand() % MAX_ROOMS;
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You find yourself in a creepy old mansion...\n");
    while (1) {
        Room* current_room = &rooms[current_room_index];
        print_room(current_room);
        print_doors(current_room);
        
        if (current_room->haunted) {
            printf("Something spooky happens... you are paralyzed with fear!\n");
            return 0;
        }
        
        int choice;
        printf("Which door do you want to go through? ");
        scanf("%d", &choice);
        if (choice < 1 || choice > current_room->num_doors) {
            printf("Invalid choice. Try again.\n");
            continue;
        }
        current_room_index = rooms[current_room_index].doors[choice - 1] - rooms;
        printf("\n");
        if (rooms[current_room_index].haunted) {
            printf("You have entered a haunted room... beware!\n");
        }
    }
    
    return 0;
}