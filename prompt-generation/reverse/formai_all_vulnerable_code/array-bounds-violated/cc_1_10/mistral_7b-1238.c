//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int room_number;
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;

void print_menu() {
    printf("1. Reserve a room\n");
    printf("2. Check availability\n");
    printf("3. Print all booked rooms\n");
    printf("4. Exit\n");
}

void reserve_room(int room_number) {
    if (num_rooms >= MAX_ROOMS) {
        printf("Error: No more rooms available.\n");
        return;
    }

    printf("Enter your name: ");
    fgets(rooms[num_rooms].name, MAX_NAME_LENGTH, stdin);
    rooms[num_rooms].name[strlen(rooms[num_rooms].name) - 1] = '\0';

    printf("Enter your phone number: ");
    fgets(rooms[num_rooms].phone, MAX_PHONE_LENGTH, stdin);
    rooms[num_rooms].phone[strlen(rooms[num_rooms].phone) - 1] = '\0';

    rooms[num_rooms].room_number = room_number;
    num_rooms++;

    printf("Room %d reserved for %s (%s).\n", room_number, rooms[num_rooms - 1].name, rooms[num_rooms - 1].phone);
}

int check_availability(int room_number) {
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            printf("Error: Room %d is already booked.\n", room_number);
            return 0;
        }
    }

    printf("Room %d is available.\n", room_number);
    return 1;
}

void print_booked_rooms() {
    printf("Booked rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("Room %d: %s (%s)\n", rooms[i].room_number, rooms[i].name, rooms[i].phone);
    }
}

int main() {
    int choice, room_number;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number to reserve: ");
                scanf("%d", &room_number);
                check_availability(room_number);
                reserve_room(room_number);
                break;
            case 2:
                printf("Enter room number to check availability: ");
                scanf("%d", &room_number);
                check_availability(room_number);
                break;
            case 3:
                print_booked_rooms();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}