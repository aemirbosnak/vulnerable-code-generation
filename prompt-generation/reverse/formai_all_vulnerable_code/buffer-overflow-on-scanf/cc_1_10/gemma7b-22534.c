//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    int num_days;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter your name: ");
    scanf("%s", newGuest->name);
    printf("Enter your room number: ");
    scanf("%d", &newGuest->room_number);
    printf("Enter the number of days you will be staying: ");
    scanf("%d", &newGuest->num_days);

    newGuest->next = head;
    head = newGuest;

    return head;
}

void printGuests(Guest* head) {
    Guest* currentGuest = head;
    printf("List of guests:\n");
    while (currentGuest) {
        printf("Name: %s, Room Number: %d, Number of Days: %d\n", currentGuest->name, currentGuest->room_number, currentGuest->num_days);
        currentGuest = currentGuest->next;
    }
}

int main() {
    Guest* head = NULL;

    // Insert guests
    head = insertGuest(head);
    head = insertGuest(head);
    head = insertGuest(head);

    // Print guests
    printGuests(head);

    return 0;
}