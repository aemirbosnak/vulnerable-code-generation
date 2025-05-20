//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    char status[50];
} Guest;

Guest guests[MAX_GUESTS];

void create_guest(int index) {
    guests[index].name[0] = '\0';
    guests[index].room_no = 0;
    guests[index].status[0] = '\0';
}

void update_guest(int index) {
    printf("Enter guest name: ");
    scanf("%s", guests[index].name);

    printf("Enter guest room number: ");
    scanf("%d", &guests[index].room_no);

    printf("Enter guest status: ");
    scanf("%s", guests[index].status);
}

void list_guests() {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].name[0] != '\0') {
            printf("Name: %s, Room No: %d, Status: %s\n", guests[i].name, guests[i].room_no, guests[i].status);
        }
    }
}

int main() {
    int index = 0;

    // Create guests
    for (int i = 0; i < MAX_GUESTS; i++) {
        create_guest(i);
    }

    // Update guest information
    update_guest(2);

    // List guests
    list_guests();

    return 0;
}