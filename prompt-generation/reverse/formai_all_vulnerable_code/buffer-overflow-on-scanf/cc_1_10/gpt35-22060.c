//FormAI DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room_number;
    int days_stayed;
    float bill;
} HotelGuest;

void print_guest_info(HotelGuest guest) {
    printf("Guest Name: %s\n", guest.name);
    printf("Room Number: %d\n", guest.room_number);
    printf("Days Stayed: %d\n", guest.days_stayed);
    printf("Total Bill: $%.2f\n", guest.bill);
    printf("---------------------\n");
}

int main() {
    int num_guests;
    printf("Enter the number of hotel guests: ");
    scanf("%d", &num_guests);
    printf("---------------------\n");

    HotelGuest* guests = (HotelGuest*) malloc(num_guests * sizeof(HotelGuest));

    for (int i = 0; i < num_guests; i++) {
        printf("Enter guest %d's name: ", i+1);
        scanf("%s", guests[i].name);

        printf("Enter guest %d's room number: ", i+1);
        scanf("%d", &guests[i].room_number);

        printf("Enter guest %d's number of days stayed: ", i+1);
        scanf("%d", &guests[i].days_stayed);

        guests[i].bill = guests[i].days_stayed * 75.99; // $75.99 per day
        printf("---------------------\n");
    }

    printf("Guest Information:\n");
    for (int i = 0; i < num_guests; i++) {
        print_guest_info(guests[i]);
    }

    free(guests);

    return 0;
}