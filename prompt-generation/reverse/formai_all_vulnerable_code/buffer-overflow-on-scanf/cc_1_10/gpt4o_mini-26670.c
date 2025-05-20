//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct {
    int id;
    char name[50];
    char phone[15];
    int is_checked_in;
} Guest;

void add_guest(Guest guests[], int *count) {
    if (*count >= MAX_GUESTS) {
        printf("Guest list is full. Cannot add more guests.\n");
        return;
    }
    Guest new_guest;
    new_guest.id = *count + 1;

    printf("Enter guest name: ");
    scanf(" %[^\n]", new_guest.name);
    
    printf("Enter guest phone number: ");
    scanf(" %[^\n]", new_guest.phone);
    
    new_guest.is_checked_in = 0; // Initially not checked in

    guests[*count] = new_guest;
    (*count)++;

    printf("Guest added successfully!\n");
}

void check_in_guest(Guest guests[], int count) {
    int guest_id;

    printf("Enter guest ID to check in: ");
    scanf("%d", &guest_id);

    if (guest_id <= 0 || guest_id > count) {
        printf("Invalid guest ID.\n");
        return;
    }

    if (guests[guest_id - 1].is_checked_in) {
        printf("Guest is already checked in.\n");
        return;
    }

    guests[guest_id - 1].is_checked_in = 1;
    printf("Guest checked in successfully!\n");
}

void check_out_guest(Guest guests[], int count) {
    int guest_id;

    printf("Enter guest ID to check out: ");
    scanf("%d", &guest_id);

    if (guest_id <= 0 || guest_id > count) {
        printf("Invalid guest ID.\n");
        return;
    }

    if (!guests[guest_id - 1].is_checked_in) {
        printf("Guest is not checked in.\n");
        return;
    }

    guests[guest_id - 1].is_checked_in = 0;
    printf("Guest checked out successfully!\n");
}

void display_guests(const Guest guests[], int count) {
    printf("\n--- Guest List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Phone: %s | Status: %s\n", 
               guests[i].id, guests[i].name, guests[i].phone,
               guests[i].is_checked_in ? "Checked In" : "Checked Out");
    }
    printf("--------------------\n");
}

int main() {
    Guest guests[MAX_GUESTS];
    int guest_count = 0;
    int choice;

    while (1) {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Add Guest\n");
        printf("2. Check In Guest\n");
        printf("3. Check Out Guest\n");
        printf("4. Display Guests\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest(guests, &guest_count);
                break;
            case 2:
                check_in_guest(guests, guest_count);
                break;
            case 3:
                check_out_guest(guests, guest_count);
                break;
            case 4:
                display_guests(guests, guest_count);
                break;
            case 5:
                printf("Exiting the system. Have a wonderful day!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}