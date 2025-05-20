//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define NAME_LENGTH 50
#define ROOM_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char roomNumber[ROOM_LENGTH];
    int duration; // number of days
    float pricePerDay;
} Guest;

Guest guests[MAX_GUESTS];
int guestCount = 0;

void addGuest() {
    if (guestCount >= MAX_GUESTS) {
        printf("Guest list is full!\n");
        return;
    }
    Guest newGuest;
    printf("Enter guest name: ");
    scanf(" %[^\n]", newGuest.name);
    printf("Enter room number: ");
    scanf(" %s", newGuest.roomNumber);
    printf("Enter duration of stay (in days): ");
    scanf("%d", &newGuest.duration);
    printf("Enter price per day: ");
    scanf("%f", &newGuest.pricePerDay);

    guests[guestCount] = newGuest;
    guestCount++;
    printf("Guest added successfully!\n");
}

void viewGuests() {
    if (guestCount == 0) {
        printf("No guests currently in the system.\n");
        return;
    }
    printf("\nList of Guests:\n");
    printf("Name\t\tRoom Number\tDuration\tPrice per Day\n");
    for (int i = 0; i < guestCount; i++) {
        printf("%s\t%s\t%d\t\t%.2f\n", guests[i].name, guests[i].roomNumber, guests[i].duration, guests[i].pricePerDay);
    }
    printf("\n");
}

void deleteGuest() {
    if (guestCount == 0) {
        printf("No guests to delete.\n");
        return;
    }
    char name[NAME_LENGTH];
    printf("Enter guest name to delete: ");
    scanf(" %[^\n]", name);
    int found = 0;
    for (int i = 0; i < guestCount; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            for (int j = i; j < guestCount - 1; j++) {
                guests[j] = guests[j + 1];
            }
            guestCount--;
            found = 1;
            printf("Guest deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Guest not found.\n");
    }
}

void saveData() {
    FILE *file = fopen("guests.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for saving data.\n");
        return;
    }
    fwrite(guests, sizeof(Guest), guestCount, file);
    fclose(file);
    printf("Data saved successfully.\n");
}

void loadData() {
    FILE *file = fopen("guests.dat", "rb");
    if (file == NULL) {
        printf("No data to load. Starting with an empty list.\n");
        return;
    }
    guestCount = fread(guests, sizeof(Guest), MAX_GUESTS, file);
    fclose(file);
    printf("Data loaded successfully. %d guests found.\n", guestCount);
}

void displayMenu() {
    printf("==== Hotel Management System ====\n");
    printf("1. Add Guest\n");
    printf("2. View Guests\n");
    printf("3. Delete Guest\n");
    printf("4. Save Data\n");
    printf("5. Load Data\n");
    printf("6. Exit\n");
    printf("=================================\n");
}

int main() {
    loadData(); // Load data at startup

    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
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
                saveData();
                break;
            case 5:
                loadData();
                break;
            case 6:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        
    } while (choice != 6);

    return 0;
}