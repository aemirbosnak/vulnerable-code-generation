//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_no;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void manage_guests() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        printf("Name: %s, Room No: %d, Status: %c\n", guests[i].name, guests[i].room_no, guests[i].status);
    }
}

void check_in(char *name, int room_no) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'O' && guests[i].room_no == room_no) {
            printf("Error: Room No %d is occupied.\n", room_no);
            return;
        }
    }

    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'F') {
            strcpy(guests[i].name, name);
            guests[i].room_no = room_no;
            guests[i].status = 'O';
            printf("Welcome, %s! Enjoy your stay in Room No. %d.\n", name, room_no);
            return;
        }
    }

    printf("Error: No available rooms.\n");
}

void check_out(char *name) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            guests[i].status = 'F';
            printf("Goodbye, %s. We hope you enjoyed your stay.\n", name);
            return;
        }
    }

    printf("Error: Guest not found.\n");
}

int main() {
    char name[20];
    int room_no;

    manage_guests();

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter room number: ");
    scanf("%d", &room_no);

    check_in(name, room_no);

    printf("Enter your name: ");
    scanf("%s", name);

    check_out(name);

    manage_guests();

    return 0;
}