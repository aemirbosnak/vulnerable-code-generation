//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_ROOMS 50

typedef struct {
    int id;
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
} Customer;

typedef struct {
    int id;
    int type;
    int price;
    int availability;
} Room;

Customer customers[MAX_CUSTOMERS];
Room rooms[MAX_ROOMS];

int numCustomers = 0;
int numRooms = 0;

void addCustomer() {
    if (numCustomers == MAX_CUSTOMERS) {
        printf("Cannot add more customers. Maximum capacity reached.\n");
        return;
    }

    Customer customer;

    printf("Enter customer ID: ");
    scanf("%d", &customer.id);

    printf("Enter customer name: ");
    scanf("%s", customer.name);

    printf("Enter customer address: ");
    scanf("%s", customer.address);

    printf("Enter customer phone number: ");
    scanf("%s", customer.phone);

    printf("Enter customer email address: ");
    scanf("%s", customer.email);

    customers[numCustomers++] = customer;
}

void addRoom() {
    if (numRooms == MAX_ROOMS) {
        printf("Cannot add more rooms. Maximum capacity reached.\n");
        return;
    }

    Room room;

    printf("Enter room ID: ");
    scanf("%d", &room.id);

    printf("Enter room type (1 for single, 2 for double, 3 for suite): ");
    scanf("%d", &room.type);

    printf("Enter room price: ");
    scanf("%d", &room.price);

    printf("Enter room availability (1 for available, 0 for occupied): ");
    scanf("%d", &room.availability);

    rooms[numRooms++] = room;
}

void printCustomers() {
    printf("Customers:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%d %s %s %s %s\n", customers[i].id, customers[i].name, customers[i].address, customers[i].phone, customers[i].email);
    }
}

void printRooms() {
    printf("Rooms:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%d %d %d %d\n", rooms[i].id, rooms[i].type, rooms[i].price, rooms[i].availability);
    }
}

int main() {
    int choice;

    while (1) {
        printf("Hotel Management System\n");
        printf("1. Add Customer\n");
        printf("2. Add Room\n");
        printf("3. Print Customers\n");
        printf("4. Print Rooms\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                addRoom();
                break;
            case 3:
                printCustomers();
                break;
            case 4:
                printRooms();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid number between 1 and 5.\n");
        }
    }

    return 0;
}