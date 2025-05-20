//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[20];
    int room_number;
    float balance;
} Guest;

Guest guests[MAX_GUESTS];

void check_in(Guest *guest) {
    printf("Welcome, %s, to the neon lights of the Cyber Hotel!\n", guest->name);
    printf("Please select a room number: ");
    scanf("%d", &guest->room_number);
    printf("Please deposit $%f into your account.\n", guest->balance);
    scanf("%f", &guest->balance);
}

void check_out(Guest *guest) {
    printf("Thank you for your stay, %s. See you next time!\n", guest->name);
    printf("Please pay your bill: $%f\n", guest->balance);
    scanf("%f", &guest->balance);
    guest->balance = 0;
}

void view_guests() {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].balance > 0) {
            printf("%s, room #%d, balance: $%f\n", guests[i].name, guests[i].room_number, guests[i].balance);
        }
    }
}

int main() {
    int choice;
    Guest guest;

    // Create a new guest
    guest = guests[0];
    check_in(&guest);

    // View all guests
    view_guests();

    // Check out a guest
    check_out(&guest);

    // View all guests again
    view_guests();

    return 0;
}