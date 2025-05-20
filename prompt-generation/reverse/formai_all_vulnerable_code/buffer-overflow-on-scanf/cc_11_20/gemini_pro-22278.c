//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_number;
    int num_nights;
    float total_cost;
} guest;

int main() {
    guest guests[100];
    int num_guests = 0;

    // Welcome message
    printf("\n=====================================================\n");
    printf("         Welcome to the Grand Hotel Management System!\n");
    printf("=====================================================\n\n");

    // Main loop
    while (1) {
        // Display menu
        printf("\nPlease select an option:\n");
        printf("1. Check in a guest\n");
        printf("2. Check out a guest\n");
        printf("3. Display guest information\n");
        printf("4. Exit\n");
        printf("> ");

        // Get input
        int choice;
        scanf("%d", &choice);

        // Check in a guest
        if (choice == 1) {
            // Get guest information
            printf("\nPlease enter the guest's name: ");
            scanf("%s", guests[num_guests].name);
            printf("Please enter the guest's address: ");
            scanf("%s", guests[num_guests].address);
            printf("Please enter the guest's phone number: ");
            scanf("%s", guests[num_guests].phone);
            printf("Please enter the guest's email address: ");
            scanf("%s", guests[num_guests].email);
            printf("Please enter the guest's room number: ");
            scanf("%d", &guests[num_guests].room_number);
            printf("Please enter the number of nights the guest will be staying: ");
            scanf("%d", &guests[num_guests].num_nights);

            // Calculate the total cost of the stay
            guests[num_guests].total_cost = guests[num_guests].num_nights * 100;

            // Increment the number of guests
            num_guests++;

            // Confirmation message
            printf("\nGuest %s has been checked in successfully!\n", guests[num_guests - 1].name);
        }

        // Check out a guest
        else if (choice == 2) {
            // Get the guest's room number
            printf("\nPlease enter the guest's room number: ");
            int room_number;
            scanf("%d", &room_number);

            // Find the guest by room number
            int guest_index = -1;
            for (int i = 0; i < num_guests; i++) {
                if (guests[i].room_number == room_number) {
                    guest_index = i;
                    break;
                }
            }

            // If the guest was found, check them out
            if (guest_index != -1) {
                // Print the guest's information
                printf("\nGuest %s has checked out.\n", guests[guest_index].name);
                printf("Total cost: %.2f\n", guests[guest_index].total_cost);

                // Remove the guest from the list
                for (int i = guest_index + 1; i < num_guests; i++) {
                    guests[i - 1] = guests[i];
                }
                num_guests--;
            }

            // If the guest was not found, display an error message
            else {
                printf("\nSorry, no guest with that room number was found.\n");
            }
        }

        // Display guest information
        else if (choice == 3) {
            // Get the guest's room number
            printf("\nPlease enter the guest's room number: ");
            int room_number;
            scanf("%d", &room_number);

            // Find the guest by room number
            int guest_index = -1;
            for (int i = 0; i < num_guests; i++) {
                if (guests[i].room_number == room_number) {
                    guest_index = i;
                    break;
                }
            }

            // If the guest was found, display their information
            if (guest_index != -1) {
                printf("\nGuest %s:\n", guests[guest_index].name);
                printf("Address: %s\n", guests[guest_index].address);
                printf("Phone: %s\n", guests[guest_index].phone);
                printf("Email: %s\n", guests[guest_index].email);
                printf("Room number: %d\n", guests[guest_index].room_number);
                printf("Number of nights: %d\n", guests[guest_index].num_nights);
                printf("Total cost: %.2f\n", guests[guest_index].total_cost);
            }

            // If the guest was not found, display an error message
            else {
                printf("\nSorry, no guest with that room number was found.\n");
            }
        }

        // Exit the program
        else if (choice == 4) {
            printf("\nThank you for using the Grand Hotel Management System! Have a wonderful day!\n");
            break;
        }

        // Invalid choice
        else {
            printf("\nInvalid choice. Please select a number between 1 and 4.\n");
        }
    }

    return 0;
}