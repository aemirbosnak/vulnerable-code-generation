//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    int num_days;
    double total_cost;
} Guest;

Guest guests[MAX_GUESTS];

void calculate_total_cost(Guest *guest) {
    int days = guest->num_days;
    double room_cost = 50;
    double breakfast_cost = 10;
    guest->total_cost = days * room_cost + days * breakfast_cost;
}

void check_in(Guest *guest) {
    printf("Welcome, %s! Please take your seat in the grand hall.\n", guest->name);
    printf("You have been assigned room number %d.\n", guest->room_number);
    printf("Please let us know how many days you will be staying.\n");
    scanf("%d", &guest->num_days);
    calculate_total_cost(guest);
}

void check_out(Guest *guest) {
    printf("Thank you for your stay, %s. We hope you enjoyed your time at the castle.\n", guest->name);
    printf("Your total cost is $%.2lf.\n", guest->total_cost);
    printf("Please leave your luggage in the designated area.\n");
}

int main() {
    int i = 0;
    for (i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].room_number = 0;
        guests[i].num_days = 0;
        guests[i].total_cost = 0.0;
    }

    Guest guest;
    printf("Welcome to the Grand Castle of Mallow.\n");
    printf("Please check in or out.\n");
    printf("Enter 'check in' to check in, or 'check out' to check out.\n");
    scanf("%s", guest.name);

    if (strcmp(guest.name, "check in") == 0) {
        check_in(&guest);
    } else if (strcmp(guest.name, "check out") == 0) {
        check_out(&guest);
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}