//FormAI DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100  //maximum rooms in the hotel
#define MAX_NAME 30    //maximum length of guest name

//structure for hotel rooms
struct Room {
    int id;
    char guest_name[MAX_NAME];
    int occupancy;
    float price;
};

//function prototypes
void add_room(struct Room rooms[], int *num_rooms);
void remove_room(struct Room rooms[], int *num_rooms);
void display_room(struct Room rooms[], int num_rooms);
void search_room(struct Room rooms[], int num_rooms);
void display_menu();

int main() {
    struct Room rooms[MAX_ROOMS];  //declare array of hotel rooms
    int num_rooms = 0;  //initialize number of rooms to 0
    int choice;  //to hold user's menu choice

    do {
        display_menu();  //display the menu
        printf("\nEnter your choice: ");
        scanf("%d", &choice);  //get user's menu choice

        switch(choice) {
            case 1:
                add_room(rooms, &num_rooms);
                break;
            case 2:
                remove_room(rooms, &num_rooms);
                break;
            case 3:
                display_room(rooms, num_rooms);
                break;
            case 4:
                search_room(rooms, num_rooms);
                break;
            case 5:
                printf("\nThank you for using our hotel management system!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

//function to add a room to the hotel
void add_room(struct Room rooms[], int *num_rooms) {
    int id, occupancy;
    char name[MAX_NAME];
    float price;

    printf("\nEnter the following details for the new room:\n");
    printf("Room ID: ");
    scanf("%d", &id);
    
    //check if room already exists
    for(int i = 0; i < *num_rooms; i++) {
        if(rooms[i].id == id) {
            printf("\nError: Room already exists with ID %d.\n", id);
            return;
        }
    }

    printf("Guest Name: ");
    scanf("%s", name);
    printf("Occupancy (0 - available, 1 - occupied): ");
    scanf("%d", &occupancy);
    printf("Price: $");
    scanf("%f", &price);

    rooms[*num_rooms].id = id;
    strcpy(rooms[*num_rooms].guest_name, name);
    rooms[*num_rooms].occupancy = occupancy;
    rooms[*num_rooms].price = price;

    *num_rooms += 1;

    printf("\nRoom added to hotel successfully.\n");
}

//function to remove a room from the hotel
void remove_room(struct Room rooms[], int *num_rooms) {
    int id, index = -1;

    printf("\nEnter the ID of the room to remove: ");
    scanf("%d", &id);

    //search for the room with given ID
    for(int i = 0; i < *num_rooms; i++) {
        if(rooms[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("\nError: Room not found with ID %d.\n", id);
        return;
    }

    //shift all rooms to the right of the index by one to overwrite the room to be removed
    for(int i = index; i < *num_rooms - 1; i++) {
        rooms[i] = rooms[i+1];
    }

    *num_rooms -= 1;

    printf("\nRoom with ID %d removed from hotel successfully.\n", id);
}

//function to display all rooms in the hotel
void display_room(struct Room rooms[], int num_rooms) {
    if(num_rooms == 0) {
        printf("\nNo rooms found in the hotel.\n");
        return;
    }

    printf("\nList of rooms in the hotel:\n");
    printf("%-10s%-20s%-20s%s\n", "Room ID", "Guest Name", "Occupancy", "Price");
    for(int i = 0; i < num_rooms; i++) {
        printf("%-10d%-20s%-20s$%.2f\n", rooms[i].id, rooms[i].guest_name, (rooms[i].occupancy == 0) ? "Available" : "Occupied", rooms[i].price);
    }
}

//function to search for a room in the hotel
void search_room(struct Room rooms[], int num_rooms) {
    int id, found = 0;

    printf("\nEnter the ID of the room to search for: ");
    scanf("%d", &id);

    for(int i = 0; i < num_rooms; i++) {
        if(rooms[i].id == id) {
            printf("\nRoom found with ID %d:\n", id);
            printf("%-10s%-20s%-20s%s\n", "Room ID", "Guest Name", "Occupancy", "Price");
            printf("%-10d%-20s%-20s$%.2f\n", rooms[i].id, rooms[i].guest_name, (rooms[i].occupancy == 0) ? "Available" : "Occupied", rooms[i].price);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nError: Room not found with ID %d.\n", id);
    }
}

//function to display the program menu
void display_menu() {
    printf("\nHOTEL MANAGEMENT SYSTEM\n");
    printf("1. Add Room\n");
    printf("2. Remove Room\n");
    printf("3. Display All Rooms\n");
    printf("4. Search Room\n");
    printf("5. Exit\n");
}