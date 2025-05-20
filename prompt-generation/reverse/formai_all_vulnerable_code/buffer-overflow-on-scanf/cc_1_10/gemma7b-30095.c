//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    int days_stayed;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter your name: ");
    scanf("%s", newGuest->name);
    printf("Enter your room number: ");
    scanf("%d", &newGuest->room_number);
    printf("Enter the number of days you will be staying: ");
    scanf("%d", &newGuest->days_stayed);
    newGuest->next = head;
    return newGuest;
}

void printGuests(Guest* head) {
    Guest* currentGuest = head;
    while (currentGuest) {
        printf("Name: %s\n", currentGuest->name);
        printf("Room Number: %d\n", currentGuest->room_number);
        printf("Days Stayed: %d\n", currentGuest->days_stayed);
        printf("-----------------------\n");
        currentGuest = currentGuest->next;
    }
}

int main() {
    Guest* head = NULL;
    int choice;

    printf("Welcome to The Rusty Dragon Inn!\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");
    printf("3. List Guests\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertGuest(head);
            break;
        case 2:
            printGuests(head);
            break;
        case 3:
            printGuests(head);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}