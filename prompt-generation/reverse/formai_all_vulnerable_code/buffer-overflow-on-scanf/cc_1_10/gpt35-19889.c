//FormAI DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define struct for hotel rooms */
typedef struct Room {
    int room_number;
    int capacity;
    int occupied;
    char guest_name[30];
} Room;

/* Initialize hotel with rooms */
Room hotel[10] = {
    {101, 2, 0, ""},
    {102, 2, 0, ""},
    {103, 2, 0, ""},
    {104, 2, 0, ""},
    {105, 4, 0, ""},
    {106, 4, 0, ""},
    {107, 4, 0, ""},
    {108, 4, 0, ""},
    {109, 6, 0, ""},
    {110, 6, 0, ""}
};

/* Function to print out hotel capacity and occupancy */
void printHotelInfo() {
    int total_capacity = 0, total_occupied = 0;
    for (int i = 0; i < 10; i++) {
        total_capacity += hotel[i].capacity;
        total_occupied += hotel[i].occupied;
    }
    printf("Hotel Capacity: %d\n", total_capacity);
    printf("Hotel Occupancy: %d\n", total_occupied);
}

/* Function to check if room is available */
int isRoomAvailable(int room_number) {
    for (int i = 0; i < 10; i++) {
        if (hotel[i].room_number == room_number) {
            if (hotel[i].occupied == 0) {
                return 1;
            }
        }
    }
    return 0;
}

/* Function to book a room */
void bookRoom(int room_number, char guest_name[]) {
    for (int i = 0; i < 10; i++) {
        if (hotel[i].room_number == room_number) {
            if (hotel[i].occupied == 0) {
                hotel[i].occupied = 1;
                strcpy(hotel[i].guest_name, guest_name);
                printf("Room %d has been booked for %s\n", room_number, guest_name);
                break;
            } else {
                printf("Room %d is already occupied\n", room_number);
                break;
            }
        }
    }
}

/* Function to check out of a room */
void checkOut(int room_number) {
    for (int i = 0; i < 10; i++) {
        if (hotel[i].room_number == room_number) {
            if (hotel[i].occupied == 1) {
                hotel[i].occupied = 0;
                printf("Room %d has been checked out\n", room_number);
                break;
            } else {
                printf("Room %d is not occupied\n", room_number);
                break;
            }
        }
    }
}

int main() {
    int option, room_number;
    char guest_name[30];
    do {
        printf("\nWelcome to C Hotel Management System\n");
        printf("1. Print Hotel Information\n");
        printf("2. Check Room Availability\n");
        printf("3. Book a Room\n");
        printf("4. Check Out of a Room\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1: 
                printHotelInfo();
                break;
            case 2: 
                printf("Enter room number: ");
                scanf("%d", &room_number);
                if (isRoomAvailable(room_number)) {
                    printf("Room %d is available\n", room_number);
                } else {
                    printf("Room %d is not available\n", room_number);
                }
                break;
            case 3: 
                printf("Enter room number: ");
                scanf("%d", &room_number);
                if (isRoomAvailable(room_number)) {
                    printf("Enter guest name: ");
                    scanf("%s", guest_name);
                    bookRoom(room_number, guest_name);
                } else {
                    printf("Room %d is not available\n", room_number);
                }
                break;
            case 4: 
                printf("Enter room number: ");
                scanf("%d", &room_number);
                checkOut(room_number);
                break;
            case 5: 
                printf("Exiting Hotel Management System...\n");
                exit(0);
            default: 
                printf("Invalid option entered, please try again\n");
                break;
        }
    } while (option != 5);
    return 0;
}