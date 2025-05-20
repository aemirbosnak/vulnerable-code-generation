//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Room {
    char name[50];
    int num_doors;
    int *doors;
} Room;

void generate_maze(int num_rooms, Room rooms[]) {
    int i, j, k, l;
    int num_doors;
    int door1, door2;

    srand(time(NULL));

    for (i = 0; i < num_rooms; i++) {
        num_doors = rand() % 4 + 1;
        rooms[i].num_doors = num_doors;
        rooms[i].doors = (int *) malloc(num_doors * sizeof(int));

        for (j = 0; j < num_doors; j++) {
            do {
                door1 = rand() % num_rooms;
            } while (door1 == i);

            do {
                door2 = rand() % num_rooms;
            } while (door2 == door1 || door2 == i);

            rooms[i].doors[j] = door1;
            rooms[door1].doors[rooms[door1].num_doors++] = door2;
        }
    }
}

void print_room(Room room) {
    printf("You are in the %s.\n", room.name);

    if (room.num_doors > 0) {
        printf("There are doors leading to:\n");

        for (int i = 0; i < room.num_doors; i++) {
            printf("%d\n", room.doors[i]);
        }
    } else {
        printf("There are no doors in this room.\n");
    }
}

int main() {
    int num_rooms;
    Room rooms[100];

    printf("Enter the number of rooms in the haunted house: ");
    scanf("%d", &num_rooms);

    generate_maze(num_rooms, rooms);

    int current_room = 0;

    while (1) {
        print_room(rooms[current_room]);

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 0 && choice < num_rooms) {
            current_room = choice;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}