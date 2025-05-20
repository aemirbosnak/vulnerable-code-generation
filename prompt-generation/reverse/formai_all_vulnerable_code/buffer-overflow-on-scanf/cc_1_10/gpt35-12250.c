//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include<stdio.h>

struct Product {
    int ID;
    char name[20];
    float price;
    int quantity;
};

int menu() {
    int choice;
    printf(" -------------------------------\n");
    printf("|      PRODUCT INVENTORY        |\n");
    printf(" -------------------------------\n");
    printf("| OPTIONS:                      |\n");
    printf("|                               |\n");
    printf("| 1. Add Product                |\n");
    printf("| 2. Remove Product             |\n");
    printf("| 3. Update Product Quantity    |\n");
    printf("| 4. Display Product List       |\n");
    printf("| 5. Quit                       |\n");
    printf(" -------------------------------\n");
    printf(" Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

void addProduct(struct Product products[], int *size) {
    printf(" Enter Product ID: ");
    scanf("%d", &products[*size].ID);
    printf(" Enter Product Name: ");
    scanf("%s", products[*size].name);
    printf(" Enter Product Price: ");
    scanf("%f", &products[*size].price);
    printf(" Enter Product Quantity: ");
    scanf("%d", &products[*size].quantity);
    printf(" Product Added Successfully!\n");
    (*size)++;
}

void removeProduct(struct Product products[], int *size, int ID) {
    int i, index = -1;
    for(i=0; i<*size; i++) {
        if(products[i].ID == ID) {
            index = i;
            break;
        }
    }
    if(index==-1) {
        printf(" Product doesn't Exist!\n");
    }
    else {
        for(i=index; i<*size-1; i++) {
            products[i] = products[i+1];
        }
        (*size)--;
        printf(" Product Removed Successfully!\n");
    }
}

void updateProduct(struct Product products[], int size, int ID, int quantity) {
    int i, index = -1;
    for(i=0; i<size; i++) {
        if(products[i].ID == ID) {
            index = i;
            break;
        }
    }
    if(index==-1) {
        printf(" Product doesn't Exist!\n");
    }
    else {
        products[index].quantity = quantity;
        printf(" Product Quantity Updated Successfully!\n");
    }
}

void displayProducts(struct Product products[], int size) {
    int i;
    printf(" ------------------------------------------------------------------\n");
    printf("|                         PRODUCT INVENTORY                        |\n");
    printf(" ------------------------------------------------------------------\n");
    printf("| ID |             Name | Price | Quantity | Total Price (Quantity) |\n");
    printf(" ------------------------------------------------------------------\n");
    for(i=0; i<size; i++) {
        printf("|%3d |%17s |%6.2f |%8d |%16.2f |\n", products[i].ID, products[i].name, products[i].price, products[i].quantity, products[i].price*products[i].quantity);
    }
    printf(" ------------------------------------------------------------------\n");
}

int main() {
    struct Product products[100];
    int choice, size=0, ID, quantity;
    
    do {
        choice = menu();
        switch(choice) {
            case 1:
                addProduct(products, &size);
                break;
            case 2:
                printf(" Enter Product ID to Remove: ");
                scanf("%d", &ID);
                removeProduct(products, &size, ID);
                break;
            case 3:
                printf(" Enter Product ID to Update: ");
                scanf("%d", &ID);
                printf(" Enter Quantity: ");
                scanf("%d", &quantity);
                updateProduct(products, size, ID, quantity);
                break;
            case 4:
                displayProducts(products, size);
                break;
            case 5:
                printf(" Thank You for using Product Inventory!\n");
                break;
            default:
                printf(" Invalid Choice, Please Try Again!\n");
        }
    } while(choice!=5);
    
    return 0;
}