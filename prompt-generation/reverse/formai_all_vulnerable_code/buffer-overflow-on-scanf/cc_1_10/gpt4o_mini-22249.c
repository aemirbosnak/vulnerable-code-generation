//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int room_number;
    int is_checked_in; // 1 for yes, 0 for no
} Guest;

Guest guests[MAX_GUESTS];
int guest_count = 0;

void add_guest() {
    if (guest_count >= MAX_GUESTS) {
        printf("Cannot add more guests. Maximum limit reached.\n");
        return;
    }
    
    Guest new_guest;
    new_guest.id = guest_count + 1;
    
    printf("Enter guest name: ");
    scanf("%s", new_guest.name);
    
    printf("Enter room number: ");
    scanf("%d", &new_guest.room_number);
    
    new_guest.is_checked_in = 0; // Initially not checked in
    guests[guest_count] = new_guest;
    guest_count++;
    
    printf("Guest added successfully! Guest ID: %d\n", new_guest.id);
}

void check_in_guest() {
    int id;
    printf("Enter guest ID to check-in: ");
    scanf("%d", &id);
    
    if (id < 1 || id > guest_count) {
        printf("Invalid guest ID.\n");
        return;
    }
    
    if (guests[id - 1].is_checked_in) {
        printf("Guest is already checked in.\n");
        return;
    }
    
    guests[id - 1].is_checked_in = 1;
    printf("Guest ID %d checked-in successfully!\n", id);
}

void check_out_guest() {
    int id;
    printf("Enter guest ID to check-out: ");
    scanf("%d", &id);
    
    if (id < 1 || id > guest_count) {
        printf("Invalid guest ID.\n");
        return;
    }
    
    if (!guests[id - 1].is_checked_in) {
        printf("Guest is not checked in.\n");
        return;
    }
    
    guests[id - 1].is_checked_in = 0;
    printf("Guest ID %d checked-out successfully!\n", id);
}

void view_bookings() {
    printf("List of all guests:\n");
    for (int i = 0; i < guest_count; i++) {
        printf("Guest ID: %d, Name: %s, Room Number: %d, Checked In: %s\n",
               guests[i].id,
               guests[i].name,
               guests[i].room_number,
               guests[i].is_checked_in ? "Yes" : "No");
    }
}

void display_menu() {
    printf("\nHotel Management System\n");
    printf("1. Add Guest\n");
    printf("2. Check In Guest\n");
    printf("3. Check Out Guest\n");
    printf("4. View Bookings\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                check_in_guest();
                break;
            case 3:
                check_out_guest();
                break;
            case 4:
                view_bookings();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;  // Never reached but included for completion
}