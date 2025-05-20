//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int count = 0;
struct product inventory[MAX_PRODUCTS];

void add_product() {
    struct product p;

    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);

    p.id = ++count;
    inventory[count - 1] = p;

    printf("Product added successfully!\n");
}

void display_inventory() {
    printf("ID\tName\tPrice\tQuantity\n");

    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void search_product() {
    int id;

    printf("Enter product ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(id == inventory[i].id) {
            printf("ID\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }

    printf("Product not found!\n");
}

void update_product() {
    int id;

    printf("Enter product ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(id == inventory[i].id) {
            printf("Enter new details:\n");
            printf("Name: ");
            scanf("%s", inventory[i].name);
            printf("Price: ");
            scanf("%f", &inventory[i].price);
            printf("Quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Product updated successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

void remove_product() {
    int id;

    printf("Enter product ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(id == inventory[i].id) {
            for(int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j+1];
            }

            count--;

            printf("Product removed successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

void print_menu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add product\n");
    printf("2. Display inventory\n");
    printf("3. Search product\n");
    printf("4. Update product details\n");
    printf("5. Remove product\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while(1) {
        print_menu();

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                search_product();
                break;
            case 4:
                update_product();
                break;
            case 5:
                remove_product();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}