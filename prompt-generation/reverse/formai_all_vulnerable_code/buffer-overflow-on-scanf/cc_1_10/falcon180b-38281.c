//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define MAX_ROOM_SIZE 20
#define GHOST_CHANCE 5

struct room {
    char name[MAX_ROOM_SIZE];
    int is_haunted;
    int is_visited;
};

void generate_rooms(struct room rooms[]) {
    for(int i = 0; i < ROOMS; i++) {
        sprintf(rooms[i].name, "Room %d", i+1);
        rooms[i].is_haunted = rand() % GHOST_CHANCE;
        rooms[i].is_visited = 0;
    }
}

void visit_room(struct room *room) {
    if(room->is_haunted) {
        printf("You enter Room %s and feel a chill run down your spine. A ghostly presence lurks in the shadows!\n", room->name);
    } else {
        printf("You enter Room %s. It's empty and unremarkable.\n", room->name);
    }
    room->is_visited = 1;
}

int main() {
    srand(time(NULL));
    struct room rooms[ROOMS];
    generate_rooms(rooms);

    int player_room = 0;
    while(player_room < ROOMS) {
        printf("You are in Room %s.\n", rooms[player_room].name);
        if(rooms[player_room].is_visited == 0) {
            visit_room(&rooms[player_room]);
        }
        printf("Which room would you like to go to? ");
        int choice;
        scanf("%d", &choice);
        if(choice >= 1 && choice <= ROOMS) {
            player_room = choice;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}