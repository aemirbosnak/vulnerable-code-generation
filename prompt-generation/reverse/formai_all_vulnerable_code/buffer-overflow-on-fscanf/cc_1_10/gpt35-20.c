//FormAI DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[20];
    int quantity;
    float price;
} product;

int size = 0;

void clearScreen();
void addProduct(product products[]);
void deleteProduct(product products[]);
void findProduct(product products[]);
void viewAllProducts(product products[]);
void saveData(product products[]);
void readData(product products[]);

int main() {
    product products[MAX_SIZE];
    char choice;

    readData(products);
    clearScreen();

    printf("Welcome to our paranoid database simulator!\n\n");
    do {
        printf("Please choose from the following operations:\n");
        printf("1. Add a product record\n");
        printf("2. Delete a product record\n");
        printf("3. Find a product\n");
        printf("4. View all products\n");
        printf("5. Exit the program\n\n");

        printf("Choice: ");
        scanf(" %c", &choice);
        clearScreen();

        switch (choice) {
            case '1':
                addProduct(products);
                break;
            case '2':
                deleteProduct(products);
                break;
            case '3':
                findProduct(products);
                break;
            case '4':
                viewAllProducts(products);
                break;
            case '5':
                saveData(products);
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid option. Please enter a valid option (1-5)\n\n");
        }
    } while (choice != '5');

    return 0;
}

void clearScreen() {
    system("clear||cls");
}

void addProduct(product products[]) {
    if (size >= MAX_SIZE) {
        printf("Database full. Cannot add more products\n\n");
        return;
    }

    printf("Enter name of product: ");
    scanf(" %[^\n]s", products[size].name);
    printf("Enter quantity of product: ");
    scanf(" %d", &products[size].quantity);
    printf("Enter price of product: ");
    scanf(" %f", &products[size].price);
    size++;
    printf("Product record has been added to the database.\n\n");
}

void deleteProduct(product products[]) {
    char name[20];
    int found = 0, i, j;

    printf("Enter name of product: ");
    scanf(" %[^\n]s", name);

    for (i = 0; i < size; i++) {
        if (strcmp(products[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found in database\n\n");
        return;
    }

    printf("Product found in database with quantity of %d and price of %.2f\n", products[i].quantity, products[i].price);
    printf("Are you sure you want to delete this product? (y/n): ");
    scanf(" %c", &name);

    if (name == 'y' || name == 'Y') {
        for (j = i; j < size - 1; j++) {
            products[j] = products[j + 1];
        }
        size--;
        printf("Product has been deleted from the database.\n\n");
    } else {
        printf("Product was not deleted from the database.\n\n");
    }
}

void findProduct(product products[]) {
    char name[20];
    int found = 0, i;

    printf("Enter name of product: ");
    scanf(" %[^\n]s", name);

    for (i = 0; i < size; i++) {
        if (strcmp(products[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Product found in database with quantity of %d and price of %.2f\n\n", products[i].quantity, products[i].price);
    } else {
        printf("Product not found in database\n\n");
    }
}

void viewAllProducts(product products[]) {
    int i;

    if (size == 0) {
        printf("Database empty. No products to display.\n\n");
        return;
    }

    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    printf("--------------------------------------\n");
    for (i = 0; i < size; i++) {
        printf("%-20s %-10d %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
    printf("\n");
}

void saveData(product products[]) {
    FILE *file;
    int i;

    file = fopen("data.txt", "w");

    for (i = 0; i < size; i++) {
        fprintf(file, "%s %d %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    fclose(file);
}

void readData(product products[]) {
    FILE *file;
    int i;

    file = fopen("data.txt", "r");

    if (file) {
        while (fscanf(file, "%s %d %f\n", products[size].name, &products[size].quantity, &products[size].price) == 3 && size < MAX_SIZE) {
            size++;
        }

        fclose(file);
    }
}