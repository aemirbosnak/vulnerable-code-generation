//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    double price;
    int quantity;
};

void print_bill(struct Item items[], int n) {
    double total = 0.0;
    printf("***************** C Cafe Billing System ***************** \n");
    printf("Item Name\t\tPrice\t\tQuantity\t\tTotal\n");
    printf("---------------------------------------------------------\n");
    for(int i=0; i<n; i++) {
        printf("%-20s %10.2lf %15d %20.2lf\n", items[i].name, items[i].price, items[i].quantity, items[i].price * items[i].quantity);
        total += (items[i].price * items[i].quantity);
    }
    printf("---------------------------------------------------------\n");
    printf("\t\t\t\tTotal: %10.2lf\n", total);
    printf("*******************************************************\n");
}

void billing_system() {
    int choice, n=0;
    struct Item items[100];
    while(1) {
        printf("Welcome to C Cafe. What would you like to do today?\n");
        printf("1. Add Item\n2. Remove Item\n3. View Bill\n4. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter Item Name: ");
                scanf("%s", items[n].name);
                printf("Enter Item Price: ");
                scanf("%lf", &items[n].price);
                printf("Enter Item Quantity: ");
                scanf("%d", &items[n].quantity);
                printf("Successfully added %d %s to your cart!\n", items[n].quantity, items[n].name);
                n++;
                break;
            case 2:
                n--;
                printf("\nLast item removed from your cart!\n");
                break;
            case 3:
                print_bill(items, n);
                printf("\nThank you for shopping with us!\n");
                return;
                break;
            case 4:
                printf("\nThank you for visiting C Cafe. Have a nice day!\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice. Please try again!\n");
                break;
        }
    }

}

int main() {
    billing_system();
    return 0;
}