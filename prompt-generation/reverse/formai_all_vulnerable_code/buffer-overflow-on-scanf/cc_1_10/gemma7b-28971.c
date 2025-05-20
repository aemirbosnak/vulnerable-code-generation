//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

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
    printf("Guests: \n");
    while (temp) {
        printf("Name: %s, Room Number: %d, Days Stayed: %d\n", temp->name, temp->room_no, temp->days_stayed);
        temp = temp->next;
    }
}

void calculateBill(Guest* head) {
    Guest* temp = head;
    int total_bill = 0;
    while (temp) {
        int days = temp->days_stayed;
        int room_no = temp->room_no;
        int rate = 1000; // Assume a rate of $1000 per night

        total_bill += days * rate;
        temp = temp->next;
    }

    printf("Total bill: $%d\n", total_bill);
}

int main() {
    Guest* head = NULL;
    head = insertGuest(head);
    insertGuest(head);
    insertGuest(head);
    printGuests(head);
    calculateBill(head);

    return 0;
}