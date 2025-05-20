//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_GUESTS 2

typedef struct Room {
    int room_no;
    char status;
    char guest_name[MAX_GUESTS];
    int num_guests;
} Room;

Room rooms[MAX_ROOMS];

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_no = i + 1;
        rooms[i].status = 'O';
        rooms[i].num_guests = 0;
    }
}

void checkIn(char *name, int numGuests) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].status == 'O' && rooms[i].num_guests < MAX_GUESTS) {
            rooms[i].status = 'B';
            rooms[i].num_guests = numGuests;
            strcpy(rooms[i].guest_name, name);
            printf("Room No. %d booked for %s with %d guests.\n", rooms[i].room_no, name, numGuests);
            return;
        }
    }

    printf("No rooms available.\n");
}

void checkOut(char *name) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (strcmp(rooms[i].guest_name, name) == 0) {
            rooms[i].status = 'O';
            rooms[i].num_guests = 0;
            printf("Room No. %d vacated.\n", rooms[i].room_no);
            return;
        }
    }

    printf("Guest not found.\n");
}

int main() {
    initializeRooms();

    char name[20];
    int numGuests;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the number of guests: ");
    scanf("%d", &numGuests);

    checkOut(name);

    return 0;
}