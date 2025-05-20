//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct node {
    struct product data;
    struct node *next;
};

struct node *head = NULL;

void add_product() {
    struct product product;
    printf("Enter product ID: ");
    scanf("%d", &product.id);
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = product;
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

void display_products() {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("Product ID: %d\n", current_node->data.id);
        printf("Product name: %s\n", current_node->data.name);
        printf("Product quantity: %d\n", current_node->data.quantity);
        printf("Product price: %.2f\n\n", current_node->data.price);
        current_node = current_node->next;
    }
}

void search_product() {
    int search_id;
    printf("Enter the product ID you want to search: ");
    scanf("%d", &search_id);

    struct node *current_node = head;
    while (current_node != NULL) {
        if (current_node->data.id == search_id) {
            printf("Product found!\n");
            printf("Product ID: %d\n", current_node->data.id);
            printf("Product name: %s\n", current_node->data.name);
            printf("Product quantity: %d\n", current_node->data.quantity);
            printf("Product price: %.2f\n\n", current_node->data.price);
            return;
        }
        current_node = current_node->next;
    }

    printf("Product not found!\n");
}

void update_product() {
    int update_id;
    printf("Enter the product ID you want to update: ");
    scanf("%d", &update_id);

    struct node *current_node = head;
    while (current_node != NULL) {
        if (current_node->data.id == update_id) {
            printf("Product found!\n");
            printf("Enter new product name: ");
            scanf("%s", current_node->data.name);
            printf("Enter new product quantity: ");
            scanf("%d", &current_node->data.quantity);
            printf("Enter new product price: ");
            scanf("%f", &current_node->data.price);
            printf("Product updated successfully!\n");
            return;
        }
        current_node = current_node->next;
    }

    printf("Product not found!\n");
}

void delete_product() {
    int delete_id;
    printf("Enter the product ID you want to delete: ");
    scanf("%d", &delete_id);

    struct node *current_node = head;
    struct node *previous_node = NULL;
    while (current_node != NULL) {
        if (current_node->data.id == delete_id) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            printf("Product deleted successfully!\n");
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Product not found!\n");
}

int main() {
    int choice;
    do {
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Search for a product\n");
        printf("4. Update a product\n");
        printf("5. Delete a product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                update_product();
                break;
            case 5:
                delete_product();
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}