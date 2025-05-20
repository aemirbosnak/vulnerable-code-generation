//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 1000

typedef struct {
    char name[50];
    int room_number;
    int check_in_day;
    int check_out_day;
} Guest;

void add_guest(Guest* guests, int next_free_slot) {
    if (next_free_slot >= MAX_GUESTS) {
        printf("We are completely booked, sir.\n");
        return;
    }

    Guest new_guest;

    printf("What is the name of the new guest?\n");
    scanf("%s", new_guest.name);

    printf("What is the room number?\n");
    scanf("%d", &new_guest.room_number);

    printf("What is the check-in day?\n");
    scanf("%d", &new_guest.check_in_day);

    printf("What is the check-out day?\n");
    scanf("%d", &new_guest.check_out_day);

    guests[next_free_slot] = new_guest;

    printf("New guest added successfully.\n");
}

void remove_guest(Guest* guests, int next_free_slot) {
    printf("What is the name of the guest to remove?\n");

    char guest_name[50];
    scanf("%s", guest_name);

    for (int i = 0; i < next_free_slot; i++) {
        if (strcmp(guests[i].name, guest_name) == 0) {
            guests[i] = guests[next_free_slot - 1];
            printf("Guest removed successfully.\n");
            return;
        }
    }

    printf("Guest not found.\n");
}

void find_guest(Guest* guests, int next_free_slot) {
    printf("What is the name of the guest to find?\n");

    char guest_name[50];
    scanf("%s", guest_name);

    for (int i = 0; i < next_free_slot; i++) {
        if (strcmp(guests[i].name, guest_name) == 0) {
            printf("Guest found:\n");
            printf("- Name: %s\n", guests[i].name);
            printf("- Room number: %d\n", guests[i].room_number);
            printf("- Check-in day: %d\n", guests[i].check_in_day);
            printf("- Check-out day: %d\n", guests[i].check_out_day);
            return;
        }
    }

    printf("Guest not found.\n");
}

void display_guests(Guest* guests, int next_free_slot) {
    printf("Here are all the guests we currently have:\n");

    for (int i = 0; i < next_free_slot; i++) {
        printf("- Name: %s\n", guests[i].name);
        printf("- Room number: %d\n", guests[i].room_number);
        printf("- Check-in day: %d\n", guests[i].check_in_day);
        printf("- Check-out day: %d\n", guests[i].check_out_day);
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Hotel Management System, sir. How can I assist you?\n");

    Guest guests[MAX_GUESTS];
    int next_free_slot = 0;

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a guest\n");
        printf("2. Remove a guest\n");
        printf("3. Find a guest\n");
        printf("4. Display all guests\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest(guests, next_free_slot);
                next_free_slot++;
                break;
            case 2:
                remove_guest(guests, next_free_slot);
                next_free_slot--;
                break;
            case 3:
                find_guest(guests, next_free_slot);
                break;
            case 4:
                display_guests(guests, next_free_slot);
                break;
            case 5:
                printf("Thank you for using our Hotel Management System, sir. Have a pleasant day!\n");
                exit(0);
            default:
                printf("I'm sorry, sir, I didn't quite catch that.\n");
                break;
        }
    }

    return 0;
}