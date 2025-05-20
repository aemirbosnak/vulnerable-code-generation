//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
} guest;

typedef struct {
    int room_number;
    guest guest;
    int days_stayed;
    float bill_amount;
} reservation;

void add_guest(reservation *reservations, int *num_reservations) {
    printf("Enter guest name: ");
    scanf(" %[^\n]", reservations[*num_reservations].guest.name);

    printf("Enter guest address: ");
    scanf(" %[^\n]", reservations[*num_reservations].guest.address);

    printf("Enter guest phone number: ");
    scanf(" %s", reservations[*num_reservations].guest.phone);

    printf("Enter guest email address: ");
    scanf(" %s", reservations[*num_reservations].guest.email);

    *num_reservations += 1;
}

void add_reservation(reservation *reservations, int *num_reservations) {
    printf("Enter room number: ");
    scanf(" %d", &reservations[*num_reservations].room_number);

    printf("Enter number of days stayed: ");
    scanf(" %d", &reservations[*num_reservations].days_stayed);

    printf("Enter bill amount: ");
    scanf(" %f", &reservations[*num_reservations].bill_amount);

    *num_reservations += 1;
}

void print_guest(guest guest) {
    printf("Guest name: %s\n", guest.name);
    printf("Guest address: %s\n", guest.address);
    printf("Guest phone number: %s\n", guest.phone);
    printf("Guest email address: %s\n", guest.email);
}

void print_reservation(reservation reservation) {
    printf("Room number: %d\n", reservation.room_number);
    printf("Guest:\n");
    print_guest(reservation.guest);
    printf("Days stayed: %d\n", reservation.days_stayed);
    printf("Bill amount: %f\n", reservation.bill_amount);
}

void print_reservations(reservation *reservations, int num_reservations) {
    for (int i = 0; i < num_reservations; i++) {
        print_reservation(reservations[i]);
        printf("\n");
    }
}

int main() {
    reservation reservations[100];
    int num_reservations = 0;

    int choice;
    do {
        printf("Hotel Management System\n");
        printf("1. Add guest\n");
        printf("2. Add reservation\n");
        printf("3. Print reservations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_guest(reservations, &num_reservations);
                break;
            case 2:
                add_reservation(reservations, &num_reservations);
                break;
            case 3:
                print_reservations(reservations, num_reservations);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}