//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 50

typedef struct Guest {
    char name[50];
    int room_no;
    int days_stayed;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter guest name: ");
    scanf("%s", newGuest->name);
    printf("Enter room number: ");
    scanf("%d", &newGuest->room_no);
    printf("Enter number of days stayed: ");
    scanf("%d", &newGuest->days_stayed);
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }

    return head;
}

void printGuests(Guest* head) {
    Guest* temp = head;
    while (temp) {
        printf("Name: %s, Room Number: %d, Days Stayed: %d\n", temp->name, temp->room_no, temp->days_stayed);
        temp = temp->next;
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