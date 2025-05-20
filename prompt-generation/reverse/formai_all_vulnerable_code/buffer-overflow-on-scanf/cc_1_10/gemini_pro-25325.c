//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_number;
    int days_stayed;
    float bill_amount;
} guest;

void check_in(guest *g) {
    printf("Enter guest name: ");
    scanf("%s", g->name);
    printf("Enter guest address: ");
    scanf("%s", g->address);
    printf("Enter guest phone: ");
    scanf("%s", g->phone);
    printf("Enter guest email: ");
    scanf("%s", g->email);
    printf("Enter room number: ");
    scanf("%d", &g->room_number);
    printf("Enter days stayed: ");
    scanf("%d", &g->days_stayed);
    g->bill_amount = 0;
}

void check_out(guest *g) {
    float room_charge = g->days_stayed * 100;
    float tax = room_charge * 0.1;
    g->bill_amount = room_charge + tax;
    printf("Guest %s checked out.\n", g->name);
    printf("Room charge: $%.2f\n", room_charge);
    printf("Tax: $%.2f\n", tax);
    printf("Total bill: $%.2f\n", g->bill_amount);
}

void display_guests(guest *guests, int num_guests) {
    for (int i = 0; i < num_guests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Phone: %s\n", guests[i].phone);
        printf("Email: %s\n", guests[i].email);
        printf("Room number: %d\n", guests[i].room_number);
        printf("Days stayed: %d\n", guests[i].days_stayed);
        printf("Bill amount: $%.2f\n\n", guests[i].bill_amount);
    }
}

int main() {
    int num_guests;
    printf("Enter the number of guests: ");
    scanf("%d", &num_guests);
    guest guests[num_guests];
    for (int i = 0; i < num_guests; i++) {
        check_in(&guests[i]);
    }
    display_guests(guests, num_guests);
    for (int i = 0; i < num_guests; i++) {
        check_out(&guests[i]);
    }
    return 0;
}