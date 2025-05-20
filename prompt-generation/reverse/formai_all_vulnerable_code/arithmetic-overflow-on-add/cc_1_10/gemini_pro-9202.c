//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Structure to store guest information
typedef struct guest {
    int guest_id;
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_no;
    int check_in_date;
    int check_out_date;
    int no_of_days;
    float bill_amount;
} guest;

// Array to store guest information
guest guests[100];

// Function to add a new guest
void add_guest(int guest_id, char *name, char *address, char *phone, char *email, int room_no, int check_in_date, int check_out_date) {
    // Check if the guest ID is already in use
    for (int i = 0; i < 100; i++) {
        if (guests[i].guest_id == guest_id) {
            printf("Guest ID already in use.\n");
            return;
        }
    }

    // Create a new guest record
    guest new_guest;
    new_guest.guest_id = guest_id;
    strcpy(new_guest.name, name);
    strcpy(new_guest.address, address);
    strcpy(new_guest.phone, phone);
    strcpy(new_guest.email, email);
    new_guest.room_no = room_no;
    new_guest.check_in_date = check_in_date;
    new_guest.check_out_date = check_out_date;
    new_guest.no_of_days = check_out_date - check_in_date;
    new_guest.bill_amount = 0.0;

    // Add the new guest record to the array
    for (int i = 0; i < 100; i++) {
        if (guests[i].guest_id == 0) {
            guests[i] = new_guest;
            break;
        }
    }

    printf("Guest added successfully.\n");
}

// Function to search for a guest by ID
guest *search_guest_by_id(int guest_id) {
    for (int i = 0; i < 100; i++) {
        if (guests[i].guest_id == guest_id) {
            return &guests[i];
        }
    }

    return NULL;
}

// Function to search for a guest by name
guest *search_guest_by_name(char *name) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            return &guests[i];
        }
    }

    return NULL;
}

// Function to check if a room is available
int is_room_available(int room_no, int check_in_date, int check_out_date) {
    for (int i = 0; i < 100; i++) {
        if (guests[i].room_no == room_no && (guests[i].check_in_date <= check_in_date && guests[i].check_out_date >= check_out_date)) {
            return 0;
        }
    }

    return 1;
}

// Function to book a room
int book_room(int guest_id, int room_no, int check_in_date, int check_out_date) {
    // Check if the guest ID is valid
    guest *guest = search_guest_by_id(guest_id);
    if (guest == NULL) {
        printf("Invalid guest ID.\n");
        return -1;
    }

    // Check if the room is available
    if (!is_room_available(room_no, check_in_date, check_out_date)) {
        printf("Room not available.\n");
        return -1;
    }

    // Update the guest's room number and check-in/check-out dates
    guest->room_no = room_no;
    guest->check_in_date = check_in_date;
    guest->check_out_date = check_out_date;
    guest->no_of_days = check_out_date - check_in_date;

    printf("Room booked successfully.\n");
    return 0;
}

// Function to check out a guest
int check_out_guest(int guest_id) {
    // Check if the guest ID is valid
    guest *guest = search_guest_by_id(guest_id);
    if (guest == NULL) {
        printf("Invalid guest ID.\n");
        return -1;
    }

    // Calculate the bill amount
    guest->bill_amount = guest->no_of_days * 100;

    // Update the guest's check-out date
    guest->check_out_date = time(NULL);

    printf("Guest checked out successfully.\n");
    return 0;
}

// Main function
int main() {
    // Add some sample guests
    add_guest(1, "John Doe", "123 Main Street", "555-1212", "john.doe@email.com", 101, time(NULL), time(NULL) + 3);
    add_guest(2, "Jane Doe", "456 Elm Street", "555-1213", "jane.doe@email.com", 102, time(NULL) + 1, time(NULL) + 4);
    add_guest(3, "John Smith", "789 Oak Street", "555-1214", "john.smith@email.com", 103, time(NULL) + 2, time(NULL) + 5);

    // Search for a guest by ID
    guest *guest = search_guest_by_id(2);
    if (guest != NULL) {
        printf("Guest found: %s\n", guest->name);
    } else {
        printf("Guest not found.\n");
    }

    // Search for a guest by name
    guest = search_guest_by_name("John Smith");
    if (guest != NULL) {
        printf("Guest found: %s\n", guest->name);
    } else {
        printf("Guest not found.\n");
    }

    // Check if a room is available
    if (is_room_available(101, time(NULL) + 1, time(NULL) + 3)) {
        printf("Room 101 is available.\n");
    } else {
        printf("Room 101 is not available.\n");
    }

    // Book a room
    book_room(1, 101, time(NULL) + 1, time(NULL) + 3);

    // Check out a guest
    check_out_guest(1);

    return 0;
}