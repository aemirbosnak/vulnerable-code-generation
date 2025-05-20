//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    int num_days;
    float total_bill;
} Guest;

Guest guests[MAX_GUESTS];

void calculate_bill(Guest *guest) {
    int days = guest->num_days;
    float rate = 1000;
    guest->total_bill = days * rate;
}

void check_in(Guest *guest) {
    printf("Welcome, %s! Please take your room key and enjoy your stay at the Grand Hotel.\n", guest->name);
    printf("Your room number is: %d\n", guest->room_no);
}

void check_out(Guest *guest) {
    printf("Thank you for staying at the Grand Hotel, %s. We hope you enjoyed your stay.\n", guest->name);
    printf("Your total bill is: $%.2f\n", guest->total_bill);
}

int main() {
    int i = 0;
    for (i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].room_no = 0;
        guests[i].num_days = 0;
        guests[i].total_bill = 0.0f;
    }

    Guest *guest = &guests[0];
    printf("Please enter your name: ");
    scanf("%s", guest->name);

    printf("Please select your room number: ");
    scanf("%d", &guest->room_no);

    printf("Please enter the number of days you will be staying: ");
    scanf("%d", &guest->num_days);

    calculate_bill(guest);
    check_in(guest);
    check_out(guest);

    return 0;
}