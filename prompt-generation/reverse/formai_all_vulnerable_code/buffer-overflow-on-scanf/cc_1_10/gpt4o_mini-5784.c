//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define ROOM_TYPES 5

// Structure to hold guest information
typedef struct {
    char name[50];
    int age;
    char roomType[20];
    int roomNumber;
    int stayDuration; // in days
} Guest;

// Function prototypes
void addGuest(Guest guests[], int *guestCount);
void viewGuests(Guest guests[], int guestCount);
void checkRoomAvailability();
void welcomeMessage();

int main() {
    Guest guests[MAX_GUESTS];
    int guestCount = 0;
    int choice;

    welcomeMessage();

    do {
        printf("\nHotel Management System Menu:\n");
        printf("1. Add Guest\n");
        printf("2. View Guests\n");
        printf("3. Check Room Availability\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest(guests, &guestCount);
                break;
            case 2:
                viewGuests(guests, guestCount);
                break;
            case 3:
                checkRoomAvailability();
                break;
            case 4:
                printf("Thank you for using the Hotel Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void welcomeMessage() {
    printf("***********************************\n");
    printf("      Welcome to Hotel Paradise    \n");
    printf("***********************************\n");
}

void addGuest(Guest guests[], int *guestCount) {
    if (*guestCount >= MAX_GUESTS) {
        printf("Error: Maximum guest limit reached!\n");
        return;
    }

    Guest newGuest;
    printf("Enter guest name: ");
    scanf(" %[^\n]", newGuest.name);
    printf("Enter guest age: ");
    scanf("%d", &newGuest.age);
    printf("Enter room type (Single/Double/Suite/Deluxe/VIP): ");
    scanf(" %s", newGuest.roomType);
    printf("Enter room number: ");
    scanf("%d", &newGuest.roomNumber);
    printf("Enter stay duration (in days): ");
    scanf("%d", &newGuest.stayDuration);

    guests[*guestCount] = newGuest;
    (*guestCount)++;

    printf("Guest added successfully!\n");
}

void viewGuests(Guest guests[], int guestCount) {
    if (guestCount == 0) {
        printf("No guests currently checked in.\n");
        return;
    }

    printf("\nList of Guests:\n");
    for (int i = 0; i < guestCount; i++) {
        printf("Guest #%d\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Age: %d\n", guests[i].age);
        printf("Room Type: %s\n", guests[i].roomType);
        printf("Room Number: %d\n", guests[i].roomNumber);
        printf("Stay Duration: %d days\n", guests[i].stayDuration);
        printf("----------------------------------\n");
    }
}

void checkRoomAvailability() {
    printf("\nRoom Availability:\n");
    printf("1. Single: 20 rooms available\n");
    printf("2. Double: 15 rooms available\n");
    printf("3. Suite: 10 rooms available\n");
    printf("4. Deluxe: 5 rooms available\n");
    printf("5. VIP: 2 rooms available\n");
    printf("Please inquire at the front desk for more details.\n");
}