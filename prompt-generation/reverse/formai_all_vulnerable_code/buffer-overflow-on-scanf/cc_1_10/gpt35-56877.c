//FormAI DATASET v1.0 Category: Hotel Management System ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Guest {
    int id;
    char name[50];
    int roomNumber;
    int daysOfStay;
    float amountPaid;
};

struct Hotel {
    struct Guest guests[100];
    int numGuests;
};

void addGuest(struct Hotel *hotel) {
    int id;
    char name[50];
    int roomNumber;
    int daysOfStay;
    float amountPaid;

    printf("Enter guest id: ");
    scanf("%d", &id);

    printf("Enter guest name: ");
    scanf("%s", name);

    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    printf("Enter days of stay: ");
    scanf("%d", &daysOfStay);

    printf("Enter amount paid: ");
    scanf("%f", &amountPaid);

    struct Guest guest;
    guest.id = id;
    strcpy(guest.name, name);
    guest.roomNumber = roomNumber;
    guest.daysOfStay = daysOfStay;
    guest.amountPaid = amountPaid;

    hotel->guests[hotel->numGuests++] = guest;
}

void removeGuest(struct Hotel *hotel, int id) {
    int i;
    for (i = 0; i < hotel->numGuests; i++) {
        if (hotel->guests[i].id == id) {
            int j;
            for (j = i; j < hotel->numGuests - 1; j++) {
                hotel->guests[j] = hotel->guests[j+1];
            }
            hotel->numGuests--;
            return;
        }
    }
}

void printGuests(struct Hotel *hotel) {
    int i;
    for (i = 0; i < hotel->numGuests; i++) {
        printf("%d. %s, Room %d, %d days, Rs. %.2f paid.\n",
               hotel->guests[i].id, hotel->guests[i].name,
               hotel->guests[i].roomNumber, hotel->guests[i].daysOfStay,
               hotel->guests[i].amountPaid);
    }
}

int main() {
    struct Hotel hotel = {0};
    int choice;
    printf("Welcome to the Hotel Management System.\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Add Guest\n");
        printf("2. Remove Guest\n");
        printf("3. Print Guests\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addGuest(&hotel);
        } else if (choice == 2) {
            int id;
            printf("Enter guest id to remove: ");
            scanf("%d", &id);
            removeGuest(&hotel, id);
        } else if (choice == 3) {
            printGuests(&hotel);
        }

    } while (choice != 4);

    return 0;
}