//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

struct node {
    struct product product;
    struct node *next;
};

struct node *head = NULL;

void add_product() {
    struct product product;
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->product = product;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void delete_product() {
    char name[50];
    printf("Enter product name to delete: ");
    scanf("%s", name);

    struct node *current_node = head;
    struct node *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->product.name, name) == 0) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Product not found.\n");
}

void update_product() {
    char name[50];
    printf("Enter product name to update: ");
    scanf("%s", name);

    struct node *current_node = head;

    while (current_node != NULL) {
        if (strcmp(current_node->product.name, name) == 0) {
            printf("Enter new product quantity: ");
            scanf("%d", &current_node->product.quantity);
            printf("Enter new product price: ");
            scanf("%f", &current_node->product.price);
            return;
        }
        current_node = current_node->next;
    }

    printf("Product not found.\n");
}

void display_products() {
    struct node *current_node = head;

    printf("Product List:\n");
    printf("-----------------\n");
    printf("Name\tQuantity\tPrice\n");
    while (current_node != NULL) {
        printf("%s\t%d\t%.2f\n", current_node->product.name, current_node->product.quantity, current_node->product.price);
        current_node = current_node->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Update Product\n");
        printf("4. Display Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                delete_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                display_products();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}