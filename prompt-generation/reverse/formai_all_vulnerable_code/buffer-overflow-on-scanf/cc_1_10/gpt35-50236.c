//FormAI DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for hotel room
typedef struct {
    int roomNum;
    int numBeds;
    int occupancy;
    float rate;
    char guestName[50];
} hotelRoom;

// Function to display menu and get user input
int getMenuChoice() {
    int choice;
    printf("Please select an option:\n");
    printf("1. Add new room\n");
    printf("2. Check in guest\n");
    printf("3. Check out guest\n");
    printf("4. View room occupancy\n");
    printf("5. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add new hotel room to array
void addNewRoom(hotelRoom *rooms, int *count) {
    int roomNum, numBeds;
    float rate;
    printf("Enter room number: ");
    scanf("%d", &roomNum);
    printf("Enter number of beds: ");
    scanf("%d", &numBeds);
    printf("Enter rate per night: ");
    scanf("%f", &rate);
    
    rooms[*count].roomNum = roomNum;
    rooms[*count].numBeds = numBeds;
    rooms[*count].occupancy = 0;
    rooms[*count].rate = rate;
    (*count)++;
    printf("Room added successfully!\n");
}

// Function to check guest into hotel room
void checkInGuest(hotelRoom *rooms, int count) {
    int roomNum;
    printf("Enter room number: ");
    scanf("%d", &roomNum);
    
    for (int i = 0; i < count; i++) {
        if (rooms[i].roomNum == roomNum) {
            if (rooms[i].occupancy == 1) {
                printf("Room is already occupied.\n");
            } else {
                printf("Enter guest name: ");
                scanf("%s", rooms[i].guestName);
                rooms[i].occupancy = 1;
                printf("Guest checked in successfully!\n");
            }
            return;
        }
    }
    printf("Room not found.\n");
}

// Function to check guest out of hotel room
void checkOutGuest(hotelRoom *rooms, int count) {
    int roomNum;
    printf("Enter room number: ");
    scanf("%d", &roomNum);
    
    for (int i = 0; i < count; i++) {
        if (rooms[i].roomNum == roomNum) {
            if (rooms[i].occupancy == 0) {
                printf("Room is not occupied.\n");
            } else {
                printf("Guest %s checked out of room %d.\n", rooms[i].guestName, rooms[i].roomNum);
                strcpy(rooms[i].guestName, "");
                rooms[i].occupancy = 0;
            }
            return;
        }
    }
    printf("Room not found.\n");
}

// Function to view hotel room occupancy
void viewRoomOccupancy(hotelRoom *rooms, int count) {
    printf("%-10s %-12s %-8s %-8s %s\n", "Room", "Beds", "Status", "Rate", "Guest Name");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-12d %-8s %-8.2f %s\n", rooms[i].roomNum, rooms[i].numBeds, rooms[i].occupancy == 1 ? "Occupied" : "Vacant", rooms[i].rate, rooms[i].guestName);
    }
}

int main() {
    hotelRoom rooms[50];
    int count = 0;
    int choice;
    do {
        choice = getMenuChoice();
        switch(choice) {
            case 1:
                addNewRoom(rooms, &count);
                break;
            case 2:
                checkInGuest(rooms, count);
                break;
            case 3:
                checkOutGuest(rooms, count);
                break;
            case 4:
                viewRoomOccupancy(rooms, count);
                break;
            case 5:
                printf("Thank you for using the hotel management system.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}