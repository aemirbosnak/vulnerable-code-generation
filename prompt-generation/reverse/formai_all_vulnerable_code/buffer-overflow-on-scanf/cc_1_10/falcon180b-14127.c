//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_FLOORS 10
#define MAX_GUESTS 1000

typedef struct {
    int room_number;
    int floor;
    char guest_name[50];
    int days_stayed;
    float total_cost;
} Guest;

Guest guests[MAX_GUESTS];
int num_guests = 0;

void add_guest(int room_number, int floor, char guest_name[50], int days_stayed, float total_cost) {
    guests[num_guests].room_number = room_number;
    guests[num_guests].floor = floor;
    strcpy(guests[num_guests].guest_name, guest_name);
    guests[num_guests].days_stayed = days_stayed;
    guests[num_guests].total_cost = total_cost;
    num_guests++;
}

void print_guests() {
    printf("Guest details:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("Room number: %d\n", guests[i].room_number);
        printf("Floor: %d\n", guests[i].floor);
        printf("Guest name: %s\n", guests[i].guest_name);
        printf("Days stayed: %d\n", guests[i].days_stayed);
        printf("Total cost: $%.2f\n\n", guests[i].total_cost);
    }
}

int main() {
    int choice;

    while (1) {
        printf("Hotel Management System\n");
        printf("1. Add guest\n");
        printf("2. Print guest details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int room_number, floor;
                char guest_name[50];
                int days_stayed;
                float total_cost;

                printf("Enter room number: ");
                scanf("%d", &room_number);
                printf("Enter floor: ");
                scanf("%d", &floor);
                printf("Enter guest name: ");
                scanf("%s", guest_name);
                printf("Enter days stayed: ");
                scanf("%d", &days_stayed);
                printf("Enter total cost: ");
                scanf("%f", &total_cost);

                add_guest(room_number, floor, guest_name, days_stayed, total_cost);
                break;
            }
            case 2: {
                print_guests();
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}