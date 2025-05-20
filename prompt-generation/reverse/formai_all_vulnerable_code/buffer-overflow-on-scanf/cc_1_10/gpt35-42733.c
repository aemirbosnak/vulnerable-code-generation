//FormAI DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for rooms
typedef struct Room {
    int roomNumber;
    char guestName[50];
    int numOfGuests;
    char dateCheckIn[15];
    char dateCheckOut[15];
    float price;
} Room;

// Function to add new room with its details
void addRoom(Room *roomList, int *numOfRooms) {
    printf("Enter Room Number: ");
    scanf("%d", &roomList[*numOfRooms].roomNumber);

    printf("Enter Guest Name: ");
    scanf("%s", roomList[*numOfRooms].guestName);

    printf("Enter Number of Guests: ");
    scanf("%d", &roomList[*numOfRooms].numOfGuests);

    printf("Enter Check-In Date (DD/MM/YYYY): ");
    scanf("%s", roomList[*numOfRooms].dateCheckIn);

    printf("Enter Check-Out Date (DD/MM/YYYY): ");
    scanf("%s", roomList[*numOfRooms].dateCheckOut);

    printf("Enter Room Price: ");
    scanf("%f", &roomList[*numOfRooms].price);

    printf("\nRoom Added Successfully!\n");

    (*numOfRooms)++;
}

// Function to display all rooms with their details
void displayRooms(Room *roomList, int numOfRooms) {
    printf("\n================ ALL ROOMS ================\n");
    printf("Room No.\tGuest Name\tGuests\tCheck-In Date\t\tCheck-Out Date\t\tPrice\n");
    for (int i = 0; i < numOfRooms; i++) {
        printf("%d\t\t%s\t\t%d\t%s\t\t%s\t\t%.2f\n", roomList[i].roomNumber, roomList[i].guestName,
               roomList[i].numOfGuests, roomList[i].dateCheckIn, roomList[i].dateCheckOut, roomList[i].price);
    }
    printf("===========================================\n");
}

// Function to search for room by its number and display its details
void searchRoom(Room *roomList, int numOfRooms) {
    int roomNo;
    printf("Enter Room Number: ");
    scanf("%d", &roomNo);

    for (int i = 0; i < numOfRooms; i++) {
        if (roomList[i].roomNumber == roomNo) {
            printf("\n================ ROOM DETAILS ================\n");
            printf("Room No.\tGuest Name\tGuests\tCheck-In Date\t\tCheck-Out Date\t\tPrice\n");
            printf("%d\t\t%s\t\t%d\t%s\t\t%s\t\t%.2f\n", roomList[i].roomNumber, roomList[i].guestName,
                   roomList[i].numOfGuests, roomList[i].dateCheckIn, roomList[i].dateCheckOut, roomList[i].price);
            printf("==============================================\n");
            return;
        }
    }

    printf("\nRoom Not Found!\n");
}

// Function to display the total price of all rooms
void totalRevenue(Room *roomList, int numOfRooms) {
    float totalPrice = 0.0;
    for (int i = 0; i < numOfRooms; i++) {
        totalPrice += roomList[i].price;
    }

    printf("\nTotal Revenue: %.2f\n", totalPrice);
}

int main() {
    Room roomList[20];
    int numOfRooms = 0;
    int choice;

    printf("Welcome to C Hotel Management System\n");

    do {
        printf("\n================ MENU ==================\n");
        printf("1- Add Room\n2- Display All Rooms\n3- Search Room\n4- Total Revenue\n5- Exit\n");
        printf("========================================\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRoom(roomList, &numOfRooms);
                break;
            case 2:
                displayRooms(roomList, numOfRooms);
                break;
            case 3:
                searchRoom(roomList, numOfRooms);
                break;
            case 4:
                totalRevenue(roomList, numOfRooms);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid Choice! Please Try Again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}