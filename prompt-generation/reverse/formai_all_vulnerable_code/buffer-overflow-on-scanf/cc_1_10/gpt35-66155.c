//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

//function to add a new product to inventory
void addProduct(struct product p[], int *inventorySize){
    printf("\nEnter details for the new product:\n");
    printf("ID: ");
    scanf("%d", &p[*inventorySize].id);
    getchar();
    printf("Name: ");
    fgets(p[*inventorySize].name, 50, stdin);
    p[*inventorySize].name[strcspn(p[*inventorySize].name, "\n")] = 0;
    printf("Quantity: ");
    scanf("%d", &p[*inventorySize].quantity);
    printf("Price: $");
    scanf("%f", &p[*inventorySize].price);
    *inventorySize += 1;
}

//function to display all products in inventory
void displayInventory(struct product p[], int inventorySize){
    if(inventorySize == 0){
        printf("\nInventory is empty.\n");
        return;
    }
    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for(int i=0; i<inventorySize; i++){
        printf("%-5d %-20s %-10d $%-10.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price);
    }
}

//function to search for a product by ID
void searchProduct(struct product p[], int inventorySize){
    int id;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);
    for(int i=0; i<inventorySize; i++){
        if(p[i].id == id){
            printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
            printf("%-5d %-20s %-10d $%-10.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price);
            return;
        }
    }
    printf("\nProduct not found.\n");
}

//function to update a product's details
void updateProduct(struct product p[], int inventorySize){
    int id, option, quantity;
    float price;
    char name[50];
    printf("\nEnter ID to update: ");
    scanf("%d", &id);

    //finding index of product with given ID
    int index = -1;
    for(int i=0; i<inventorySize; i++){
        if(p[i].id == id){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("\nProduct not found.\n");
        return;
    }

    printf("\nChoose an option:\n");
    printf("1. Update Name\n");
    printf("2. Update Quantity\n");
    printf("3. Update Price\n");
    printf("Choose an option (1/2/3): ");
    scanf("%d", &option);

    switch(option){
        case 1:
            getchar();
            printf("Enter new name: ");
            fgets(name, 50, stdin);
            name[strcspn(name, "\n")] = 0;
            strcpy(p[index].name, name);
            break;
        case 2:
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            p[index].quantity = quantity;
            break;
        case 3:
            printf("Enter new price: $");
            scanf("%f", &price);
            p[index].price = price;
            break;
        default:
            printf("\nInvalid option.\n");
            return;
    }
    printf("\nProduct details updated successfully.\n");
}

//function to delete a product from inventory
void deleteProduct(struct product p[], int *inventorySize){
    int id, index;
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);
    for(int i=0; i<*inventorySize; i++){
        if(p[i].id == id){
            index = i;
            for(int j=i; j<*inventorySize-1; j++){
                p[j] = p[j+1];
            }
            *inventorySize -= 1;
            printf("\nProduct deleted successfully.\n");
            return;
        }
    }
    printf("\nProduct not found.\n");
}

int main(){
    struct product p[50];
    int inventorySize = 0;
    int choice;

    while(1){
        printf("\n\n********** Product Inventory System **********\n\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Choose an option (1/2/3/4/5/6): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct(p, &inventorySize);
                break;
            case 2:
                displayInventory(p, inventorySize);
                break;
            case 3:
                searchProduct(p, inventorySize);
                break;
            case 4:
                updateProduct(p, inventorySize);
                break;
            case 5:
                deleteProduct(p, &inventorySize);
                break;
            case 6:
                printf("\nGoodbye.\n");
                exit(0);
            default:
                printf("\nInvalid option.\n");
        }
    }
    return 0;
}