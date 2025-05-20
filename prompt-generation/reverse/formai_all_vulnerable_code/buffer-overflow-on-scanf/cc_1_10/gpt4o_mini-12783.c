//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    int room_number;
    int nights_stayed;
} Guest;

void add_guest(Guest *guests, int *guest_count) {
    if (*guest_count >= MAX_GUESTS) {
        printf("Guest list is full!\n");
        return;
    }
    Guest *new_guest = &guests[*guest_count];
    printf("Enter guest name: ");
    scanf("%s", new_guest->name);
    printf("Enter age: ");
    scanf("%d", &new_guest->age);
    printf("Enter room number: ");
    scanf("%d", &new_guest->room_number);
    printf("Enter number of nights stayed: ");
    scanf("%d", &new_guest->nights_stayed);
    (*guest_count)++;
    printf("Guest added successfully!\n");
}

void display_guests(Guest *guests, int guest_count) {
    if (guest_count == 0) {
        printf("No guests to display.\n");
        return;
    }
    printf("List of Guests:\n");
    printf("Name\t\tAge\tRoom Number\tNights Stayed\n");
    for (int i = 0; i < guest_count; i++) {
        printf("%s\t\t%d\t%d\t\t%d\n", guests[i].name, guests[i].age, guests[i].room_number, guests[i].nights_stayed);
    }
}

void search_guest(Guest *guests, int guest_count) {
    char name[NAME_LENGTH];
    printf("Enter guest name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < guest_count; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            printf("Found guest: %s, Age: %d, Room Number: %d, Nights Stayed: %d\n", guests[i].name, guests[i].age, guests[i].room_number, guests[i].nights_stayed);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Guest not found.\n");
    }
}

void delete_guest(Guest *guests, int *guest_count) {
    if (*guest_count == 0) {
        printf("No guests to delete.\n");
        return;
    }
    char name[NAME_LENGTH];
    printf("Enter the name of the guest to delete: ");
    scanf("%s", name);
    int found = -1;
    for (int i = 0; i < *guest_count; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        for (int i = found; i < (*guest_count - 1); i++) {
            guests[i] = guests[i + 1];
        }
        (*guest_count)--;
        printf("Guest deleted successfully!\n");
    } else {
        printf("Guest not found.\n");
    }
}

int main() {
    Guest *guests = (Guest *)malloc(MAX_GUESTS * sizeof(Guest));
    if (!guests) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    int guest_count = 0;
    int choice;

    do {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Search Guest\n");
        printf("4. Delete Guest\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest(guests, &guest_count);
                break;
            case 2:
                display_guests(guests, guest_count);
                break;
            case 3:
                search_guest(guests, guest_count);
                break;
            case 4:
                delete_guest(guests, &guest_count);
                break;
            case 5:
                printf("Exiting the Hotel Management System.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    free(guests);
    return 0;
}