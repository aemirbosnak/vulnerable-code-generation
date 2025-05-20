//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void manage_guests() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        printf("%s - %d - %c\n", guests[i].name, guests[i].room_number, guests[i].status);
    }
}

void check_in(char *name, int room_number) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'O' && guests[i].name == name && guests[i].room_number == room_number) {
            guests[i].status = 'C';
            printf("Welcome, %s! Your room number is %d.\n", name, room_number);
            return;
        }
    }

    printf("Error: Room not available.\n");
}

void check_out(char *name) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'C' && guests[i].name == name) {
            guests[i].status = 'O';
            printf("Goodbye, %s.\n", name);
            return;
        }
    }

    printf("Error: Guest not found.\n");
}

int main() {
    char name[20];
    int room_number;

    manage_guests();

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your room number: ");
    scanf("%d", &room_number);

    check_in(name, room_number);

    printf("Enter your name: ");
    scanf("%s", name);

    check_out(name);

    manage_guests();

    return 0;
}