//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define NAME_LENGTH 50

typedef struct Guest {
    int id;
    char name[NAME_LENGTH];
    int roomNumber;
} Guest;

Guest guests[MAX_GUESTS];
int guestCount = 0;

void addGuest();
void viewGuests();
void updateGuest();
void deleteGuest();
void menu();
void clearInputBuffer();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    
    printf("=== Hotel Management System ===\n");
    printf("1. Add Guest\n");
    printf("2. View Guests\n");
    printf("3. Update Guest\n");
    printf("4. Delete Guest\n");
    printf("5. Exit\n");
    printf("==============================\n");
    printf("Select an option: ");
    
    scanf("%d", &choice);
    clearInputBuffer(); // clear any newline character left in the buffer

    switch(choice) {
        case 1:
            addGuest();
            break;
        case 2:
            viewGuests();
            break;
        case 3:
            updateGuest();
            break;
        case 4:
            deleteGuest();
            break;
        case 5:
            printf("Thank you for using the Hotel Management System. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid option! Please try again.\n");
            break;
    }
    
    menu(); // Recursive call to show menu again
}

void addGuest() {
    if (guestCount >= MAX_GUESTS) {
        printf("Cannot add more guests. Maximum limit reached.\n");
        return;
    }

    Guest newGuest;
    newGuest.id = guestCount + 1; // Simple ID assignment
    printf("Enter Guest Name: ");
    fgets(newGuest.name, NAME_LENGTH, stdin);
    newGuest.name[strcspn(newGuest.name, "\n")] = 0; // Remove new line
    printf("Enter Room Number: ");
    scanf("%d", &newGuest.roomNumber);
    clearInputBuffer(); // clear newline

    guests[guestCount] = newGuest;
    guestCount++;

    printf("Guest added successfully!\n");
}

void viewGuests() {
    if (guestCount == 0) {
        printf("No guests currently registered.\n");
        return;
    }

    printf("=== List of Guests ===\n");
    for (int i = 0; i < guestCount; i++) {
        printf("ID: %d, Name: %s, Room Number: %d\n", guests[i].id, guests[i].name, guests[i].roomNumber);
    }
}

void updateGuest() {
    int id;
    printf("Enter Guest ID to update: ");
    scanf("%d", &id);
    clearInputBuffer(); // clear newline

    if (id < 1 || id > guestCount) {
        printf("Guest ID not found.\n");
        return;
    }

    Guest *guest = &guests[id - 1]; // Accessing guest by ID
    printf("Updating Guest ID %d, Current Name: %s, Current Room: %d\n", guest->id, guest->name, guest->roomNumber);
    
    printf("Enter new Guest Name: ");
    fgets(guest->name, NAME_LENGTH, stdin);
    guest->name[strcspn(guest->name, "\n")] = 0; // Remove new line
    printf("Enter new Room Number: ");
    scanf("%d", &guest->roomNumber);
    clearInputBuffer(); // clear newline

    printf("Guest updated successfully!\n");
}

void deleteGuest() {
    int id;
    printf("Enter Guest ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer(); // clear newline

    if (id < 1 || id > guestCount) {
        printf("Guest ID not found.\n");
        return;
    }

    // Shift guests down to remove the deleted guest
    for (int i = id - 1; i < guestCount - 1; i++) {
        guests[i] = guests[i + 1];
    }
    guestCount--;

    printf("Guest deleted successfully!\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}