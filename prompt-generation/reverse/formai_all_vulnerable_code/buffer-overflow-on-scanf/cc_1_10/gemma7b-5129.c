//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10

struct Guest {
    char name[50];
    int room_no;
    char status;
    struct Guest* next;
};

void insert_guest(struct Guest** head) {
    struct Guest* new_guest = (struct Guest*)malloc(sizeof(struct Guest));
    printf("Enter guest name: ");
    scanf("%s", new_guest->name);
    printf("Enter room number: ");
    scanf("%d", &new_guest->room_no);
    new_guest->status = 'O';
    new_guest->next = NULL;

    if (*head == NULL) {
        *head = new_guest;
    } else {
        (*head)->next = new_guest;
    }
}

void print_guests(struct Guest* head) {
    struct Guest* current = head;
    while (current) {
        printf("Name: %s, Room No: %d, Status: %c\n", current->name, current->room_no, current->status);
        current = current->next;
    }
}

int main() {
    struct Guest* head = NULL;
    char choice;

    do {
        printf("Enter 'I' to insert a guest, 'P' to print guests, or 'Q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'I':
                insert_guest(&head);
                break;
            case 'P':
                print_guests(head);
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    } while (choice != 'Q');

    return 0;
}