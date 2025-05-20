//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 20

typedef struct Guest {
    char name[50];
    int room_no;
    int num_days;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void print_guest_list() {
    int i = 0;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status != 'X') {
            printf("Name: %s, Room No: %d, Number of Days: %d\n", guests[i].name, guests[i].room_no, guests[i].num_days);
        }
    }
}

void add_guest() {
    int i = 0;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'O') {
            break;
        }
    }

    if (i == MAX_GUESTS) {
        printf("No rooms available.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", guests[i].name);

    printf("Enter room number: ");
    scanf("%d", &guests[i].room_no);

    printf("Enter number of days: ");
    scanf("%d", &guests[i].num_days);

    guests[i].status = 'X';
}

void update_guest() {
    char name[50];
    int room_no;

    printf("Enter guest name: ");
    scanf("%s", name);

    printf("Enter room number: ");
    scanf("%d", &room_no);

    int i = 0;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (strcmp(guests[i].name, name) == 0 && guests[i].room_no == room_no) {
            printf("Enter new number of days: ");
            scanf("%d", &guests[i].num_days);
            break;
        }
    }

    if (i == MAX_GUESTS) {
        printf("Guest not found.\n");
    }
}

void check_out() {
    char name[50];
    int room_no;

    printf("Enter guest name: ");
    scanf("%s", name);

    printf("Enter room number: ");
    scanf("%d", &room_no);

    int i = 0;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (strcmp(guests[i].name, name) == 0 && guests[i].room_no == room_no) {
            guests[i].status = 'O';
            printf("Guest checked out.\n");
            break;
        }
    }

    if (i == MAX_GUESTS) {
        printf("Guest not found.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Hotel Management System.\n");
    printf("1. Print Guest List\n");
    printf("2. Add Guest\n");
    printf("3. Update Guest\n");
    printf("4. Check Out\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            print_guest_list();
            break;
        case 2:
            add_guest();
            break;
        case 3:
            update_guest();
            break;
        case 4:
            check_out();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}