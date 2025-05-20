//FormAI DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 50

struct reservation {
    char guest_name[30];
    int room_number;
    int num_of_nights;
};

int num_of_guests = 0;
int num_of_rooms = 0;
struct reservation hotel[MAX_ROOMS];

void add_guest() {
    if (num_of_guests == MAX_GUESTS) {
        printf("Sorry, the hotel is full.\n");
        return;
    }

    struct reservation new_guest;
    printf("Enter guest name: ");
    scanf("%s", &new_guest.guest_name);
    printf("Enter room number: ");
    scanf("%d", &new_guest.room_number);
    printf("Enter number of nights: ");
    scanf("%d", &new_guest.num_of_nights);

    hotel[num_of_guests] = new_guest;
    num_of_guests++;

    printf("Guest added successfully.\n");
}

void print_guests() {
    printf("\n");
    if (num_of_guests == 0) {
        printf("No guests in the hotel.\n");
        return;
    }
    printf("Guest list:\n");
    for (int i = 0; i < num_of_guests; i++) {
        printf("%s\t\t%d\t\t%d\n", hotel[i].guest_name, hotel[i].room_number, hotel[i].num_of_nights);
    }
}

int get_total_room_nights() {
    int total_nights = 0;
    for (int i = 0; i < num_of_guests; i++) {
        total_nights += hotel[i].num_of_nights;
    }
    return total_nights;
}

void print_room_availability() {
    printf("\n");
    if (num_of_rooms == 0) {
        printf("No rooms in the hotel.\n");
        return;
    }
    printf("Room availability:\n");
    for (int i = 1; i <= num_of_rooms; i++) {
        int is_available = 1;
        for (int j = 0; j < num_of_guests; j++) {
            if (hotel[j].room_number == i) {
                is_available = 0;
                break;
            }
        }
        if (is_available) {
            printf("Room %d: Available\n", i);
        } else {
            printf("Room %d: Occupied\n", i);
        }
    }
}

int main() {
    num_of_rooms = 10;
    printf("Welcome to the C Hotel Management System\n");

    while (1) {
        printf("\n1. Add guest\n");
        printf("2. Print guest list\n");
        printf("3. Get total room nights\n");
        printf("4. Print room availability\n");
        printf("5. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                print_guests();
                break;
            case 3:
                printf("\nTotal room nights: %d\n", get_total_room_nights());
                break;
            case 4:
                print_room_availability();
                break;
            case 5:
                printf("\nThank you for using the C Hotel Management System!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}