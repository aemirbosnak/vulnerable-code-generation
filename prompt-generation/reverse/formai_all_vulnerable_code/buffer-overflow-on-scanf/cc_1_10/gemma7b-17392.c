//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    int days_stayed;
    double total_amount;
} Guest;

Guest guests[MAX_GUESTS];

void manage_guests() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        printf("Name: %s\n", guests[i].name);
        printf("Room number: %d\n", guests[i].room_number);
        printf("Days stayed: %d\n", guests[i].days_stayed);
        printf("Total amount: %.2lf\n", guests[i].total_amount);
        printf("\n");
    }
}

void calculate_total_amount(int days_stayed, double room_rate) {
    double total_amount = days_stayed * room_rate;
    guests[MAX_GUESTS - 1].total_amount = total_amount;
}

int main() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].room_number = 0;
        guests[i].days_stayed = 0;
        guests[i].total_amount = 0.0;
    }

    printf("Welcome to the Hotel Management System!\n");

    // Check if guests are already registered
    manage_guests();

    // Register a new guest
    printf("Enter your name: ");
    scanf("%s", guests[MAX_GUESTS - 1].name);

    printf("Enter your room number: ");
    scanf("%d", &guests[MAX_GUESTS - 1].room_number);

    printf("Enter the number of days you will stay: ");
    scanf("%d", &guests[MAX_GUESTS - 1].days_stayed);

    // Calculate the total amount
    calculate_total_amount(guests[MAX_GUESTS - 1].days_stayed, 100.0);

    // Display the guest's information
    manage_guests();

    return 0;
}