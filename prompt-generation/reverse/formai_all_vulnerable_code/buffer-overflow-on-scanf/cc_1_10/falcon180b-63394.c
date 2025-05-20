//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_ROOM_TYPES 10
#define MAX_STAFF 50
#define MAX_RESERVATIONS 100
#define MAX_RESTAURANT_ITEMS 50
#define MAX_RESTAURANT_ORDERS 100
#define MAX_ROOM_SERVICES 10

typedef struct {
    int roomNo;
    int guestID;
    int daysStayed;
    int totalCost;
} Reservation;

typedef struct {
    int roomTypeID;
    char roomTypeName[50];
    int noOfRooms;
    int basePrice;
} RoomType;

typedef struct {
    int staffID;
    char staffName[50];
    char staffPosition[50];
    int staffSalary;
} Staff;

typedef struct {
    int reservationID;
    Reservation reservation;
    Staff staff;
    int restaurantOrderID;
    int restaurantOrder[MAX_RESTAURANT_ITEMS];
    int noOfItems;
    int totalCost;
} Guest;

typedef struct {
    int serviceID;
    char serviceName[50];
    int cost;
} RoomService;

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
} GuestDetails;

typedef struct {
    int guestID;
    GuestDetails guestDetails;
    Reservation reservation;
    Staff staff;
    int noOfRoomServices;
    RoomService roomService[MAX_ROOM_SERVICES];
    int totalCost;
} Bill;

int main() {
    int choice;

    while(1) {
        printf("\nHOTEL MANAGEMENT SYSTEM\n");
        printf("1. Room Management\n");
        printf("2. Guest Management\n");
        printf("3. Staff Management\n");
        printf("4. Restaurant Management\n");
        printf("5. Room Service Management\n");
        printf("6. Generate Bill\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Room Management
                break;
            case 2:
                // Guest Management
                break;
            case 3:
                // Staff Management
                break;
            case 4:
                // Restaurant Management
                break;
            case 5:
                // Room Service Management
                break;
            case 6:
                // Generate Bill
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}