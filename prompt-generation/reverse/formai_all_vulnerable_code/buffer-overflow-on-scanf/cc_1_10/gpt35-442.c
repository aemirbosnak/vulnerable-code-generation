//FormAI DATASET v1.0 Category: Hotel Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int menu();
void addGuest();
void viewGuests();
void deleteGuest();
void checkoutGuest();

struct Guest {
    char name[50];
    int roomNumber;
    int numberOfNights;
    float bill;
} guests[50];

int main() {
    int choice;

    while (1) {
        choice = menu();

        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2:
                viewGuests();
                break;
            case 3:
                deleteGuest();
                break;
            case 4:
                checkoutGuest();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!");
                break;
        }
    }

    return 0;
}

// Display menu and return choice
int menu() {
    int choice;

    printf("\n\nHotel Management System\n");
    printf("-------------------------\n");
    printf("1. Add new guest\n");
    printf("2. View all guests\n");
    printf("3. Delete a guest\n");
    printf("4. Check out a guest\n");
    printf("5. Exit\n");
    printf("-------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// Add a new guest
void addGuest() {
    int i = 0;

    while (guests[i].name[0] != '\0' && i < 50) {
        i++;
    }

    if (i >= 50) {
        printf("\nHotel is fully booked!");
        return;
    }

    printf("\nEnter guest name: ");
    scanf("%s", guests[i].name);
    printf("Enter room number: ");
    scanf("%d", &guests[i].roomNumber);
    printf("Enter number of nights: ");
    scanf("%d", &guests[i].numberOfNights);

    guests[i].bill = guests[i].numberOfNights * 50.0;

    printf("Guest has been added to the system.");
}

// View all guests
void viewGuests() {
    int i;

    printf("\n\nAll Guests\n");
    printf("-----------\n");

    for (i = 0; i < 50; i++) {
        if (guests[i].name[0] != '\0') {
            printf("Name: %s\n", guests[i].name);
            printf("Room number: %d\n", guests[i].roomNumber);
            printf("Number of nights: %d\n", guests[i].numberOfNights);
            printf("Bill: $%.2f\n", guests[i].bill);
            printf("-----------\n");
        } else {
            break;
        }
    }
}

// Delete a guest
void deleteGuest() {
    int i, roomNumber;

    printf("\nEnter the room number of the guest to delete: ");
    scanf("%d", &roomNumber);

    for (i = 0; i < 50; i++) {
        if (guests[i].roomNumber == roomNumber) {
            guests[i].name[0] = '\0';
            printf("\nGuest has been deleted from the system.");
            return;
        }
    }

    printf("\nGuest not found in the system.");
}

// Check out a guest
void checkoutGuest() {
    int i, roomNumber;

    printf("\nEnter the room number of the guest to check out: ");
    scanf("%d", &roomNumber);

    for (i = 0; i < 50; i++) {
        if (guests[i].roomNumber == roomNumber) {
            printf("\nGuest %s has checked out.", guests[i].name);
            guests[i].name[0] = '\0';
            return;
        }
    }

    printf("\nGuest not found in the system.");
}