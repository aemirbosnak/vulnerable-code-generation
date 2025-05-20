//FormAI DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about each hotel guest
typedef struct {
    char name[50];
    int room_number;
    int nights_stayed;
    float total_bill;
} Guest;

// Function to initialize a new guest struct
Guest* create_guest(char name[], int room_number, int nights_stayed, float total_bill) {
    Guest* new_guest = malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->nights_stayed = nights_stayed;
    new_guest->total_bill = total_bill;
    return new_guest;
}

// Function to display guest information
void display_guest(Guest* guest) {
    printf("Name: %s\n", guest->name);
    printf("Room Number: %d\n", guest->room_number);
    printf("Nights Stayed: %d\n", guest->nights_stayed);
    printf("Total Bill: %.2f\n", guest->total_bill);
}

// Main function
int main() {
    // Initialize array to hold up to 100 guests
    Guest* guests[100];
    int num_guests = 0;

    // Display menu options
    printf("Welcome to the Hotel Management System!\n");
    printf("1. Add Guest\n");
    printf("2. Display Guest Information\n");
    printf("3. Exit\n");

    // Loop until user chooses to exit
    int choice = 0;
    while (choice != 3) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1: {
                // Get guest information from user
                char name[50];
                int room_number, nights_stayed;
                float total_bill;
                printf("Enter guest name: ");
                scanf("%s", name);
                printf("Enter room number: ");
                scanf("%d", &room_number);
                printf("Enter number of nights stayed: ");
                scanf("%d", &nights_stayed);
                printf("Enter total bill amount: ");
                scanf("%f", &total_bill);

                // Create new guest and add to array
                Guest* new_guest = create_guest(name, room_number, nights_stayed, total_bill);
                guests[num_guests] = new_guest;
                num_guests++;

                printf("\nGuest Added!\n\n");
                break;
            }
            case 2: {
                // Get room number from user
                int room_number;
                printf("Enter room number to display information: ");
                scanf("%d", &room_number);

                // Search for guest with matching room number
                int i;
                for (i = 0; i < num_guests; i++) {
                    if (guests[i]->room_number == room_number) {
                        // Found matching guest, display information
                        printf("\nGuest Information:\n");
                        display_guest(guests[i]);
                        break;
                    }
                }

                // If no matching guest was found
                if (i == num_guests) {
                    printf("\nNo guest found with that room number.\n\n");
                }

                break;
            }
            case 3: {
                // Exit program
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice, please try again.\n\n");
                break;
            }
        }
    }

    // Free memory allocated for each guest
    int i;
    for (i = 0; i < num_guests; i++) {
        free(guests[i]);
    }

    return 0;
}