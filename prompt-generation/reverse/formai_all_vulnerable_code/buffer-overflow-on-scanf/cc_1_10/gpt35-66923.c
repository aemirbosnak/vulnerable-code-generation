//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct product{
    char name[50];
    int code;
    float price;
    int quantity;
}Product;

void addProduct(Product productList[], int *productCount){
    int code, quantity;
    char name[50];
    float price;
    fflush(stdin);
    printf("\nEnter product code: ");
    scanf("%d", &code);
    //Checking if the product already exists in the inventory
    for(int i=0;i<*productCount;i++){
        if(productList[i].code == code){
            printf("\nProduct already exists with the same code.\n");
            return;
        }
    }
    fflush(stdin);
    printf("Enter product name: ");
    fgets(name,50,stdin);
    fflush(stdin);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter quantity in stock: ");
    scanf("%d", &quantity);
    //Adding the new product to the inventory
    Product newProduct = {0};
    strcpy(newProduct.name, name);
    newProduct.code = code;
    newProduct.price = price;
    newProduct.quantity = quantity;
    productList[*productCount] = newProduct;
    *productCount += 1;
    printf("\nProduct added to the inventory successfully!\n");
}

void displayProducts(Product productList[], int productCount){
    printf("\nProduct Inventory:\n");
    printf("Code\tName\tPrice\tQuantity\n");
    for(int i=0;i<productCount;i++){
        printf("%d\t%s\t%f\t%d\n", productList[i].code, productList[i].name, productList[i].price, productList[i].quantity);
    }
}

void searchProduct(Product productList[], int productCount){
    int searchCode;
    fflush(stdin);
    printf("\nEnter product code to search: ");
    scanf("%d", &searchCode);
    for(int i=0;i<productCount;i++){
        if(productList[i].code == searchCode){
            printf("\nProduct found\n");
            printf("Name: %s\n", productList[i].name);
            printf("Price: %f\n", productList[i].price);
            printf("Quantity: %d\n", productList[i].quantity);
            return;
        }
    }
    printf("\nProduct not found\n");
}

void updateProductStock(Product productList[], int productCount){
    int updateCode, updateQuantity;
    fflush(stdin);
    printf("\nEnter product code to update: ");
    scanf("%d", &updateCode);
    for(int i=0;i<productCount;i++){
        if(productList[i].code == updateCode){
            printf("\nEnter new quantity: ");
            scanf("%d", &updateQuantity);
            productList[i].quantity = updateQuantity;
            printf("\nStock updated successfully!\n");
            return;
        }
    }
    printf("\nProduct not found\n");
}

int main(){
    Product productList[50] = {0};
    int productCount = 0, choice;
    do{
        printf("\n===== Product Inventory System =====\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Update product stock\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addProduct(productList, &productCount);
                    break;
            case 2: displayProducts(productList, productCount);
                    break;
            case 3: searchProduct(productList, productCount);
                    break;
            case 4: updateProductStock(productList, productCount);
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice\n");
        }
    }while(choice != 5);
    return 0;
}