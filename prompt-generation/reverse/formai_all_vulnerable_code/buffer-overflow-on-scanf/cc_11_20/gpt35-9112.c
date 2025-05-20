//FormAI DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for room
typedef struct {
    int roomNo;
    char roomType[20];
    int price;
    int availability;
} Room;

int main() {
    int choice;
    int i, j, roomCount=0;
    int searchRoom;
    Room hotel[20]; // Define array of structures for hotel rooms
    
    printf("***** Welcome to C Hotel Management System *****\n");
    
    // Display menu
    while (1) {
        printf("\n-------- MENU --------\n");
        printf("1. Add Room\n");
        printf("2. Search Room\n");
        printf("3. View Rooms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (roomCount < 20) { // Check if maximum limit of rooms reached
                    // Obtain room details
                    printf("\nEnter Room Number: ");
                    scanf("%d", &hotel[roomCount].roomNo);
                    printf("Enter Room Type: ");
                    scanf("%s", hotel[roomCount].roomType);
                    printf("Enter Room Price: ");
                    scanf("%d", &hotel[roomCount].price);
                    hotel[roomCount].availability = 1; // Set room availability to true
                    roomCount++; // Increment count of rooms
                    printf("\nRoom added successfully!");
                }
                else {
                    printf("\nMaximum number of rooms reached!");
                }
                break;
            case 2:
                if (roomCount == 0) { // Check if there are any rooms added
                    printf("\nNo rooms added yet!");
                    break;
                }
                printf("\nEnter Room Number to search: ");
                scanf("%d", &searchRoom);
                for (i=0; i<roomCount; i++) {
                    if (hotel[i].roomNo == searchRoom) { // Check if room number matches
                        printf("\nRoom Number: %d", hotel[i].roomNo);
                        printf("\nRoom Type: %s", hotel[i].roomType);
                        printf("\nRoom Price: %d", hotel[i].price);
                        if (hotel[i].availability == 1) { // Check if room is available
                            printf("\nRoom is available.");
                        }
                        else {
                            printf("\nRoom is not available.");
                        }
                        break;
                    }
                }
                if (i == roomCount) { // If room number not found
                    printf("\nRoom not found!");
                }
                break;
            case 3:
                if (roomCount == 0) { // Check if there are any rooms added
                    printf("\nNo rooms added yet!");
                    break;
                }
                printf("\n------- LIST OF ROOMS ------");
                printf("\nRoom No.\tType\tPrice\tAvailability");
                for (i=0; i<roomCount; i++) {
                    printf("\n%d\t\t%s\t%d", hotel[i].roomNo, hotel[i].roomType, hotel[i].price);
                    if (hotel[i].availability == 1) { // Check if room is available
                        printf("\tAvailable");
                    }
                    else {
                        printf("\tNot available");
                    }
                }
                break;
            case 4:
                printf("\nThank you for using C Hotel Management System!");
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    
    return 0;
}