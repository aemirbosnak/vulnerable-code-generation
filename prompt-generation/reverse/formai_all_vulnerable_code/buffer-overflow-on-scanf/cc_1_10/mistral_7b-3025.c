//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    int room_number;
    char phone[MAX_PHONE_LENGTH];
} Guest;

Guest room[MAX_ROOMS];
int num_guests = 0;

void add_guest(int room_number) {
    if (num_guests >= MAX_ROOMS) {
        printf("Hotel is full.\n");
        return;
    }

    printf("Enter guest name: ");
    fgets(room[num_guests].name, MAX_NAME_LENGTH, stdin);
    room[num_guests].name[strcspn(room[num_guests].name, "\n")] = '\0';

    printf("Enter guest phone number: ");
    fgets(room[num_guests].phone, MAX_PHONE_LENGTH, stdin);
    room[num_guests].phone[strcspn(room[num_guests].phone, "\n")] = '\0';

    room[num_guests].room_number = room_number;
    num_guests++;
}

void display_guests() {
    int i;

    for (i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", room[i].name);
        printf("Room number: %d\n", room[i].room_number);
        printf("Phone number: %s\n", room[i].phone);
        printf("\n");
    }
}

int main() {
    int choice, room_number;

    while (1) {
        printf("1. Add guest\n");
        printf("2. Display guests\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                add_guest(room_number);
                break;
            case 2:
                display_guests();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}