//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Item;

typedef struct {
    char name[50];
    int quantity;
} Order;

void addItem(Item menu[], int *size) {
    printf("Enter item ID: ");
    scanf("%d", &menu[*size].id);
    printf("Enter item name: ");
    scanf("%s", menu[*size].name);
    printf("Enter item price: ");
    scanf("%f", &menu[*size].price);
    (*size)++;
}

void displayMenu(Item menu[], int size) {
    printf("\nMenu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void addOrder(Order order[], int *size) {
    printf("\nEnter order name: ");
    scanf("%s", order[*size].name);
    printf("Enter order quantity: ");
    scanf("%d", &order[*size].quantity);
    (*size)++;
}

void calculateTotal(Item menu[], Order order[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (menu[i].id == order[j].quantity) {
                total += menu[i].price * order[j].quantity;
            }
        }
    }
    printf("\nTotal: $%.2f\n", total);
}

int main() {
    int menuSize = 0, orderSize = 0;
    Item menu[100];
    Order order[100];

    addItem(menu, &menuSize);
    displayMenu(menu, menuSize);

    addOrder(order, &orderSize);

    calculateTotal(menu, order, orderSize);

    return 0;
}