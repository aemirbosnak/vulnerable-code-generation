//FormAI DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_ROOMS 50
#define MAX_NAME_LEN 50
#define MAX_ADDRESS_LEN 100
#define MAX_PHONE_LEN 15

struct Room 
{
    int roomNumber;
    int price;
    int occupied;
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];
};

struct Hotel 
{
    char name[MAX_NAME_LEN];
    int numRooms;
    struct Room rooms[MAX_ROOMS];
};

void displayMenu() 
{
    printf("\nHotel Management Menu\n");
    printf("-------------------------\n");
    printf("1. Check-in a guest\n");
    printf("2. Check-out a guest\n");
    printf("3. View room status\n");
    printf("4. View all rooms\n");
    printf("5. Exit\n");
}

int findEmptyRoom(struct Room rooms[]) 
{
    for (int i = 0; i < MAX_ROOMS; i++) 
    {
        if (!rooms[i].occupied) 
        {
            return i;
        }
    }
    return -1; // no empty rooms found
}

void checkIn(struct Hotel *hotel) 
{
    int roomNumber, price;
    char name[MAX_NAME_LEN], address[MAX_ADDRESS_LEN], phone[MAX_PHONE_LEN];
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    if (hotel->rooms[roomNumber].occupied) 
    {
        printf("Sorry, Room %d is already occupied!\n", roomNumber);
        return;
    }
    printf("Enter guest name: ");
    scanf("%s", name);
    printf("Enter guest address: ");
    scanf("%s", address);
    printf("Enter guest phone number: ");
    scanf("%s", phone);
    price = 100 + (10 * roomNumber); // calculate room price based on room number
    hotel->rooms[roomNumber] = (struct Room) { roomNumber, price, 1, name, address, phone };
    printf("Guest checked in to Room %d.\n", roomNumber);
}

void checkOut(struct Hotel *hotel) 
{
    int roomNumber;
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    if (!hotel->rooms[roomNumber].occupied) 
    {
        printf("Sorry, Room %d is not occupied!\n", roomNumber);
        return;
    }
    printf("Guest %s has checked out of Room %d.\n", hotel->rooms[roomNumber].name, roomNumber);
    hotel->rooms[roomNumber] = (struct Room) { roomNumber, 0, 0, "", "", "" }; // clear room info
}

void viewRoomStatus(struct Hotel *hotel) 
{
    int roomNumber;
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    if (!hotel->rooms[roomNumber].occupied) 
    {
        printf("Room %d is unoccupied!\n", roomNumber);
    } 
    else 
    {
        printf("Room Number: %d\n", hotel->rooms[roomNumber].roomNumber);
        printf("Guest Name: %s\n", hotel->rooms[roomNumber].name);
        printf("Guest Address: %s\n", hotel->rooms[roomNumber].address);
        printf("Guest Phone Number: %s\n", hotel->rooms[roomNumber].phone);
        printf("Occupied: %s\n", hotel->rooms[roomNumber].occupied ? "Yes" : "No");
        printf("Price: $%d per night\n", hotel->rooms[roomNumber].price);
    }
}

void viewAllRooms(struct Hotel *hotel) 
{
    printf("All Rooms:\n");
    for (int i = 0; i < MAX_ROOMS; i++) 
    {
        printf("-------------------------\n");
        if (hotel->rooms[i].occupied) 
        {
            printf("Room Number: %d\n", hotel->rooms[i].roomNumber);
            printf("Guest Name: %s\n", hotel->rooms[i].name);
            printf("Guest Address: %s\n", hotel->rooms[i].address);
            printf("Guest Phone Number: %s\n", hotel->rooms[i].phone);
            printf("Occupied: %s\n", hotel->rooms[i].occupied ? "Yes" : "No");
            printf("Price: $%d per night\n", hotel->rooms[i].price);
        } 
        else 
        {
            printf("Room %d is unoccupied\n", i);
        }
    }
}

int main() 
{
    struct Hotel hotel = { "Hotel California", MAX_ROOMS, {0} };
    int choice;
    while (1) 
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                checkIn(&hotel);
                break;
            case 2:
                checkOut(&hotel);
                break;
            case 3:
                viewRoomStatus(&hotel);
                break;
            case 4:
                viewAllRooms(&hotel);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}