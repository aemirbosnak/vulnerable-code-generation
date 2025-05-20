//FormAI DATASET v1.0 Category: Product Inventory System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

void add_product(struct product[], int*);
void list_products(struct product[], int);
void update_product(struct product[], int);
void delete_product(struct product[], int*);

int main() {
    int choice, count = 0;
    struct product p[10];

    while(1) {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product(p, &count);
                break;
            case 2:
                list_products(p, count);
                break;
            case 3:
                update_product(p, count);
                break;
            case 4:
                delete_product(p, &count);
                break;
            case 5:
                printf("\nThank you for using Product Inventory System.\n\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void add_product(struct product p[], int *count) {
    printf("\nEnter product ID: ");
    scanf("%d", &p[*count].id);
    printf("Enter product name: ");
    scanf("%s", p[*count].name);
    printf("Enter product quantity: ");
    scanf("%d", &p[*count].quantity);
    printf("Enter product price: ");
    scanf("%f", &p[*count].price);

    printf("\nProduct added successfully.\n");
    (*count)++;
}

void list_products(struct product p[], int count) {
    if(count == 0) {
        printf("\nNo products available.\n");
        return;
    }

    printf("\nProduct ID\tProduct Name\t\tProduct Quantity\tProduct Price\n");
    printf("----------------------------------------------------------------------\n");
    for(int i=0; i<count; i++) {
        printf("%d\t\t%s\t\t%d\t\t\t%.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price);
    }
}

void update_product(struct product p[], int count) {
    int id, flag = 0;
    printf("\nEnter product ID to update: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++) {
        if(p[i].id == id) {
            printf("Enter new product name: ");
            scanf("%s", p[i].name);
            printf("Enter new product quantity: ");
            scanf("%d", &p[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &p[i].price);
            printf("\nProduct details updated successfully.\n");
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("\nProduct ID not found.\n");
    }
}

void delete_product(struct product p[], int *count) {
    int id, flag = 0;
    printf("\nEnter product ID to delete: ");
    scanf("%d", &id);

    for(int i=0; i<*count; i++) {
        if(p[i].id == id) {
            for(int j=i; j<*count-1; j++) {
                p[j] = p[j+1];
            }
            (*count)--;
            printf("\nProduct deleted successfully.\n");
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("\nProduct ID not found.\n");
    }
}