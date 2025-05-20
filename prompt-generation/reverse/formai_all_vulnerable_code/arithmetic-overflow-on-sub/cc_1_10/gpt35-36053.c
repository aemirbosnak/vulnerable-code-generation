//FormAI DATASET v1.0 Category: Hotel Management System ; Style: calm
#include<stdio.h>
#include<string.h>

// Global array to store hotel room information
int roomOccupied[100] = {0};
int roomCost[100] = {0};

// Function to display menu options
void displayMenu() {
    printf("\n*****C Hotel Management System*****\n");
    printf("1. Book a Room\n");
    printf("2. View Room Status\n");
    printf("3. Check Out\n");
    printf("4. Display Occupancy Rate\n");
    printf("5. Exit\n");
}

// Function to book a room
void bookRoom() {
    int roomNum;
    printf("\nEnter room number you want to book: ");
    scanf("%d", &roomNum);

    if(roomOccupied[roomNum - 1] == 0) {
        printf("Enter cost of the room per day: ");
        scanf("%d", &roomCost[roomNum - 1]);
        roomOccupied[roomNum - 1] = 1;
        printf("Room booked successfully!");
    } else {
        printf("Room is already occupied.");
    }
}

// Function to view room status
void viewRoomStatus() {
    printf("\n*****Room Status*****\n");
    for(int i=0; i<100; i++) {
        if(roomOccupied[i] == 1) {
            printf("Room %d is occupied with cost %d per day.\n", i+1, roomCost[i]);
        } else {
            printf("Room %d is vacant.\n", i+1);
        }
    }
}

// Function to check-out
void checkOut() {
    int roomNum;
    printf("\nEnter room number you want to check out: ");
    scanf("%d", &roomNum);

    if(roomOccupied[roomNum - 1] == 1) {
        int days;
        printf("Enter number of days stayed: ");
        scanf("%d", &days);
        int totalCost = days * roomCost[roomNum - 1];
        roomOccupied[roomNum - 1] = 0;
        printf("Thank you for staying with us. Your total bill is %d.", totalCost);
    } else {
        printf("Room is already vacant.");
    }
}

// Function to display occupancy rate
void displayOccupancyRate() {
    int count = 0;
    for(int i=0; i<100; i++) {
        if(roomOccupied[i] == 1) {
            count++;
        }
    }
    float occupancyRate = (float)count / 100 * 100;
    printf("\nThe hotel's occupancy rate is %.2f%%\n", occupancyRate);
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                bookRoom();
                break;
            case 2:
                viewRoomStatus();
                break;
            case 3:
                checkOut();
                break;
            case 4:
                displayOccupancyRate();
                break;
            case 5:
                printf("Thank you for using C Hotel Management System.");
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    } while(choice != 5);

    return 0;
}