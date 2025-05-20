//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct room {
    int number;
    int price;
    int available;
};

void checkRoomAvailability(struct room room) {
    if (room.available) {
        printf("%d is available.\n", room.number);
    } else {
        printf("%d is not available.\n", room.number);
    }
}

void bookRoom(struct room room) {
    if (room.available) {
        printf("You have booked room %d for $%.2f.\n", room.number, room.price);
        room.available = 0;
    } else {
        printf("Room %d is already booked.\n", room.number);
    }
}

int main() {
    struct room room1 = {1, 100, 1};
    struct room room2 = {2, 150, 0};
    struct room room3 = {3, 200, 0};

    printf("1. Check room availability\n2. Book room\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            checkRoomAvailability(room1);
            checkRoomAvailability(room2);
            checkRoomAvailability(room3);
            break;
        case 2:
            bookRoom(room1);
            bookRoom(room2);
            bookRoom(room3);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}