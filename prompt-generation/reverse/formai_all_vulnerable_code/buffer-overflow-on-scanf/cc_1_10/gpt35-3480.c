//FormAI DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the maximum capacity of the Hotel Management System
#define MAX_ROOMS 100

// defining the maximum length of the string
#define MAX_STRING_LENGTH 50

// defining the room structure
typedef struct Room {
    int room_number;
    char guest_name[MAX_STRING_LENGTH];
    float room_rate;
} Room;

int num_of_rooms = 0;

Room hotel_rooms[MAX_ROOMS];

// function to add a new room to the system
void add_room() {
    Room new_room;
    // prompting the user to input the room number
    printf("Enter room number: ");
    scanf("%d", &new_room.room_number);
    // prompting the user to input the guest name
    printf("Enter guest name: ");
    scanf("%s", &new_room.guest_name);
    // prompting the user to input the room rate
    printf("Enter room rate: ");
    scanf("%f", &new_room.room_rate);
    // addding the new_room to the hotel_rooms array
    hotel_rooms[num_of_rooms] = new_room;
    num_of_rooms++;
    printf("\nNew room added successfully!\n");
}

// function to display all the rooms in the system
void display_all_rooms() {
    if(num_of_rooms == 0) {
        printf("\nNo rooms have been added to the system yet.\n");
    } else {
        printf("\nList of rooms in the system:\n");
        printf("Room Number\tGuest Name\tRoom Rate\n");
        for(int i=0; i<num_of_rooms; i++) {
            printf("%d\t\t%s\t\t%.2f\n", hotel_rooms[i].room_number, hotel_rooms[i].guest_name, hotel_rooms[i].room_rate);
        }
    }
}

// function to find a room by the room number
void find_room() {
    int room_number;
    printf("Enter the room number: ");
    scanf("%d", &room_number);
    for(int i=0; i<num_of_rooms; i++) {
        if(hotel_rooms[i].room_number == room_number) {
            printf("\nRoom found! Details are as follows:\n");
            printf("Room Number: %d\nGuest Name: %s\nRoom Rate: %.2f\n", hotel_rooms[i].room_number, hotel_rooms[i].guest_name, hotel_rooms[i].room_rate);
            return;
        }
    }
    printf("\nRoom not found.\n");
}

// function to remove a room from the system
void remove_room() {
    int room_number;
    printf("Enter the room number you wish to remove: ");
    scanf("%d", &room_number);
    for(int i=0; i<num_of_rooms; i++) {
        if(hotel_rooms[i].room_number == room_number) {
            for(int j=i; j<num_of_rooms-1; j++) {
                hotel_rooms[j] = hotel_rooms[j+1];
            }
            num_of_rooms--;
            printf("\nRoom removed successfully!\n");
            return;
        }
    }
    printf("\nRoom not found.\n");
}

int main() {
    int choice;
    do {
        // displaying the menu
        printf("\nWelcome to the Hotel Management System!\n");
        printf("1. Add a new room\n");
        printf("2. Display all rooms\n");
        printf("3. Find a room by room number\n");
        printf("4. Remove a room\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_room();
                break;
            case 2:
                display_all_rooms();
                break;
            case 3:
                find_room();
                break;
            case 4:
                remove_room();
                break;
            case 5:
                printf("\nThank you for using the Hotel Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice (1-5).\n");
        }
    } while(choice != 5);
    return 0;
}