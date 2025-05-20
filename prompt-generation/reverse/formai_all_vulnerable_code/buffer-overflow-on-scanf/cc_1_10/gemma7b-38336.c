//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_no;
    int days_stayed;
    double total_bill;
} Guest;

Guest guests[MAX_GUESTS];

void calculate_bill(Guest *guest) {
    int days = guest->days_stayed;
    double rate = 1000;
    guest->total_bill = days * rate;
}

void print_guests() {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].name[0] != '\0') {
            printf("Name: %s, Room No: %d, Days Stayed: %d, Total Bill: %.2lf\n", guests[i].name, guests[i].room_no, guests[i].days_stayed, guests[i].total_bill);
        }
    }
}

int main() {
    int i = 0;
    char ch;

    while (1) {
        printf("Enter 'a' to add a guest, 'p' to print guests, or 'q' to quit: ");
        scanf(" %c", &ch);

        switch (ch) {
            case 'a':
                 guests[i].name[0] = '\0';
                printf("Enter guest name: ");
                scanf(" %s", guests[i].name);
                printf("Enter room number: ");
                scanf(" %d", &guests[i].room_no);
                printf("Enter number of days stayed: ");
                scanf(" %d", &guests[i].days_stayed);
                calculate_bill(&guests[i]);
                i++;
                break;
            case 'p':
                print_guests();
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}