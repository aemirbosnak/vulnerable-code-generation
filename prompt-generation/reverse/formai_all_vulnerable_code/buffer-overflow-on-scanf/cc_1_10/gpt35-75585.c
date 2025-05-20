//FormAI DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include<stdio.h>
#include<string.h>

#define MAX_ROOMS 50

//Structure for Room
typedef struct {
    int roomNumber;
    char occupantName[30];
    int occupancyStatus;
} Room;

//Function prototypes
void addRoom(Room rooms[], int *numRooms);
void removeRoom(Room rooms[], int *numRooms);
void displayRooms(Room rooms[], int numRooms);
void checkIn(Room rooms[], int numRooms);
void checkOut(Room rooms[], int numRooms);

int main() {
    Room rooms[MAX_ROOMS];
    int numRooms = 0, option;

    //Menu driven code
    do {
        printf("\n-- Hotel Management System --\n");
        printf("1. Add Room\n");
        printf("2. Remove Room\n");
        printf("3. Display Rooms\n");
        printf("4. Check In\n");
        printf("5. Check Out\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: //Add Room
                addRoom(rooms, &numRooms);
                break;
            case 2: //Remove Room
                removeRoom(rooms, &numRooms);
                break;
            case 3: //Display Rooms
                displayRooms(rooms, numRooms);
                break;
            case 4: //Check In
                checkIn(rooms, numRooms);
                break;
            case 5: //Check Out
                checkOut(rooms, numRooms);
                break;
            case 6: //Exit
                printf("\nExiting Hotel Management System...\n");
                break;
            default:
                printf("\nInvalid option. Please enter a valid option.\n");
                break;
        }
    } while(option != 6);

    return 0;
}

//Function to add a room
void addRoom(Room rooms[], int *numRooms) {
    int i, roomNumber;

    //Checking if maximum number of rooms are already present
    if(*numRooms == MAX_ROOMS) {
        printf("\nMaximum limit of rooms reached.\n");
        return;
    }

    //Checking if room already exists
    printf("\nEnter room number: ");
    scanf("%d", &roomNumber);
    for(i=0; i<*numRooms; i++) {
        if(roomNumber == rooms[i].roomNumber) {
            printf("\nRoom already exists.\n");
            return;
        }
    }

    //Adding new room
    rooms[*numRooms].roomNumber = roomNumber;
    strcpy(rooms[*numRooms].occupantName, "Not Occupied");
    rooms[*numRooms].occupancyStatus = 0;
    printf("\nRoom added successfully.\n");
    (*numRooms)++;
}

//Function to remove a room
void removeRoom(Room rooms[], int *numRooms) {
    int i, j, roomNumber, flag=0;

    //Checking if no rooms are present
    if(*numRooms == 0) {
        printf("\nNo rooms present.\n");
        return;
    }

    //Checking if room exists
    printf("\nEnter room number: ");
    scanf("%d", &roomNumber);
    for(i=0; i<*numRooms; i++) {
        if(roomNumber == rooms[i].roomNumber) {
            flag = 1;
            break;
        }
    }
    if(!flag) {
        printf("\nRoom does not exist.\n");
        return;
    }

    //Removing the room
    for(j=i+1; j<*numRooms; j++) {
        rooms[j-1].roomNumber = rooms[j].roomNumber;
        strcpy(rooms[j-1].occupantName, rooms[j].occupantName);
        rooms[j-1].occupancyStatus = rooms[j].occupancyStatus;
    }
    (*numRooms)--;
    printf("\nRoom removed successfully.\n");
}

//Function to display all rooms
void displayRooms(Room rooms[], int numRooms) {
    int i;

    //Checking if no rooms are present
    if(numRooms == 0) {
        printf("\nNo rooms present.\n");
        return;
    }

    //Displaying all rooms
    for(i=0; i<numRooms; i++) {
        printf("\nRoom Number: %d", rooms[i].roomNumber);
        printf("\nOccupant Name: %s", rooms[i].occupantName);
        printf("\nOccupancy Status: %d", rooms[i].occupancyStatus);
        printf("\n\n");
    }
}

//Function to check in a room
void checkIn(Room rooms[], int numRooms) {
    int i, roomNumber;

    //Checking if no rooms are present
    if(numRooms == 0) {
        printf("\nNo rooms present.\n");
        return;
    }

    //Checking if room already occupied
    printf("\nEnter room number: ");
    scanf("%d", &roomNumber);
    for(i=0; i<numRooms; i++) {
        if(roomNumber == rooms[i].roomNumber) {
            if(rooms[i].occupancyStatus == 1) {
                printf("\nRoom already occupied.\n");
                return;
            }
            printf("\nEnter occupant name: ");
            scanf("%s", rooms[i].occupantName);
            rooms[i].occupancyStatus = 1;
            printf("\nRoom checked in successfully.\n");
            return;
        }
    }
    printf("\nRoom does not exist.\n");
}

//Function to check out a room
void checkOut(Room rooms[], int numRooms) {
    int i, roomNumber;

    //Checking if no rooms are present
    if(numRooms == 0) {
        printf("\nNo rooms present.\n");
        return;
    }

    //Checking if room already vacant
    printf("\nEnter room number: ");
    scanf("%d", &roomNumber);
    for(i=0; i<numRooms; i++) {
        if(roomNumber == rooms[i].roomNumber) {
            if(rooms[i].occupancyStatus == 0) {
                printf("\nRoom already vacant.\n");
                return;
            }
            strcpy(rooms[i].occupantName, "Not Occupied");
            rooms[i].occupancyStatus = 0;
            printf("\nRoom checked out successfully.\n");
            return;
        }
    }
    printf("\nRoom does not exist.\n");
}