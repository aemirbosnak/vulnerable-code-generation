//FormAI DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include <stdio.h>
#include <string.h>

struct product {
    int code;
    char name[30];
    float price;
    int stock;
};

void add_product(struct product list[], int *size) {
    struct product new_prod;
    printf("Enter product code: ");
    scanf("%d", &new_prod.code);
    
    printf("Enter product name: ");
    scanf("%s", new_prod.name);
    
    printf("Enter product price: ");
    scanf("%f", &new_prod.price);
    
    printf("Enter product stock: ");
    scanf("%d", &new_prod.stock);
    
    list[*size] = new_prod;
    (*size)++;
    printf("Product added!\n");
}

void remove_product(struct product list[], int *size, int code) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (list[i].code == code) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found.\n");
    } else {
        for (int i = index; i < *size - 1; i++) {
            list[i] = list[i + 1];
        }
        (*size)--;
        printf("Product removed!\n");
    }
}

void search_product(struct product list[], int size, int code) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (list[i].code == code) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found.\n");
    } else {
        printf("%d %s %.2f %d\n", list[index].code, list[index].name, list[index].price, list[index].stock);
    }
}

void display_inventory(struct product list[], int size) {
    printf("Code\tName\tPrice\tStock\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\t%d\n", list[i].code, list[i].name, list[i].price, list[i].stock);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    struct product inventory[100];
    int size = 0;
    int choice;
    while (1) {
        printf("\n1. Add product\n2. Remove product\n3. Search product\n4. Display inventory\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product(inventory, &size);
                break;
            case 2:
                printf("Enter product code to remove: ");
                int code1;
                scanf("%d", &code1);
                remove_product(inventory, &size, code1);
                break;
            case 3:
                printf("Enter product code to search: ");
                int code2;
                scanf("%d", &code2);
                search_product(inventory, size, code2);
                break;
            case 4:
                display_inventory(inventory, size);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}