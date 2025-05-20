//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char gender[10];
    float salary;
} Guest;

typedef struct {
    char name[50];
    Guest guest;
    char status[10];
    int check_in;
    int check_out;
    float total_bill;
} Reservation;

int main() {
    Reservation res[10];
    int i, n;

    printf("Enter number of reservations: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter reservation details:\n");
        scanf("%s %d %s %d %d %f", res[i].name, &res[i].guest.age, res[i].guest.gender, &res[i].check_in, &res[i].check_out, &res[i].total_bill);
    }

    // Display reservations
    printf("\nReservations:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", res[i].name);
        printf("Guest: %s\n", res[i].guest.name);
        printf("Age: %d\n", res[i].guest.age);
        printf("Gender: %s\n", res[i].guest.gender);
        printf("Status: %s\n", res[i].status);
        printf("Check-in: %d\n", res[i].check_in);
        printf("Check-out: %d\n", res[i].check_out);
        printf("Total Bill: $%.2f\n", res[i].total_bill);
    }

    // Calculate total revenue
    float total_revenue = 0;
    for (i = 0; i < n; i++) {
        total_revenue += res[i].total_bill;
    }
    printf("\nTotal Revenue: $%.2f\n", total_revenue);

    return 0;
}