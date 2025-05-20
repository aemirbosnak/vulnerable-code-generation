//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    char email[50];
    char phone_no[20];
} Guest;

Guest guests[MAX_GUESTS];

void add_guest() {
    Guest new_guest;

    printf("Enter guest name: ");
    scanf("%s", new_guest.name);

    printf("Enter room number: ");
    scanf("%d", &new_guest.room_no);

    printf("Enter email address: ");
    scanf("%s", new_guest.email);

    printf("Enter phone number: ");
    scanf("%s", new_guest.phone_no);

    guests[MAX_GUESTS - 1] = new_guest;
}

void list_guests() {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].name[0] != '\0') {
            printf("Name: %s\n", guests[i].name);
            printf("Room No: %d\n", guests[i].room_no);
            printf("Email: %s\n", guests[i].email);
            printf("Phone No: %s\n", guests[i].phone_no);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Hotel Management System!\n");

    printf("1. Add Guest\n");
    printf("2. List Guests\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_guest();
            break;
        case 2:
            list_guests();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}