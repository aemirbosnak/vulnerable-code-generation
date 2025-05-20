//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

struct node {
    struct product data;
    struct node *next;
};

struct node *head = NULL;

void insert_product() {
    struct node *temp = (struct node*) malloc(sizeof(struct node));

    printf("Enter product name: ");
    scanf("%s", temp->data.name);
    printf("Enter quantity: ");
    scanf("%d", &temp->data.quantity);
    printf("Enter price: ");
    scanf("%f", &temp->data.price);

    temp->next = head;
    head = temp;

    printf("Product added succesfully!\n");
}

void delete_product() {
    if (head == NULL) {
        printf("No products available!\n");
        return;
    }

    char name[50];
    printf("Enter the name of the product to delete: ");
    scanf("%s", name);

    struct node *temp = head, *prev;

    if (strcmp(temp->data.name, name) == 0) {
        head = head->next;
        free(temp);
        printf("Product deleted succesfully!\n");
        return;
    }

    while (temp != NULL && strcmp(temp->data.name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Product deleted succesfully!\n");
}

void display_products() {
    if (head == NULL) {
        printf("No products available!\n");
        return;
    }

    struct node *temp = head;
    printf("%-20s %-10s %s\n", "PRODUCT NAME", "QUANTITY", "PRICE");
    while (temp != NULL) {
        printf("%-20s %-10d $%-7.2f\n", temp->data.name, temp->data.quantity, temp->data.price);
        temp = temp->next;
    }
}

void sell_product() {
    if (head == NULL) {
        printf("No products available!\n");
        return;
    }

    char name[50];
    printf("Enter the name of the product to sell: ");
    scanf("%s", name);

    struct node *temp = head;

    while (temp != NULL && strcmp(temp->data.name, name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product not found!\n");
        return;
    }

    printf("Enter quantity to sell: ");
    int quantity;
    scanf("%d", &quantity);

    if (quantity > temp->data.quantity) {
        printf("Not enough stock available!\n");
        return;
    }

    temp->data.quantity -= quantity;
    printf("%d %s sold succesfully!\n", quantity, temp->data.name);

    if (temp->data.quantity == 0) {
        delete_product();
    }
}

int main() {
    int choice;

    do {
        printf("\n********** C MEDICAL STORE MANAGEMENT SYSTEM **********\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Display Products\n");
        printf("4. Sell Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_product();
                break;

            case 2:
                delete_product();
                break;

            case 3:
                display_products();
                break;

            case 4:
                sell_product();
                break;

            case 5:
                printf("Thank you for using C Medical Store Management System!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}