//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include<stdio.h>
#include<string.h>

struct order {
    char name[20];
    int quantity;
    float price;
};

void add_order(struct order o[], int *n) {
    printf("\nEnter item name: ");
    scanf("%s", o[*n].name);
    printf("Enter quantity: ");
    scanf("%d", &o[*n].quantity);
    printf("Enter price: ");
    scanf("%f", &o[*n].price);
    (*n)++;
}

void print_order(struct order o) {
    printf("%-20s %-10d %-10.2f %-10.2f\n", o.name, o.quantity, o.price, o.quantity*o.price);
}

void print_bill(struct order o[], int n) {
    float total = 0;
    printf("\n\n=========================\n");
    printf("      C Cafe Bill        \n");
    printf("=========================\n");
    printf("%-20s %-10s %-10s %-10s\n", "Item Name", "Quantity", "Price", "Total");
    for (int i=0; i<n; i++) {
        print_order(o[i]);
        total += o[i].quantity*o[i].price;
    }
    printf("=========================\n");
    printf("Total: %.2f\n", total);
}

int main() {
    struct order orders[100];
    int n = 0;
    int option = 0;
    while (option != 3) {
        printf("\n\nWelcome to C Cafe Billing System\n");
        printf("1. Add Item\n");
        printf("2. Print Bill\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_order(orders, &n);
                break;
            case 2:
                print_bill(orders, n);
                break;
            case 3:
                printf("\nThank you for using C Cafe Billing System!\n");
                break;
            default:
                printf("\nInvalid Option!\n");
                break;
        }
    }
    return 0;
}