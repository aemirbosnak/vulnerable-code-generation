//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct customer {
    int id;
    char name[50];
    int phone;
    double balance;
};

struct bill {
    int id;
    int customer_id;
    char item[50];
    double price;
};

int main() {
    struct customer customers[5];
    struct bill bills[5];
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("Enter customer ID: ");
        scanf("%d", &customers[i].id);
        printf("Enter customer name: ");
        scanf("%s", customers[i].name);
        printf("Enter customer phone: ");
        scanf("%d", &customers[i].phone);
        printf("Enter customer balance: ");
        scanf("%lf", &customers[i].balance);
    }

    for (i = 0; i < 5; i++) {
        printf("Enter bill ID: ");
        scanf("%d", &bills[i].id);
        printf("Enter customer ID: ");
        scanf("%d", &bills[i].customer_id);
        printf("Enter item: ");
        scanf("%s", bills[i].item);
        printf("Enter price: ");
        scanf("%lf", &bills[i].price);
    }

    // Calculate total bill
    double total = 0;
    for (i = 0; i < 5; i++) {
        total += bills[i].price;
    }

    // Calculate discount
    double discount = 0;
    if (total > 1000) {
        discount = total * 0.1;
    } else if (total > 500) {
        discount = total * 0.05;
    }

    // Calculate final bill
    double final_bill = total - discount;

    // Print bill
    printf("Bill No.\tItem\tPrice\n");
    for (i = 0; i < 5; i++) {
        printf("%d\t%s\t%.2lf\n", bills[i].id, bills[i].item, bills[i].price);
    }
    printf("Total: %.2lf\n", total);
    printf("Discount: %.2lf\n", discount);
    printf("Final Bill: %.2lf\n", final_bill);

    // Print customer details
    printf("Customer ID\tName\tPhone\tBalance\n");
    for (i = 0; i < 5; i++) {
        printf("%d\t%s\t%d\t%.2lf\n", customers[i].id, customers[i].name, customers[i].phone, customers[i].balance);
    }

    return 0;
}