//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    int num_days;
    float total_cost;
} Guest;

Guest guests[MAX_GUESTS];

void calculate_cost(Guest *guest) {
    int days = guest->num_days;
    float room_charge = 1000;
    float service_charge = 200;
    guest->total_cost = days * room_charge + days * service_charge;
}

void check_in(Guest *guest) {
    printf("Welcome, %s! Please select a room number:", guest->name);
    scanf("%d", &guest->room_no);
    calculate_cost(guest);
}

void check_out(Guest *guest) {
    printf("Thank you for your stay, %s. Your total cost is $%.2f.", guest->name, guest->total_cost);
}

int main() {
    int i = 0;
    for (i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].room_no = 0;
        guests[i].num_days = 0;
        guests[i].total_cost = 0.0f;
    }

    int num_guests = 0;
    printf("Enter the number of guests:");
    scanf("%d", &num_guests);

    for (i = 0; i < num_guests; i++) {
        printf("Enter the name of the guest:");
        scanf("%s", guests[i].name);

        printf("Enter the number of days the guest will stay:");
        scanf("%d", &guests[i].num_days);
    }

    for (i = 0; i < num_guests; i++) {
        check_in(&guests[i]);
    }

    for (i = 0; i < num_guests; i++) {
        check_out(&guests[i]);
    }

    return 0;
}