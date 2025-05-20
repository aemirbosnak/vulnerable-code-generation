//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct room {
    int north;
    int south;
    int east;
    int west;
    int visited;
    char description[80];
} room;

room rooms[MAX_ROOMS];

int current_room;

void create_rooms() {
    int i;
    
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].north = -1;
        rooms[i].south = -1;
        rooms[i].east = -1;
        rooms[i].west = -1;
        rooms[i].visited = 0;
        sprintf(rooms[i].description, "Room %d", i);
    }
    
    rooms[0].north = 1;
    rooms[0].east = 2;
    rooms[0].south = 3;
    
    rooms[1].south = 0;
    rooms[1].east = 4;
    
    rooms[2].west = 0;
    rooms[2].east = 5;
    
    rooms[3].north = 0;
    rooms[3].south = 6;
    
    rooms[4].west = 1;
    rooms[4].east = 7;
    
    rooms[5].west = 2;
    rooms[5].east = 8;
    
    rooms[6].north = 3;
    rooms[6].south = 9;
    
    rooms[7].west = 4;
    rooms[7].east = 9;
    
    rooms[8].west = 5;
    
    rooms[9].north = 6;
    rooms[9].west = 7;
    
    current_room = 0;
}

void print_room() {
    printf("%s\n", rooms[current_room].description);
    
    if (rooms[current_room].north != -1) {
        printf("There is a door to the north.\n");
    }
    
    if (rooms[current_room].south != -1) {
        printf("There is a door to the south.\n");
    }
    
    if (rooms[current_room].east != -1) {
        printf("There is a door to the east.\n");
    }
    
    if (rooms[current_room].west != -1) {
        printf("There is a door to the west.\n");
    }
}

void move(char direction) {
    switch (direction) {
        case 'n':
            if (rooms[current_room].north != -1) {
                current_room = rooms[current_room].north;
            }
            break;
        case 's':
            if (rooms[current_room].south != -1) {
                current_room = rooms[current_room].south;
            }
            break;
        case 'e':
            if (rooms[current_room].east != -1) {
                current_room = rooms[current_room].east;
            }
            break;
        case 'w':
            if (rooms[current_room].west != -1) {
                current_room = rooms[current_room].west;
            }
            break;
    }
}

int main() {
    char input;
    
    create_rooms();
    
    while (1) {
        print_room();
        
        printf("Enter a direction (n, s, e, w): ");
        scanf(" %c", &input);
        
        move(input);
    }
    
    return 0;
}