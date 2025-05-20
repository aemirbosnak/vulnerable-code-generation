//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char name[50];
    float price;
    int quantity;
} Item;

typedef struct bill {
    char name[50];
    float total;
    char payment[50];
} Bill;

int main() {
    Item items[5];
    Bill bills[5];
    int n = 0;

    printf("Welcome to the post-apocalyptic billing system!\n");
    printf("Please enter the name of the item:\n");
    fgets(items[n].name, sizeof(items[n].name), stdin);
    printf("Please enter the price of the item:\n");
    scanf("%f", &items[n].price);
    printf("Please enter the quantity of the item:\n");
    scanf("%d", &items[n].quantity);

    while (n < 5) {
        printf("Would you like to enter another item? (y/n): ");
        char choice = getchar();
        if (choice == 'y' || choice == 'Y') {
            n++;
            printf("Please enter the name of the item:\n");
            fgets(items[n].name, sizeof(items[n].name), stdin);
            printf("Please enter the price of the item:\n");
            scanf("%f", &items[n].price);
            printf("Please enter the quantity of the item:\n");
            scanf("%d", &items[n].quantity);
        }
    }

    printf("Please enter the name of the customer:\n");
    fgets(bills[0].name, sizeof(bills[0].name), stdin);
    printf("Please enter the total amount of the bill:\n");
    scanf("%f", &bills[0].total);
    printf("Please enter the payment method of the customer:\n");
    fgets(bills[0].payment, sizeof(bills[0].payment), stdin);

    for (int i = 1; i < n; i++) {
        printf("Please enter the name of the customer:\n");
        fgets(bills[i].name, sizeof(bills[i].name), stdin);
        printf("Please enter the total amount of the bill:\n");
        scanf("%f", &bills[i].total);
        printf("Please enter the payment method of the customer:\n");
        fgets(bills[i].payment, sizeof(bills[i].payment), stdin);
    }

    printf("Please enter the name of the customer:\n");
    fgets(bills[n].name, sizeof(bills[n].name), stdin);
    printf("Please enter the total amount of the bill:\n");
    scanf("%f", &bills[n].total);
    printf("Please enter the payment method of the customer:\n");
    fgets(bills[n].payment, sizeof(bills[n].payment), stdin);

    for (int i = 0; i < n; i++) {
        printf("Item: %s, Price: %.2f, Quantity: %d\n", items[i].name, items[i].price, items[i].quantity);
        printf("Bill: %s, Total: %.2f, Payment: %s\n", bills[i].name, bills[i].total, bills[i].payment);
    }

    return 0;
}