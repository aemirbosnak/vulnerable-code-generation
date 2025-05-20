//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
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

    struct node *new_node = malloc(sizeof(struct node));
    new_node->product = product;
    new_node->next = head;
    head = new_node;
}

void delete_product() {
    char name[50];
    printf("Enter product name to delete: ");
    scanf("%s", name);

    struct node *current = head;
    struct node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->product.name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void update_product() {
    char name[50];
    printf("Enter product name to update: ");
    scanf("%s", name);

    struct node *current = head;
    while (current != NULL) {
        if (strcmp(current->product.name, name) == 0) {
            printf("Enter new product quantity: ");
            scanf("%d", &current->product.quantity);
            printf("Enter new product price: ");
            scanf("%f", &current->product.price);
            break;
        }
        current = current->next;
    }
}

void display_products() {
    struct node *current = head;
    printf("-----------------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-10s | %-10s |\n", "ID", "Name", "Quantity", "Price");
    printf("-----------------------------------------------------------------------------\n");
    int id = 1;
    while (current != NULL) {
        printf("| %-5d | %-20s | %-10d | %-10.2f |\n", id++, current->product.name, current->product.quantity, current->product.price);
        current = current->next;
    }
    printf("-----------------------------------------------------------------------------\n");
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Product\n2. Delete Product\n3. Update Product\n4. Display Products\n5. Quit\n");
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
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}