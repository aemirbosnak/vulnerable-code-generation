//FormAI DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

struct room {
    int number;
    int occupied;
    char guest[50];
};

struct room hotel[MAX_ROOMS];

void add_room(int number) {
    if(number <= MAX_ROOMS) {
        hotel[number-1].number = number;
        hotel[number-1].occupied = 0;
        strcpy(hotel[number-1].guest, "Empty");
        printf("Room %d added successfully!\n", number);
    } else {
        printf("Maximum room limit exceeded!\n");
    }
}

void remove_room(int number) {
    if(hotel[number-1].number == number) {
        if(hotel[number-1].occupied == 1) {
            printf("Cannot remove room %d, it is occupied!\n", number);
        } else {
            hotel[number-1].number = 0;
            hotel[number-1].occupied = 0;
            strcpy(hotel[number-1].guest, "");
            printf("Room %d removed successfully!\n", number);
        }
    } else {
        printf("Room %d not found!\n", number);
    }
}

void assign_room(char *guest, int room_number) {
    if(hotel[room_number-1].number == room_number) {
        if(hotel[room_number-1].occupied == 1) {
            printf("Cannot assign room %d, it is already occupied!\n", room_number);
        } else {
            hotel[room_number-1].occupied = 1;
            strcpy(hotel[room_number-1].guest, guest);
            printf("Room %d assigned to %s!\n", room_number, guest);
        }
    } else {
        printf("Room %d not found!\n", room_number);
    }
}

void remove_assignment(int room_number) {
    if(hotel[room_number-1].number == room_number) {
        if(hotel[room_number-1].occupied == 0) {
            printf("Cannot remove assignment for room %d, it is vacant!\n", room_number);
        } else {
            hotel[room_number-1].occupied = 0;
            strcpy(hotel[room_number-1].guest, "Empty");
            printf("Room %d assignment removed successfully!\n", room_number);
        }
    } else {
        printf("Room %d not found!\n", room_number);
    }
}

void print_status() {
    printf("\nRoom Status:\n");
    printf("+------------+----------------+--------------+\n");
    printf("| Room Number |    Guest       |    Occupied  |\n");
    printf("+------------+----------------+--------------+\n");
    for(int i=0; i < MAX_ROOMS; i++) {
        if(hotel[i].number != 0) {
            printf("|    %3d     |  %-14s |      %s      |\n", hotel[i].number, hotel[i].guest, (hotel[i].occupied == 1) ? "YES" : "NO");
        }
    }
    printf("+------------+----------------+--------------+\n");
}

int main() {
    int choice, number;
    char name[50];

    printf("Welcome to the Hotel Management System!\n");

    do {
        printf("\n");
        printf("1. Add Room.\n");
        printf("2. Remove Room.\n");
        printf("3. Assign Room.\n");
        printf("4. Remove Assignment.\n");
        printf("5. Print Status.\n");
        printf("6. Exit.\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Room Number : ");
                scanf("%d", &number);
                add_room(number);
                break;
            case 2:
                printf("\nEnter Room Number : ");
                scanf("%d", &number);
                remove_room(number);
                break;
            case 3:
                printf("\nEnter Guest Name : ");
                scanf("%s", name);
                printf("\nEnter Room Number : ");
                scanf("%d", &number);
                assign_room(name, number);
                break;
            case 4:
                printf("\nEnter Room Number : ");
                scanf("%d", &number);
                remove_assignment(number);
                break;
            case 5:
                print_status();
                break;
            case 6:
                printf("Thank you!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }

    } while (choice != 6);

    return 0;
}