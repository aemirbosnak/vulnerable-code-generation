//FormAI DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 50

// Global variables
char roomNumbers[MAX_ROOMS][6]; // Hold room numbers
int roomPrices[MAX_ROOMS]; // Hold room prices
int numRooms = 0; // Number of rooms in the array

// Function prototypes
void addRoom(void);
void displayRooms(void);
void searchRooms(void);
void deleteRoom(void);

int main() {
    int choice = 0;
    do {
        // Display main menu
        printf("Welcome to the C Hotel Management System!\n");
        printf("-----------------------------------------\n");
        printf("1. Add a room\n");
        printf("2. Display all rooms\n");
        printf("3. Search for a room\n");
        printf("4. Delete a room\n");
        printf("5. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform action based on user's choice
        switch(choice) {
            case 1:
                addRoom();
                break;
            case 2:
                displayRooms();
                break;
            case 3:
                searchRooms();
                break;
            case 4:
                deleteRoom();
                break;
            case 5:
                printf("Thank you for using the C Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}

// Function to add a room to the system
void addRoom(void) {
    char num[6];
    int price;
    
    printf("Please enter the room number (max 5 characters): ");
    scanf("%s", num);
    printf("Please enter the room price: ");
    scanf("%d", &price);
    
    // Check if room number already exists in system
    for(int i = 0; i < numRooms; i++) {
        if(strcmp(roomNumbers[i], num) == 0) {
            printf("Room number already exists. Please try again.\n");
            return;
        }
    }
    
    // Add room number and price to system
    strcpy(roomNumbers[numRooms], num);
    roomPrices[numRooms] = price;
    numRooms++;
    
    printf("Room added successfully!\n");
}

// Function to display all rooms in the system
void displayRooms(void) {
    printf("Room Number\tPrice\n");
    for(int i = 0; i < numRooms; i++) {
        printf("%s\t\t%d\n", roomNumbers[i], roomPrices[i]);
    }
}

// Function to search for a room in the system
void searchRooms(void) {
    char num[6];
    
    printf("Please enter the room number to search for: ");
    scanf("%s", num);
    
    // Search for room number in system
    for(int i = 0; i < numRooms; i++) {
        if(strcmp(roomNumbers[i], num) == 0) {
            printf("Room found!\n");
            printf("Room Number\tPrice\n");
            printf("%s\t\t%d\n", roomNumbers[i], roomPrices[i]);
            return;
        }
    }
    
    // Room number not found
    printf("Room not found.\n");
}

// Function to delete a room from the system
void deleteRoom(void) {
    char num[6];
    int found = 0;
    
    printf("Please enter the room number to delete: ");
    scanf("%s", num);
    
    // Search for room number in system
    for(int i = 0; i < numRooms; i++) {
        if(strcmp(roomNumbers[i], num) == 0) {
            // Move all elements in array up by one
            for(int j = i; j < numRooms - 1; j++) {
                strcpy(roomNumbers[j], roomNumbers[j+1]);
                roomPrices[j] = roomPrices[j+1];
            }
            numRooms--;
            printf("Room deleted successfully!\n");
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Room not found. Please try again.\n");
    }
}