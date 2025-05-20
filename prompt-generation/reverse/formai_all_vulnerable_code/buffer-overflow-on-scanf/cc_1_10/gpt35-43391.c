//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ROOM {
    int roomId;
    char roomType[20];
    int price;
    char availability[5];
};

struct GUEST {
    int guestId;
    char guestName[50];
    int age;
    char gender[10];
    char address[100];
    char phone[15];
};

struct RESERVATION {
    int resId;
    int guestId;
    int roomId;
    char checkIn[20];
    char checkOut[20];
};

struct ROOM rooms[10] = {{1, "Single Bed", 5000, "Yes"},
                        {2, "Single Bed", 5000, "Yes"},
                        {3, "Double Bed", 8000, "Yes"},
                        {4, "Double Bed", 8000, "Yes"},
                        {5, "Suite", 12000, "Yes"},
                        {6, "Suite", 12000, "Yes"},
                        {7, "Single Bed", 5000, "Yes"},
                        {8, "Double Bed", 8000, "Yes"},
                        {9, "Deluxe", 15000, "Yes"},
                        {10, "Deluxe", 15000, "Yes"}};
                        
struct GUEST guests[10];
int guestCount = 0;

struct RESERVATION reservations[10];
int resCount = 0;

void showRooms() {
    printf("\n********** HOTEL ROOMS **********\n\n");
    printf("Room ID\tRoom Type\tPrice per Night\tAvailability\n");
    for(int i=0; i<10; i++) {
        printf("%d\t%s\t%d\t\t%s\n", rooms[i].roomId, rooms[i].roomType, rooms[i].price, rooms[i].availability);
    }
    printf("\n");
}

void showGuests() {
    printf("\n********** HOTEL GUESTS **********\n\n");
    printf("Guest ID\tGuest Name\tAge\tGender\tAddress\t\t\tPhone\n");
    for(int i=0; i<guestCount; i++) {
        printf("%d\t\t%s\t\t%d\t%s\t%s\t\t%s\n", guests[i].guestId, guests[i].guestName, guests[i].age, guests[i].gender, guests[i].address, guests[i].phone);
    }
    printf("\n");
}

void showReservations() {
    printf("\n********** HOTEL RESERVATIONS **********\n\n");
    printf("Reservation ID\tGuest ID\tRoom ID\tCheck In\tCheck Out\n");
    for(int i=0; i<resCount; i++) {
        printf("%d\t\t%d\t\t%d\t%s\t%s\n", reservations[i].resId, reservations[i].guestId, reservations[i].roomId, reservations[i].checkIn, reservations[i].checkOut);
    }
    printf("\n");
}

int main() {
    int choice;
    while(1) {
        printf("********** HOTEL MANAGEMENT SYSTEM **********\n\n");
        printf("1. Show all available rooms\n");
        printf("2. Show all guests\n");
        printf("3. Show all reservations\n");
        printf("4. Add a guest\n");
        printf("5. Make a reservation\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                showRooms();
                break;
            case 2:
                showGuests();
                break;
            case 3:
                showReservations();
                break;
            case 4:
                printf("\nEnter guest details:\n");
                printf("Name: ");
                scanf(" %[^\n]*c", guests[guestCount].guestName);
                printf("Age: ");
                scanf("%d", &guests[guestCount].age);
                printf("Gender: ");
                scanf(" %[^\n]*c", guests[guestCount].gender);
                printf("Address: ");
                scanf(" %[^\n]*c", guests[guestCount].address);
                printf("Phone: ");
                scanf(" %[^\n]*c", guests[guestCount].phone);
                guests[guestCount].guestId = guestCount + 1;
                guestCount++;
                printf("\nGuest added successfully!\n\n");
                break;
            case 5:
                printf("\nEnter reservation details:\n");
                printf("Guest ID: ");
                scanf("%d", &reservations[resCount].guestId);
                printf("Room ID: ");
                scanf("%d", &reservations[resCount].roomId);
                printf("Check In (dd/mm/yyyy): ");
                scanf(" %[^\n]*c", reservations[resCount].checkIn);
                printf("Check Out (dd/mm/yyyy): ");
                scanf(" %[^\n]*c", reservations[resCount].checkOut);
                reservations[resCount].resId = resCount + 1;
                for(int i=0; i<10; i++) {
                    if(rooms[i].roomId == reservations[resCount].roomId) {
                        strcpy(rooms[i].availability, "No");
                        break;
                    }
                }
                resCount++;
                printf("\nReservation made successfully!\n\n");
                break;
            case 6:
                return 0;
            default:
                printf("\nInvalid Choice!\n\n");
        }
    }
    return 0;
}