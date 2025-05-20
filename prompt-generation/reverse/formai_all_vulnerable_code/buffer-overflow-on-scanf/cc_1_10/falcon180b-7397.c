//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROOMS 100
#define MAX_ROOM_TYPES 10
#define MAX_CUSTOMERS 1000
#define MAX_BOOKINGS 10000
#define MAX_STAFF 100

typedef struct {
    char name[50];
    int age;
    char address[100];
    int phone;
} Customer;

typedef struct {
    char name[50];
    int age;
    char address[100];
    int phone;
    int salary;
} Staff;

typedef struct {
    int roomNumber;
    int roomType;
    int price;
    int availability;
    int customerID;
} Room;

typedef struct {
    char name[50];
    int price;
    int availability;
} RoomType;

typedef struct {
    int bookingID;
    int customerID;
    int checkInDate;
    int checkOutDate;
    int roomNumber;
    int totalPrice;
} Booking;

int main() {
    int choice;
    while(1) {
        printf("Hotel Management System\n");
        printf("1. Add customer\n");
        printf("2. Add staff\n");
        printf("3. Add room type\n");
        printf("4. Add room\n");
        printf("5. Make booking\n");
        printf("6. View bookings\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Add customer
                break;
            case 2:
                // Add staff
                break;
            case 3:
                // Add room type
                break;
            case 4:
                // Add room
                break;
            case 5:
                // Make booking
                break;
            case 6:
                // View bookings
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}