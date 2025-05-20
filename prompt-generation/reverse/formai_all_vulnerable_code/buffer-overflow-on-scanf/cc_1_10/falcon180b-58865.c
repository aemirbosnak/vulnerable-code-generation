//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 300

typedef struct {
    int roomNumber;
    char guestName[50];
    int daysStayed;
} Guest;

Guest guests[MAX_GUESTS];

int numGuests = 0;

void addGuest() {
    printf("Enter room number: ");
    scanf("%d", &guests[numGuests].roomNumber);

    printf("Enter guest name: ");
    scanf("%s", guests[numGuests].guestName);

    printf("Enter number of days stayed: ");
    scanf("%d", &guests[numGuests].daysStayed);

    numGuests++;
}

void removeGuest(int roomNumber) {
    int i;
    for (i = 0; i < numGuests; i++) {
        if (guests[i].roomNumber == roomNumber) {
            numGuests--;
            break;
        }
    }
}

void printGuests() {
    printf("Guest List:\n");
    printf("Room Number | Guest Name | Days Stayed\n");
    printf("-------------------------------------------------\n");
    int i;
    for (i = 0; i < numGuests; i++) {
        printf("%d | %s | %d\n", guests[i].roomNumber, guests[i].guestName, guests[i].daysStayed);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Guest\n2. Remove Guest\n3. Print Guest List\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addGuest();
            break;
        case 2:
            printf("Enter room number: ");
            int roomNumber;
            scanf("%d", &roomNumber);
            removeGuest(roomNumber);
            break;
        case 3:
            printGuests();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}