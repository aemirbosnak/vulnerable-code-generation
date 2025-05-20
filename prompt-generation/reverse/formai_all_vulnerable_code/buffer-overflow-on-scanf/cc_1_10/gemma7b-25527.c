//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_no;
    char status;
    struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    printf("Enter name: ");
    scanf("%s", new_guest->name);
    printf("Enter room number: ");
    scanf("%d", &new_guest->room_no);
    new_guest->status = 'O';
    new_guest->next = NULL;

    if (head == NULL) {
        head = new_guest;
    } else {
        head->next = new_guest;
    }

    return head;
}

void print_guests(Guest* head) {
    Guest* current_guest = head;
    printf("Guests:\n");
    while (current_guest) {
        printf("Name: %s, Room No: %d, Status: %c\n", current_guest->name, current_guest->room_no, current_guest->status);
        current_guest = current_guest->next;
    }
}

void update_guest_status(Guest* head, char status) {
    Guest* current_guest = head;
    while (current_guest) {
        if (strcmp(current_guest->name, "John Doe") == 0) {
            current_guest->status = status;
        }
        current_guest = current_guest->next;
    }
}

int main() {
    Guest* head = NULL;
    head = insert_guest(head);
    head = insert_guest(head);
    print_guests(head);
    update_guest_status(head, 'C');
    print_guests(head);

    return 0;
}