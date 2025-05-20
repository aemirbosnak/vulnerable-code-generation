//FormAI DATASET v1.0 Category: Hotel Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing hotel guest information
struct guest {
    char name[50];
    int room_number;
    int nights;
    float total_cost;
};

// Function to display the main menu
void display_menu() {
    printf("=============== HOTEL MANAGEMENT SYSTEM ===============\n");
    printf("1. Add Guest\n");
    printf("2. Display Guests\n");
    printf("3. Search Guest\n");
    printf("4. Delete Guest\n");
    printf("5. Exit System\n");
    printf("======================================================\n");
    printf("Enter your choice: ");
}

// Function to add a new guest
void add_guest(struct guest *guests, int *num_guests) {
    printf("================== ADD GUEST ==================\n");
    printf("Enter guest name: ");
    scanf("%s", guests[*num_guests].name);
    printf("Enter room number: ");
    scanf("%d", &guests[*num_guests].room_number);
    printf("Enter number of nights: ");
    scanf("%d", &guests[*num_guests].nights);
    guests[*num_guests].total_cost = guests[*num_guests].nights * 120; // Assuming $120 per night

    printf("Guest added successfully.\n");

    (*num_guests)++;
}

// Function to display all guests
void display_guests(struct guest *guests, int num_guests) {
    printf("================== GUEST LIST ==================\n");
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i+1);
        printf("Name: %s\n", guests[i].name);
        printf("Room Number: %d\n", guests[i].room_number);
        printf("Number of Nights: %d\n", guests[i].nights);
        printf("Total Cost: $%.2f\n", guests[i].total_cost);
    }
}

// Function to search for a guest by name
void search_guest(struct guest *guests, int num_guests) {
    char search_name[50];
    printf("================== SEARCH GUEST ==================\n");
    printf("Enter guest name: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, search_name) == 0) {
            printf("Guest found!\n");
            printf("Name: %s\n", guests[i].name);
            printf("Room Number: %d\n", guests[i].room_number);
            printf("Number of Nights: %d\n", guests[i].nights);
            printf("Total Cost: $%.2f\n", guests[i].total_cost);
            return;
        }
    }

    printf("Guest not found.\n");
}

// Function to delete a guest by name
void delete_guest(struct guest *guests, int *num_guests) {
    char delete_name[50];
    printf("================== DELETE GUEST ==================\n");
    printf("Enter guest name: ");
    scanf("%s", delete_name);

    for (int i = 0; i < *num_guests; i++) {
        if (strcmp(guests[i].name, delete_name) == 0) {
            printf("Guest deleted!\n");

            // Shift remaining guests back one element
            for (int j = i + 1; j < *num_guests; j++) {
                guests[j-1] = guests[j];
            }

            (*num_guests)--;
            return;
        }
    }

    printf("Guest not found.\n");
}

// Main function
int main() {
    struct guest guests[100];
    int num_guests = 0;

    int choice = 0;
    while (choice != 5) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest(guests, &num_guests);
                break;
            case 2:
                if (num_guests == 0) {
                    printf("No guests to display.\n");
                } else {
                    display_guests(guests, num_guests);
                }
                break;
            case 3:
                if (num_guests == 0) {
                    printf("No guests to search.\n");
                } else {
                    search_guest(guests, num_guests);
                }
                break;
            case 4:
                if (num_guests == 0) {
                    printf("No guests to delete.\n");
                } else {
                    delete_guest(guests, &num_guests);
                }
                break;
            case 5:
                printf("Exiting hotel management system...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}