//FormAI DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    int daysStayed;
} Room;

void clearScreen() {
    //system specific command to clear screen
    system("clear"); //for unix/linux based systems
    system("cls"); //for windows based systems
}

void displayMainMenu() {
    printf("\n=============== HOTEL MANAGEMENT SYSTEM ===============\n");
    printf("1. Check-in a guest\n");
    printf("2. Display all occupied rooms\n");
    printf("3. Display all unoccupied rooms\n");
    printf("4. Check-out a guest\n");
    printf("5. Quit\n");
    printf("=======================================================\n");
}

void displayAllRooms(Room rooms[]) {
    clearScreen();
    printf("\n============= ALL OCCUPIED ROOMS ==============\n");
    printf("Room No.\tGuest Name\tDays Stayed\n");
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].roomNumber != 0) {
            printf("%d\t\t%s\t\t%d\n", rooms[i].roomNumber, rooms[i].guestName, rooms[i].daysStayed);
        }
    }
    printf("===============================================\n");
}

void displayVacantRooms(Room rooms[]) {
    clearScreen();
    printf("\n============= ALL VACANT ROOMS ==============\n");
    printf("Room No.\n");
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].roomNumber == 0) {
            printf("%d\n", i+1);
        }
    }
    printf("==============================================\n");

}

void checkInGuest(Room rooms[]) {
    clearScreen();
    char name[MAX_NAME_LENGTH];
    int roomNumber, daysStayed;
    printf("\n=============== CHECK-IN ===============\n");
    printf("Enter guest name: ");
    scanf("%s", name);
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    printf("Enter days stayed: ");
    scanf("%d", &daysStayed);
    if(rooms[roomNumber-1].roomNumber == 0) {
        rooms[roomNumber-1].roomNumber = roomNumber;
        strcpy(rooms[roomNumber-1].guestName, name);
        rooms[roomNumber-1].daysStayed = daysStayed;
        printf("\nCHECK-IN SUCCESSFUL\n");
    } else {
        printf("\nROOM IS ALREADY OCCUPIED\n");
    }
}

void checkOutGuest(Room rooms[]) {
    clearScreen();
    int roomNumber;
    printf("\n=============== CHECK-OUT ===============\n");
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    if(rooms[roomNumber-1].roomNumber != 0) {
        rooms[roomNumber-1].roomNumber = 0;
        memset(rooms[roomNumber-1].guestName, 0, MAX_NAME_LENGTH);
        rooms[roomNumber-1].daysStayed = 0;
        printf("\nCHECK-OUT SUCCESSFUL\n");
    } else {
        printf("\nROOM IS ALREADY VACANT\n");
    }
}

int main() {
    Room rooms[MAX_ROOMS] = {{1, "Guest 1", 2},
                              {0, "", 0},
                              {3, "Guest 3", 1},
                              {0, "", 0},
                              {0, "", 0},
                              {6, "Guest 6", 3}, 
                              {0, "", 0},
                              {8, "Guest 8", 5},
                              {0, "", 0},
                              {10, "Guest 10", 7}};
    int choice;
    do {
        displayMainMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                checkInGuest(rooms);
                break;
            case 2:
                displayAllRooms(rooms);
                break;
            case 3:
                displayVacantRooms(rooms);
                break;
            case 4:
                checkOutGuest(rooms);
                break;
            case 5:
                printf("\nTHANK YOU FOR USING OUR SYSTEM\n");
                break;
            default:
                printf("\nINVALID CHOICE, PLEASE TRY AGAIN\n");
        }
    } while(choice != 5);
    return 0;
}