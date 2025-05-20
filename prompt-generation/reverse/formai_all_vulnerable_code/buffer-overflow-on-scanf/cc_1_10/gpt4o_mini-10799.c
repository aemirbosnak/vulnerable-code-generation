//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a guest
struct Guest {
    char name[50];
    int age;
    char roomType[20];
};

// Function prototypes
void welcomeMessage();
void checkIn(struct Guest *guests, int *guestCount);
void checkOut(struct Guest *guests, int *guestCount);
void displayGuests(struct Guest *guests, int guestCount);
void medievalMenu();

int main() {
    int choice, guestCount = 0;
    struct Guest guests[100]; // Maximum of 100 guests

    welcomeMessage();

    do {
        medievalMenu();
        printf("Enter thy choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkIn(guests, &guestCount);
                break;
            case 2:
                checkOut(guests, &guestCount);
                break;
            case 3:
                displayGuests(guests, guestCount);
                break;
            case 4:
                printf("Farewell, traveler!\n");
                break;
            default:
                printf("Nay, that option is not valid. Please choose again!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void welcomeMessage() {
    printf("=========================================\n");
    printf("  Welcome to the Enchanted Inn of Lore  \n");
    printf("=========================================\n\n");
    printf("Join us for a memorable stay in the heart of the kingdom!\n");
}

void medievalMenu() {
    printf("\n*** The Innkeeper's Menu ***\n");
    printf("1. Check-in a noble guest\n");
    printf("2. Check-out a noble guest\n");
    printf("3. Display current guests\n");
    printf("4. Leave the inn\n");
}

void checkIn(struct Guest *guests, int *guestCount) {
    if (*guestCount >= 100) {
        printf("Alas! The inn is fully occupied!\n");
        return;
    }

    struct Guest newGuest;
    printf("Enter the name of the guest: ");
    scanf(" %[^\n]s", newGuest.name);
    printf("Enter the age of the guest: ");
    scanf("%d", &newGuest.age);
    printf("Enter the type of room (Single, Double, Suite): ");
    scanf(" %[^\n]s", newGuest.roomType);

    guests[*guestCount] = newGuest;
    (*guestCount)++;
    printf("The noble guest has been checked in!\n");
}

void checkOut(struct Guest *guests, int *guestCount) {
    if (*guestCount <= 0) {
        printf("No guests to check out at this time.\n");
        return;
    }

    char name[50];
    printf("Enter the name of the guest to check out: ");
    scanf(" %[^\n]s", name);

    int found = 0;
    for (int i = 0; i < *guestCount; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            found = 1;
            printf("The noble %s has checked out!\n", guests[i].name);
            // Shift guests down
            for (int j = i; j < *guestCount - 1; j++) {
                guests[j] = guests[j + 1];
            }
            (*guestCount)--;
            break;
        }
    }
    
    if (!found) {
        printf("Alas! No guest by that name hath checked in.\n");
    }
}

void displayGuests(struct Guest *guests, int guestCount) {
    if (guestCount == 0) {
        printf("The inn is as empty as a tavern after closing!\n");
        return;
    }

    printf("\nCurrent guests in the Enchanted Inn:\n");
    for (int i = 0; i < guestCount; i++) {
        printf("Guest %d: %s, Age: %d, Room Type: %s\n", i + 1, guests[i].name, guests[i].age, guests[i].roomType);
    }
}