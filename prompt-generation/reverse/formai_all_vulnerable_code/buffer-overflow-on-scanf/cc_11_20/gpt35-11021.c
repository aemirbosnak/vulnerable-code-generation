//FormAI DATASET v1.0 Category: Hotel Management System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Room {
    int roomNumber;
    int numberOfBeds;
    int isOccupied;
    float price;
} Room;

int main() {

    int numRooms = 10;
    Room rooms[numRooms];

    // Setting up the hotel rooms
    for(int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i+1;
        rooms[i].numberOfBeds = 2;
        rooms[i].isOccupied = 0;
        rooms[i].price = 100.00;
    }

    printf("Welcome to the Curious Hotel Management System!\n");

    // Loop through user inputs until they choose to exit
    int choice = 0;
    while(choice != 4) {
        printf("\n1. Check-In a guest\n");
        printf("2. Check-Out a guest\n");
        printf("3. View room availability and prices\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement for user selection
        switch(choice) {
            case 1: 
                printf("Enter room number for check-in: ");
                int roomNum;
                scanf("%d", &roomNum);

                if(rooms[roomNum-1].isOccupied == 0) {
                    rooms[roomNum-1].isOccupied = 1;
                    printf("Room %d checked in successfully. Enjoy your stay!\n", roomNum);
                } else {
                    printf("Sorry, that room is already occupied. Please choose a different room.\n");
                }
                break;

            case 2: 
                printf("Enter room number for check-out: ");
                int roomNum2;
                scanf("%d", &roomNum2);

                if(rooms[roomNum2-1].isOccupied == 1) {
                    rooms[roomNum2-1].isOccupied = 0;
                    printf("Room %d checked out successfully. Thanks for staying with us!\n", roomNum2);
                } else {
                    printf("Sorry, that room is not occupied. Please enter a different room number.\n");
                }
                break;

            case 3: 
                printf("Room availability and prices:\n\n");
                printf("Room Number\tNumber of Beds\tPrice per Night\tOccupancy Status\n");
                for(int i = 0; i < numRooms; i++) {
                    if(rooms[i].isOccupied == 0) {
                        printf("%d\t\t%d\t\t%.2f\t\tUnoccupied\n", rooms[i].roomNumber, rooms[i].numberOfBeds, rooms[i].price);
                    } else {
                        printf("%d\t\t%d\t\t%.2f\t\tOccupied\n", rooms[i].roomNumber, rooms[i].numberOfBeds, rooms[i].price);
                    }
                }
                break;

            case 4:
                printf("Thank you for using the Curious Hotel Management System!\n");
                break;

            default: 
                printf("Invalid input. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}