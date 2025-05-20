//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
};

void add_product(struct product *p, int id, char name[], int quantity) {
    p->id = id;
    strcpy(p->name, name);
    p->quantity = quantity;
}

void remove_product(struct product *p) {
    p->quantity = 0;
    strcpy(p->name, "");
}

void print_product(struct product *p) {
    printf("Id: %d\nName: %s\nQuantity: %d\n\n", p->id, p->name, p->quantity);
}

int main() {
    int choice, id, quantity;
    char name[50];
    struct product products[50];
    int i = 0;

    printf("*** Warehouse Management System ***\n\n");

    while (1) {
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. View Products\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter product id: ");
                scanf("%d", &id);

                printf("Enter product name: ");
                scanf("%s", name);

                printf("Enter product quantity: ");
                scanf("%d", &quantity);

                add_product(&products[i], id, name, quantity);
                i++;

                printf("\nProduct added successfully!\n\n");
                break;
            case 2:
                if (i > 0) {
                    printf("\nEnter product id to remove: ");
                    scanf("%d", &id);

                    int index = -1;

                    for (int j = 0; j < i; j++) {
                        if (products[j].id == id) {
                            index = j;
                            break;
                        }
                    }

                    if (index != -1) {
                        remove_product(&products[index]);
                        printf("Product removed successfully!\n\n");
                    } else {
                        printf("Product with id %d not found!\n\n", id);
                    }
                } else {
                    printf("\nNo products found!\n\n");
                }
                break;
            case 3:
                if (i > 0) {
                    for (int j = 0; j < i; j++) {
                        print_product(&products[j]);
                    }
                } else {
                    printf("\nNo products found!\n\n");
                }
                break;
            case 4:
                printf("\nExiting...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n\n");
        }
    }

    return 0;
}