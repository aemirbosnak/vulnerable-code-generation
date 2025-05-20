//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int room_number;
    char *guest_name;
    int num_nights;
    int total_cost;
} reservation;

void add_reservation(reservation **reservations, int *num_reservations) {
    reservation *new_reservation = malloc(sizeof(reservation));
    printf("Enter room number: ");
    scanf("%d", &new_reservation->room_number);
    printf("Enter guest name: ");
    scanf("%s", new_reservation->guest_name);
    printf("Enter number of nights: ");
    scanf("%d", &new_reservation->num_nights);
    *num_reservations += 1;
    *reservations = realloc(*reservations, *num_reservations * sizeof(reservation));
    (*reservations)[*num_reservations - 1] = *new_reservation;
}

void print_reservations(reservation *reservations, int num_reservations) {
    for (int i = 0; i < num_reservations; i++) {
        printf("Room number: %d\n", reservations[i].room_number);
        printf("Guest name: %s\n", reservations[i].guest_name);
        printf("Number of nights: %d\n", reservations[i].num_nights);
        printf("Total cost: $%d\n\n", reservations[i].total_cost);
    }
}

int main() {
    reservation *reservations = NULL;
    int num_reservations = 0;

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add reservation\n");
        printf("2. Print reservations\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_reservation(&reservations, &num_reservations);
                break;
            case 2:
                print_reservations(reservations, num_reservations);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}