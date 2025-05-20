//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct {
    int id;
    char name[50];
    char email[50];
    int room_number;
} Guest;

Guest guests[MAX_GUESTS];
int guest_count = 0;

// Function prototypes
void add_guest();
void display_guests();
void checkout_guest();
void clear_buffer();

int main() {
    int choice;
    
    while (1) {
        printf("\n---------- Hotel Management System ----------\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Checkout Guest\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                display_guests();
                break;
            case 3:
                checkout_guest();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_guest() {
    if (guest_count >= MAX_GUESTS) {
        printf("Maximum guest limit reached!\n");
        return;
    }

    Guest new_guest;
    new_guest.id = guest_count + 1;

    printf("Enter guest name: ");
    fgets(new_guest.name, sizeof(new_guest.name), stdin);
    new_guest.name[strcspn(new_guest.name, "\n")] = 0; // Remove newline

    printf("Enter guest email: ");
    fgets(new_guest.email, sizeof(new_guest.email), stdin);
    new_guest.email[strcspn(new_guest.email, "\n")] = 0; // Remove newline

    printf("Enter room number: ");
    scanf("%d", &new_guest.room_number);
    clear_buffer();

    guests[guest_count++] = new_guest;
    printf("Guest added successfully with ID: %d\n", new_guest.id);
}

void display_guests() {
    if (guest_count == 0) {
        printf("No guests found!\n");
        return;
    }

    printf("\nList of Guests:\n");
    printf("ID\tName\t\tEmail\t\t\tRoom Number\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < guest_count; i++) {
        printf("%d\t%s\t%s\t%d\n", guests[i].id, guests[i].name, guests[i].email, guests[i].room_number);
    }
}

void checkout_guest() {
    int id;
    printf("Enter guest ID to checkout: ");
    scanf("%d", &id);
    clear_buffer();

    if (id <= 0 || id > guest_count) {
        printf("Invalid guest ID.\n");
        return;
    }

    for (int i = id - 1; i < guest_count - 1; i++) {
        guests[i] = guests[i + 1];
    }
    guest_count--;
    printf("Guest with ID %d has been checked out successfully.\n", id);
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear standard input buffer
}