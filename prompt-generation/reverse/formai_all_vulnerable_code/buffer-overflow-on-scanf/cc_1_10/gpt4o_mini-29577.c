//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 100
#define NAME_LENGTH 50
#define ROOM_LENGTH 15

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char room[ROOM_LENGTH];
    int nights;
    double price_per_night;
    double total_amount;
} Guest;

Guest guests[MAX_GUESTS];
int guest_count = 0;

void add_guest() {
    if (guest_count == MAX_GUESTS) {
        printf("Guest limit reached. Cannot add more guests.\n");
        return;
    }
    
    Guest new_guest;
    new_guest.id = guest_count + 1;
    
    printf("Enter guest name: ");
    getchar(); // to consume leftover newline from previous input
    fgets(new_guest.name, NAME_LENGTH, stdin);
    new_guest.name[strcspn(new_guest.name, "\n")] = 0; // Remove newline character

    printf("Enter room number: ");
    fgets(new_guest.room, ROOM_LENGTH, stdin);
    new_guest.room[strcspn(new_guest.room, "\n")] = 0; // Remove newline character

    printf("Enter number of nights: ");
    scanf("%d", &new_guest.nights);
    
    printf("Enter price per night: ");
    scanf("%lf", &new_guest.price_per_night);
    
    new_guest.total_amount = new_guest.nights * new_guest.price_per_night;
    
    guests[guest_count] = new_guest;
    guest_count++;
    
    printf("Guest added successfully! ID: %d\n", new_guest.id);
}

void display_guests() {
    if (guest_count == 0) {
        printf("No guests currently registered.\n");
        return;
    }
    
    printf("\n--- List of Guests ---\n");
    for (int i = 0; i < guest_count; i++) {
        printf("ID: %d, Name: %s, Room: %s, Nights: %d, Price/Night: %.2f, Total: %.2f\n", 
                guests[i].id, guests[i].name, guests[i].room, guests[i].nights, 
                guests[i].price_per_night, guests[i].total_amount);
    }
}

void check_availability() {
    char room[ROOM_LENGTH];
    printf("Enter room number to check availability: ");
    getchar(); // to consume leftover newline from previous input
    fgets(room, ROOM_LENGTH, stdin);
    room[strcspn(room, "\n")] = 0; // Remove newline character

    int available = 1; // Assume room is available
    for (int i = 0; i < guest_count; i++) {
        if (strcmp(guests[i].room, room) == 0) {
            available = 0; // Room is not available
            break;
        }
    }

    if (available) {
        printf("Room %s is available.\n", room);
    } else {
        printf("Room %s is already booked.\n", room);
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Check Availability\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                display_guests();
                break;
            case 3:
                check_availability();
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}