//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct customer {
    char name[50];
    int id;
};

struct menu {
    char item[50];
    float price;
};

int main() {
    struct customer c1;
    struct customer c2;
    struct menu m1, m2, m3;

    printf("Welcome to Cafe Billing System!\n");

    printf("Enter the name of customer 1: ");
    scanf("%s", c1.name);
    printf("Enter the customer ID of customer 1: ");
    scanf("%d", &c1.id);

    printf("Enter the name of customer 2: ");
    scanf("%s", c2.name);
    printf("Enter the customer ID of customer 2: ");
    scanf("%d", &c2.id);

    printf("Enter the name of menu 1: ");
    scanf("%s", m1.item);
    printf("Enter the price of menu 1: ");
    scanf("%f", &m1.price);

    printf("Enter the name of menu 2: ");
    scanf("%s", m2.item);
    printf("Enter the price of menu 2: ");
    scanf("%f", &m2.price);

    printf("Enter the name of menu 3: ");
    scanf("%s", m3.item);
    printf("Enter the price of menu 3: ");
    scanf("%f", &m3.price);

    printf("\nMenu 1: %s - $%.2f\n", m1.item, m1.price);
    printf("Menu 2: %s - $%.2f\n", m2.item, m2.price);
    printf("Menu 3: %s - $%.2f\n", m3.item, m3.price);

    printf("\nCustomer 1's total bill: $%.2f\n", c1.id * m1.price);
    printf("Customer 2's total bill: $%.2f\n", c2.id * m2.price);
    printf("Total bill: $%.2f\n", c1.id * m1.price + c2.id * m2.price);

    return 0;
}