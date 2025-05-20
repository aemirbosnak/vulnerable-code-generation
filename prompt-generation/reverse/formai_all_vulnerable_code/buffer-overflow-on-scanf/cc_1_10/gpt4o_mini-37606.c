//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_ROOMS 50

typedef struct {
    int roomNumber;
    char roomType[30];
    float price;
    int isOccupied;
} Room;

typedef struct {
    int customerId;
    char name[50];
    int roomNumber;
} Customer;

Room rooms[MAX_ROOMS];
Customer customers[MAX_CUSTOMERS];
int roomCount = 0;
int customerCount = 0;

void addRoom() {
    if (roomCount >= MAX_ROOMS) {
        printf("Cannot add more rooms.\n");
        return;
    }
    printf("Enter room number: ");
    scanf("%d", &rooms[roomCount].roomNumber);
    printf("Enter room type: ");
    scanf("%s", rooms[roomCount].roomType);
    printf("Enter room price: ");
    scanf("%f", &rooms[roomCount].price);
    rooms[roomCount].isOccupied = 0;
    roomCount++;
    printf("Room added successfully!\n");
}

void viewRooms() {
    printf("Room Number\tType\tPrice\tOccupied\n");
    for (int i = 0; i < roomCount; i++) {
        printf("%d\t\t%s\t%.2f\t%s\n", 
            rooms[i].roomNumber, 
            rooms[i].roomType, 
            rooms[i].price, 
            rooms[i].isOccupied ? "Yes" : "No");
    }
}

void bookRoom() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Cannot add more customers.\n");
        return;
    }
    int roomNumber;
    printf("Enter room number to book: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (rooms[i].isOccupied) {
                printf("Room is already occupied!\n");
                return;
            }
            customers[customerCount].customerId = customerCount + 1;
            printf("Enter your name: ");
            scanf("%s", customers[customerCount].name);
            customers[customerCount].roomNumber = roomNumber;
            rooms[i].isOccupied = 1;
            customerCount++;
            printf("Room booked successfully, Customer ID: %d\n", customers[customerCount - 1].customerId);
            return;
        }
    }
    printf("Room not found!\n");
}

void checkOut() {
    int customerId;
    printf("Enter customer ID for checkout: ");
    scanf("%d", &customerId);
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].customerId == customerId) {
            for (int j = 0; j < roomCount; j++) {
                if (rooms[j].roomNumber == customers[i].roomNumber) {
                    rooms[j].isOccupied = 0;
                    printf("Check out successful for Customer ID: %d\n", customerId);
                    // Shift customers to maintain order
                    for (int k = i; k < customerCount - 1; k++) {
                        customers[k] = customers[k + 1];
                    }
                    customerCount--;
                    return;
                }
            }
        }
    }
    printf("Customer ID not found!\n");
}

void displayMenu() {
    printf("\n---- Hotel Management System ----\n");
    printf("1. Add Room\n");
    printf("2. View Rooms\n");
    printf("3. Book Room\n");
    printf("4. Check Out\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
            case 1: addRoom(); break;
            case 2: viewRooms(); break;
            case 3: bookRoom(); break;
            case 4: checkOut(); break;
            case 5: 
                printf("Exiting the system.\n");
                exit(0);
            default: 
                printf("Invalid option. Please select again.\n");
        }
    }
    return 0;
}