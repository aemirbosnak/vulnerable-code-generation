//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about guests
struct Guest {
    int roomNumber;
    char name[50];
    char address[100];
    char phone[15];
    float balance;
    int checkedIn;
};

// Function prototypes
void addGuest();
void removeGuest();
void checkIn();
void checkOut();
void viewGuests();
void saveData();
void loadData();

// Global variables
struct Guest guests[100];
int numGuests = 0;

int main() {
    // Load data from file
    loadData();

    int choice;
    do {
        printf("\n----- Hotel Management System Menu -----\n");
        printf("1. Add Guest\n");
        printf("2. Remove Guest\n");
        printf("3. Check In Guest\n");
        printf("4. Check Out Guest\n");
        printf("5. View Guests\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest();
                break;

            case 2:
                removeGuest();
                break;

            case 3:
                checkIn();
                break;

            case 4:
                checkOut();
                break;

            case 5:
                viewGuests();
                break;

            case 6:
                // Save data to file
                saveData();
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void addGuest() {
    if (numGuests >= 100) {
        printf("Error: Maximum number of guests reached.\n");
        return;
    }

    struct Guest newGuest;
    printf("Enter guest name: ");
    scanf("%s", newGuest.name);
    printf("Enter guest address: ");
    scanf("%s", newGuest.address);
    printf("Enter guest phone: ");
    scanf("%s", newGuest.phone);

    // Find available room number
    int i;
    for (i = 1; i <= 100; i++) {
        int found = 0;
        int j;
        for (j = 0; j < numGuests; j++) {
            if (guests[j].roomNumber == i) {
                found = 1;
                break;
            }
        }
        if (!found) {
            newGuest.roomNumber = i;
            break;
        }
    }

    newGuest.balance = 0.0;
    newGuest.checkedIn = 0;

    guests[numGuests++] = newGuest;
    printf("Guest added successfully.\n");
}

void removeGuest() {
    int roomNumber;
    printf("Enter room number of guest to remove: ");
    scanf("%d", &roomNumber);

    int i;
    for (i = 0; i < numGuests; i++) {
        if (guests[i].roomNumber == roomNumber) {
            printf("Guest '%s' removed successfully.\n", guests[i].name);
            guests[i] = guests[--numGuests];
            return;
        }
    }

    printf("Error: Guest not found.\n");
}

void checkIn() {
    int roomNumber;
    printf("Enter room number of guest to check in: ");
    scanf("%d", &roomNumber);

    int i;
    for (i = 0; i < numGuests; i++) {
        if (guests[i].roomNumber == roomNumber) {
            if (guests[i].checkedIn) {
                printf("Error: Guest already checked in.\n");
            } else {
                guests[i].checkedIn = 1;
                printf("Guest '%s' checked in successfully.\n", guests[i].name);
            }
            return;
        }
    }

    printf("Error: Guest not found.\n");
}

void checkOut() {
    int roomNumber;
    printf("Enter room number of guest to check out: ");
    scanf("%d", &roomNumber);

    int i;
    for (i = 0; i < numGuests; i++) {
        if (guests[i].roomNumber == roomNumber) {
            if (!guests[i].checkedIn) {
                printf("Error: Guest not checked in.\n");
            } else {
                guests[i].checkedIn = 0;
                printf("Guest '%s' checked out successfully.\n", guests[i].name);
            }
            return;
        }
    }

    printf("Error: Guest not found.\n");
}

void viewGuests() {
    printf("Room #\tName\t\tAddress\t\tPhone\t\tBalance\tChecked In\n");
    int i;
    for (i = 0; i < numGuests; i++) {
        printf("%d\t%s\t%s\t%s\t$%.2f\t%s\n",
            guests[i].roomNumber, guests[i].name, guests[i].address,
            guests[i].phone, guests[i].balance,
            guests[i].checkedIn ? "Yes" : "No");
    }
}

void saveData() {
    FILE *file = fopen("data.txt", "w");
    fprintf(file, "%d\n", numGuests);
    int i;
    for (i = 0; i < numGuests; i++) {
        fprintf(file, "%d,%s,%s,%s,%.2f,%d\n",
            guests[i].roomNumber, guests[i].name, guests[i].address,
            guests[i].phone, guests[i].balance, guests[i].checkedIn);
    }
    fclose(file);
}

void loadData() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        return;
    }
    fscanf(file, "%d\n", &numGuests);
    int i;
    for (i = 0; i < numGuests; i++) {
        fscanf(file, "%d,%[^,],%[^,],%[^,],%f,%d\n",
            &guests[i].roomNumber, guests[i].name, guests[i].address,
            guests[i].phone, &guests[i].balance, &guests[i].checkedIn);
    }
    fclose(file);
}