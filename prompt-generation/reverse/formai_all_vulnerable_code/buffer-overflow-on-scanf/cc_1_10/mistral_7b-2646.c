//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct {
    int room_number;
    char name[50];
    char gender[10];
} Guest;

Guest guests[MAX_GUESTS];
int num_guests = 0;

void add_guest(Guest new_guest) {
    if (num_guests < MAX_GUESTS) {
        guests[num_guests] = new_guest;
        num_guests++;
    } else {
        printf("Hotel is full.\n");
    }
}

void remove_guest(int room_number) {
    int i;

    for (i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            for (int j = i; j < num_guests - 1; j++) {
                guests[j] = guests[j + 1];
            }
            num_guests--;
            break;
        }
    }
}

void display_guests() {
    int i;

    for (i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Room Number: %d\n", guests[i].room_number);
        printf("Name: %s\n", guests[i].name);
        printf("Gender: %s\n", guests[i].gender);
        printf("----------------------------------\n");
    }
}

int main() {
    char command[20];
    int room_number;

    while (1) {
        printf("\nHotel Management System\n");
        printf("Enter command (add/remove/display/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            Guest new_guest;

            printf("Enter room number: ");
            scanf("%d", &room_number);
            printf("Enter name: ");
            scanf("%s", new_guest.name);
            printf("Enter gender: ");
            scanf("%s", new_guest.gender);
            new_guest.room_number = room_number;

            add_guest(new_guest);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter room number: ");
            scanf("%d", &room_number);

            remove_guest(room_number);
        } else if (strcmp(command, "display") == 0) {
            display_guests();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}