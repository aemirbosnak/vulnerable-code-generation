//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
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
    int days_stayed;
    float bill_amount;
} guest;

// Function to add a new guest
void add_guest(guest *guests, int *num_guests) {
    // Get guest information from the user
    printf("Enter guest name: ");
    scanf("%s", guests[*num_guests].name);

    printf("Enter guest address: ");
    scanf(" %[^\n]%*c", guests[*num_guests].address);

    printf("Enter guest phone number: ");
    scanf("%s", guests[*num_guests].phone);

    printf("Enter guest email address: ");
    scanf("%s", guests[*num_guests].email);

    // Generate a random room number
    guests[*num_guests].room_number = rand() % 100 + 1;

    // Set the number of days stayed to 0
    guests[*num_guests].days_stayed = 0;

    // Set the bill amount to 0
    guests[*num_guests].bill_amount = 0;

    // Increment the number of guests
    (*num_guests)++;
}

// Function to check in a guest
void check_in_guest(guest *guests, int *num_guests) {
    // Get the guest's name
    char name[50];
    printf("Enter guest name: ");
    scanf("%s", name);

    // Find the guest by name
    int i;
    for (i = 0; i < *num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            break;
        }
    }

    // If the guest was not found, print an error message
    if (i == *num_guests) {
        printf("Guest not found.\n");
        return;
    }

    // Check if the guest is already checked in
    if (guests[i].days_stayed > 0) {
        printf("Guest is already checked in.\n");
        return;
    }

    // Check in the guest
    guests[i].days_stayed = 1;
}

// Function to check out a guest
void check_out_guest(guest *guests, int *num_guests) {
    // Get the guest's name
    char name[50];
    printf("Enter guest name: ");
    scanf("%s", name);

    // Find the guest by name
    int i;
    for (i = 0; i < *num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            break;
        }
    }

    // If the guest was not found, print an error message
    if (i == *num_guests) {
        printf("Guest not found.\n");
        return;
    }

    // Check if the guest is already checked out
    if (guests[i].days_stayed == 0) {
        printf("Guest is already checked out.\n");
        return;
    }

    // Calculate the bill amount
    guests[i].bill_amount = guests[i].days_stayed * 100;

    // Check out the guest
    guests[i].days_stayed = 0;
}

// Function to print the guest list
void print_guest_list(guest *guests, int num_guests) {
    printf("Guest List:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("%s\n", guests[i].name);
    }
}

// Function to print the guest information
void print_guest_info(guest *guests, int num_guests) {
    // Get the guest's name
    char name[50];
    printf("Enter guest name: ");
    scanf("%s", name);

    // Find the guest by name
    int i;
    for (i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            break;
        }
    }

    // If the guest was not found, print an error message
    if (i == num_guests) {
        printf("Guest not found.\n");
        return;
    }

    // Print the guest information
    printf("Guest Information:\n");
    printf("Name: %s\n", guests[i].name);
    printf("Address: %s\n", guests[i].address);
    printf("Phone: %s\n", guests[i].phone);
    printf("Email: %s\n", guests[i].email);
    printf("Room Number: %d\n", guests[i].room_number);
    printf("Days Stayed: %d\n", guests[i].days_stayed);
    printf("Bill Amount: %.2f\n", guests[i].bill_amount);
}

// Main function
int main() {
    // Initialize the guest list
    guest guests[100];
    int num_guests = 0;

    // Main menu
    int choice;
    do {
        printf("\nCyberpunk Hotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. Check In Guest\n");
        printf("3. Check Out Guest\n");
        printf("4. Print Guest List\n");
        printf("5. Print Guest Information\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_guest(guests, &num_guests);
                break;
            case 2:
                check_in_guest(guests, &num_guests);
                break;
            case 3:
                check_out_guest(guests, &num_guests);
                break;
            case 4:
                print_guest_list(guests, num_guests);
                break;
            case 5:
                print_guest_info(guests, num_guests);
                break;
            case 6:
                printf("Exiting Cyberpunk Hotel Management System.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}