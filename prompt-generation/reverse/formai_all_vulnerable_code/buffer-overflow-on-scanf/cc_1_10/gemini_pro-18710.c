//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// A struct to store guest information
typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    int room_number;
    int days_stayed;
    float bill_amount;
} guest;

// A function to display the main menu
void main_menu() {
    printf("\n\n** Welcome to the Cheerful Hotel Management System! **\n\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");
    printf("3. View Guest List\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

// A function to add a new guest to the system
void check_in() {
    guest new_guest;

    printf("\nEnter guest name: ");
    scanf(" %[^\n]%*c", new_guest.name);

    printf("Enter guest address: ");
    scanf(" %[^\n]%*c", new_guest.address);

    printf("Enter guest phone number: ");
    scanf(" %[^\n]%*c", new_guest.phone);

    printf("Enter room number: ");
    scanf("%d", &new_guest.room_number);

    printf("Enter number of days stayed: ");
    scanf("%d", &new_guest.days_stayed);

    new_guest.bill_amount = new_guest.days_stayed * 100;

    printf("\nGuest added successfully!\n\n");
}

// A function to check out a guest from the system
void check_out() {
    int room_number;

    printf("\nEnter room number: ");
    scanf("%d", &room_number);

    // Search for the guest in the list
    guest *found_guest = NULL;

    // TODO: Add code to search for the guest in the list based on the room number

    if (found_guest == NULL) {
        printf("\nGuest not found!\n\n");
        return;
    }

    // Calculate the bill amount
    float bill_amount = found_guest->days_stayed * 100;

    // Print the bill
    printf("\n** Guest Bill **\n\n");
    printf("Name: %s\n", found_guest->name);
    printf("Room Number: %d\n", found_guest->room_number);
    printf("Days Stayed: %d\n", found_guest->days_stayed);
    printf("Bill Amount: %.2f\n\n", bill_amount);

    // Remove the guest from the list
    // TODO: Add code to remove the guest from the list
}

// A function to view the list of guests
void view_guest_list() {
    // TODO: Add code to display the list of guests
}

// The main function
int main() {
    int choice;

    do {
        main_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_in();
                break;
            case 2:
                check_out();
                break;
            case 3:
                view_guest_list();
                break;
            case 4:
                printf("\nThank you for using the Cheerful Hotel Management System!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n\n");
        }
    } while (choice != 4);

    return 0;
}