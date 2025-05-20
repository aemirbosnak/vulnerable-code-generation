//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 50

struct WareHouse {
    int id;
    char name[MAX_SIZE];
    int quantity;
    float price;
};

struct WareHouse stock[MAX_SIZE];
int count = 0;

void add() {
    int id;
    char name[MAX_SIZE];
    int quantity;
    float price;

    printf("\nEnter product id: ");
    scanf("%d", &id);
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);

    stock[count].id = id;
    strcpy(stock[count].name, name);
    stock[count].quantity = quantity;
    stock[count].price = price;

    count++;
    printf("\nProduct Added Successfully.\n\n");
}

void remove_product() {
    int product_id, i, found = 0;
    printf("\nEnter product id to remove: ");
    scanf("%d", &product_id);
    for (i = 0; i < count; i++) {
        if (stock[i].id == product_id) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo product found with id %d.\n\n", product_id);
    } else {
        for (int j = i; j < count - 1; j++) {
            stock[j] = stock[j + 1];
        }
        count--;
        printf("\nProduct Removed Successfully.\n\n");
    }
}

void display_all() {
    if (count == 0) {
        printf("\nNo Products Found.\n\n");
        return;
    }
    printf("\n%-5s\t%-20s\t%-10s\t%-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-5d\t%-20s\t%-10d\t%-10.2f\n", stock[i].id, stock[i].name, stock[i].quantity, stock[i].price);
    }
}

void search_product() {
    int product_id, i, found = 0;
    printf("\nEnter product id to search: ");
    scanf("%d", &product_id);
    for (i = 0; i < count; i++) {
        if (stock[i].id == product_id) {
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nNo product found with id %d.\n\n", product_id);
    } else {
        printf("\nProduct Found.\n\n");
        printf("%-5s\t%-20s\t%-10s\t%-10s\n", "ID", "Name", "Quantity", "Price");
        printf("%-5d\t%-20s\t%-10d\t%-10.2f\n", stock[i].id, stock[i].name, stock[i].quantity, stock[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("Warehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Search Product\n");
        printf("4. Display All Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                search_product();
                break;
            case 4:
                display_all();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice!\n\n");
                break;
        }
    } while (choice != 5);

    return 0;
}