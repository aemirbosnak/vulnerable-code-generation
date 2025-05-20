//FormAI DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

struct product {
    int product_id;
    char product_name[50];
    float product_price;
    int product_quantity;
};

struct node {
    struct product data;
    struct node *next;
};

struct node *head = NULL;
int total_products = 0;

void add_product() {
    struct product p;
    printf("Enter Product ID: ");
    scanf("%d", &p.product_id);
    printf("Enter Product Name: ");
    scanf("%s", &p.product_name);
    printf("Enter Product Price: ");
    scanf("%f", &p.product_price);
    printf("Enter Product Quantity: ");
    scanf("%d", &p.product_quantity);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = p;
    new_node->next = head;
    head = new_node;
    total_products++;
    printf("Product Added Successfully!\n");
}

void search_product() {
    int id, found = 0;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    struct node *current = head;
    while(current != NULL) {
        if(current->data.product_id == id) {
            printf("Product Name: %s\n", current->data.product_name);
            printf("Product Price: %.2f\n", current->data.product_price);
            printf("Product Quantity: %d\n", current->data.product_quantity);
            found = 1;
            break;
        }
        current = current->next;
    }
    if(!found) {
        printf("Product not found!\n");
    }
}

void display_products() {
    struct node *current = head;
    printf("Product ID     Product Name        Product Price   Product Quantity\n");
    while(current != NULL) {
        printf("%-15d%-20s%-16.2f%d\n", current->data.product_id, current->data.product_name, current->data.product_price, current->data.product_quantity);
        current = current->next;
    }
    printf("Total Products: %d\n", total_products);
}

void delete_product() {
    int id, found = 0;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    struct node *current = head;
    struct node *previous = NULL;
    while(current != NULL) {
        if(current->data.product_id == id) {
            found = 1;
            if(previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Product Deleted Successfully!\n");
            break;
        }
        previous = current;
        current = current->next;
    }
    if(!found) {
        printf("Product not found!\n");
    }
}

int main() {
    int choice;
    printf("\t\tWelcome to the Product Inventory System\n");
    do {
        printf("\n1. Add Product\n2. Search Product\n3. Display Products\n4. Delete Product\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                search_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                printf("Thanks for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    } while(choice != 5);
    return 0;
}