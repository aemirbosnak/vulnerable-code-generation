//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

item shoppingCart[MAX_ITEMS];
int numItems = 0;
float totalCost = 0.0;

void addItem(char* name, float price, int quantity) {
    if (numItems < MAX_ITEMS) {
        strcpy(shoppingCart[numItems].name, name);
        shoppingCart[numItems].price = price;
        shoppingCart[numItems].quantity = quantity;
        numItems++;
        totalCost += shoppingCart[numItems-1].price * shoppingCart[numItems-1].quantity;
    } else {
        printf("Shopping cart is full!\n");
    }
}

void removeItem(int index) {
    if (index >= 0 && index < numItems) {
        numItems--;
        totalCost -= shoppingCart[index].price * shoppingCart[index].quantity;
        for (int i = index; i < numItems; i++) {
            shoppingCart[i] = shoppingCart[i+1];
        }
    } else {
        printf("Invalid item index!\n");
    }
}

void printCart() {
    printf("Shopping cart:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f (%d)\n", shoppingCart[i].name, shoppingCart[i].price, shoppingCart[i].quantity);
    }
    printf("Total cost: $%.2f\n", totalCost);
}

int main() {
    char name[50];
    float price;
    int quantity;

    printf("Welcome to the Personal Finance Planner!\n");

    while (1) {
        printf("Enter item name: ");
        scanf("%s", name);

        printf("Enter item price: ");
        scanf("%f", &price);

        printf("Enter item quantity: ");
        scanf("%d", &quantity);

        addItem(name, price, quantity);

        printf("Current shopping cart:\n");
        printCart();

        printf("Do you want to continue shopping? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    return 0;
}