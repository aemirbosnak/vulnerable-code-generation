//FormAI DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room_booking {
    char name[50];
    int room_number;
    int duration_of_stay;
    float cost;
};

void book_room(struct room_booking rooms[], int* count) {

    getchar(); //to consume the newline character
    printf("Enter your name: ");
    fgets(rooms[*count].name, 50, stdin);
    printf("Enter room number: ");
    scanf("%d", &rooms[*count].room_number);
    printf("Enter number of days to stay: ");
    scanf("%d", &rooms[*count].duration_of_stay);
    rooms[*count].cost = 100 * rooms[*count].duration_of_stay; //assuming a fixed per day cost of $100
    printf("\nThank you for booking!\n\n");
    (*count)++;
}

void view_bookings(struct room_booking rooms[], int count) {

    printf("Current bookings:\n");
    printf("--------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s", rooms[i].name);
        printf("Room Number: %d\n", rooms[i].room_number);
        printf("Duration of Stay: %d days\n", rooms[i].duration_of_stay);
        printf("Total Cost: $%.2f\n", rooms[i].cost);
        printf("--------------------\n");
    }
}

int main() {

    printf("Welcome to the C Hotel Management System\n\n");
    struct room_booking rooms[10];
    int count = 0;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Book a room\n");
        printf("2. View bookings\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
        case 1:
            book_room(rooms, &count);
            break;
        case 2:
            view_bookings(rooms, count);
            break;
        case 3:
            printf("Goodbye!\n\n");
            exit(0);
        default:
            printf("Invalid option\n\n");
        }
    }

    return 0;
}