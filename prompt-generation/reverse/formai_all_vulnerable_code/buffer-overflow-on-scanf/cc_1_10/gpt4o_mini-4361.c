//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define NAME_LENGTH 50
#define ROOM_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char room[ROOM_LENGTH];
    int nights;
    float total_cost;
} Guest;

Guest guests[MAX_GUESTS];
int guest_count = 0;

void add_guest() {
    if (guest_count >= MAX_GUESTS) {
        printf("\nHotel is fully booked. Unable to add more guests.\n");
        return;
    }

    Guest new_guest;
    printf("\nEnter guest's name: ");
    scanf("%s", new_guest.name);
    printf("Enter room number: ");
    scanf("%s", new_guest.room);
    printf("Enter number of nights: ");
    scanf("%d", &new_guest.nights);
    
    new_guest.total_cost = new_guest.nights * 100.0; // Assuming a flat rate of 100 per night
    guests[guest_count++] = new_guest;
    printf("\nGuest added successfully!\n");
}

void view_guests() {
    if (guest_count == 0) {
        printf("\nNo guests currently checked in.\n");
        return;
    }
    printf("\nCurrent Guests:\n");
    for (int i = 0; i < guest_count; i++) {
        printf("Name: %s, Room: %s, Nights: %d, Total Cost: $%.2f\n", 
                guests[i].name, guests[i].room, guests[i].nights, guests[i].total_cost);
    }
}

void checkout_guest() {
    if (guest_count == 0) {
        printf("\nNo guests to check out.\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("\nEnter guest's name for checkout: ");
    scanf("%s", name);

    for (int i = 0; i < guest_count; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            printf("\nChecking out guest %s from room %s.\n", guests[i].name, guests[i].room);
            for (int j = i; j < guest_count - 1; j++) {
                guests[j] = guests[j + 1];
            }
            guest_count--;
            printf("Guest checked out successfully!\n");
            return;
        }
    }
    printf("\nGuest not found.\n");
}

void calculate_total_revenue() {
    float total_revenue = 0.0;
    for (int i = 0; i < guest_count; i++) {
        total_revenue += guests[i].total_cost;
    }
    printf("\nTotal revenue from current guests: $%.2f\n", total_revenue);
}

void display_menu() {
    printf("\n=========================\n");
    printf("   Hotel Management Menu  \n");
    printf("=========================\n");
    printf("1. Add Guest\n");
    printf("2. View Guests\n");
    printf("3. Checkout Guest\n");
    printf("4. Calculate Total Revenue\n");
    printf("5. Exit\n");
    printf("=========================\n");
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Please choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_guest();
                break;
            case 2:
                view_guests();
                break;
            case 3:
                checkout_guest();
                break;
            case 4:
                calculate_total_revenue();
                break;
            case 5:
                printf("Goodbye! Thank you for using the Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}