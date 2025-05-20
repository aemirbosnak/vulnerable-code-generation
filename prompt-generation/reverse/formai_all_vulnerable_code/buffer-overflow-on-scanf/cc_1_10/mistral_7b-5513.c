//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char room_type[20];
    int room_number;
    float price_per_night;
    int num_nights;
    float total_cost;
} reservation;

void print_reservation(reservation r) {
    printf("\nName: %s", r.name);
    printf("\nRoom Type: %s", r.room_type);
    printf("\nRoom Number: %d", r.room_number);
    printf("\nPrice per Night: %.2f", r.price_per_night);
    printf("\nNumber of Nights: %d", r.num_nights);
    printf("\nTotal Cost: %.2f\n", r.total_cost);
}

int main() {
    int num_reservations;
    reservation *reservations;

    printf("Welcome to Cozy Hotel Management System!\n");
    printf("Enter the number of reservations: ");
    scanf("%d", &num_reservations);

    reservations = (reservation *) malloc(num_reservations * sizeof(reservation));

    for (int i = 0; i < num_reservations; i++) {
        printf("\nReservation %d:\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", reservations[i].name);
        printf("Enter Room Type: ");
        scanf("%s", reservations[i].room_type);
        printf("Enter Room Number: ");
        scanf("%d", &reservations[i].room_number);
        printf("Enter Price per Night: ");
        scanf("%f", &reservations[i].price_per_night);
        printf("Enter Number of Nights: ");
        scanf("%d", &reservations[i].num_nights);
        reservations[i].total_cost = reservations[i].price_per_night * reservations[i].num_nights;
    }

    printf("\nReservations:\n");
    for (int i = 0; i < num_reservations; i++) {
        print_reservation(reservations[i]);
    }

    free(reservations);

    return 0;
}