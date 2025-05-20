//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter your name: ");
    scanf("%s", newGuest->name);
    printf("Enter your room number: ");
    scanf("%d", &newGuest->room_no);

    if (head == NULL) {
        head = newGuest;
    } else {
        newGuest->next = head;
        head = newGuest;
    }

    return head;
}

void printGuests(Guest* head) {
    Guest* currentGuest = head;
    printf("Guests:\n");
    while (currentGuest) {
        printf("%s in room %d\n", currentGuest->name, currentGuest->room_no);
        currentGuest = currentGuest->next;
    }
}

int main() {
    Guest* head = NULL;

    // Insert guests
    insertGuest(head);
    insertGuest(head);
    insertGuest(head);

    // Print guests
    printGuests(head);

    return 0;
}