//FormAI DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to display menu
void displayMenu() {
    printf("\n\nWELCOME TO THE C HOTEL MANAGEMENT SYSTEM\n\n");
    printf("1. Check-In\n");
    printf("2. Check-Out\n");
    printf("3. View Room Status\n");
    printf("4. Order Room Service\n");
    printf("5. Exit\n\n");
    printf("Please enter your choice: ");
}

// Function to handle check-in process
void checkIn() {
    printf("\nCHECK-IN\n\n");

    // Get guest details
    char name[30];
    int roomNumber;
    printf("Please enter your name: ");
    scanf("%s", &name);
    printf("Please enter the room number you would like to check-in to: ");
    scanf("%d", &roomNumber);

    // Allocate room to guest
    printf("\nWelcome, %s! You have been allocated Room %d. Enjoy your stay!\n", name, roomNumber);
}

// Function to handle check-out process
void checkOut() {
    printf("\nCHECK-OUT\n\n");

    // Get guest details
    char name[30];
    int roomNumber;
    printf("Please enter your name: ");
    scanf("%s", &name);
    printf("Please enter your room number: ");
    scanf("%d", &roomNumber);

    // Calculate bill
    int nights;
    printf("How many nights did you stay? ");
    scanf("%d", &nights);
    int bill = nights * 100;

    // Print bill
    printf("\nThank you for staying with us, %s! Your bill for Room %d is $%d. We hope to see you again soon!\n", name, roomNumber, bill);
}

// Function to view room status
void viewRoomStatus() {
    printf("\nVIEW ROOM STATUS\n\n");

    // Print room status
    printf("Room 101 - Available\n");
    printf("Room 102 - Occupied\n");
    printf("Room 103 - Available\n\n");
}

// Function to order room service
void orderRoomService() {
    printf("\nORDER ROOM SERVICE\n\n");

    // Print menu
    printf("1. Hamburger - $10\n");
    printf("2. Pizza - $12\n");
    printf("3. Sandwich - $8\n\n");

    // Get order
    int order;
    printf("Please enter the number of the item you would like to order: ");
    scanf("%d", &order);

    // Calculate bill
    int bill;
    switch(order) {
        case 1:
            bill = 10;
            break;
        case 2:
            bill = 12;
            break;
        case 3:
            bill = 8;
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    // Print confirmation and bill
    printf("\nThank you for ordering. Your bill is $%d.\n", bill);
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkIn();
                break;
            case 2:
                checkOut();
                break;
            case 3:
                viewRoomStatus();
                break;
            case 4:
                orderRoomService();
                break;
            case 5:
                printf("\nThank you for using the C Hotel Management System!\n\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    } while(1);

    return 0;
}