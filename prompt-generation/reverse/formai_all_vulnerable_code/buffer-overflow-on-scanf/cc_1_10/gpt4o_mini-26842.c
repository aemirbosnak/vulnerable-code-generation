//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define ROOM_SERVICE_COST 15.00

typedef struct {
    char name[50];
    int roomNumber;
    int daysStayed;
    int wantsRoomService;
} Guest;

Guest guests[MAX_GUESTS];
int guestCount = 0;

void addGuest() {
    if (guestCount >= MAX_GUESTS) {
        printf("The hotel is full! Sorry, you’ll have to sleep in the lobby. Good luck!\n");
        return;
    }

    Guest newGuest;
    printf("Welcome to the Quirky Hotel! What's your name? ");
    scanf("%s", newGuest.name);
    newGuest.roomNumber = guestCount + 101; // Seriously, who doesn't want a room number like 101?
    printf("You've been assigned Room %d. Enjoy your stay! (Don't steal the towels!)\n", newGuest.roomNumber);
    printf("How many days will you be staying? ");
    scanf("%d", &newGuest.daysStayed);
    printf("Would you like room service? (1 for Yes, 0 for No) ");
    scanf("%d", &newGuest.wantsRoomService);
    
    guests[guestCount++] = newGuest;
    printf("Great, %s! You’ve checked in successfully! (Don’t be surprised if you meet a ghost in the hallway...)\n", newGuest.name);
}

void showGuests() {
    printf("\nCurrent Guests:\n");
    for (int i = 0; i < guestCount; i++) {
        printf("Guest: %s, Room: %d, Days Stayed: %d, Room Service Requested: %s\n", 
            guests[i].name, guests[i].roomNumber, guests[i].daysStayed, 
            guests[i].wantsRoomService ? "Yes" : "No");
    }
}

void calculateBill() {
    printf("\nCalculating Bills: (Warning: Ghosts might steal your cash!)\n");
    for (int i = 0; i < guestCount; i++) {
        float bill = guests[i].daysStayed * 100.00; // Let's say each room costs $100 a night.
        if (guests[i].wantsRoomService) {
            bill += ROOM_SERVICE_COST * guests[i].daysStayed;
        }
        printf("The bill for %s in Room %d is: $%.2f\n", guests[i].name, guests[i].roomNumber, bill);
    }
}

void checkout() {
    if (guestCount == 0) {
        printf("No guests to checkout! The hotel must be a secret hideout!\n");
        return;
    }

    char name[50];
    printf("Who is checking out? (Just say 'ME!' if you’re bold!) ");
    scanf("%s", name);
    
    for (int i = 0; i < guestCount; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            printf("Thank you for staying with us, %s! Please don’t leave your dirty socks!\n", guests[i].name);
            for (int j = i; j < guestCount - 1; j++) {
                guests[j] = guests[j + 1];
            }
            guestCount--;
            return;
        }
    }
    printf("I’m afraid we don’t have a booking under that name! Did you forget to tell us your name?\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Quirky Hotel Management System ===\n");
        printf("1. Check In\n");
        printf("2. Show Guests\n");
        printf("3. Calculate Bills\n");
        printf("4. Check Out\n");
        printf("5. Exit\n");
        printf("=======================================\n");
        printf("What would you like to do? (Choose wisely!): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2:
                showGuests();
                break;
            case 3:
                calculateBill();
                break;
            case 4:
                checkout();
                break;
            case 5:
                printf("Thank you for visiting the Quirky Hotel! Come back when you want more hilarities!\n");
                exit(0);
            default:
                printf("Invalid choice! Our ghosts recommend choosing a number between 1 and 5.\n");
        }
    }

    return 0;
}