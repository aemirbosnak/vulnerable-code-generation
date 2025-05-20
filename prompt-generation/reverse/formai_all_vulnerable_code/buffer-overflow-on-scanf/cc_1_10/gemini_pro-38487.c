//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    char room_type[20];
    int num_nights;
    float total_cost;
} guest_t;

int main() {
    // Create an array of guests
    guest_t guests[100];

    // Initialize the number of guests to 0
    int num_guests = 0;

    // Get the guest information
    printf("Welcome to the Hotel Management System!\n");
    printf("Please enter the guest information:\n");
    for (int i = 0; i < 100; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", guests[i].name);
        printf("Address: ");
        scanf(" %[^\n]%*c", guests[i].address); // Read the entire line, including spaces
        printf("Phone: ");
        scanf("%s", guests[i].phone);
        printf("Email: ");
        scanf("%s", guests[i].email);
        printf("Room Type: ");
        scanf("%s", guests[i].room_type);
        printf("Number of Nights: ");
        scanf("%d", &guests[i].num_nights);

        // Calculate the total cost
        if (strcmp(guests[i].room_type, "Standard") == 0) {
            guests[i].total_cost = 100 * guests[i].num_nights;
        } else if (strcmp(guests[i].room_type, "Deluxe") == 0) {
            guests[i].total_cost = 150 * guests[i].num_nights;
        } else if (strcmp(guests[i].room_type, "Suite") == 0) {
            guests[i].total_cost = 200 * guests[i].num_nights;
        }

        // Increment the number of guests
        num_guests++;

        // Check if the user wants to continue
        char choice;
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n') {
            break;
        }
    }

    // Print the guest information
    printf("\nGuest Information:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Phone: %s\n", guests[i].phone);
        printf("Email: %s\n", guests[i].email);
        printf("Room Type: %s\n", guests[i].room_type);
        printf("Number of Nights: %d\n", guests[i].num_nights);
        printf("Total Cost: $%.2f\n", guests[i].total_cost);
        printf("\n");
    }

    return 0;
}