//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//creating structure for product
struct Product {
    char name[20];
    int id;
    int quantity;
    float price;
};

//function to add new product
void addProduct(struct Product *p, int *n) {
    printf("Enter name of product: ");
    scanf("%s", (p + *n)->name);
    printf("Enter ID of product: ");
    scanf("%d", &(p + *n)->id);
    printf("Enter quantity of product: ");
    scanf("%d", &(p + *n)->quantity);
    printf("Enter price of product: ");
    scanf("%f", &(p + *n)->price);
    (*n)++;
    printf("\nProduct added successfully!\n\n");
}

//function to display all products
void display(struct Product *p, int n) {
    printf("\n%-20s %-10s %-10s %-10s\n", "Product Name", "ID", "Quantity", "Price");
    for(int i = 0; i < n; i++) {
        printf("%-20s %-10d %-10d %-10.2f\n", (p + i)->name, (p + i)->id, (p + i)->quantity, (p + i)->price);
    }
    printf("\n");
}

//function to find product by ID
void findProductByID(struct Product *p, int n) {
    int id;
    printf("Enter ID of product to be searched: ");
    scanf("%d", &id);
    int flag = 0;
    for(int i = 0; i < n; i++) {
        if((p + i)->id == id) {
            printf("\nProduct found!\n");
            printf("%-20s %-10s %-10s %-10s\n", "Product Name", "ID", "Quantity", "Price");
            printf("%-20s %-10d %-10d %-10.2f\n\n", (p + i)->name, (p + i)->id, (p + i)->quantity, (p + i)->price);
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("\nProduct not found!\n\n");
    }
}

//function to find product by name
void findProductByName(struct Product *p, int n) {
    char name[20];
    printf("Enter name of product to be searched: ");
    scanf("%s", name);
    int flag = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp((p + i)->name, name) == 0) {
            printf("\nProduct found!\n");
            printf("%-20s %-10s %-10s %-10s\n", "Product Name", "ID", "Quantity", "Price");
            printf("%-20s %-10d %-10d %-10.2f\n\n", (p + i)->name, (p + i)->id, (p + i)->quantity, (p + i)->price);
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("\nProduct not found!\n\n");
    }
}

//main function
int main() {
    int choice, n = 0;
    struct Product *p = (struct Product*) malloc(sizeof(struct Product));

    do {
        printf("1. Add new product\n");
        printf("2. Display all products\n");
        printf("3. Find product by ID\n");
        printf("4. Find product by name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(p, &n);
                break;

            case 2:
                display(p, n);
                break;

            case 3:
                findProductByID(p, n);
                break;

            case 4:
                findProductByName(p, n);
                break;
                
            case 5:
                printf("\nThank you for using our system!\n\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n\n");
                break;
        }

    } while(choice != 5);

    //freeing dynamically allocated memory
    free(p);

    return 0;
}