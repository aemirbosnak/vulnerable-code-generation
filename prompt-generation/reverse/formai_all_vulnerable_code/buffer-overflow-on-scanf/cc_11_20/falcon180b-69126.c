//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100
#define MAX_RESERVATIONS 100
#define MAX_ROOM_TYPES 10

typedef struct {
    char name[50];
    char address[100];
    char phone[15];
} Guest;

typedef struct {
    int id;
    char name[50];
    float price;
    int availability;
} Room;

typedef struct {
    int id;
    char name[50];
    int price;
} RoomType;

typedef struct {
    int id;
    Guest guest;
    Room room;
    int checkInDate;
    int checkOutDate;
    int status;
} Reservation;

typedef struct {
    int id;
    char name[50];
    int capacity;
} Restaurant;

typedef struct {
    int id;
    char name[50];
    int capacity;
} ConferenceRoom;

int main() {
    int choice;
    while (1) {
        printf("\nWelcome to Hotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. View Guest\n");
        printf("3. Add Room\n");
        printf("4. View Room\n");
        printf("5. Add Reservation\n");
        printf("6. View Reservation\n");
        printf("7. Add Restaurant\n");
        printf("8. View Restaurant\n");
        printf("9. Add Conference Room\n");
        printf("10. View Conference Room\n");
        printf("11. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Add Guest
                break;
            case 2:
                // View Guest
                break;
            case 3:
                // Add Room
                break;
            case 4:
                // View Room
                break;
            case 5:
                // Add Reservation
                break;
            case 6:
                // View Reservation
                break;
            case 7:
                // Add Restaurant
                break;
            case 8:
                // View Restaurant
                break;
            case 9:
                // Add Conference Room
                break;
            case 10:
                // View Conference Room
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}