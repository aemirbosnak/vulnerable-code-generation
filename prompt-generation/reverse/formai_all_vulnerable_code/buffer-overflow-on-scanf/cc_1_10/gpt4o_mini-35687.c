//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
    struct Product* next;
} Product;

Product* head = NULL;

void addProduct();
void viewProducts();
void deleteProduct();
void freeMemory();

int main() {
    int choice;
    while (1) {
        printf("\n----- Product Inventory System -----\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Delete Product\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                freeMemory();
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void addProduct() {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    if (newProduct == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Product ID: ");
    scanf("%d", &newProduct->id);
    printf("Enter Product Name: ");
    getchar(); // to consume newline from previous input
    fgets(newProduct->name, sizeof(newProduct->name), stdin);
    newProduct->name[strcspn(newProduct->name, "\n")] = 0; // remove newline
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct->quantity);
    printf("Enter Product Price: ");
    scanf("%f", &newProduct->price);
    newProduct->next = head;
    head = newProduct;

    printf("Product added successfully!\n");
}

void viewProducts() {
    if (head == NULL) {
        printf("No products available in inventory!\n");
        return;
    }
    
    Product* temp = head;
    printf("\n--- Product List ---\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------------------\n");
    while (temp != NULL) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", temp->id, temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

void deleteProduct() {
    int id;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    Product* temp = head;
    Product* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product with ID %d not found!\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Product deleted successfully!\n");
}

void freeMemory() {
    Product* current = head;
    Product* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}