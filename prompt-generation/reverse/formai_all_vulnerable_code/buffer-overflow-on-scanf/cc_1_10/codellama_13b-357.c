//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
// Hotel Management System Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure for storing guest information
struct guest {
    char name[50];
    char room_number[10];
    int room_type;
};

// Function to add a new guest
void add_guest(struct guest *guests, int *num_guests) {
    // Print a message to the user
    printf("Enter the guest's name: ");
    // Read in the guest's name
    scanf("%s", guests[*num_guests].name);
    // Print a message to the user
    printf("Enter the guest's room number: ");
    // Read in the guest's room number
    scanf("%s", guests[*num_guests].room_number);
    // Print a message to the user
    printf("Enter the guest's room type: ");
    // Read in the guest's room type
    scanf("%d", &guests[*num_guests].room_type);
    // Increment the number of guests
    (*num_guests)++;
}

// Function to display all guests
void display_guests(struct guest *guests, int num_guests) {
    // Print a header
    printf("Guest List\n");
    // Loop through all guests
    for (int i = 0; i < num_guests; i++) {
        // Print the guest's information
        printf("%s: %s (%d)\n", guests[i].name, guests[i].room_number, guests[i].room_type);
    }
}

// Function to update a guest's information
void update_guest(struct guest *guests, int num_guests, int index) {
    // Print a message to the user
    printf("Enter the guest's new information:\n");
    // Read in the new guest's name
    scanf("%s", guests[index].name);
    // Read in the new guest's room number
    scanf("%s", guests[index].room_number);
    // Read in the new guest's room type
    scanf("%d", &guests[index].room_type);
}

// Function to delete a guest
void delete_guest(struct guest *guests, int num_guests, int index) {
    // Shift all guests after the deleted guest to the left
    for (int i = index; i < num_guests - 1; i++) {
        guests[i] = guests[i + 1];
    }
    // Decrement the number of guests
    num_guests--;
}

int main() {
    // Declare an array of guests
    struct guest guests[10];
    // Initialize the number of guests
    int num_guests = 0;

    // Add a new guest
    add_guest(guests, &num_guests);

    // Display all guests
    display_guests(guests, num_guests);

    // Update a guest's information
    update_guest(guests, num_guests, 0);

    // Delete a guest
    delete_guest(guests, num_guests, 0);

    // Display all guests again
    display_guests(guests, num_guests);

    return 0;
}