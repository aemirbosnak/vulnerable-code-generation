//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int room_number;
    float balance;
};

struct room {
    int number;
    char type[10];
    int capacity;
    float price;
    struct guest current_guest;
};

int main() {
    int num_rooms, choice;
    printf("How many rooms does your hotel have? ");
    scanf("%d", &num_rooms);

    // Allocate memory for the rooms array
    struct room* rooms = (struct room*) malloc(num_rooms * sizeof(struct room));

    // Initialize the rooms with default values
    for (int i = 0; i < num_rooms; i++) {
        struct room r;
        r.number = i + 1;
        strcpy(r.type, "Single");
        r.capacity = 1;
        r.price = 50.00;
        rooms[i] = r;
    }

    while (1) {
        printf("\n\n");
        printf("1. Guest check in\n");
        printf("2. Guest check out\n");
        printf("3. Print all rooms\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct guest g;
                printf("\nEnter guest name: ");
                scanf("%s", g.name);
                printf("Enter room number: ");
                scanf("%d", &g.room_number);
                printf("Enter balance: ");
                scanf("%f", &g.balance);

                if (rooms[g.room_number - 1].current_guest.room_number != 0) {
                    printf("\nRoom is already occupied.\n");
                } else {
                    rooms[g.room_number - 1].current_guest = g;
                    printf("\nGuest checked in successfully.\n");
                }
                break;
            }
            case 2: {
                int room_number;
                printf("\nEnter room number: ");
                scanf("%d", &room_number);

                if (rooms[room_number - 1].current_guest.room_number == 0) {
                    printf("\nRoom is not occupied.\n");
                } else {
                    struct guest g = rooms[room_number - 1].current_guest;
                    printf("\nGuest %s checked out of room %d. Balance due: $%.2f\n", g.name, g.room_number, g.balance);
                    rooms[room_number - 1].current_guest.room_number = 0;
                }
                break;
            }
            case 3: {
                printf("\n");
                printf("Room Number  Type    Capacity  Price    Guest Name  Balance\n");
                printf("----------------------------------------------------------------\n");
                for (int i = 0; i < num_rooms; i++) {
                    struct room r = rooms[i];
                    printf("%-12d %-7s %-9d $%-7.2f ", r.number, r.type, r.capacity, r.price);
                    if (r.current_guest.room_number == 0) {
                        printf("%-11s $%-6s\n", "-", "-");
                    } else {
                        printf("%-11s $%-6.2f\n", r.current_guest.name, r.current_guest.balance);
                    }
                }
                break;
            }
            case 4: {
                free(rooms);
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}