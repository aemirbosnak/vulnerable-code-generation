//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

struct guest {
    int room_no;
    char name[50];
    char address[100];
    char phone_no[15];
    int days_spent;
    float bill;
};

struct guest guests[100]; // Holds information of 100 guests
int total_guests = 0;

// Function to add a new guest
void add_guest() {
    struct guest new_guest;
    printf("Enter room number: ");
    scanf("%d", &new_guest.room_no);
    printf("Enter guest name: ");
    scanf("%s", &new_guest.name);
    printf("Enter guest address: ");
    scanf("%s", &new_guest.address);
    printf("Enter guest phone number: ");
    scanf("%s", &new_guest.phone_no);
    printf("Enter number of days spent: ");
    scanf("%d", &new_guest.days_spent);
    printf("Enter bill amount: ");
    scanf("%f", &new_guest.bill);
    guests[total_guests++] = new_guest; // Add new_guest to guests array
    printf("New guest added successfully!\n");
}

// Function to remove a guest by room number
void remove_guest() {
    int room_no;
    printf("Enter room number of the guest to be removed: ");
    scanf("%d", &room_no);
    int index = -1;
    for (int i = 0; i < total_guests; i++) {
        if (guests[i].room_no == room_no) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Guest with room number %d not found.\n", room_no);
    } else {
        for (int i = index; i < total_guests - 1; i++) {
            guests[i] = guests[i + 1];
        }
        total_guests--;
        printf("Guest with room number %d removed successfully!\n", room_no);
    }
}

// Function to display details of all guests
void display_all_guests() {
    printf("\n== All Guests ==\n\n");
    for (int i = 0; i < total_guests; i++) {
        printf("Guest %d\n", i + 1);
        printf("Room Number: %d\n", guests[i].room_no);
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Phone number: %s\n", guests[i].phone_no);
        printf("Days spent: %d\n", guests[i].days_spent);
        printf("Bill: %.2f\n", guests[i].bill);
        printf("--------------------\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n== C Hotel Management System ==\n\n");
        printf("1. Add Guest\n");
        printf("2. Remove Guest\n");
        printf("3. Display all Guests\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                remove_guest();
                break;
            case 3:
                display_all_guests();
                break;
            case 4:
                printf("\nExiting... Have a nice day!\n");
                return 0;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}