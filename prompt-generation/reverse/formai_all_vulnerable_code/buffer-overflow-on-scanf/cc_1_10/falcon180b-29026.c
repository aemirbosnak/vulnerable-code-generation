//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000

typedef struct {
    int room_number;
    char guest_name[50];
    int days_stayed;
    float total_cost;
} GUEST;

GUEST guests[MAX_GUESTS];

int num_guests = 0;

void add_guest() {
    printf("Enter room number: ");
    scanf("%d", &guests[num_guests].room_number);

    printf("Enter guest name: ");
    scanf("%s", guests[num_guests].guest_name);

    printf("Enter number of days stayed: ");
    scanf("%d", &guests[num_guests].days_stayed);

    printf("Enter total cost: $");
    scanf("%f", &guests[num_guests].total_cost);

    num_guests++;
}

void display_guests() {
    printf("\nGuest List:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i+1);
        printf("Room number: %d\n", guests[i].room_number);
        printf("Guest name: %s\n", guests[i].guest_name);
        printf("Number of days stayed: %d\n", guests[i].days_stayed);
        printf("Total cost: $%.2f\n\n", guests[i].total_cost);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nHotel Management System\n");
        printf("------------------------\n");
        printf("1. Add guest\n");
        printf("2. Display guest list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest();
                break;

            case 2:
                display_guests();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}