//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Room {
    char room_no[5];
    char type[20];
    int available;
    int price;
    struct Room* next;
} Room;

void insertRoom(Room** head) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    printf("Enter room number: ");
    scanf("%s", newRoom->room_no);
    printf("Enter room type: ");
    scanf("%s", newRoom->type);
    printf("Enter availability (1/0): ");
    scanf("%d", &newRoom->available);
    printf("Enter price: ");
    scanf("%d", &newRoom->price);
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

void displayRooms(Room* head) {
    while (head) {
        printf("Room No: %s\n", head->room_no);
        printf("Type: %s\n", head->type);
        printf("Available: %d\n", head->available);
        printf("Price: %d\n", head->price);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Room* head = NULL;

    while (1) {
        printf("1. Insert Room\n");
        printf("2. Display Rooms\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertRoom(&head);
                break;
            case 2:
                displayRooms(head);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    return 0;
}