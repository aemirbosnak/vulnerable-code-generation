//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char check_in_date[11]; // Format: YYYY-MM-DD
    char check_out_date[11]; // Format: YYYY-MM-DD
    int is_checked_in; // 1 for checked-in, 0 for checked-out
} Guest;

Guest guests[MAX_GUESTS];
int guest_count = 0;

void add_guest() {
    if (guest_count >= MAX_GUESTS) {
        printf("Cannot add more guests. The hotel is full!\n");
        return;
    }

    Guest new_guest;
    new_guest.id = guest_count + 1;
    
    printf("Enter guest name: ");
    scanf(" %[^\n]", new_guest.name);
    
    printf("Enter check-in date (YYYY-MM-DD): ");
    scanf("%s", new_guest.check_in_date);
    
    printf("Enter check-out date (YYYY-MM-DD): ");
    scanf("%s", new_guest.check_out_date);
    
    new_guest.is_checked_in = 1; // Mark as checked-in
    guests[guest_count] = new_guest;
    guest_count++;
    
    printf("Guest added successfully. Guest ID: %d\n", new_guest.id);
}

void check_out_guest() {
    int id;
    printf("Enter guest ID to check out: ");
    scanf("%d", &id);

    if (id < 1 || id > guest_count || !guests[id - 1].is_checked_in) {
        printf("Invalid guest ID or guest is not checked in!\n");
        return;
    }

    guests[id - 1].is_checked_in = 0; // Mark as checked-out
    printf("Guest ID %d has checked out successfully.\n", id);
}

void display_guests() {
    printf("\n--- Current Guests ---\n");
    for (int i = 0; i < guest_count; i++) {
        if (guests[i].is_checked_in) {
            printf("Guest ID: %d, Name: %s, Check-in: %s, Check-out: %s\n",
                   guests[i].id, guests[i].name, guests[i].check_in_date, guests[i].check_out_date);
        }
    }
}

void menu() {
    int choice;

    do {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Add Guest\n");
        printf("2. Check Out Guest\n");
        printf("3. Display Current Guests\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                check_out_guest();
                break;
            case 3:
                display_guests();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}