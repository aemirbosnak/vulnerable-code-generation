//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    char name[50];
    char item[50];
    float amount;
    int quantity;
} Order;

void addOrder(Order orders[], int *size) {
    printf("Enter order name: ");
    scanf("%s", orders[*size].name);
    printf("Enter item name: ");
    scanf("%s", orders[*size].item);
    printf("Enter amount: ");
    scanf("%f", &orders[*size].amount);
    printf("Enter quantity: ");
    scanf("%d", &orders[*size].quantity);
    (*size)++;
}

void displayOrder(Order order) {
    printf("\nOrder Name: %s\n", order.name);
    printf("Item Name: %s\n", order.item);
    printf("Amount: %.2f\n", order.amount);
    printf("Quantity: %d\n", order.quantity);
    printf("-------------------------------------------------\n");
}

void calculateTotal(Order orders[], int size) {
    float total = 0;
    printf("\n\nOrder Summary:\n");
    for(int i=0; i<size; i++) {
        total += (orders[i].amount * orders[i].quantity);
        displayOrder(orders[i]);
    }
    printf("\nTotal Amount: %.2f\n", total);
}

int main() {
    Order orders[100];
    int size = 0;

    printf("\n\nWelcome to Cafe Billing System\n");
    printf("-------------------------------------------------\n");

    while(1) {
        printf("\n1. Add Order\n2. Display Orders\n3. Calculate Total\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addOrder(orders, &size);
                break;
            case 2:
                printf("\n\nOrder List:\n");
                for(int i=0; i<size; i++) {
                    displayOrder(orders[i]);
                }
                break;
            case 3:
                calculateTotal(orders, size);
                break;
            case 4:
                printf("\n\nThank you for using Cafe Billing System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}