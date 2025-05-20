//FormAI DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int room_num;
    int occupancy;
};

int main() {
    int num_rooms = 10; // total number of rooms in the hotel
    struct room rooms[num_rooms]; // array of rooms
    
    // set initial values for all rooms
    for(int i = 0; i < num_rooms; i++) {
        rooms[i].room_num = i+1;
        rooms[i].occupancy = 0;
    }
    
    // main menu loop
    while(1) {
        printf("Welcome to the hotel management system.\n");
        printf("Please select an option:\n");
        printf("1. Check room availability\n");
        printf("2. Book a room\n");
        printf("3. Cancel a booking\n");
        printf("4. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // print list of available rooms
                printf("Available rooms:\n");
                for(int i = 0; i < num_rooms; i++) {
                    if(rooms[i].occupancy == 0) {
                        printf("Room number %d\n", rooms[i].room_num);
                    }
                }
                break;
            case 2:
                // book a room
                printf("Please enter the room number you would like to book:\n");
                int room_choice;
                scanf("%d", &room_choice);
                int found_room = 0;
                for(int i = 0; i < num_rooms; i++) {
                    if(rooms[i].room_num == room_choice) {
                        found_room = 1;
                        if(rooms[i].occupancy == 0) {
                            printf("Booking successful.\n");
                            rooms[i].occupancy = 1;
                        } else {
                            printf("Sorry, that room is already booked.\n");
                        }
                    }
                }
                if(!found_room) {
                    printf("Sorry, that room does not exist.\n");
                }
                break;
            case 3:
                // cancel a booking
                printf("Please enter the room number you would like to cancel a booking for:\n");
                int cancel_choice;
                scanf("%d", &cancel_choice);
                found_room = 0;
                for(int i = 0; i < num_rooms; i++) {
                    if(rooms[i].room_num == cancel_choice) {
                        found_room = 1;
                        if(rooms[i].occupancy == 1) {
                            printf("Booking cancelled.\n");
                            rooms[i].occupancy = 0;
                        } else {
                            printf("Sorry, that room is not currently booked.\n");
                        }
                    }
                }
                if(!found_room) {
                    printf("Sorry, that room does not exist.\n");
                }
                break;
            case 4:
                // exit program
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}