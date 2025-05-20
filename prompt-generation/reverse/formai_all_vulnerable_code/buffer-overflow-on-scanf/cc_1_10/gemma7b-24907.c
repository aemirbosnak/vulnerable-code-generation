//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

struct Guest {
    char name[50];
    int room_number;
    int days_stayed;
    struct Guest* next;
};

void insert_guest(struct Guest** head) {
    struct Guest* new_guest = (struct Guest*)malloc(sizeof(struct Guest));
    printf("Enter guest name: ");
    scanf("%s", new_guest->name);
    printf("Enter room number: ");
    scanf("%d", &new_guest->room_number);
    printf("Enter number of days stayed: ");
    scanf("%d", &new_guest->days_stayed);

    new_guest->next = *head;
    *head = new_guest;
}

void print_guests(struct Guest* head) {
    struct Guest* current_guest = head;
    while (current_guest) {
        printf("Name: %s, Room Number: %d, Days Stayed: %d\n", current_guest->name, current_guest->room_number, current_guest->days_stayed);
        current_guest = current_guest->next;
    }
}

int main() {
    struct Guest* head = NULL;
    char choice;

    do {
        printf("Enter 'i' to insert a guest, 'p' to print guests, or 'q' to quit: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'i':
                insert_guest(&head);
                break;
            case 'p':
                print_guests(head);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    } while (choice != 'q');

    return 0;
}