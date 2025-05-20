//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    char status;
    struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
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

void check_guest(Guest* head) {
    char guest_name[50];
    printf("Enter guest name: ");
    scanf("%s", guest_name);

    Guest* current_guest = head;

    while (current_guest) {
        if (strcmp(current_guest->name, guest_name) == 0) {
            printf("Guest status: %c\n", current_guest->status);
            break;
        }
        current_guest = current_guest->next;
    }

    if (current_guest == NULL) {
        printf("Guest not found.\n");
    }
}

void update_guest(Guest* head) {
    char guest_name[50];
    printf("Enter guest name: ");
    scanf("%s", guest_name);

    Guest* current_guest = head;

    while (current_guest) {
        if (strcmp(current_guest->name, guest_name) == 0) {
            printf("Enter new guest status: ");
            scanf(" %c", &current_guest->status);
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
        printf("1. Insert Guest\n");
        printf("2. Check Guest\n");
        printf("3. Update Guest\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insert_guest(head);
                break;
            case 2:
                check_guest(head);
                break;
            case 3:
                update_guest(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        if (head == NULL) {
            printf("No guests.\n");
        }
    }

    return 0;
}