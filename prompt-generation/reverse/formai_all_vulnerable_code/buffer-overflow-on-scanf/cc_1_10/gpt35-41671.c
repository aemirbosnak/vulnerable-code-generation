//FormAI DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roomNumber;
    char name[50];
    int days;
    char roomType[10];
    float price;
} guest;

guest guests[50];
int numGuests = 0;

void bookRoom(int roomNum, char *name, int days, char *roomType, float price) {
    guests[numGuests].roomNumber = roomNum;
    strcpy(guests[numGuests].name, name);
    guests[numGuests].days = days;
    strcpy(guests[numGuests].roomType, roomType);
    guests[numGuests].price = price;
    numGuests++;
}

void displayGuests() {
    printf("\nList of guests:\n\n");
    printf("Room Number\tName\t\t\tDays\tRoom Type\tPrice\n");
    for(int i = 0; i < numGuests; i++) {
        printf("%d\t\t%s\t\t\t%d\t%s\t\t$%.2f\n", guests[i].roomNumber, guests[i].name, guests[i].days, guests[i].roomType, guests[i].price);
    }
    printf("\n");
}

int main() {
    int choice;
    int roomNumber;
    char name[50];
    int days;
    char roomType[10];
    float price;

    do {
        printf("\n");
        printf("\n1. Book a room");
        printf("\n2. Display guests");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Book a room
                printf("\nEnter room number: ");
                scanf("%d", &roomNumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number of days: ");
                scanf("%d", &days);
                printf("Enter room type (single/double): ");
                scanf("%s", roomType);
                if(strcmp(roomType, "single") == 0) { // Single room
                    price = days * 75.0;
                } else if(strcmp(roomType, "double") == 0) { // Double room
                    price = days * 150.0;
                } else {
                    printf("Invalid room type!");
                    continue;
                }
                bookRoom(roomNumber, name, days, roomType, price);
                printf("\nRoom booked successfully!");
                break;

            case 2: // Display guests
                displayGuests();
                break;

            case 3: // Exit
                printf("\nExiting program...");
                exit(0);

            default: // Invalid choice
                printf("\nInvalid choice! Please try again.");
                break;
        }
    } while(choice != 3);

    return 0;
}