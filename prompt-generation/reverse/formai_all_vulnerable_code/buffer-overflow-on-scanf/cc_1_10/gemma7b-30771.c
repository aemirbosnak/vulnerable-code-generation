//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10

struct guest_record {
    char name[50];
    char room_no[10];
    int no_of_days;
    float total_bill;
};

struct guest_record guests[MAX_GUESTS];

void add_guest(struct guest_record *guest) {
    printf("Enter guest name: ");
    scanf("%s", guest->name);

    printf("Enter room number: ");
    scanf("%s", guest->room_no);

    printf("Enter number of days: ");
    scanf("%d", &guest->no_of_days);

    printf("Enter total bill: ");
    scanf("%f", &guest->total_bill);
}

void calculate_bill(struct guest_record *guest) {
    int days = guest->no_of_days;
    float rate = 1000;

    guest->total_bill = days * rate;
}

void print_guests(struct guest_record *guests) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].name[0] != '\0') {
            printf("Name: %s, Room No: %s, No. of Days: %d, Total Bill: %.2f\n", guests[i].name, guests[i].room_no, guests[i].no_of_days, guests[i].total_bill);
        }
    }
}

int main() {
    struct guest_record guest;

    add_guest(&guest);
    calculate_bill(&guest);
    print_guests(guests);

    return 0;
}