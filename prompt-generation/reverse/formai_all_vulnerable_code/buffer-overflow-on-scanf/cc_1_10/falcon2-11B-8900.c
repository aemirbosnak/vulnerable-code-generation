//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROOM_SIZE 10
#define MAX_GUEST_NAME_SIZE 50

typedef struct {
    char guestName[MAX_GUEST_NAME_SIZE];
    char roomNumber[MAX_ROOM_SIZE];
} Guest;

int main() {
    int roomCount = 0;
    Guest guests[MAX_ROOM_SIZE];

    // Print welcome message
    printf("Welcome to the C Hotel Management System!\n");

    // Ask user for number of rooms
    printf("Please enter the number of rooms: ");
    scanf("%d", &roomCount);

    // Allocate memory for guest data
    for (int i = 0; i < roomCount; i++) {
        guests[i].guestName[0] = '\0';
        guests[i].roomNumber[0] = '\0';
    }

    // Loop until user wants to quit
    while (1) {
        // Print current room count
        printf("Current room count: %d\n", roomCount);

        // Check if user wants to quit
        printf("Enter 'quit' to quit, 'add' to add a guest, or 'list' to list guests: ");
        char input[MAX_GUEST_NAME_SIZE];
        scanf("%s", input);

        // Quit if user enters 'quit'
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Add guest if user enters 'add'
        if (strcmp(input, "add") == 0) {
            printf("Enter guest name: ");
            scanf("%s", guests[roomCount].guestName);
            printf("Enter room number: ");
            scanf("%s", guests[roomCount].roomNumber);
            roomCount++;
        }

        // List guests if user enters 'list'
        if (strcmp(input, "list") == 0) {
            printf("Guest list:\n");
            for (int i = 0; i < roomCount; i++) {
                printf("%s - %s\n", guests[i].guestName, guests[i].roomNumber);
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < roomCount; i++) {
        free(guests[i].guestName);
        free(guests[i].roomNumber);
    }

    return 0;
}