//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_number;
    int days_stayed;
    float bill_amount;
} guest_t;

void add_guest(guest_t *guest) {
    printf("Enter guest name: ");
    scanf("%s", guest->name);
    printf("Enter guest address: ");
    scanf(" %[^\n]%*c", guest->address);  // Read address with spaces
    printf("Enter guest phone: ");
    scanf("%s", guest->phone);
    printf("Enter guest email: ");
    scanf(" %[^\n]%*c", guest->email);  // Read email with spaces
    printf("Enter guest room number: ");
    scanf("%d", &guest->room_number);
    printf("Enter guest days stayed: ");
    scanf("%d", &guest->days_stayed);
    printf("Enter guest bill amount: ");
    scanf("%f", &guest->bill_amount);
}

void print_guest(guest_t guest) {
    printf("Guest name: %s\n", guest.name);
    printf("Guest address: %s\n", guest.address);
    printf("Guest phone: %s\n", guest.phone);
    printf("Guest email: %s\n", guest.email);
    printf("Guest room number: %d\n", guest.room_number);
    printf("Guest days stayed: %d\n", guest.days_stayed);
    printf("Guest bill amount: %.2f\n", guest.bill_amount);
}

int main() {
    // Create an array of guests
    guest_t guests[100];
    int num_guests = 0;

    // Add some sample guests
    add_guest(&guests[0]);
    add_guest(&guests[1]);
    add_guest(&guests[2]);
    num_guests = 3;

    // Print the guest list
    printf("Guest list:\n");
    for (int i = 0; i < num_guests; i++) {
        print_guest(guests[i]);
        printf("\n");
    }

    return 0;
}