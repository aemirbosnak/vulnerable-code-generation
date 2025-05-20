//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: optimized
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
        head->next = newGuest;
    }

    return head;
}

void checkGuest(Guest* head) {
    char name[50];
    printf("Enter guest name: ");
    scanf("%s", name);

    Guest* currentGuest = head;
    while (currentGuest) {
        if (strcmp(currentGuest->name, name) == 0) {
            printf("Guest details:\n");
            printf("Name: %s\n", currentGuest->name);
            printf("Room number: %d\n", currentGuest->room_no);
            printf("Status: %c\n", currentGuest->status);
            break;
        }
        currentGuest = currentGuest->next;
    }

    if (currentGuest == NULL) {
        printf("Guest not found.\n");
    }
}

int main() {
    Guest* head = NULL;

    while (1) {
        printf("Enter 1 to insert guest, 2 to check guest, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertGuest(head);
                break;
            case 2:
                checkGuest(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}