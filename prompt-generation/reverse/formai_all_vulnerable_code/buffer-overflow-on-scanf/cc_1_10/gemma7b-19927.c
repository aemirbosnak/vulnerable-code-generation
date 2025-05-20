//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_number;
    int days_stayed;
    double total_cost;
} Guest;

Guest guests[MAX_GUESTS];

void create_guest(int guest_id) {
    guests[guest_id].name[0] = '\0';
    guests[guest_id].room_number = 0;
    guests[guest_id].days_stayed = 0;
    guests[guest_id].total_cost = 0.0;
}

void update_guest(int guest_id) {
    printf("Enter guest name: ");
    scanf("%s", guests[guest_id].name);

    printf("Enter room number: ");
    scanf("%d", &guests[guest_id].room_number);

    printf("Enter number of days stayed: ");
    scanf("%d", &guests[guest_id].days_stayed);
}

double calculate_total_cost(int guest_id) {
    int days_stayed = guests[guest_id].days_stayed;
    double room_rate = 100.0;
    double total_cost = days_stayed * room_rate;

    return total_cost;
}

void print_guest_details(int guest_id) {
    printf("Guest Name: %s\n", guests[guest_id].name);
    printf("Room Number: %d\n", guests[guest_id].room_number);
    printf("Number of Days Stayed: %d\n", guests[guest_id].days_stayed);
    printf("Total Cost: %.2lf\n", guests[guest_id].total_cost);
}

int main() {
    int guest_id = 0;

    create_guest(guest_id);
    update_guest(guest_id);
    calculate_total_cost(guest_id);
    print_guest_details(guest_id);

    return 0;
}