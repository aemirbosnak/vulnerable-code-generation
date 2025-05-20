//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_no;
    char status;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter guest name: ");
    scanf("%s", newGuest->name);
    printf("Enter room number: ");
    scanf("%d", &newGuest->room_no);
    newGuest->status = 'O';
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }

    return head;
}

void displayGuests(Guest* head) {
    Guest* temp = head;
    printf("List of guests:\n");
    while (temp) {
        printf("Name: %s, Room No: %d, Status: %c\n", temp->name, temp->room_no, temp->status);
        temp = temp->next;
    }
}

int main() {
    Guest* head = NULL;
    head = insertGuest(head);
    insertGuest(head);
    insertGuest(head);
    displayGuests(head);
    return 0;
}