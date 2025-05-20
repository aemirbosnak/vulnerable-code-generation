//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_NAME_LENGTH 50

// Define the guest structure
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char roomType[MAX_NAME_LENGTH];
    int nights;
} Guest;

// Function prototypes
void addGuest();
void displayGuests();
void saveGuest(Guest guest);
void loadGuests();
void clearBuffer();

int guestCount = 0;
Guest guests[MAX_GUESTS];

int main() {
    int choice;

    while (1) {
        printf("=== Hotel Management System ===\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2:
                displayGuests();
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addGuest() {
    if (guestCount >= MAX_GUESTS) {
        printf("Maximum guest limit reached.\n");
        return;
    }

    Guest newGuest;
    newGuest.id = guestCount + 1; // Simple ID assignment
    printf("Enter guest name: ");
    fgets(newGuest.name, MAX_NAME_LENGTH, stdin);
    strtok(newGuest.name, "\n"); // Remove newline character

    printf("Enter guest age: ");
    scanf("%d", &newGuest.age);
    clearBuffer();

    printf("Enter room type: ");
    fgets(newGuest.roomType, MAX_NAME_LENGTH, stdin);
    strtok(newGuest.roomType, "\n");

    printf("Enter number of nights: ");
    scanf("%d", &newGuest.nights);
    clearBuffer();

    guests[guestCount] = newGuest;
    guestCount++;
    
    saveGuest(newGuest);
    printf("Guest added successfully!\n");
}

void displayGuests() {
    if (guestCount == 0) {
        printf("No guests currently registered.\n");
        return;
    }

    printf("=== Registered Guests ===\n");
    for (int i = 0; i < guestCount; i++) {
        printf("ID: %d\n", guests[i].id);
        printf("Name: %s\n", guests[i].name);
        printf("Age: %d\n", guests[i].age);
        printf("Room Type: %s\n", guests[i].roomType);
        printf("Nights: %d\n", guests[i].nights);
        printf("------------------------------\n");
    }
}

void saveGuest(Guest guest) {
    FILE *file = fopen("guests.txt", "a");
    if (file == NULL) {
        printf("Error opening the file!\n");
        return;
    }
  
    fprintf(file, "%d,%s,%d,%s,%d\n", guest.id, guest.name, guest.age, guest.roomType, guest.nights);
    fclose(file);
}

void loadGuests() {
    FILE *file = fopen("guests.txt", "r");
    if (file == NULL) {
        printf("Error opening the file!\n");
        return;
    }

    while (!feof(file)) {
        Guest guest;
        if (fscanf(file, "%d,%49[^,],%d,%49[^,],%d\n", &guest.id, guest.name, &guest.age, guest.roomType, &guest.nights) == 5) {
            guests[guestCount++] = guest;
        }
    }
    fclose(file);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}