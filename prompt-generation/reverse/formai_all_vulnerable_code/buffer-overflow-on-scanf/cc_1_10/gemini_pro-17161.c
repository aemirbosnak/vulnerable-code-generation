//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    int room_number;
    int checkin_date;
    int checkout_date;
    float bill_amount;
} guest;

guest guests[1000];
int num_guests = 0;

void add_guest() {
    guest new_guest;

    printf("Enter guest ID: ");
    scanf("%d", &new_guest.id);

    printf("Enter guest name: ");
    scanf("%s", new_guest.name);

    printf("Enter guest email: ");
    scanf("%s", new_guest.email);

    printf("Enter guest phone: ");
    scanf("%s", new_guest.phone);

    printf("Enter guest address: ");
    scanf("%s", new_guest.address);

    printf("Enter guest room number: ");
    scanf("%d", &new_guest.room_number);

    printf("Enter guest checkin date: ");
    scanf("%d", &new_guest.checkin_date);

    printf("Enter guest checkout date: ");
    scanf("%d", &new_guest.checkout_date);

    printf("Enter guest bill amount: ");
    scanf("%f", &new_guest.bill_amount);

    guests[num_guests] = new_guest;
    num_guests++;
}

void print_guest(guest guest) {
    printf("Guest ID: %d\n", guest.id);
    printf("Guest name: %s\n", guest.name);
    printf("Guest email: %s\n", guest.email);
    printf("Guest phone: %s\n", guest.phone);
    printf("Guest address: %s\n", guest.address);
    printf("Guest room number: %d\n", guest.room_number);
    printf("Guest checkin date: %d\n", guest.checkin_date);
    printf("Guest checkout date: %d\n", guest.checkout_date);
    printf("Guest bill amount: %f\n", guest.bill_amount);
}

void print_all_guests() {
    for (int i = 0; i < num_guests; i++) {
        print_guest(guests[i]);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Add guest\n");
        printf("2. Print all guests\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                print_all_guests();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}