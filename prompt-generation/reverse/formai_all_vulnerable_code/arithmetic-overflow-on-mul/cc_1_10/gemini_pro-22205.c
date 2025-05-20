//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store guest information
typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_number;
    int nights_stayed;
    float bill_amount;
} guest;

// Function to add a new guest
void add_guest(guest *guests, int *num_guests) {
    // Get guest information from user
    printf("Enter guest name: ");
    scanf("%s", guests[*num_guests].name);

    printf("Enter guest address: ");
    scanf("%s", guests[*num_guests].address);

    printf("Enter guest phone number: ");
    scanf("%s", guests[*num_guests].phone);

    printf("Enter guest email address: ");
    scanf("%s", guests[*num_guests].email);

    printf("Enter guest room number: ");
    scanf("%d", &guests[*num_guests].room_number);

    printf("Enter number of nights stayed: ");
    scanf("%d", &guests[*num_guests].nights_stayed);

    // Calculate bill amount
    guests[*num_guests].bill_amount = guests[*num_guests].nights_stayed * 100;

    // Increment number of guests
    (*num_guests)++;
}

// Function to display guest information
void display_guest(guest guest) {
    printf("Guest name: %s\n", guest.name);
    printf("Guest address: %s\n", guest.address);
    printf("Guest phone number: %s\n", guest.phone);
    printf("Guest email address: %s\n", guest.email);
    printf("Guest room number: %d\n", guest.room_number);
    printf("Guest nights stayed: %d\n", guest.nights_stayed);
    printf("Guest bill amount: %.2f\n", guest.bill_amount);
}

// Function to search for a guest by name
int search_guest_by_name(guest *guests, int num_guests, char *name) {
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to delete a guest by name
void delete_guest_by_name(guest *guests, int *num_guests, char *name) {
    int index = search_guest_by_name(guests, *num_guests, name);

    if (index == -1) {
        printf("Guest not found.\n");
    } else {
        // Shift all guests after the deleted guest to the left
        for (int i = index; i < *num_guests - 1; i++) {
            guests[i] = guests[i + 1];
        }

        // Decrement number of guests
        (*num_guests)--;
    }
}

// Function to display all guests
void display_all_guests(guest *guests, int num_guests) {
    for (int i = 0; i < num_guests; i++) {
        display_guest(guests[i]);
        printf("\n");
    }
}

// Function to sort guests by name
void sort_guests_by_name(guest *guests, int num_guests) {
    for (int i = 0; i < num_guests - 1; i++) {
        for (int j = i + 1; j < num_guests; j++) {
            if (strcmp(guests[i].name, guests[j].name) > 0) {
                guest temp = guests[i];
                guests[i] = guests[j];
                guests[j] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Array of guests
    guest guests[100];

    // Number of guests
    int num_guests = 0;

    // Add some sample guests
    add_guest(guests, &num_guests);
    add_guest(guests, &num_guests);
    add_guest(guests, &num_guests);

    // Display all guests
    printf("All guests:\n");
    display_all_guests(guests, num_guests);

    // Search for a guest by name
    char name[50];
    printf("Enter guest name to search for: ");
    scanf("%s", name);

    int index = search_guest_by_name(guests, num_guests, name);

    if (index == -1) {
        printf("Guest not found.\n");
    } else {
        printf("Guest found:\n");
        display_guest(guests[index]);
    }

    // Delete a guest by name
    printf("Enter guest name to delete: ");
    scanf("%s", name);

    delete_guest_by_name(guests, &num_guests, name);

    // Display all guests after deletion
    printf("All guests after deletion:\n");
    display_all_guests(guests, num_guests);

    // Sort guests by name
    sort_guests_by_name(guests, num_guests);

    // Display all guests after sorting
    printf("All guests after sorting:\n");
    display_all_guests(guests, num_guests);

    return 0;
}