//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int room_number;
    char guest_name[50];
    char check_in[11];
    char check_out[11];
    float bill;
} Room;

#define MAX_ROOMS 100

void calculate_bill(Room *room) {
    int days_stay = (strtod(room->check_out, NULL) - strtod(room->check_in, NULL)) / 86400;
    room->bill = pow(2, days_stay) * 50;
}

int main() {
    Room rooms[MAX_ROOMS];
    int i, n;

    printf("Hotel Management System\n");
    printf("------------------------\n");

    printf("Enter the number of rooms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nRoom %d Details:\n", i + 1);
        printf("Enter room number: ");
        scanf("%d", &rooms[i].room_number);
        printf("Enter guest name: ");
        scanf("%s", rooms[i].guest_name);
        printf("Enter check-in date (dd-mm-yyyy): ");
        scanf("%s", rooms[i].check_in);
        printf("Enter check-out date (dd-mm-yyyy): ");
        scanf("%s", rooms[i].check_out);

        calculate_bill(&rooms[i]);
    }

    printf("\nRoom Details:\n");
    for (i = 0; i < n; i++) {
        printf("\nRoom %d\n", i + 1);
        printf("Room Number: %d\n", rooms[i].room_number);
        printf("Guest Name: %s\n", rooms[i].guest_name);
        printf("Check-in Date: %s\n", rooms[i].check_in);
        printf("Check-out Date: %s\n", rooms[i].check_out);
        printf("Bill: %.2f\n", rooms[i].bill);
    }

    return 0;
}