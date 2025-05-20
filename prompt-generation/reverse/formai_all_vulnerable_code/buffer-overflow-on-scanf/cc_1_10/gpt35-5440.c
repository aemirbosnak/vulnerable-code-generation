//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include<stdio.h>
#include<string.h>

//Structure to hold product data
struct product {
    char name[50];
    int code;
    int quantity;
    float price;
};

//Function to add new product in inventory
void addProduct(struct product p[], int *size) {
    printf("Enter product name: ");
    scanf("%s", p[*size].name);
    printf("Enter product code: ");
    scanf("%d", &p[*size].code);
    printf("Enter product quantity: ");
    scanf("%d", &p[*size].quantity);
    printf("Enter product price: ");
    scanf("%f", &p[*size].price);
    (*size)++;
    printf("Product added successfully!\n");
}

//Function to search for a product and return its index
int searchProduct(struct product p[], int size, int code) {
    for(int i=0; i<size; i++) {
        if(p[i].code == code) {
            return i;
        }
    }
    return -1;
}

//Function to update existing product in inventory
void updateProduct(struct product p[], int size, int code) {
    int index = searchProduct(p, size, code);
    if(index == -1) {
        printf("Product not found!\n");
        return;
    }
    printf("Enter updated quantity: ");
    scanf("%d", &p[index].quantity);
    printf("Enter updated price: ");
    scanf("%f", &p[index].price);
    printf("Product updated successfully!\n");
}

//Function to delete existing product from inventory
void deleteProduct(struct product p[], int *size, int code) {
    int index = searchProduct(p, *size, code);
    if(index == -1) {
        printf("Product not found!\n");
        return;
    }
    for(int i=index; i<(*size)-1; i++) {
        p[i] = p[i+1];
    }
    (*size)--;
    printf("Product deleted successfully!\n");
}

//Function to display all products in inventory
void displayInventory(struct product p[], int size) {
    printf("Product Name\tProduct Code\tQuantity\tPrice\n");
    for(int i=0; i<size; i++) {
        printf("%s\t\t%d\t\t%d\t\t%.2f\n", p[i].name, p[i].code, p[i].quantity, p[i].price);
    }
}

int main() {
    struct product inventory[100];
    int size = 0, choice, code;
    
    //Menu driven program
    do {
        printf("\n***************** Product Inventory System ******************\n");
        printf("\n1. Add Product");
        printf("\n2. Update Product");
        printf("\n3. Delete Product");
        printf("\n4. Display Inventory");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(inventory, &size);
                break;
            case 2:
                printf("Enter product code to update: ");
                scanf("%d", &code);
                updateProduct(inventory, size, code);
                break;
            case 3:
                printf("Enter product code to delete: ");
                scanf("%d", &code);
                deleteProduct(inventory, &size, code);
                break;
            case 4:
                displayInventory(inventory, size);
                break;
            case 5:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);
    return 0;
}