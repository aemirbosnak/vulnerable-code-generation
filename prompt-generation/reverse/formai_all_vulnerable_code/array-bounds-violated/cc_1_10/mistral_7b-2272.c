//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20
#define MAX_RESERVATIONS 5

typedef struct {
    int room_number;
    int is_occupied;
} Room;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int check_in_day;
    int check_out_day;
    int room_number;
} Reservation;

Room rooms[MAX_ROOMS];
Reservation reservations[MAX_RESERVATIONS];
int num_reservations = 0;

void initialize_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_number = i + 1;
        rooms[i].is_occupied = 0;
    }
}

int find_available_room() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (!rooms[i].is_occupied) {
            rooms[i].is_occupied = 1;
            return i + 1;
        }
    }
    return -1;
}

void make_reservation(char *name, int check_in_day, int check_out_day) {
    int room_number = find_available_room();
    if (room_number == -1) {
        printf("No available rooms.\n");
        return;
    }

    strcpy(reservations[num_reservations].name, name);
    reservations[num_reservations].check_in_day = check_in_day;
    reservations[num_reservations].check_out_day = check_out_day;
    reservations[num_reservations].room_number = room_number;
    num_reservations++;

    printf("Reservation made successfully.\n");
}

void view_available_rooms() {
    printf("Available rooms:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (!rooms[i].is_occupied) {
            printf("%d\n", i + 1);
        }
    }
}

void check_out(int reservation_index) {
    if (reservation_index < 0 || reservation_index >= num_reservations) {
        printf("Invalid reservation index.\n");
        return;
    }

    rooms[reservations[reservation_index].room_number].is_occupied = 0;

    printf("Check-out completed successfully.\n");
}

int main() {
    initialize_rooms();

    char name[MAX_NAME_LENGTH];
    int choice, check_in_day, check_out_day;

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Make Reservation\n");
        printf("2. View Available Rooms\n");
        printf("3. Check Out\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter check-in day: ");
                scanf("%d", &check_in_day);
                printf("Enter check-out day: ");
                scanf("%d", &check_out_day);
                make_reservation(name, check_in_day, check_out_day);
                break;
            case 2:
                view_available_rooms();
                break;
            case 3:
                printf("Enter reservation index to check out: ");
                scanf("%d", &choice);
                check_out(choice);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}