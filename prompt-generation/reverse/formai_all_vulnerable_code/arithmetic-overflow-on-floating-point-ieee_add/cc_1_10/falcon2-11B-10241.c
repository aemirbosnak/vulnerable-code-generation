//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct customer {
    char name[50];
    float balance;
};

struct bill {
    char name[50];
    float amount;
};

struct menu {
    char name[50];
    float price;
};

int main() {
    struct customer customer1;
    struct customer customer2;
    struct customer customer3;

    struct bill bill1;
    struct bill bill2;
    struct bill bill3;

    struct menu menu1;
    struct menu menu2;
    struct menu menu3;

    printf("Welcome to Cafe Billing System!\n");

    printf("Enter customer name: ");
    scanf("%s", customer1.name);
    printf("Enter customer balance: ");
    scanf("%f", &customer1.balance);

    printf("Enter customer name: ");
    scanf("%s", customer2.name);
    printf("Enter customer balance: ");
    scanf("%f", &customer2.balance);

    printf("Enter customer name: ");
    scanf("%s", customer3.name);
    printf("Enter customer balance: ");
    scanf("%f", &customer3.balance);

    printf("Enter bill name: ");
    scanf("%s", bill1.name);
    printf("Enter bill amount: ");
    scanf("%f", &bill1.amount);

    printf("Enter bill name: ");
    scanf("%s", bill2.name);
    printf("Enter bill amount: ");
    scanf("%f", &bill2.amount);

    printf("Enter bill name: ");
    scanf("%s", bill3.name);
    printf("Enter bill amount: ");
    scanf("%f", &bill3.amount);

    printf("Enter menu name: ");
    scanf("%s", menu1.name);
    printf("Enter menu price: ");
    scanf("%f", &menu1.price);

    printf("Enter menu name: ");
    scanf("%s", menu2.name);
    printf("Enter menu price: ");
    scanf("%f", &menu2.price);

    printf("Enter menu name: ");
    scanf("%s", menu3.name);
    printf("Enter menu price: ");
    scanf("%f", &menu3.price);

    // Calculate total balance
    float totalBalance = customer1.balance + customer2.balance + customer3.balance;

    // Calculate total bill amount
    float totalBillAmount = bill1.amount + bill2.amount + bill3.amount;

    // Calculate total menu price
    float totalMenuPrice = menu1.price + menu2.price + menu3.price;

    // Calculate total amount to be paid
    float totalAmount = totalBillAmount + totalMenuPrice;

    // Check if customer has enough balance
    if (totalAmount > totalBalance) {
        printf("Customer does not have enough balance!\n");
    } else {
        printf("Customer has enough balance!\n");

        // Subtract total bill amount from customer balance
        customer1.balance -= bill1.amount;
        customer2.balance -= bill2.amount;
        customer3.balance -= bill3.amount;

        // Subtract total menu price from customer balance
        customer1.balance -= menu1.price;
        customer2.balance -= menu2.price;
        customer3.balance -= menu3.price;

        // Print final balance for each customer
        printf("Final balance for customer 1: %.2f\n", customer1.balance);
        printf("Final balance for customer 2: %.2f\n", customer2.balance);
        printf("Final balance for customer 3: %.2f\n", customer3.balance);
    }

    return 0;
}