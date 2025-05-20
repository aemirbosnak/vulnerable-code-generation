//FormAI DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct staff {
    char name[50];
    char position[20];
    int empID;
    float salary;
} Staff;

typedef struct room {
    int roomNumber;
    char type[20];
    int numOfBeds;
    float price;
    int isBooked;
    char guestName[50];
} Room;

int staffCount = 0;
int roomCount = 0;

Staff* staffArr;
Room* roomArr;

void printMenu() {
    printf("------------------------\n");
    printf("Hotel Management System\n");
    printf("------------------------\n");
    printf("1. Add staff\n");
    printf("2. Add room\n");
    printf("3. Book room\n");
    printf("4. Check out\n");
    printf("5. Print staff details\n");
    printf("6. Print room details\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void addStaff() {
    staffCount++;
    staffArr = (Staff*) realloc(staffArr, staffCount * sizeof(Staff));

    printf("Enter staff name: ");
    scanf("%s", staffArr[staffCount-1].name);

    printf("Enter staff position: ");
    scanf("%s", staffArr[staffCount-1].position);

    printf("Enter staff employee ID: ");
    scanf("%d", &staffArr[staffCount-1].empID);

    printf("Enter staff salary: ");
    scanf("%f", &staffArr[staffCount-1].salary);

    printf("Staff added successfully!\n");
}

void addRoom() {
    roomCount++;
    roomArr = (Room*) realloc(roomArr, roomCount * sizeof(Room));

    printf("Enter room number: ");
    scanf("%d", &roomArr[roomCount-1].roomNumber);

    printf("Enter room type: ");
    scanf("%s", roomArr[roomCount-1].type);

    printf("Enter number of beds in room: ");
    scanf("%d", &roomArr[roomCount-1].numOfBeds);

    printf("Enter room price: ");
    scanf("%f", &roomArr[roomCount-1].price);

    roomArr[roomCount-1].isBooked = 0;

    printf("Room added successfully!\n");
}

void bookRoom() {
    int roomNumber;
    printf("Enter room number to book: ");
    scanf("%d", &roomNumber);

    int i;
    for (i = 0; i < roomCount; i++) {
        if (roomArr[i].roomNumber == roomNumber) {
            if (roomArr[i].isBooked == 0) {
                roomArr[i].isBooked = 1;
                printf("Enter guest name: ");
                scanf("%s", roomArr[i].guestName);
                printf("Room booked successfully!\n");
                return;
            } else {
                printf("Room is already booked!\n");
                return;
            }
        }
    }

    printf("Room not found!\n");
}

void checkOut() {
    int roomNumber;
    printf("Enter room number to check out: ");
    scanf("%d", &roomNumber);

    int i;
    for (i = 0; i < roomCount; i++) {
        if (roomArr[i].roomNumber == roomNumber) {
            if (roomArr[i].isBooked == 1) {
                roomArr[i].isBooked = 0;
                strcpy(roomArr[i].guestName, "");
                printf("Checked out successfully!\n");
                return;
            } else {
                printf("Room is not booked!\n");
                return;
            }
        }
    }

    printf("Room not found!\n");
}

void printStaff() {
    int i;
    for (i = 0; i < staffCount; i++) {
        printf("------------------------\n");
        printf("Staff name: %s\n", staffArr[i].name);
        printf("Staff position: %s\n", staffArr[i].position);
        printf("Staff employee ID: %d\n", staffArr[i].empID);
        printf("Staff salary: $%.2f\n", staffArr[i].salary);
    }
}

void printRooms() {
    int i;
    for (i = 0; i < roomCount; i++) {
        printf("------------------------\n");
        printf("Room number: %d\n", roomArr[i].roomNumber);
        printf("Room type: %s\n", roomArr[i].type);
        printf("Number of beds: %d\n", roomArr[i].numOfBeds);
        printf("Price per night: $%.2f\n", roomArr[i].price);
        if (roomArr[i].isBooked == 1) {
            printf("Room is booked by: %s\n", roomArr[i].guestName);
        } else {
            printf("Room is available\n");
        }
    }
}

int main() {
    staffArr = (Staff*) malloc(sizeof(Staff));
    roomArr = (Room*) malloc(sizeof(Room));

    int choice = 0;
    while (choice != 7) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStaff();
                break;
            case 2:
                addRoom();
                break;
            case 3:
                bookRoom();
                break;
            case 4:
                checkOut();
                break;
            case 5:
                printStaff();
                break;
            case 6:
                printRooms();
                break;
            case 7:
                printf("Thank you for using the Hotel Management System\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    free(staffArr);
    free(roomArr);

    return 0;
}