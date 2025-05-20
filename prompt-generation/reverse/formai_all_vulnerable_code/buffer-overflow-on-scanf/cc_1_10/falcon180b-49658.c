//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char name[50];
    char order[100];
    float price;
} Order;

void add_order(Order orders[], int *size, char name[], char order[], float price) {
    strcpy(orders[*size].name, name);
    strcpy(orders[*size].order, order);
    orders[*size].price = price;
    (*size)++;
}

void display_orders(Order orders[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("Name: %s\nOrder: %s\nPrice: %.2f\n\n", orders[i].name, orders[i].order, orders[i].price);
    }
}

int main() {
    int size = 0;
    Order orders[100];
    char name[50];
    char order[100];
    float price;

    printf("Welcome to the Cafe Billing System!\n");

    while(1) {
        printf("\nEnter customer name: ");
        scanf("%s", name);

        printf("Enter order: ");
        scanf("%s", order);

        printf("Enter price: ");
        scanf("%f", &price);

        add_order(orders, &size, name, order, price);

        printf("\nOrder added successfully!\n");

        printf("Do you want to add another order? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if(choice == 'n' || choice == 'N') {
            break;
        }
    }

    printf("\nTotal orders: %d\n", size);
    display_orders(orders, size);

    return 0;
}