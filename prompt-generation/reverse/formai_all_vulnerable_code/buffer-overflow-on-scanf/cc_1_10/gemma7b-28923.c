//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct hotel_management_system {
    char name[50];
    int room_number;
    char room_type;
    int availability;
    float price;
} hotel_management_system;

// Create a function to insert a room into the hotel management system
void insert_room(hotel_management_system *pms) {
    printf("Enter the room name: ");
    scanf("%s", pms->name);

    printf("Enter the room number: ");
    scanf("%d", &pms->room_number);

    printf("Enter the room type: ");
    scanf("%c", &pms->room_type);

    printf("Enter the room availability: ");
    scanf("%d", &pms->availability);

    printf("Enter the room price: ");
    scanf("%f", &pms->price);
}

// Create a function to search for a room in the hotel management system
void search_room(hotel_management_system *pms) {
    printf("Enter the room number: ");
    scanf("%d", &pms->room_number);

    printf("Enter the room type: ");
    scanf("%c", &pms->room_type);

    if (pms->availability == 1) {
        printf("Room found!\n");
        printf("Name: %s\n", pms->name);
        printf("Room Number: %d\n", pms->room_number);
        printf("Room Type: %c\n", pms->room_type);
        printf("Price: %.2f\n", pms->price);
    } else {
        printf("Room not found.\n");
    }
}

// Create a function to update the availability of a room in the hotel management system
void update_availability(hotel_management_system *pms) {
    printf("Enter the room number: ");
    scanf("%d", &pms->room_number);

    printf("Enter the new availability: ");
    scanf("%d", &pms->availability);
}

// Create a function to delete a room from the hotel management system
void delete_room(hotel_management_system *pms) {
    printf("Enter the room number: ");
    scanf("%d", &pms->room_number);

    if (pms->availability == 0) {
        printf("Room deleted.\n");
        pms->availability = -1;
    } else {
        printf("Room not deleted.\n");
    }
}

int main() {
    // Create an array of hotel management system structures
    hotel_management_system pms[100];

    // Insert a room into the hotel management system
    insert_room(pms);

    // Search for a room in the hotel management system
    search_room(pms);

    // Update the availability of a room in the hotel management system
    update_availability(pms);

    // Delete a room from the hotel management system
    delete_room(pms);

    return 0;
}