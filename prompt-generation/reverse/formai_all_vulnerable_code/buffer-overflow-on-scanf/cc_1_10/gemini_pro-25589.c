//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store guest information
typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    int room_number;
    int days_stayed;
} guest;

// Function to add a new guest
void add_guest(guest* guests, int* num_guests) {
    // Get guest information from the user
    printf("Enter guest name: ");
    scanf("%s", guests[*num_guests].name);

    printf("Enter guest address: ");
    scanf(" %[^\n]%*c", guests[*num_guests].address);

    printf("Enter guest phone: ");
    scanf("%s", guests[*num_guests].phone);

    // Assign a room number to the guest
    guests[*num_guests].room_number = *num_guests + 1;

    // Get the number of days the guest will be staying
    printf("Enter number of days the guest will be staying: ");
    scanf("%d", &guests[*num_guests].days_stayed);

    // Increment the number of guests
    (*num_guests)++;
}

// Function to display guest information
void display_guest_info(guest* guests, int num_guests) {
    // Loop through the array of guests and display their information
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Phone: %s\n", guests[i].phone);
        printf("Room number: %d\n", guests[i].room_number);
        printf("Days stayed: %d\n", guests[i].days_stayed);
        printf("\n");
    }
}

// Function to search for a guest by name
int search_guest_by_name(guest* guests, int num_guests, char* name) {
    // Loop through the array of guests and search for the guest by name
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            // Guest found, return the index of the guest
            return i;
        }
    }

    // Guest not found, return -1
    return -1;
}

// Function to check in a guest
void check_in_guest(guest* guests, int num_guests, char* name) {
    // Search for the guest by name
    int guest_index = search_guest_by_name(guests, num_guests, name);

    // If the guest is not found, display an error message
    if (guest_index == -1) {
        printf("Guest not found.\n");
        return;
    }

    // If the guest is already checked in, display an error message
    if (guests[guest_index].room_number != 0) {
        printf("Guest is already checked in.\n");
        return;
    }

    // Assign a room number to the guest
    guests[guest_index].room_number = num_guests + 1;

    // Display a success message
    printf("Guest checked in successfully.\n");
}

// Function to check out a guest
void check_out_guest(guest* guests, int num_guests, char* name) {
    // Search for the guest by name
    int guest_index = search_guest_by_name(guests, num_guests, name);

    // If the guest is not found, display an error message
    if (guest_index == -1) {
        printf("Guest not found.\n");
        return;
    }

    // If the guest is not checked in, display an error message
    if (guests[guest_index].room_number == 0) {
        printf("Guest is not checked in.\n");
        return;
    }

    // Calculate the total cost of the stay
    int total_cost = guests[guest_index].days_stayed * 100;

    // Display the total cost of the stay
    printf("Total cost of stay: %d\n", total_cost);

    // Check out the guest
    guests[guest_index].room_number = 0;

    // Display a success message
    printf("Guest checked out successfully.\n");
}

// Main function
int main() {
    // Array to store guest information
    guest guests[100];

    // Number of guests
    int num_guests = 0;

    // Main loop
    while (1) {
        // Display the menu
        printf("1. Add a new guest\n");
        printf("2. Display guest information\n");
        printf("3. Check in a guest\n");
        printf("4. Check out a guest\n");
        printf("5. Exit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_guest(guests, &num_guests);
                break;
            case 2:
                display_guest_info(guests, num_guests);
                break;
            case 3:
                {
                    char name[50];
                    printf("Enter guest name: ");
                    scanf("%s", name);
                    check_in_guest(guests, num_guests, name);
                    break;
                }
            case 4:
                {
                    char name[50];
                    printf("Enter guest name: ");
                    scanf("%s", name);
                    check_out_guest(guests, num_guests, name);
                    break;
                }
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}