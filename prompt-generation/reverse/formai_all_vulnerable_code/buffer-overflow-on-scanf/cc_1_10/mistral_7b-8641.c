//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int room_number;
    int next;
} Room;

Room rooms[MAX_ROOMS];
int top = -1;

void add_room(int room_number);
void print_rooms(int room_number);

void add_room(int room_number) {
    if (top >= MAX_ROOMS) {
        printf("Error: No more rooms available.\n");
        return;
    }

    strcpy(rooms[++top].name, "Unoccupied");
    rooms[top].room_number = room_number;
    rooms[top].next = -1;

    if (room_number > 0) {
        add_room(room_number - 1);
    }
}

void print_rooms(int room_number) {
    if (room_number > 0) {
        print_rooms(room_number - 1);
    }

    if (strcmp(rooms[room_number].name, "Unoccupied") != 0) {
        printf("Room %d is occupied by %s\n", rooms[room_number].room_number, rooms[room_number].name);
    } else {
        printf("Room %d is unoccupied\n", rooms[room_number].room_number);
    }
}

int main() {
    int n, i;

    printf("Enter number of rooms to add: ");
    scanf("%d", &n);

    add_room(n);

    printf("Printing room details:\n");
    print_rooms(1);

    return 0;
}