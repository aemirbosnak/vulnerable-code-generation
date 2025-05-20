//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: genius
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int room_number;
    char phone[MAX_PHONE_LENGTH];
} Guest;

Guest guests[MAX_ROOMS];
int num_guests = 0;

void add_guest(char *name, int room_number, char *phone) {
    if (num_guests >= MAX_ROOMS) {
        printf("Hotel is full.\n");
        return;
    }
    strcpy(guests[num_guests].name, name);
    guests[num_guests].room_number = room_number;
    strcpy(guests[num_guests].phone, phone);
    num_guests++;
}

int main() {
    char name[MAX_NAME_LENGTH];
    int room_number;
    char phone[MAX_PHONE_LENGTH];

    while (1) {
        printf("Enter guest name (or 'quit' to exit): ");
        scanf("%s", name);
        if (strcmp(name, "quit") == 0) {
            break;
        }
        printf("Enter room number: ");
        scanf("%d", &room_number);
        printf("Enter phone number: ");
        scanf("%s", phone);
        add_guest(name, room_number, phone);
    }

    printf("\nList of guests:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("Name: %s, Room Number: %d, Phone: %s\n", guests[i].name, guests[i].room_number, guests[i].phone);
    }

    return 0;
}