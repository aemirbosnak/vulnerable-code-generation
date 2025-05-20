//FormAI DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definitions
typedef struct {
    int roomNo;
    char type[20];
    float price;
    int availability;
} Room;

typedef struct {
    int customerID;
    char name[50];
    char email[50];
    char gender[10];
    int age;
    int roomNo;
    char checkInDate[20];
    char checkOutDate[20];
} Customer;

// Global variables
Room rooms[50];
Customer customers[50];
int roomCount = 0, customerCount = 0;

// Function prototypes
void addRoom();
void displayRooms();
void addCustomer();
void displayCustomers();

int main() {
    int choice;
    printf("Welcome to C Hotel Management System\n");
    do {
        printf("\n1. Add Room\n2. Display Rooms\n3. Add Customer\n4. Display Customers\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addRoom(); break;
            case 2: displayRooms(); break;
            case 3: addCustomer(); break;
            case 4: displayCustomers(); break;
            case 5: printf("Thank you for using C Hotel Management System\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}

void addRoom() {
    Room room;
    printf("Enter Room No: ");
    scanf("%d", &room.roomNo);
    printf("Enter Room Type: ");
    scanf("%s", room.type);
    printf("Enter Room Price: ");
    scanf("%f", &room.price);
    room.availability = 1;
    rooms[roomCount++] = room;
    printf("Room added successfully\n");
}

void displayRooms() {
    printf("Room No\tType\tPrice\tAvailability\n");
    for (int i = 0; i < roomCount; i++) {
        printf("%d\t%s\t%.2f\t%s\n", rooms[i].roomNo, rooms[i].type, rooms[i].price, (rooms[i].availability ? "Available" : "Not Available"));
    }
}

void addCustomer() {
    Customer customer;
    printf("Enter Customer Name: ");
    scanf("%s", customer.name);
    printf("Enter Customer Email: ");
    scanf("%s", customer.email);
    printf("Enter Customer Gender: ");
    scanf("%s", customer.gender);
    printf("Enter Customer Age: ");
    scanf("%d", &customer.age);
    printf("Enter Room No: ");
    scanf("%d", &customer.roomNo);
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNo == customer.roomNo) {
            if (rooms[i].availability) {
                rooms[i].availability = 0;
                break;
            } else {
                printf("Room not available\n");
                return;
            }
        }
    }
    printf("Enter Check-in Date: ");
    scanf("%s", customer.checkInDate);
    printf("Enter Check-out Date: ");
    scanf("%s", customer.checkOutDate);
    customer.customerID = 1000 + customerCount;
    customers[customerCount++] = customer;
    printf("Customer added successfully\n");
}

void displayCustomers() {
    printf("Customer ID\tName\tEmail\tGender\tAge\tRoom No\tCheck-in Date\tCheck-out Date\n");
    for (int i = 0; i < customerCount; i++) {
        printf("%d\t%s\t%s\t%s\t%d\t%d\t%s\t%s\n", customers[i].customerID, customers[i].name, customers[i].email, customers[i].gender, customers[i].age, customers[i].roomNo, customers[i].checkInDate, customers[i].checkOutDate);
    }
}