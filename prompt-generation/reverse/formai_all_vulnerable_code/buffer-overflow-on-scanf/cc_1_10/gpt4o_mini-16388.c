//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ROOM_NUMBER 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char room_number[MAX_ROOM_NUMBER];
    int nights;
    double price_per_night;
} Guest;

Guest guests[MAX_GUESTS];
int guest_count = 0;

void add_guest() {
    if (guest_count >= MAX_GUESTS) {
        printf("Guest limit reached!\n");
        return;
    }
    
    Guest new_guest;
    printf("Enter guest name: ");
    scanf("%s", new_guest.name);
    printf("Enter room number: ");
    scanf("%s", new_guest.room_number);
    printf("Enter number of nights: ");
    scanf("%d", &new_guest.nights);
    printf("Enter price per night: ");
    scanf("%lf", &new_guest.price_per_night);
    
    guests[guest_count] = new_guest;
    guest_count++;
    printf("Guest added successfully!\n");
}

void display_guests() {
    if (guest_count == 0) {
        printf("No guests available.\n");
        return;
    }
    
    printf("\n--- List of Guests ---\n");
    for (int i = 0; i < guest_count; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Room Number: %s\n", guests[i].room_number);
        printf("Number of Nights: %d\n", guests[i].nights);
        printf("Price Per Night: %.2f\n", guests[i].price_per_night);
        printf("Total Price: %.2f\n", guests[i].nights * guests[i].price_per_night);
        printf("-------------------------\n");
    }
}

void search_guest() {
    char name[MAX_NAME_LENGTH];
    printf("Enter guest name to search: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < guest_count; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            found = 1;
            printf("Guest Found:\n");
            printf("Name: %s\n", guests[i].name);
            printf("Room Number: %s\n", guests[i].room_number);
            printf("Number of Nights: %d\n", guests[i].nights);
            printf("Price Per Night: %.2f\n", guests[i].price_per_night);
            printf("Total Price: %.2f\n", guests[i].nights * guests[i].price_per_night);
            break;
        }
    }
    
    if (!found) {
        printf("Guest not found.\n");
    }
}

void menu() {
    while (1) {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Search for Guest\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_guest();
                break;
            case 2:
                display_guests();
                break;
            case 3:
                search_guest();
                break;
            case 4:
                printf("Exiting the Hotel Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}