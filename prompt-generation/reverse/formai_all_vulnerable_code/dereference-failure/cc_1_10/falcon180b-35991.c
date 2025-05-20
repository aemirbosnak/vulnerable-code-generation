//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Product {
    char name[MAX_SIZE];
    int quantity;
    float price;
    struct Product *next;
};

void addProduct(struct Product *head, char name[], int quantity, float price) {
    struct Product *newProduct = (struct Product*)malloc(sizeof(struct Product));
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = NULL;

    if (head == NULL) {
        head = newProduct;
    } else {
        struct Product *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newProduct;
    }
}

void displayProducts(struct Product *head) {
    if (head == NULL) {
        printf("No products found.\n");
        return;
    }

    printf("Product Name\tQuantity\tPrice\n");
    while (head!= NULL) {
        printf("%s\t%d\t%.2f\n", head->name, head->quantity, head->price);
        head = head->next;
    }
}

float calculateTotalPrice(struct Product *head) {
    float totalPrice = 0.0;
    while (head!= NULL) {
        totalPrice += head->price * head->quantity;
        head = head->next;
    }
    return totalPrice;
}

int main() {
    struct Product *head = NULL;

    addProduct(head, "Apple", 10, 1.50);
    addProduct(head, "Banana", 20, 1.00);
    addProduct(head, "Orange", 30, 2.00);

    printf("Products:\n");
    displayProducts(head);

    printf("\nTotal Price: $%.2f\n", calculateTotalPrice(head));

    return 0;
}