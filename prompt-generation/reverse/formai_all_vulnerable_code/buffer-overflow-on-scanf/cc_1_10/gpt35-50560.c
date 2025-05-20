//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining structure for the product
struct Product {
    char name[20];
    int id;
    float price;
    int quantity;
};

// function to add new product
void addProduct(struct Product list[], int size) {
    printf("\nAdd Product\n");

    printf("Enter Product ID: ");
    scanf("%d", &list[size].id);

    printf("Enter Product Name: ");
    scanf("%s", list[size].name);

    printf("Enter Product Price: ");
    scanf("%f", &list[size].price);

    printf("Enter Product Quantity: ");
    scanf("%d", &list[size].quantity);
}

// function to display all products
void displayProducts(struct Product list[], int size) {
    printf("\nProduct List\n");

    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", list[i].id, list[i].name, list[i].price, list[i].quantity);
    }

    printf("\n");
}

// function to search for product by ID
void searchProductById(struct Product list[], int size) {
    int id, found = 0;

    printf("\nSearch Product By ID\n");

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        if (list[i].id == id) {
            printf("ID\tName\t\tPrice\tQuantity\n");
            printf("-------------------------------------------------\n");
            printf("%d\t%s\t\t%.2f\t%d\n", list[i].id, list[i].name, list[i].price, list[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n\n", id);
    }
}

// function to search for product by name
void searchProductByName(struct Product list[], int size) {
    char name[20];
    int found = 0;

    printf("\nSearch Product By Name\n");

    printf("Enter Product Name: ");
    scanf("%s", name);

    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            printf("ID\tName\t\tPrice\tQuantity\n");
            printf("-------------------------------------------------\n");
            printf("%d\t%s\t\t%.2f\t%d\n", list[i].id, list[i].name, list[i].price, list[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("Product with Name %s not found.\n\n", name);
    }
}

int main() {
    struct Product list[100];
    int size = 0;
    int choice;

    do {
        printf("\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product By ID\n");
        printf("4. Search Product By Name\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(list, size);
                size++;
                break;
            case 2:
                displayProducts(list, size);
                break;
            case 3:
                searchProductById(list, size);
                break;
            case 4:
                searchProductByName(list, size);
                break;
            case 5:
                printf("\nThank you for using the Product Inventory System!\n\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}