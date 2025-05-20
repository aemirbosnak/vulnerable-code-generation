//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define NAME_LENGTH 50
#define ADDRESS_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
    char check_in_date[11]; // Format: YYYY-MM-DD
    char check_out_date[11]; // Format: YYYY-MM-DD
    int room_number;
    int is_checked_in;
} Guest;

Guest guests[MAX_GUESTS];
int guest_count = 0;

void add_guest() {
    if (guest_count >= MAX_GUESTS) {
        printf("Guest list is full!\n");
        return;
    }
    Guest new_guest;
    new_guest.id = guest_count + 1; // Simple ID assignment
    printf("Enter Guest Name: ");
    scanf(" %[^\n]s", new_guest.name);
    printf("Enter Address: ");
    scanf(" %[^\n]s", new_guest.address);
    printf("Enter Check-in Date (YYYY-MM-DD): ");
    scanf("%s", new_guest.check_in_date);
    printf("Enter Check-out Date (YYYY-MM-DD): ");
    scanf("%s", new_guest.check_out_date);
    printf("Enter Room Number: ");
    scanf("%d", &new_guest.room_number);
    new_guest.is_checked_in = 1;

    guests[guest_count] = new_guest;
    guest_count++;
    printf("Guest added successfully!\n");
}

void display_guests() {
    printf("\n--- Guest List ---\n");
    if (guest_count == 0) {
        printf("No guests currently checked in.\n");
        return;
    }
    for (int i = 0; i < guest_count; i++) {
        if (guests[i].is_checked_in) {
            printf("ID: %d\n", guests[i].id);
            printf("Name: %s\n", guests[i].name);
            printf("Address: %s\n", guests[i].address);
            printf("Check-in Date: %s\n", guests[i].check_in_date);
            printf("Check-out Date: %s\n", guests[i].check_out_date);
            printf("Room Number: %d\n\n", guests[i].room_number);
        }
    }
}

void check_out_guest() {
    int guest_id;
    printf("Enter Guest ID to check out: ");
    scanf("%d", &guest_id);
    
    if (guest_id < 1 || guest_id > guest_count || !guests[guest_id - 1].is_checked_in) {
        printf("Invalid Guest ID or guest is not checked in.\n");
        return;
    }
    
    guests[guest_id - 1].is_checked_in = 0; // Mark as checked out
    printf("Guest checked out successfully!\n");
}

void display_menu() {
    printf("\n--- Hotel Management System ---\n");
    printf("1. Add Guest\n");
    printf("2. Display Guests\n");
    printf("3. Check Out Guest\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                display_guests();
                break;
            case 3:
                check_out_guest();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
  
    return 0;
}