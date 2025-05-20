//FormAI DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold guest information
typedef struct {
    char name[50];
    int room_number;
    int nights_stayed;
    float balance;
} Guest;

// Function to display guest information
void display_guest(Guest guest) {
    printf("Name: %s\n", guest.name);
    printf("Room Number: %d\n", guest.room_number);
    printf("Nights Stayed: %d\n", guest.nights_stayed);
    printf("Balance: $%.2f\n", guest.balance);
    printf("============================================\n");
}

// Function to check in a guest
void check_in(Guest* guest_list, int num_guests) {
    printf("Please enter guest name: ");
    char name[50];
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0'; // Remove newline character

    int room_number;
    printf("Please enter room number: ");
    scanf("%d", &room_number);

    int nights_stayed;
    printf("Please enter number of nights stayed: ");
    scanf("%d", &nights_stayed);

    // Create new guest
    Guest new_guest;
    strcpy(new_guest.name, name);
    new_guest.room_number = room_number;
    new_guest.nights_stayed = nights_stayed;
    new_guest.balance = 0.0;

    // Add new guest to guest list
    guest_list[num_guests] = new_guest;
    num_guests++;

    printf("\nGuest successfully checked in!\n");
    printf("============================================\n");
}

// Function to check out a guest
void check_out(Guest* guest_list, int num_guests) {
    int room_number;
    printf("Please enter room number: ");
    scanf("%d", &room_number);

    // Find guest with matching room number
    int index = -1;
    for (int i = 0; i < num_guests; i++) {
        if (guest_list[i].room_number == room_number) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nSorry, no guest found with that room number.\n");
        printf("============================================\n");
        return;
    }

    // Calculate balance due
    float room_rate = 120.0; // $120 per night
    float balance = room_rate * guest_list[index].nights_stayed;
    guest_list[index].balance = balance;

    printf("\nGuest successfully checked out!\n");
    printf("Total Balance Due: $%.2f\n", guest_list[index].balance);
    printf("============================================\n");

    // Remove guest from guest list
    for (int i = index; i < num_guests - 1; i++) {
        guest_list[i] = guest_list[i + 1];
    }
    num_guests--;
}

int main() {
    int num_guests = 0;
    Guest guest_list[50];

    while (1) {
        printf("Welcome to the C Hotel Management System!\n");
        printf("Please select an option:\n");
        printf("1. Check In Guest\n");
        printf("2. Check Out Guest\n");
        printf("3. View All Guests\n");
        printf("4. Exit\n");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_in(guest_list, num_guests);
                break;
            case 2:
                check_out(guest_list, num_guests);
                break;
            case 3:
                printf("\nAll Guests:\n");
                for (int i = 0; i < num_guests; i++) {
                    display_guest(guest_list[i]);
                }
                break;
            case 4:
                printf("\nThank you for using C Hotel Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
                printf("============================================\n");
                break;
        }
    }
    
    return 0;
}