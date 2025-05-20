//FormAI DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

/* define structure for room details */
typedef struct room {
    int roomNumber;
    char roomType[20];
    float roomRate;
    char guestName[50];
    int occupied;
} Room;

/* function prototypes */
int findAvailableRoom(Room[], int);
void checkIn(Room[], int);
void checkOut(Room[], int);
void displayAllRooms(Room[], int);
void displayOccupiedRooms(Room[], int);
void displayAvailableRooms(Room[], int);

int main() {
    int numRooms, i, choice;
    Room *rooms;

    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &numRooms);

    /* allocate memory for room details */
    rooms = (Room *) malloc(numRooms * sizeof(Room));

    /* initialize all rooms to be available */
    for (i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].occupied = 0;
    }

    do {
        /* display menu options */
        printf("\nHotel Management System:\n");
        printf("1. Check-in\n");
        printf("2. Check-out\n");
        printf("3. Display all rooms\n");
        printf("4. Display occupied rooms\n");
        printf("5. Display available rooms\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkIn(rooms, numRooms);
                break;
            case 2:
                checkOut(rooms, numRooms);
                break;
            case 3:
                displayAllRooms(rooms, numRooms);
                break;
            case 4:
                displayOccupiedRooms(rooms, numRooms);
                break;
            case 5:
                displayAvailableRooms(rooms, numRooms);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    free(rooms); /* free memory */

    return 0;
}

/* function to find available room */
int findAvailableRoom(Room rooms[], int numRooms) {
    int i;

    for (i = 0; i < numRooms; i++) {
        if (!rooms[i].occupied) {
            return i;
        }
    }

    return -1; /* return -1 if no available room found */
}

/* function to check-in a guest */
void checkIn(Room rooms[], int numRooms) {
    int roomIndex = findAvailableRoom(rooms, numRooms);

    if (roomIndex == -1) {
        printf("No available room!\n");
        return;
    }

    /* set room details */
    printf("Room number: %d\n", rooms[roomIndex].roomNumber);
    printf("Enter room type: ");
    scanf("%s", rooms[roomIndex].roomType);
    printf("Enter room rate: ");
    scanf("%f", &rooms[roomIndex].roomRate);
    printf("Enter guest name: ");
    scanf("%s", rooms[roomIndex].guestName);

    rooms[roomIndex].occupied = 1;
    printf("Guest checked in successfully!\n");
}

/* function to check-out a guest */
void checkOut(Room rooms[], int numRooms) {
    int i, roomNum;

    printf("Enter room number to check out: ");
    scanf("%d", &roomNum);

    for (i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNum && rooms[i].occupied == 1) {
            /* reset room details */
            printf("Guest name: %s\n", rooms[i].guestName);
            rooms[i].roomType[0] = '\0';
            rooms[i].roomRate = 0.0;
            rooms[i].guestName[0] = '\0';
            rooms[i].occupied = 0;
            printf("Guest checked out successfully!\n");
            return;
        }
    }

    printf("Room not found or already vacant!\n");
}

/* function to display all rooms */
void displayAllRooms(Room rooms[], int numRooms) {
    int i;

    printf("Room\tType\t\tRate\tGuest\n");

    for (i = 0; i < numRooms; i++) {
        printf("%d\t%s\t%s\t", rooms[i].roomNumber, rooms[i].roomType, rooms[i].occupied ? "occupied" : "available");
        if (rooms[i].occupied) {
            printf("%s (%.2f)\n", rooms[i].guestName, rooms[i].roomRate);
        }
        else {
            printf("-\n");
        }
    }
}

/* function to display all occupied rooms */
void displayOccupiedRooms(Room rooms[], int numRooms) {
    int i, count = 0;

    printf("Occupied rooms:\n");

    for (i = 0; i < numRooms; i++) {
        if (rooms[i].occupied) {
            printf("%d\t%s\t%.2f\t%s\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].roomRate, rooms[i].guestName);
            count++;
        }
    }

    if (count == 0) {
        printf("No occupied rooms!\n");
    }
}

/* function to display all available rooms */
void displayAvailableRooms(Room rooms[], int numRooms) {
    int i, count = 0;

    printf("Available rooms:\n");

    for (i = 0; i < numRooms; i++) {
        if (!rooms[i].occupied) {
            printf("%d\t%s\n", rooms[i].roomNumber, rooms[i].roomType);
            count++;
        }
    }

    if (count == 0) {
        printf("No available rooms!\n");
    }
}