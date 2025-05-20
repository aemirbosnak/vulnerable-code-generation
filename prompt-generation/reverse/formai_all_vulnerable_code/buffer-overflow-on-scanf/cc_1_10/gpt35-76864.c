//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

void display(struct product[]);
void add(struct product[]);
void remove_product(struct product[]);

int num_products = 0;

int main() {
    struct product inventory[100];
    int choice;

    while (1) {
        printf("\nWelcome to our Product Inventory System!\n");
        printf("1. Display products\n");
        printf("2. Add product\n");
        printf("3. Remove product\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display(inventory);
                break;
            case 2:
                add(inventory);
                break;
            case 3:
                remove_product(inventory);
                break;
            case 4:
                printf("Thank you for choosing our Product Inventory System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void display(struct product inventory[]) {
    if (num_products == 0) {
        printf("\nNo products in inventory!\n");
        return;
    }

    printf("\nProduct ID\tProduct Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void add(struct product inventory[]) {
    if (num_products == 100) {
        printf("\nSorry. Inventory is full!\n");
        return;
    }

    struct product new_product;
    new_product.id = num_products + 1;

    printf("\nEnter product name: ");
    scanf("%s", new_product.name);

    printf("\nEnter quantity: ");
    scanf("%d", &new_product.quantity);

    printf("\nEnter price: ");
    scanf("%f", &new_product.price);

    inventory[num_products++] = new_product;

    printf("\nProduct added successfully!\n");
}

void remove_product(struct product inventory[]) {
    if (num_products == 0) {
        printf("\nNo products in inventory!\n");
        return;
    }

    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    int index = -1;

    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nProduct not found!\n");
    } else {
        for (int i = index; i < num_products - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        num_products--;
        printf("\nProduct removed successfully!\n");
    }
}