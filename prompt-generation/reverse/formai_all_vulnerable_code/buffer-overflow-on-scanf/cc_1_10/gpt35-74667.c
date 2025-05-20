//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct product *p) {
    printf("Enter product name: ");
    scanf("%s", p->name);
    printf("Enter quantity: ");
    scanf("%d", &p->quantity);
    printf("Enter price: ");
    scanf("%f", &p->price);
}

void displayProduct(struct product p) {
    printf("%s, Quantity: %d, Price: $%.2f\n", p.name, p.quantity, p.price);
}

int main() {
    struct product inventory[100];
    int choice = 0, count = 0;

    while (choice != 3) {
        printf("\nProduct Inventory System");
        printf("\n1. Add Product\n2. Display Products\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < 100) {
                    addProduct(&inventory[count]);
                    count++;
                } else {
                    printf("Inventory full!\n");
                }
                break;
            case 2:
                if (count > 0) {
                    for (int i = 0; i < count; i++) {
                        displayProduct(inventory[i]);
                    }
                } else {
                    printf("Inventory empty!\n");
                }
                break;
            case 3:
                printf("Thank you for using the product inventory system.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}