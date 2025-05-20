//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_CUSTOMERS 100
#define MAX_BOOKINGS 1000

typedef struct {
    int roomNumber;
    char customerName[50];
    int bookingID;
} Booking;

typedef struct {
    int id;
    char name[50];
    char address[100];
    char phoneNumber[20];
} Customer;

typedef struct {
    int id;
    char type[50];
    int price;
} Room;

int main() {
    Customer customers[MAX_CUSTOMERS];
    Room rooms[MAX_ROOMS];
    Booking bookings[MAX_BOOKINGS];

    int numCustomers = 0, numRooms = 0, numBookings = 0;

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add Customer\n2. Add Room\n3. Make Booking\n4. View Bookings\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer details:\n");
                scanf("%s %s %s %s", customers[numCustomers].name, customers[numCustomers].address, customers[numCustomers].phoneNumber, "");
                numCustomers++;
                break;
            case 2:
                printf("Enter room details:\n");
                scanf("%s %d", rooms[numRooms].type, &rooms[numRooms].price);
                numRooms++;
                break;
            case 3:
                printf("Enter customer name:\n");
                scanf("%s", bookings[numBookings].customerName);
                printf("Enter room number:\n");
                scanf("%d", &bookings[numBookings].roomNumber);
                bookings[numBookings].bookingID = numBookings + 1;
                numBookings++;
                break;
            case 4:
                printf("Bookings:\n");
                for (int i = 0; i < numBookings; i++) {
                    printf("%d. %s - Room %d\n", bookings[i].bookingID, bookings[i].customerName, bookings[i].roomNumber);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}