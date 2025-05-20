//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head) {
    Guest* new_guest = malloc(sizeof(Guest));
    new_guest->next = NULL;

    printf("Enter guest name: ");
    scanf("%s", new_guest->name);

    printf("Enter room number: ");
    scanf("%d", &new_guest->room_number);

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
        printf("Name: %s, Room Number: %d\n", current_guest->name, current_guest->room_number);
        current_guest = current_guest->next;
    }
}

int main() {
    Guest* head = NULL;

    while (1) {
        printf("Enter 'add' to add a guest, 'print' to print guests, or 'exit' to exit: ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            head = insert_guest(head);
        } else if (strcmp(command, "print") == 0) {
            print_guests(head);
        } else if (strcmp(command, "exit") == 0) {
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}