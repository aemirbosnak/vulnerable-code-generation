//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    char status;
    struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head) {
    Guest* new_guest = malloc(sizeof(Guest));
    printf("Enter guest name: ");
    scanf("%s", new_guest->name);
    printf("Enter room number: ");
    scanf("%d", &new_guest->room_number);
    new_guest->status = 'O';
    new_guest->next = NULL;

    if (head == NULL) {
        head = new_guest;
    } else {
        head->next = new_guest;
    }

    return head;
}

void check_in(Guest* head) {
    printf("Enter guest name: ");
    char guest_name[50];
    scanf("%s", guest_name);

    Guest* current_guest = head;

    while (current_guest) {
        if (strcmp(current_guest->name, guest_name) == 0) {
            printf("Room number: %d\n", current_guest->room_number);
            current_guest->status = 'I';
            break;
        }
        current_guest = current_guest->next;
    }

    if (current_guest == NULL) {
        printf("Guest not found.\n");
    }
}

void check_out(Guest* head) {
    printf("Enter guest name: ");
    char guest_name[50];
    scanf("%s", guest_name);

    Guest* current_guest = head;

    while (current_guest) {
        if (strcmp(current_guest->name, guest_name) == 0) {
            current_guest->status = 'O';
            printf("Check out successful.\n");
            break;
        }
        current_guest = current_guest->next;
    }

    if (current_guest == NULL) {
        printf("Guest not found.\n");
    }
}

int main() {
    Guest* head = NULL;

    while (1) {
        printf("Enter 'I' to check in, 'O' to check out, or 'Q' to quit: ");
        char command[20];
        scanf("%s", command);

        switch (command[0]) {
            case 'I':
                head = insert_guest(head);
                break;
            case 'O':
                check_out(head);
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}