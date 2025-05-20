//FormAI DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int room_count = 0;
int guest_count = 0;

typedef struct {
    int room_number;
    int capacity;
    int is_vacant;
} room;

typedef struct {
    char name[50];
    int room_number;
} guest;

room rooms[10];
guest guests[10];

void add_room(int room_number, int capacity) {
    if (room_count < 10) {
        rooms[room_count].room_number = room_number;
        rooms[room_count].capacity = capacity;
        rooms[room_count].is_vacant = 1;
        room_count++;
        printf("Room added successfully!\n");
    } else {
        printf("Sorry, you cannot add any more rooms.\n");
    }
}

void list_rooms() {
    printf("Room Number\tCapacity\tVacancy\n");
    for (int i = 0; i < room_count; i++) {
        printf("%d\t\t%d\t\t", rooms[i].room_number, rooms[i].capacity);
        if (rooms[i].is_vacant) {
            printf("Vacant\n");
        } else {
            printf("Occupied by %s\n", guests[i].name);
        }
    }
}

void add_guest(char name[50], int room_number) {
    if (guest_count < 10) {
        for (int i = 0; i < room_count; i++) {
            if (rooms[i].room_number == room_number) {
                if (rooms[i].is_vacant) {
                    guests[guest_count].room_number = room_number;
                    strcpy(guests[guest_count].name, name);
                    rooms[i].is_vacant = 0;
                    guest_count++;
                    printf("Guest added successfully!\n");
                } else {
                    printf("Sorry, the room is already occupied.\n");
                }
            }
        }
    } else {
        printf("Sorry, you cannot add any more guests.\n");
    }
}

void list_guests() {
    printf("Room Number\tGuest Name\n");
    for (int i = 0; i < guest_count; i++) {
        printf("%d\t\t%s\n", guests[i].room_number, guests[i].name);
    }
}

int main() {
    int choice, room_number, capacity;
    char name[50];
    
    do {
        printf("Welcome to the Hotel Management System!\n");
        printf("1. Add Room\n");
        printf("2. List Rooms\n");
        printf("3. Add Guest\n");
        printf("4. List Guests\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                printf("Enter capacity: ");
                scanf("%d", &capacity);
                add_room(room_number, capacity);
                break;
            case 2:
                list_rooms();
                break;
            case 3:
                printf("Enter guest name: ");
                scanf("%s", &name);
                printf("Enter room number: ");
                scanf("%d", &room_number);
                add_guest(name, room_number);
                break;
            case 4:
                list_guests();
                break;
            case 0:
                printf("Thank you for using the Hotel Management System.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 0);
    
    return 0;
}