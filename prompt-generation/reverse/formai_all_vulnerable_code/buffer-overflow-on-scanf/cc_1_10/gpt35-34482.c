//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for storing product details
struct product {
    int pid;
    char name[50];
    int price;
    int stock;
};

// Function for adding new products
void add_product(struct product *p, int num) {
    printf("Enter details of %d products:\n\n", num);
    for(int i=0; i<num; i++) {
        printf("Product ID: ");
        scanf("%d", &(p+i)->pid);
        printf("Product Name: ");
        scanf("%s", (p+i)->name);
        printf("Price: ");
        scanf("%d", &(p+i)->price);
        printf("Stock: ");
        scanf("%d", &(p+i)->stock);
        printf("\n");
    }
}

// Function for displaying all products
void display_all(struct product *p, int num) {
    printf("Product Details:\n\n");
    for(int i=0; i<num; i++) {
        printf("Product ID: %d\n", (p+i)->pid);
        printf("Product Name: %s\n", (p+i)->name);
        printf("Price: %d\n", (p+i)->price);
        printf("Stock: %d\n\n", (p+i)->stock);
    }
}

// Function for searching products by their name
void search_by_name(struct product *p, int num) {
    char name[50];
    int found = 0;
    printf("Enter the product name: ");
    scanf("%s", name);
    printf("\n");
    for(int i=0; i<num; i++) {
        if(strcmp((p+i)->name, name) == 0) {
            printf("Product found!\n\n");
            printf("Product ID: %d\n", (p+i)->pid);
            printf("Product Name: %s\n", (p+i)->name);
            printf("Price: %d\n", (p+i)->price);
            printf("Stock: %d\n\n", (p+i)->stock);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Product not found!\n\n");
    }
}

// Function for updating product details
void update_product(struct product *p, int num, int id) {
    int index = -1;
    for(int i=0; i<num; i++) {
        if((p+i)->pid == id) {
            index = i;
            break;
        }
    }
    if(index != -1) {
        printf("Enter new details for product %d:\n\n", id);
        printf("Product Name: ");
        scanf("%s", (p+index)->name);
        printf("Price: ");
        scanf("%d", &(p+index)->price);
        printf("Stock: ");
        scanf("%d", &(p+index)->stock);
        printf("\n");
    }
    else {
        printf("Product not found!\n\n");
    }
}

int main() {
    int choice, num, id;
    printf("Welcome to the Product Inventory System!\n\n");
    struct product *ptr = NULL;
    printf("How many products do you want to add? ");
    scanf("%d", &num);
    ptr = (struct product*) malloc(num * sizeof(struct product));
    add_product(ptr, num);
    do {
        printf("Select an option:\n");
        printf("1. Display all products\n");
        printf("2. Search product by name\n");
        printf("3. Update product details\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_all(ptr, num);
                break;
            case 2:
                search_by_name(ptr, num);
                break;
            case 3:
                printf("Enter the product ID: ");
                scanf("%d", &id);
                printf("\n");
                update_product(ptr, num, id);
                break;
            case 4:
                printf("Thank you for using the Product Inventory System!\n\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n\n");
        }
    } while(choice != 4);
    free(ptr);
    return 0;
}