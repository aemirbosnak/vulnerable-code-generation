//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: retro
#include <stdio.h>
#include <string.h>

// Define the hotel management system structure
typedef struct hotel_management_system {
    char name[50];
    int room_number;
    char room_type;
    int occupancy;
    float price;
} hotel_management_system;

// Create an array of hotel management system structures
hotel_management_system hotel_management_systems[100];

// Function to add a new room to the hotel management system
void add_room(hotel_management_system *hotel_management_system) {
    printf("Enter the room name: ");
    scanf("%s", hotel_management_system->name);

    printf("Enter the room number: ");
    scanf("%d", &hotel_management_system->room_number);

    printf("Enter the room type (single, double, suite): ");
    scanf("%c", &hotel_management_system->room_type);

    printf("Enter the occupancy: ");
    scanf("%d", &hotel_management_system->occupancy);

    printf("Enter the price: ");
    scanf("%f", &hotel_management_system->price);
}

// Function to list all rooms in the hotel management system
void list_rooms(hotel_management_system *hotel_management_systems) {
    for (int i = 0; i < 100; i++) {
        if (hotel_management_systems[i].occupancy) {
            printf("Room Name: %s\n", hotel_management_systems[i].name);
            printf("Room Number: %d\n", hotel_management_systems[i].room_number);
            printf("Room Type: %c\n", hotel_management_systems[i].room_type);
            printf("Occupancy: %d\n", hotel_management_systems[i].occupancy);
            printf("Price: %.2f\n", hotel_management_systems[i].price);
            printf("\n");
        }
    }
}

// Function to search for a room in the hotel management system
void search_room(hotel_management_system *hotel_management_systems) {
    char room_name[50];

    printf("Enter the room name: ");
    scanf("%s", room_name);

    for (int i = 0; i < 100; i++) {
        if (strcmp(hotel_management_systems[i].name, room_name) == 0) {
            printf("Room Name: %s\n", hotel_management_systems[i].name);
            printf("Room Number: %d\n", hotel_management_systems[i].room_number);
            printf("Room Type: %c\n", hotel_management_systems[i].room_type);
            printf("Occupancy: %d\n", hotel_management_systems[i].occupancy);
            printf("Price: %.2f\n", hotel_management_systems[i].price);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Hotel Management System!\n");

    printf("1. Add a new room\n");
    printf("2. List all rooms\n");
    printf("3. Search for a room\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_room(&hotel_management_systems[0]);
            break;
        case 2:
            list_rooms(hotel_management_systems);
            break;
        case 3:
            search_room(hotel_management_systems);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}