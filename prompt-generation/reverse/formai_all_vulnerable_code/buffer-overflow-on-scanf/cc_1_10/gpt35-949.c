//FormAI DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    char name[20];
    int quantity;
    float price;
} product;

void add_product(product inventory[], int *count) {
    printf("\nEnter the name of the product: ");
    scanf("%s", inventory[*count].name);
    printf("\nEnter the quantity of the product: ");
    scanf("%d", &inventory[*count].quantity);
    printf("\nEnter the price of the product: ");
    scanf("%f", &inventory[*count].price);

    (*count)++;
    printf("\nProduct added to inventory!\n");
    printf("---------------------------\n\n");
}

void update_product(product inventory[], int count) {
    char name[20];
    int found = 0;

    printf("\nEnter the name of the product to update: ");
    scanf("%s", name);

    for(int i=0; i<count; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            printf("\nCurrent quantity: %d", inventory[i].quantity);
            printf("\nEnter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("\nCurrent price: %.2f", inventory[i].price);
            printf("\nEnter new price: ");
            scanf("%f", &inventory[i].price);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("\nProduct not found!\n");
    } else {
        printf("\nProduct updated!\n");
    }

    printf("---------------------------\n\n");
}

void delete_product(product inventory[], int *count) {
    char name[20];
    int found = 0;

    printf("\nEnter the name of the product to delete: ");
    scanf("%s", name);

    for(int i=0; i<*count; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            inventory[i] = inventory[*count-1];
            (*count)--;
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("\nProduct not found!\n");
    } else {
        printf("\nProduct deleted!\n");
    }

    printf("---------------------------\n\n");
}

void view_inventory(product inventory[], int count) {
    printf("\nName\tQuantity\tPrice\n");

    for(int i=0; i<count; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    printf("---------------------------\n\n");
}

int main() {
    product inventory[100];
    int count = 0;
    int choice;

    while(1) {
        printf("\nC Cupid's Product Inventory System\n");
        printf("---------------------------\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. View Inventory\n");
        printf("5. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product(inventory, &count);
                break;
            case 2:
                update_product(inventory, count);
                break;
            case 3:
                delete_product(inventory, &count);
                break;
            case 4:
                view_inventory(inventory, count);
                break;
            case 5:
                printf("\nGoodbye my love!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                printf("---------------------------\n\n");
                break;
        }
    }

    return 0;
}