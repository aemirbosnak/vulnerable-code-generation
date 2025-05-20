//FormAI DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

struct Room {
    int roomNumber;
    char* guestName;
    int occupancyStatus;
    int nightsStayed;
    float roomRate;
};

void addNewGuest(struct Room *rooms, int numRooms);
void displayOccupancyStatus(struct Room *rooms, int numRooms);
void displayRevenue(struct Room *rooms, int numRooms);
void checkoutGuest(struct Room *rooms, int numRooms);

int main() {
    int numRooms;
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &numRooms);

    // allocate memory for rooms
    struct Room *rooms = malloc(numRooms * sizeof(struct Room));

    // initialize rooms
    for(int i = 0; i < numRooms; i++) {
        struct Room r = {i+1, NULL, 0, 0, 100.0}; // initialize with room rate of $100 per night
        rooms[i] = r;
    }

    int choice;
    do {
        printf("\n\n\n\n***********************************************************\n");
        printf("                       HOTEL MANAGEMENT SYSTEM             \n");
        printf("***********************************************************\n");
        printf("\n\n\n1. Add a new guest");
        printf("\n2. Display occupancy status");
        printf("\n3. Display revenue");
        printf("\n4. Checkout guest");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addNewGuest(rooms, numRooms); break;
            case 2: displayOccupancyStatus(rooms, numRooms); break;
            case 3: displayRevenue(rooms, numRooms); break;
            case 4: checkoutGuest(rooms, numRooms); break;
            case 5: printf("\nGoodbye!\n"); break;
            default: printf("\nInvalid choice. Please try again.\n"); break;
        }

    } while(choice != 5);

    // free memory for rooms
    free(rooms);

    return 0;
}

void addNewGuest(struct Room *rooms, int numRooms) {
    int roomNum;
    char name[100];
    int nights;

    // ask for room number
    printf("\nEnter room number: ");
    scanf("%d", &roomNum);
    if(roomNum < 1 || roomNum > numRooms) {
        printf("\nInvalid room number.\n");
        return;
    }

    // ask for guest name
    printf("\nEnter guest name: ");
    scanf("%s", name);

    // ask for number of nights stayed
    printf("\nEnter number of nights stayed: ");
    scanf("%d", &nights);

    // update room information
    rooms[roomNum-1].guestName = strdup(name);
    rooms[roomNum-1].occupancyStatus = 1;
    rooms[roomNum-1].nightsStayed = nights;
    printf("\nGuest added to room %d.\n", roomNum);
}

void displayOccupancyStatus(struct Room *rooms, int numRooms) {
    printf("\n\nROOM\tSTATUS\tGUEST NAME\tNIGHTS\tRATE/NIGHT\n");
    for(int i = 0; i < numRooms; i++) {
        printf("%d\t%d\t", rooms[i].roomNumber, rooms[i].occupancyStatus);
        if(rooms[i].guestName == NULL) {
            printf("\t\t");
        } else {
            printf("%s\t", rooms[i].guestName);
        }
        printf("%d\t$%.2f\n", rooms[i].nightsStayed, rooms[i].roomRate);
    }
}

void displayRevenue(struct Room *rooms, int numRooms) {
    float totalRevenue = 0.0;
    for(int i = 0; i < numRooms; i++) {
        if(rooms[i].occupancyStatus == 1) {
            totalRevenue += rooms[i].nightsStayed * rooms[i].roomRate;
        }
    }
    printf("\n\nTotal revenue: $%.2f\n", totalRevenue);
}

void checkoutGuest(struct Room *rooms, int numRooms) {
    int roomNum;
    // ask for room number
    printf("\nEnter room number: ");
    scanf("%d", &roomNum);
    if(roomNum < 1 || roomNum > numRooms) {
        printf("\nInvalid room number.\n");
        return;
    }

    struct Room r = {roomNum, NULL, 0, 0, 100.0};
    rooms[roomNum-1] = r; // reset room information
    printf("\nGuest in room %d has been checked out.\n", roomNum);
}