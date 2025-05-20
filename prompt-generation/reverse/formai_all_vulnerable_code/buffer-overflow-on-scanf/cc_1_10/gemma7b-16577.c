//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    double bill;
} Guest;

typedef struct Room {
    int room_no;
    int occupancy;
    double rate;
} Room;

Guest guests[MAX_GUESTS];
Room rooms[MAX_ROOMS];

void manage_guests() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        printf("Guest name: %s\n", guests[i].name);
        printf("Room number: %d\n", guests[i].room_no);
        printf("Bill: %.2lf\n", guests[i].bill);
    }
}

void manage_rooms() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        printf("Room number: %d\n", rooms[i].room_no);
        printf("Occupancy: %d\n", rooms[i].occupancy);
        printf("Rate: %.2lf\n", rooms[i].rate);
    }
}

int main() {
    int choice;

    printf("Enter 1 to manage guests, 2 to manage rooms: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            manage_guests();
            break;
        case 2:
            manage_rooms();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}