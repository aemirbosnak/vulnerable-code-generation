//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    int room_number;
    int days_stayed;
    float bill;
} guest;

void add_guest(guest *guests, int *num_guests) {
    printf("Enter guest name: ");
    scanf("%s", guests[*num_guests].name);

    printf("Enter guest address: ");
    scanf(" %[^\n]%*c", guests[*num_guests].address);

    printf("Enter guest phone number: ");
    scanf("%s", guests[*num_guests].phone);

    printf("Enter guest room number: ");
    scanf("%d", &guests[*num_guests].room_number);

    printf("Enter number of days stayed: ");
    scanf("%d", &guests[*num_guests].days_stayed);

    guests[*num_guests].bill = guests[*num_guests].days_stayed * 100;

    *num_guests += 1;
}

void print_guests(guest *guests, int num_guests) {
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Phone: %s\n", guests[i].phone);
        printf("Room number: %d\n", guests[i].room_number);
        printf("Days stayed: %d\n", guests[i].days_stayed);
        printf("Bill: %.2f\n", guests[i].bill);
        printf("\n");
    }
}

int main() {
    guest guests[100];
    int num_guests = 0;

    int choice = 0;
    while (choice != 3) {
        printf("1. Add guest\n");
        printf("2. Print guests\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest(guests, &num_guests);
                break;
            case 2:
                print_guests(guests, num_guests);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}