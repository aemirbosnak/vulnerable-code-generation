//FormAI DATASET v1.0 Category: Hotel Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for the hotel guests
typedef struct guest {
    int id;
    char name[50];
    char room_type[10];
    char check_in_date[20];
    char check_out_date[20];
    float room_rate;
    int status;
} Guest;

// Function prototypes
void check_in(Guest* guest_list, int* guest_count);
void check_out(Guest* guest_list, int* guest_count);
void display_guests(Guest* guest_list, int* guest_count);
void display_menu();

int main() {
    int choice;
    int guest_count = 0;
    Guest* guest_list = NULL;

    while (1) {
        system("clear"); // Clear the screen

        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_in(guest_list, &guest_count);
                break;
            case 2:
                check_out(guest_list, &guest_count);
                break;
            case 3:
                display_guests(guest_list, &guest_count);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Pause so user can read output
        system("read -p 'Press Enter to continue...' var");
    }

    return 0;
}

// Function to check in a new guest
void check_in(Guest* guest_list, int* guest_count) {
    Guest new_guest;

    // Increment the guest count
    (*guest_count)++;

    // Reallocate memory for the additional guest
    guest_list = (Guest*)realloc(guest_list, (*guest_count) * sizeof(Guest));

    // Get guest information
    printf("Enter Guest Name: ");
    scanf("%s", new_guest.name);

    printf("Enter Room Type (S/D/L): ");
    scanf("%s", new_guest.room_type);

    printf("Enter Check-In Date (YYYY-MM-DD): ");
    scanf("%s", new_guest.check_in_date);

    printf("Enter Check-Out Date (YYYY-MM-DD): ");
    scanf("%s", new_guest.check_out_date);

    // Check the room type and assign rate accordingly
    if (strcmp(new_guest.room_type, "S") == 0) {
        new_guest.room_rate = 100.0;
    } else if (strcmp(new_guest.room_type, "D") == 0) {
        new_guest.room_rate = 150.0;
    } else if (strcmp(new_guest.room_type, "L") == 0) {
        new_guest.room_rate = 200.0;
    } else {
        printf("Invalid room type. Guest not added.\n");
        (*guest_count)--;
        return;
    }

    // Assign a unique id to the guest
    new_guest.id = 1000 + (*guest_count);

    // Set the guest status to checked in
    new_guest.status = 1;

    // Add the guest to the list
    guest_list[(*guest_count)-1] = new_guest;

    printf("Guest checked in successfully!\n");
}

// Function to check out an existing guest
void check_out(Guest* guest_list, int* guest_count) {
    int guest_id;
    int found = 0;

    // Get the guest id
    printf("Enter Guest ID to check-out: ");
    scanf("%d", &guest_id);

    // Check if the guest exists and is checked-in
    for (int i = 0; i < (*guest_count); i++) {
        if (guest_list[i].id == guest_id && guest_list[i].status == 1) {
            guest_list[i].status = 0;
            printf("Guest checked out successfully!\n");
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Guest not found or already checked out.\n");
    }
}

// Function to display all guests in the hotel
void display_guests(Guest* guest_list, int* guest_count) {
    printf("-------------------------------\n");
    printf("Guest ID\tName\tRoom Type\tCheck-In Date\tCheck-Out Date\n");
    printf("-------------------------------\n");

    for (int i = 0; i < (*guest_count); i++) {
        printf("%d\t\t%s\t%s\t\t%s\t\t%s\n", guest_list[i].id, guest_list[i].name, guest_list[i].room_type,
            guest_list[i].check_in_date, guest_list[i].check_out_date);
    }

    printf("-------------------------------\n");
}

// Function to display the application menu
void display_menu() {
    printf("-------------------------------\n");
    printf("Hotel Management System\n");
    printf("-------------------------------\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Display guests\n");
    printf("4. Exit\n");
    printf("-------------------------------\n");
}