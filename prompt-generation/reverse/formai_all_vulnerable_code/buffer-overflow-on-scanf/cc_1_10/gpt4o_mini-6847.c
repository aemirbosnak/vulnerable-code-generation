//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define NAME_LEN 50

typedef struct {
    int room_number;
    char guest_name[NAME_LEN];
    int is_checked_in; // 1 if checked in, 0 otherwise
} Guest;

Guest hotel[MAX_GUESTS];
int guest_count = 0;

void add_guest() {
    if (guest_count >= MAX_GUESTS) {
        printf("Hotel is full, cannot add more guests.\n");
        return;
    }
    int room_number;
    char name[NAME_LEN];
    
    printf("Enter room number: ");
    scanf("%d", &room_number);
    getchar(); // consume newline

    printf("Enter guest name: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character

    hotel[guest_count].room_number = room_number;
    strcpy(hotel[guest_count].guest_name, name);
    hotel[guest_count].is_checked_in = 1; // mark guest as checked in
    guest_count++;

    printf("Guest %s added to room %d.\n", name, room_number);
}

void list_guests() {
    if (guest_count == 0) {
        printf("No guests checked in.\n");
        return;
    }

    printf("Current guests:\n");
    for (int i = 0; i < guest_count; i++) {
        if (hotel[i].is_checked_in) {
            printf("Room Number: %d | Guest Name: %s\n", hotel[i].room_number, hotel[i].guest_name);
        }
    }
}

void checkout_guest() {
    int room_number;
    printf("Enter room number to checkout: ");
    scanf("%d", &room_number);

    for (int i = 0; i < guest_count; i++) {
        if (hotel[i].room_number == room_number && hotel[i].is_checked_in) {
            hotel[i].is_checked_in = 0; // mark guest as checked out
            printf("Guest %s checked out from room %d.\n", hotel[i].guest_name, room_number);
            return;
        }
    }
    printf("No guest found in room %d.\n", room_number);
}

void room_status() {
    for (int i = 0; i < guest_count; i++) {
        if (hotel[i].is_checked_in) {
            printf("Room Number: %d is occupied by %s.\n", hotel[i].room_number, hotel[i].guest_name);
        } else {
            printf("Room Number: %d is available.\n", hotel[i].room_number);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nHotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. List Guests\n");
        printf("3. Checkout Guest\n");
        printf("4. Check Room Status\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_guest();
                break;
            case 2:
                list_guests();
                break;
            case 3:
                checkout_guest();
                break;
            case 4:
                room_status();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}