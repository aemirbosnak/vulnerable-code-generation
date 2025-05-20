//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct Room {
    int room_no;
    char status;
    char type;
    float rate;
} Room;

Room rooms[MAX_ROOMS];

void display_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room No: %d, Status: %c, Type: %c, Rate: %.2f\n", rooms[i].room_no, rooms[i].status, rooms[i].type, rooms[i].rate);
    }
}

void book_room(int room_no, char status, char type, float rate) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].room_no == room_no) {
            rooms[i].status = status;
            rooms[i].type = type;
            rooms[i].rate = rate;
            return;
        }
    }

    printf("Error: Room not found.\n");
}

int main() {
    int choice;
    int room_no;
    char status;
    char type;
    float rate;

    // Initialize rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_no = i + 1;
        rooms[i].status = 'O';
        rooms[i].type = 'D';
        rooms[i].rate = 1000.0;
    }

    // Display rooms
    display_rooms();

    // Book a room
    printf("Enter room number: ");
    scanf("%d", &room_no);

    printf("Enter status (O/A): ");
    scanf(" %c", &status);

    printf("Enter type (D/H): ");
    scanf(" %c", &type);

    printf("Enter rate: ");
    scanf("%f", &rate);

    book_room(room_no, status, type, rate);

    // Display updated rooms
    display_rooms();

    return 0;
}