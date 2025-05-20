//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Room {
    int number;
    int is_occupied;
    struct Room *next;
} Room;

Room *head = NULL;

void add_room(int number) {
    Room *new_room = (Room *) malloc(sizeof(Room));
    new_room->number = number;
    new_room->is_occupied = 0;
    new_room->next = head;
    head = new_room;
}

void display_rooms() {
    Room *current = head;
    printf("\nRooms Available:\n");
    while (current != NULL) {
        printf("Room %d - %s\n", current->number, (current->is_occupied) ? "Occupied" : "Available");
        current = current->next;
    }
}

void book_room(int number) {
    Room *current = head;
    while (current != NULL) {
        if (current->number == number && !current->is_occupied) {
            current->is_occupied = 1;
            printf("Room %d booked successfully.\n", number);
            return;
        }
        current = current->next;
    }
    printf("Room %d not available.\n", number);
}

void cancel_reservation(int number) {
    Room *current = head, *previous = NULL;
    while (current != NULL) {
        if (current->number == number && current->is_occupied) {
            current->is_occupied = 0;
            printf("Reservation for Room %d cancelled successfully.\n", number);
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("No reservation found for Room %d.\n", number);
}

int main() {
    int choice, number;
    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add Room\n");
        printf("2. Display Rooms\n");
        printf("3. Book Room\n");
        printf("4. Cancel Reservation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number: ");
                scanf("%d", &number);
                add_room(number);
                break;
            case 2:
                display_rooms();
                break;
            case 3:
                printf("Enter room number: ");
                scanf("%d", &number);
                book_room(number);
                break;
            case 4:
                printf("Enter room number: ");
                scanf("%d", &number);
                cancel_reservation(number);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}