//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bill{
    char name[100];
    char item[100];
    char quantity[20];
    char price[20];
    char total[20];
};

int main() {
    int choice;
    struct bill bill;
    printf("Cafe Billing System\n");
    printf("1. Add items to the bill\n");
    printf("2. View bill details\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter customer name: ");
            scanf("%s", bill.name);
            printf("Enter item name: ");
            scanf("%s", bill.item);
            printf("Enter quantity: ");
            scanf("%s", bill.quantity);
            printf("Enter price: ");
            scanf("%s", bill.price);
            printf("Total bill amount: ");
            scanf("%s", bill.total);
            break;
        case 2:
            printf("Bill Details:\n");
            printf("Name: %s\n", bill.name);
            printf("Item: %s\n", bill.item);
            printf("Quantity: %s\n", bill.quantity);
            printf("Price: %s\n", bill.price);
            printf("Total: %s\n", bill.total);
            break;
        case 3:
            printf("Thank you for using Cafe Billing System!");
            exit(0);
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}