//FormAI DATASET v1.0 Category: Product Inventory System ; Style: creative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct product {
    int code;
    char name[50];
    float price;
    int quantity;
};

void get_product(struct product *p) {
    printf("Enter product code: ");
    scanf("%d", &p->code);

    printf("Enter product name: ");
    scanf("%s", p->name);

    printf("Enter product price: ");
    scanf("%f", &p->price);

    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);
}

void add_product(struct product *inventory, int *n) {
    get_product(&inventory[*n]);

    printf("Product has been added to inventory!\n");

    (*n)++;
}

void remove_product(struct product *inventory, int *n) {
    int code_to_remove;

    printf("Enter product code to remove: ");
    scanf("%d", &code_to_remove);

    int i;
    for(i=0;i<*n;i++) {
        if(inventory[i].code == code_to_remove) {
            inventory[i] = inventory[*n-1];
            printf("Product has been removed from inventory!\n");
            (*n)--;
            break;
        }
    }
}

void display_inventory(struct product *inventory, int n) {
    printf("Product Inventory:\n");
    printf("%-10s%-20s%-10s%s\n", "Code", "Name", "Price", "Quantity");

    int i;
    for(i=0;i<n;i++) {
        printf("%-10d%-20s%-10.2f%d\n", inventory[i].code, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void save_inventory(struct product *inventory, int n) {
    FILE *file;
    file = fopen("inventory.txt", "w");

    int i;
    for(i=0;i<n;i++) {
        fprintf(file, "%d %s %f %d\n", inventory[i].code, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }

    fclose(file);

    printf("Inventory has been saved to file!\n");
}

void load_inventory(struct product *inventory, int *n) {
    FILE *file;
    file = fopen("inventory.txt", "r");

    if(file != NULL) {
        while(fscanf(file, "%d %s %f %d", &inventory[*n].code, inventory[*n].name, &inventory[*n].price, &inventory[*n].quantity) == 4) {
            (*n)++;
        }

        fclose(file);

        printf("Inventory has been loaded from file!\n");
    } else {
        printf("File not found! Inventory has not been loaded!\n");
    }
}

int main() {
    struct product inventory[100];
    int n = 0;
    char option;

    load_inventory(inventory, &n);

    while(1) {
        printf("\nChoose an option:\n");
        printf("A - Add product\n");
        printf("R - Remove product\n");
        printf("D - Display inventory\n");
        printf("S - Save inventory\n");
        printf("Q - Quit\n");

        scanf(" %c", &option);

        switch(option) {
            case 'A':
                add_product(inventory, &n);
                break;
            case 'R':
                remove_product(inventory, &n);
                break;
            case 'D':
                display_inventory(inventory, n);
                break;
            case 'S':
                save_inventory(inventory, n);
                break;
            case 'Q':
                printf("Exiting program...\n");
                save_inventory(inventory, n);
                exit(0);
            default:
                printf("Invalid option! Please choose a valid option.\n");
        }
    }

    return 0;
}