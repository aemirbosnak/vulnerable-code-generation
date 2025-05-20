//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_num;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter your name: ");
    scanf("%s", newGuest->name);
    printf("Enter your room number: ");
    scanf("%d", &newGuest->room_num);
    newGuest->next = head;
    return newGuest;
}

void printGuests(Guest* head) {
    Guest* currentGuest = head;
    while (currentGuest) {
        printf("Name: %s, Room Number: %d\n", currentGuest->name, currentGuest->room_num);
        currentGuest = currentGuest->next;
    }
}

void updateGuest(Guest* head) {
    Guest* currentGuest = head;
    printf("Enter the name of the guest you want to update: ");
    char name[20];
    scanf("%s", name);
    while (currentGuest) {
        if (strcmp(currentGuest->name, name) == 0) {
            printf("Enter the new name: ");
            scanf("%s", currentGuest->name);
            printf("Enter the new room number: ");
            scanf("%d", &currentGuest->room_num);
            break;
        }
        currentGuest = currentGuest->next;
    }
    if (currentGuest == NULL) {
        printf("Guest not found.\n");
    }
}

void deleteGuest(Guest* head) {
    Guest* currentGuest = head;
    printf("Enter the name of the guest you want to delete: ");
    char name[20];
    scanf("%s", name);
    while (currentGuest) {
        if (strcmp(currentGuest->name, name) == 0) {
            Guest* prevGuest = NULL;
            if (currentGuest == head) {
                head = currentGuest->next;
            } else {
                prevGuest = currentGuest->next;
                prevGuest->next = currentGuest->next;
            }
            free(currentGuest);
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
    int choice;

    while (1) {
        printf("Enter 1 to insert a guest, 2 to print guests, 3 to update a guest, 4 to delete a guest, or 5 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertGuest(head);
                break;
            case 2:
                printGuests(head);
                break;
            case 3:
                updateGuest(head);
                break;
            case 4:
                deleteGuest(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}