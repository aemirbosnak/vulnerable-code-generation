//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_no;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void check_in(char *name, int room_no) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'O' && guests[i].name == name) {
            guests[i].room_no = room_no;
            guests[i].status = 'C';
            printf("Welcome, %s, to room %d.\n", name, room_no);
            return;
        }
    }

    printf("Error: Room is not available.\n");
}

void check_out(char *name) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'C' && guests[i].name == name) {
            guests[i].status = 'O';
            printf("Goodbye, %s.\n", name);
            return;
        }
    }

    printf("Error: Guest is not found.\n");
}

int main() {
    char name[20];
    int room_no;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your room number: ");
    scanf("%d", &room_no);

    check_in(name, room_no);

    printf("Enter your name: ");
    scanf("%s", name);

    check_out(name);

    return 0;
}