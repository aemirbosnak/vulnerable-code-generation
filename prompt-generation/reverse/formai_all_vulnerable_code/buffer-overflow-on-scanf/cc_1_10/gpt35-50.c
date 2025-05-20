//FormAI DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int room_num;
    int days_staying;
    float total_bill;
};

void check_in(struct guest *hotel_guests, int max_rooms);
void check_out(struct guest *hotel_guests, int max_rooms);
void view_guests(struct guest *hotel_guests, int max_rooms);

int main() {

    int max_rooms = 10; // maximum number of rooms in hotel

    // create array of guest structures
    struct guest hotel_guests[max_rooms];

    int choice;

    do {
        printf("\nHotel Management System\n\n");
        printf("1: Check In\n");
        printf("2: Check Out\n");
        printf("3: View Guests\n");
        printf("4: Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                check_in(hotel_guests, max_rooms);
                break;
            case 2:
                check_out(hotel_guests, max_rooms);
                break;
            case 3:
                view_guests(hotel_guests, max_rooms);
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void check_in(struct guest *hotel_guests, int max_rooms) {
    int i;
    int free_room = -1;

    for (i = 0; i < max_rooms; i++) {
        if (hotel_guests[i].room_num == 0) { // room is empty
            free_room = i; // mark room as available
            break;
        }
    }

    if (free_room == -1) {
        printf("\nSorry, the hotel is fully booked.\n");
    } else {
        printf("\nRoom available! Please enter the following information:\n");

        // get guest info from user
        printf("Name: ");
        scanf("%s", hotel_guests[free_room].name);
        printf("Room Number: ");
        scanf("%d", &hotel_guests[free_room].room_num);
        printf("Days Staying: ");
        scanf("%d", &hotel_guests[free_room].days_staying);

        // calculate total bill based on room rate and number of days staying
        float room_rate = 50.0; // $50 per night
        hotel_guests[free_room].total_bill = room_rate * hotel_guests[free_room].days_staying;

        printf("\nCheck in successful!\n");
    }
}

void check_out(struct guest *hotel_guests, int max_rooms) {
    int room_num;
    int i;
    int checked_out = 0;

    printf("\nEnter the room number of the guest checking out: ");
    scanf("%d", &room_num);

    for (i = 0; i < max_rooms; i++) {
        if (hotel_guests[i].room_num == room_num) { // guest found
            printf("\nGuest found!\n");

            // display guest info and total bill
            printf("Name: %s\n", hotel_guests[i].name);
            printf("Room Number: %d\n", hotel_guests[i].room_num);
            printf("Days Staying: %d\n", hotel_guests[i].days_staying);
            printf("Total Bill: $%.2f\n", hotel_guests[i].total_bill);

            // mark room as available
            hotel_guests[i].room_num = 0;
            checked_out = 1;
            break;
        }
    }

    if (!checked_out) {
        printf("\nSorry, guest not found.\n");
    } else {
        printf("\nCheck out successful!\n");
    }
}

void view_guests(struct guest *hotel_guests, int max_rooms) {
    int i;
    int guests_exist = 0;

    printf("\nGuest List:\n\n");

    for (i = 0; i < max_rooms; i++) {
        if (hotel_guests[i].room_num != 0) { // guest exists
            printf("Name: %s\n", hotel_guests[i].name);
            printf("Room Number: %d\n", hotel_guests[i].room_num);
            printf("Days Staying: %d\n", hotel_guests[i].days_staying);
            printf("Total Bill: $%.2f\n", hotel_guests[i].total_bill);
            printf("\n");
            guests_exist = 1;
        }
    }

    if (!guests_exist) {
        printf("No guests checked in.\n");
    }
}