//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define MAX_ROOMS 10
#define MAX_GUESTS 5

typedef struct {
    int room_number;
    int is_occupied;
} Room;

typedef struct {
    int guest_id;
    char name[20];
    int room_number;
} Guest;

Room rooms[MAX_ROOMS];
Guest guests[MAX_GUESTS];
int num_guests = 0, num_rooms_occupied = 0;

void assign_room(int guest_id) {
    int i;

    for (i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].is_occupied == 0) {
            rooms[i].is_occupied = 1;
            guests[guest_id].room_number = i + 1;
            num_rooms_occupied++;
            break;
        }
    }
}

int main() {
    int guest_id, choice;

    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].is_occupied = 0;
    }

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Register Guest\n");
        printf("2. Checkout Guest\n");
        printf("3. Display Occupied Rooms\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_guests < MAX_GUESTS) {
                    printf("Enter guest name: ");
                    scanf("%s", guests[num_guests].name);
                    assign_room(num_guests);
                    num_guests++;
                    printf("Guest registered successfully.\n");
                } else {
                    printf("Maximum guests capacity reached.\n");
                }
                break;
            case 2:
                printf("Enter guest ID: ");
                scanf("%d", &guest_id);
                if (guest_id >= 0 && guest_id < num_guests) {
                    rooms[guests[guest_id].room_number - 1].is_occupied = 0;
                    num_rooms_occupied--;
                    printf("Guest checked out successfully.\n");
                } else {
                    printf("Invalid guest ID.\n");
                }
                break;
            case 3:
                printf("Occupied Rooms:\n");
                for (int i = 0; i < MAX_ROOMS; i++) {
                    if (rooms[i].is_occupied == 1) {
                        printf("Room %d occupied by %s\n", i + 1, guests[i - num_rooms_occupied].name);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}