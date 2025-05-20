//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

void menu(void);
void addProduct(struct product products[], int *count);
void updateProduct(struct product products[], int count);
void deleteProduct(struct product products[], int *count);
void displayProduct(struct product products[], int count);
void searchProduct(struct product products[], int count);

int main() {
    int count = 0, choice;
    char option;

    struct product products[100];

    do {
        printf("\nWelcome to Product Inventory System\n");
        menu();
        printf("Please enter your choice: ");
        
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                updateProduct(products, count);
                break;
            case 3:
                deleteProduct(products, &count);
                break;
            case 4:
                displayProduct(products, count);
                break;
            case 5:
                searchProduct(products, count);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &option);
        fflush(stdin);
    } while (option == 'y' || option == 'Y');

    return 0;
}

void menu() {
    printf("1. Add a product\n");
    printf("2. Update a product\n");
    printf("3. Delete a product\n");
    printf("4. Display all products\n");
    printf("5. Search for a product\n");
    printf("6. Exit\n");
}

void addProduct(struct product products[], int *count) {
    printf("Enter product name: ");
    fgets(products[*count].name, sizeof(products[*count].name), stdin);
    products[*count].name[strcspn(products[*count].name, "\n")] = '\0';

    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);
    fflush(stdin);

    printf("Enter product price: ");
    scanf("%f", &products[*count].price);
    fflush(stdin);

    products[*count].id = *count + 1;

    (*count)++;
}

void updateProduct(struct product products[], int count) {
    int id, i, choice;

    printf("Enter product ID to update: ");
    scanf("%d", &id);
    fflush(stdin);

    for (i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("Product ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n\n", products[i].price);

            do {
                printf("1. Update Name\n");
                printf("2. Update Quantity\n");
                printf("3. Update Price\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");

                scanf("%d", &choice);
                fflush(stdin);

                switch(choice) {
                    case 1:
                        printf("Enter new name: ");
                        fgets(products[i].name, sizeof(products[i].name), stdin);
                        products[i].name[strcspn(products[i].name, "\n")] = '\0';
                        break;
                    case 2:
                        printf("Enter new quantity: ");
                        scanf("%d", &products[i].quantity);
                        fflush(stdin);
                        break;
                    case 3:
                        printf("Enter new price: ");
                        scanf("%f", &products[i].price);
                        fflush(stdin);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
            } while (choice != 4);
            return;
        }
    }

    printf("Product not found!\n");
}

void deleteProduct(struct product products[], int *count) {
    int id, i, j;

    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    fflush(stdin);

    for (i = 0; i < *count; i++) {
        if (products[i].id == id) {
            for (j = i; j < *count - 1; j++) {
                products[j].id = products[j + 1].id;
                strcpy(products[j].name, products[j + 1].name);
                products[j].quantity = products[j + 1].quantity;
                products[j].price = products[j + 1].price;
            }
            (*count)--;
            printf("Product deleted successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

void displayProduct(struct product products[], int count) {
    int i;

    printf("\nProduct Inventory\n\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Product Name", "Quantity", "Price");

    for (i = 0; i < count; i++) {
        printf("%-5d %-20s %-10d %-10.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct(struct product products[], int count) {
    char name[50];
    int i, found = 0;

    printf("Enter product name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n\n", products[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Product not found!\n");
    }
}