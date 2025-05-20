//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_ADDRESS_LEN 100

// Structure to represent a customer
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];
} Customer;

// Structure to represent a room
typedef struct {
    int number;
    int status; // 0: vacant, 1: occupied
    Customer* customer;
} Room;

// Structure to represent a hotel
typedef struct {
    int num_rooms;
    Room* rooms;
} Hotel;

// Function to create a new customer
Customer* create_customer(char* name, char* phone, char* address) {
    Customer* customer = (Customer*)malloc(sizeof(Customer));
    strcpy(customer->name, name);
    strcpy(customer->phone, phone);
    strcpy(customer->address, address);
    return customer;
}

// Function to create a new hotel
Hotel* create_hotel(int num_rooms) {
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    hotel->num_rooms = num_rooms;
    hotel->rooms = (Room*)malloc(num_rooms * sizeof(Room));
    for (int i = 0; i < num_rooms; i++) {
        hotel->rooms[i].number = i + 1;
        hotel->rooms[i].status = 0;
        hotel->rooms[i].customer = NULL;
    }
    return hotel;
}

// Function to book a room for a customer
void book_room(Hotel* hotel, Customer* customer) {
    int i;
    for (i = 0; i < hotel->num_rooms; i++) {
        if (hotel->rooms[i].status == 0) {
            hotel->rooms[i].status = 1;
            hotel->rooms[i].customer = customer;
            break;
        }
    }
    if (i == hotel->num_rooms) {
        printf("No vacant rooms available.\n");
    }
}

// Function to display the status of a room
void display_room_status(Hotel* hotel, int room_number) {
    if (room_number < 1 || room_number > hotel->num_rooms) {
        printf("Invalid room number.\n");
        return;
    }
    Room* room = &hotel->rooms[room_number - 1];
    if (room->status == 0) {
        printf("Room %d is vacant.\n", room_number);
    } else {
        printf("Room %d is occupied by customer %s.\n", room_number, room->customer->name);
    }
}

// Function to display the status of all rooms
void display_all_room_status(Hotel* hotel) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        display_room_status(hotel, i + 1);
    }
}

int main() {
    Hotel* hotel = create_hotel(10);
    Customer* customer1 = create_customer("John Doe", "555-1234", "123 Main St");
    Customer* customer2 = create_customer("Jane Doe", "555-5678", "456 Elm St");
    book_room(hotel, customer1);
    book_room(hotel, customer2);
    display_room_status(hotel, 3);
    display_all_room_status(hotel);
    return 0;
}