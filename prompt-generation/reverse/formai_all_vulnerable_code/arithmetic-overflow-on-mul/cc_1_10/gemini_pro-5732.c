//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: creative
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
    int num_nights;
    float bill_amount;
} guest;

// Function to add a new guest
void add_guest(guest *guests, int *num_guests) {
    // Get guest information from the user
    printf("Enter guest name: ");
    scanf("%s", guests[*num_guests].name);

    printf("Enter guest address: ");
    scanf(" %[^\n]%*c", guests[*num_guests].address); // Read the entire line

    printf("Enter guest phone number: ");
    scanf("%s", guests[*num_guests].phone);

    printf("Enter guest email address: ");
    scanf("%s", guests[*num_guests].email);

    printf("Enter guest room number: ");
    scanf("%d", &guests[*num_guests].room_number);

    printf("Enter number of nights staying: ");
    scanf("%d", &guests[*num_guests].num_nights);

    // Calculate the bill amount
    guests[*num_guests].bill_amount = guests[*num_guests].num_nights * 100; // Assuming $100 per night

    // Increment the number of guests
    (*num_guests)++;
}

// Function to search for a guest by name
void search_guest(guest *guests, int num_guests) {
    // Get the guest name from the user
    char name[50];
    printf("Enter guest name to search for: ");
    scanf("%s", name);

    // Search for the guest
    int found = 0;
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            // Guest found, print their information
            printf("Guest found:\n");
            printf("Name: %s\n", guests[i].name);
            printf("Address: %s\n", guests[i].address);
            printf("Phone number: %s\n", guests[i].phone);
            printf("Email address: %s\n", guests[i].email);
            printf("Room number: %d\n", guests[i].room_number);
            printf("Number of nights staying: %d\n", guests[i].num_nights);
            printf("Bill amount: $%.2f\n", guests[i].bill_amount);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Guest not found.\n");
    }
}

// Function to print all guests
void print_guests(guest *guests, int num_guests) {
    printf("Guests:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Phone number: %s\n", guests[i].phone);
        printf("Email address: %s\n", guests[i].email);
        printf("Room number: %d\n", guests[i].room_number);
        printf("Number of nights staying: %d\n", guests[i].num_nights);
        printf("Bill amount: $%.2f\n", guests[i].bill_amount);

        printf("\n");
    }
}

// Main function
int main() {
    // Create an array of guests
    guest guests[100];

    // Initialize the number of guests to 0
    int num_guests = 0;

    // Add some sample guests
    add_guest(guests, &num_guests);
    add_guest(guests, &num_guests);

    // Search for a guest by name
    search_guest(guests, num_guests);

    // Print all guests
    print_guests(guests, num_guests);

    return 0;
}