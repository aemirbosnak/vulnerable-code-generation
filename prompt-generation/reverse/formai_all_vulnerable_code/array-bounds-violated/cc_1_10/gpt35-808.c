//FormAI DATASET v1.0 Category: Hotel Management System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function Prototypes
void menu();
void addRooms();
void displayRooms();
void bookRooms();
void checkOut();
void displayGuests();

// Global Variables
int currentRoom = 0;

// Room Structure
struct room {
    int room_number;
    int beds;
    int price;
    int availability;
    char booked_by[20];
} rooms[10];

// Guest Structure
struct guest {
    char name[20];
    int room_number;
    int total_price;
} guests[10];

int main() {
    menu();
    return 0;
}

// Function Definitions

void menu() {
    int choice;
    do {
        printf("\n\n\t---------HOTEL MANAGEMENT SYSTEM---------");
        printf("\n\n\n\t\t1. Add Rooms");
        printf("\n\t\t2. Display Rooms");
        printf("\n\t\t3. Book Room");
        printf("\n\t\t4. Check Out");
        printf("\n\t\t5. Display Guests");
        printf("\n\t\t6. Exit");
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRooms();
                break;
            case 2:
                displayRooms();
                break;
            case 3:
                bookRooms();
                break;
            case 4:
                checkOut();
                break;
            case 5:
                displayGuests();
                break;
            case 6:
                exit(0);
            default:
                printf("\n\t\tInvalid choice, please try again\n");
                break;
        }
    } while (choice != 6);
}

void addRooms() {
    printf("\n\n\t---------ADD ROOMS---------\n\n");
    for (int i = 0; i < 10; i++) {
        rooms[i].room_number = i + 1;
        printf("\n\t\tEnter number of beds for Room %d: ", rooms[i].room_number);
        scanf("%d", &rooms[i].beds);
        printf("\n\t\tEnter price for Room %d: ", rooms[i].room_number);
        scanf("%d", &rooms[i].price);
        rooms[i].availability = 1;
        strcpy(rooms[i].booked_by, "Nobody");
    }
    printf("\n\t\tRooms have been added successfully\n");
}

void displayRooms() {
    printf("\n\n\t---------DISPLAY ROOMS---------\n\n");
    printf("\n\t|%-15s | %-20s | %-10s | %-15s|", "Room Number", "Number of Beds", "Price", "Availability");
    printf("\n\t------------------------------------------------------------------------------------");
    for (int i = 0; i < 10; i++) {
        printf("\n\t|%-15d | %-20d | %-10d | %-15s|", rooms[i].room_number, rooms[i].beds, rooms[i].price,
               rooms[i].availability == 1 ? "Available" : "Not Available");
    }
}

void bookRooms() {
    int room_number, nights;
    printf("\n\n\t---------BOOK ROOMS---------\n\n");
    printf("\n\t\tEnter the Room Number you wish to book: ");
    scanf("%d", &room_number);
    if (rooms[room_number - 1].availability == 0) {
        printf("\n\t\tRoom not available!");
        return;
    }
    rooms[room_number - 1].availability = 0;
    printf("\n\t\tEnter number of nights you wish to stay: ");
    scanf("%d", &nights);
    guests[currentRoom].room_number = room_number;
    printf("\n\t\tEnter your name: ");
    scanf("%s", guests[currentRoom].name);
    guests[currentRoom].total_price = nights * rooms[room_number - 1].price;
    rooms[room_number - 1].booked_by, guests[currentRoom].name;
    currentRoom++;
    printf("\n\t\tRoom booked successfully!");
}

void checkOut() {
    int room_number;
    printf("\n\n\t---------CHECK OUT---------\n\n");
    printf("\n\t\tEnter the Room Number you wish to check out: ");
    scanf("%d", &room_number);
    rooms[room_number - 1].availability = 1;
    printf("\n\t\tCheck out successful!");
}

void displayGuests() {
    printf("\n\n\t---------DISPLAY GUESTS---------\n\n");
    printf("\n\t|%-15s | %-20s | %-10s |", "Room Number", "Guest Name", "Total Price");
    printf("\n\t-----------------------------------------------");
    for (int i = 0; i < currentRoom; i++) {
        printf("\n\t|%-15d | %-20s | %-10d |", guests[i].room_number, guests[i].name, guests[i].total_price);
    }
}