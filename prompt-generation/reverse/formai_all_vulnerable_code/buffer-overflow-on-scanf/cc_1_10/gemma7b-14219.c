//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

struct Guest {
    char name[20];
    int room_no;
    float bill;
};

struct Guest guests[MAX_GUESTS];

void display_guests() {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].name[0] != '\0') {
            printf("Name: %s, Room No: %d, Bill: %.2f\n", guests[i].name, guests[i].room_no, guests[i].bill);
        }
    }
}

void add_guest() {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].name[0] == '\0') {
            printf("Enter name: ");
            scanf("%s", guests[i].name);

            printf("Enter room number: ");
            scanf("%d", &guests[i].room_no);

            printf("Enter bill: ");
            scanf("%f", &guests[i].bill);

            break;
        }
    }
}

void update_guest_bill(int room_no, float new_bill) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].room_no == room_no) {
            guests[i].bill = new_bill;
            break;
        }
    }
}

void check_out(int room_no) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].room_no == room_no) {
            guests[i].name[0] = '\0';
            break;
        }
    }
}

int main() {
    add_guest();
    add_guest();
    update_guest_bill(1, 50.0);
    check_out(2);
    display_guests();

    return 0;
}