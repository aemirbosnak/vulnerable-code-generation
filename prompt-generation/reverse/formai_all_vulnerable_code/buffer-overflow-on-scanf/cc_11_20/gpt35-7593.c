//FormAI DATASET v1.0 Category: Hotel Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    int room_no;
    char name[20];
    int days_stayed;
    float room_rate;
    float total_bill;
};

int main() {
    struct customer c[5]; // maximum 5 customers
    int count = 0; // number of customers currently checked in
    int choice = 0; // choice of the user from menu
    int room_no = 0; // room number to be searched for
    int i;

    do {
        printf("Welcome to C Hotel Management System\n");
        printf("1. Check-in\n");
        printf("2. Check-out\n");
        printf("3. Search customer by room number\n");
        printf("4. Display all customers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count == 5) {
                    printf("Sorry, all rooms are taken.\n");
                } else {
                    printf("Enter customer details:\n");
                    printf("Room number: ");
                    scanf("%d", &c[count].room_no);
                    printf("Name: ");
                    scanf("%s", c[count].name);
                    printf("Days stayed: ");
                    scanf("%d", &c[count].days_stayed);
                    printf("Room rate per day: ");
                    scanf("%f", &c[count].room_rate);
                    c[count].total_bill = c[count].days_stayed * c[count].room_rate;
                    printf("Total bill: %.2f\n", c[count].total_bill);
                    count++;
                }
                break;

            case 2:
                printf("Enter room number to check-out: ");
                scanf("%d", &room_no);
                for (i = 0; i < count; i++) {
                    if (c[i].room_no == room_no) {
                        printf("Customer details:\n");
                        printf("Room number: %d\n", c[i].room_no);
                        printf("Name: %s\n", c[i].name);
                        printf("Days stayed: %d\n", c[i].days_stayed);
                        printf("Room rate per day: %.2f\n", c[i].room_rate);
                        printf("Total bill: %.2f\n", c[i].total_bill);
                        count--;
                        c[i] = c[count];
                        printf("Check-out successful.\n");
                        break;
                    }
                }
                if (i == count) {
                    printf("Sorry, room number not found.\n");
                }
                break;

            case 3:
                printf("Enter room number to search: ");
                scanf("%d", &room_no);
                for (i = 0; i < count; i++) {
                    if (c[i].room_no == room_no) {
                        printf("Customer details:\n");
                        printf("Room number: %d\n", c[i].room_no);
                        printf("Name: %s\n", c[i].name);
                        printf("Days stayed: %d\n", c[i].days_stayed);
                        printf("Room rate per day: %.2f\n", c[i].room_rate);
                        printf("Total bill: %.2f\n", c[i].total_bill);
                        break;
                    }
                }
                if (i == count) {
                    printf("Sorry, room number not found.\n");
                }
                break;

            case 4:
                if (count == 0) {
                    printf("No customers checked-in.\n");
                } else {
                    printf("All customers:\n");
                    for (i = 0; i < count; i++) {
                        printf("Customer %d:\n", i+1);
                        printf("Room number: %d\n", c[i].room_no);
                        printf("Name: %s\n", c[i].name);
                        printf("Days stayed: %d\n", c[i].days_stayed);
                        printf("Room rate per day: %.2f\n", c[i].room_rate);
                        printf("Total bill: %.2f\n", c[i].total_bill);
                        printf("\n");
                    }
                }
                break;

            case 5:
                printf("Thank you for using C Hotel Management System.\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}