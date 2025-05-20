//FormAI DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int room_no;
    int stay_duration;
    int total_bill;
} Guest;

void clear_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void add_new_guest(Guest *guests, int *num_guests) {
    printf("\nEnter guest name: ");
    clear_buffer();
    fgets(guests[*num_guests].name, sizeof(guests[*num_guests].name), stdin);
    printf("Enter room number: ");
    scanf("%d", &guests[*num_guests].room_no);
    printf("Enter stay duration in days: ");
    scanf("%d", &guests[*num_guests].stay_duration);
    guests[*num_guests].total_bill = guests[*num_guests].stay_duration * 100;

    printf("\nGuest added successfully!\n");
    printf("Name: %sRoom Number: %d\nTotal Bill: %d\n", guests[*num_guests].name, guests[*num_guests].room_no, guests[*num_guests].total_bill);

    (*num_guests)++;
}

void remove_guest(Guest *guests, int *num_guests) {
    int room_no;
    printf("\nEnter room number of guest to be removed: ");
    scanf("%d", &room_no);

    int guest_index = -1;
    for (int i = 0; i < *num_guests; i++) {
        if (guests[i].room_no == room_no) {
            guest_index = i;
            break;
        }
    }

    if (guest_index == -1) {
        printf("\nNo guest found with room number: %d\n", room_no);
    } else {
        printf("\nGuest removed successfully!\n");
        printf("Name: %sRoom Number: %d\nTotal Bill: %d\n", guests[guest_index].name, guests[guest_index].room_no, guests[guest_index].total_bill);
        for (int i = guest_index; i < *num_guests - 1; i++) {
            guests[i] = guests[i + 1];
        }
        (*num_guests)--;
    }
}

void view_guests(Guest *guests, int num_guests) {
    if (num_guests == 0) {
        printf("\nNo guests to display!\n");
    } else {
        printf("\nGuests currently staying at the hotel:\n");
        for (int i = 0; i < num_guests; i++) {
            printf("\nName: %s", guests[i].name);
            printf("Room Number: %d\n", guests[i].room_no);
            printf("Total Bill: %d\n", guests[i].total_bill);
        }
    }
}

int main() {
    Guest guests[100];
    int num_guests = 0;
    int choice = -1;

    while (choice != 4) {
        printf("\n\nHOTEL MANAGEMENT SYSTEM\n\n");
        printf("1. Add new guest\n");
        printf("2. Remove guest\n");
        printf("3. View guests\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_new_guest(guests, &num_guests);
                break;
            case 2:
                remove_guest(guests, &num_guests);
                break;
            case 3:
                view_guests(guests, num_guests);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}