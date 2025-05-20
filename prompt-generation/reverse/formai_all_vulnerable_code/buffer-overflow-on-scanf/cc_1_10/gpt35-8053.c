//FormAI DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOTEL_SIZE 100

struct hotel {
    int room_number;
    char guest_name[50];
    int days_stayed;
};

struct hotel hotels[MAX_HOTEL_SIZE];
int num_hotels = 0;

void add_hotel() {
    if(num_hotels == MAX_HOTEL_SIZE) {
        printf("Hotel database is full.\n");
        return;
    }

    struct hotel h;

    printf("Enter room number: ");
    scanf("%d", &h.room_number);

    printf("Enter guest name: ");
    scanf("%s", h.guest_name);

    printf("Enter number of days stayed: ");
    scanf("%d", &h.days_stayed);

    hotels[num_hotels++] = h;

    printf("Successfully added hotel information.\n");
}

void print_hotel(struct hotel h) {
    printf("Room Number: %d\n", h.room_number);
    printf("Guest Name: %s\n", h.guest_name);
    printf("Days Stayed: %d\n", h.days_stayed);
}

void view_hotel() {
    if(num_hotels == 0) {
        printf("No hotels in database.\n");
        return;
    }

    for(int i = 0; i < num_hotels; i++) {
        printf("Hotel %d:\n", i+1);
        print_hotel(hotels[i]);
        printf("\n");
    }
}

int main() {
    int option;

    do {
        printf("Hotel Management System Menu:\n");
        printf("1. Add Hotel Information\n");
        printf("2. View All Hotel Information\n");
        printf("3. Quit\n");
        printf("Enter option number: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                add_hotel();
                break;
            case 2:
                view_hotel();
                break;
            case 3:
                printf("Exiting Hotel Management System.");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    } while(option != 3);

    return 0;
}