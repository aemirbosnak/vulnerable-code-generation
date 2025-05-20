//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int room_number;
    char check_in_date[20];
    char check_out_date[20];
    int num_of_guests;
} guests[50];

int num_of_guests = 0;
int room_numbers[50];

void check_in_guest() {
    printf("\nEnter guest name: ");
    scanf("%s", guests[num_of_guests].name);

    int room_num;
    do {
        printf("Enter room number (1-50): ");
        scanf("%d", &room_num);

        if (room_numbers[room_num] == 1) {
            printf("Room number is already occupied. Please enter a different room number.\n");
        }
    } while (room_numbers[room_num] == 1);

    guests[num_of_guests].room_number = room_num;
    room_numbers[room_num] = 1;

    printf("Enter check-in date (dd/mm/yyyy): ");
    scanf("%s", guests[num_of_guests].check_in_date);

    printf("Enter check-out date (dd/mm/yyyy): ");
    scanf("%s", guests[num_of_guests].check_out_date);

    printf("Enter number of guests: ");
    scanf("%d", &guests[num_of_guests].num_of_guests);

    num_of_guests++;

    printf("\nGuest checked in successfully!\n");
}

void check_out_guest() {
    int room_num;
    printf("\nEnter room number to check-out: ");
    scanf("%d", &room_num);

    int guest_index = -1;
    for (int i = 0; i < num_of_guests; i++) {
        if (guests[i].room_number == room_num) {
            guest_index = i;
            break;
        }
    }

    if (guest_index == -1) {
        printf("Guest with room number %d was not found.\n", room_num);
    } else {
        printf("Guest with room number %d checked out successfully!\n", room_num);
        room_numbers[room_num] = 0;

        for (int i = guest_index; i < num_of_guests - 1; i++) {
            guests[i] = guests[i + 1];
        }

        num_of_guests--;
    }
}

void display_guests() {
    printf("\nGuests currently checked in:\n\n");
    printf("Name\t\tRoom Number\tCheck-in Date\tCheck-out Date\tNo. of Guests\n");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < num_of_guests; i++) {
        printf("%s\t\t%d\t\t%s\t%s\t%d\n", guests[i].name, guests[i].room_number, guests[i].check_in_date, guests[i].check_out_date, guests[i].num_of_guests);
    }

    printf("\n");
}

int main() {
    for (int i = 1; i <= 50; i++) {
        room_numbers[i] = 0;
    }

    int choice;
    do {
        printf("MENU:\n");
        printf("1. Check-in guest\n");
        printf("2. Check-out guest\n");
        printf("3. Display guests currently checked in\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                check_in_guest();
                break;
            case 2:
                check_out_guest();
                break;
            case 3:
                display_guests();
                break;
            case 4:
                printf("\nExiting Hotel Management System...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice (1-4).\n");
        }
    } while (choice != 4);

    return 0;
}