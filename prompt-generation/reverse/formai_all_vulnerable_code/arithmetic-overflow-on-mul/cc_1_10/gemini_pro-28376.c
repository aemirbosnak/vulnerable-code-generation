//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

struct Guest {
    char name[50];
    int roomNumber;
    int nights;
    float bill;
};

struct Hotel {
    struct Guest guests[100];
    int numGuests;
};

void checkIn(struct Hotel *hotel) {
    struct Guest guest;

    printf("Welcome to our hotel!\n");
    printf("What is your name?\n");
    scanf("%s", guest.name);

    printf("What room number would you like?\n");
    scanf("%d", &guest.roomNumber);

    printf("How many nights will you be staying?\n");
    scanf("%d", &guest.nights);

    guest.bill = guest.nights * 100;

    hotel->guests[hotel->numGuests] = guest;
    hotel->numGuests++;

    printf("Thank you for checking in, %s!\n", guest.name);
}

void checkOut(struct Hotel *hotel) {
    int roomNumber;

    printf("What is your room number?\n");
    scanf("%d", &roomNumber);

    for (int i = 0; i < hotel->numGuests; i++) {
        if (hotel->guests[i].roomNumber == roomNumber) {
            printf("Thank you for staying with us, %s!\n", hotel->guests[i].name);
            hotel->guests[i] = hotel->guests[hotel->numGuests - 1];
            hotel->numGuests--;
            break;
        }
    }
}

void printGuests(struct Hotel *hotel) {
    printf("Guests:\n");
    for (int i = 0; i < hotel->numGuests; i++) {
        printf("%s, Room %d, Nights: %d, Bill: $%.2f\n", hotel->guests[i].name, hotel->guests[i].roomNumber, hotel->guests[i].nights, hotel->guests[i].bill);
    }
}

int main() {
    struct Hotel hotel;
    hotel.numGuests = 0;

    int choice;

    do {
        printf("What would you like to do?\n");
        printf("1. Check in\n");
        printf("2. Check out\n");
        printf("3. Print guests\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkIn(&hotel);
                break;
            case 2:
                checkOut(&hotel);
                break;
            case 3:
                printGuests(&hotel);
                break;
            case 4:
                printf("Thank you for using our hotel management system!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}