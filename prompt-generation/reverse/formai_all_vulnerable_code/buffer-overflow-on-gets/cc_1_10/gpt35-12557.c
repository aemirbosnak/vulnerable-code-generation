//FormAI DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure definition
struct Product {
    int productId;
    char productName[50];
    int quantityAvailable;
    float price;
};

//function to add new product to inventory
void addProduct(struct Product *p, int size) {
    printf("\nEnter the following details of the product: \n");

    //taking input for new product
    printf("Product ID: ");
    scanf("%d",&p[size].productId);
    fflush(stdin);

    printf("Product Name: ");
    gets(p[size].productName);

    printf("Quantity Available: ");
    scanf("%d",&p[size].quantityAvailable);

    printf("Price: ");
    scanf("%f",&p[size].price);

    printf("\nNew Product Added Successfully!\n");
}

//function to search for a product using its ID
int searchProduct(struct Product *p, int size, int id) {
    for(int i=0; i<size; i++) {
        if(p[i].productId == id) {
            return i;
        }
    }
    return -1;
}

//function to update product details
void updateProduct(struct Product *p, int size) {
    int id, index;
    printf("\nEnter the ID of the product to be updated: ");
    scanf("%d",&id);

    index = searchProduct(p,size,id);

    if(index == -1) {
        printf("\nProduct not found.\n");
        return;
    }

    //taking input for updated product details
    printf("\nEnter the updated details: \n");

    printf("Product Name: ");
    fflush(stdin);
    gets(p[index].productName);

    printf("Quantity Available: ");
    scanf("%d",&p[index].quantityAvailable);

    printf("Price: ");
    scanf("%f",&p[index].price);

    printf("\nProduct updated successfully!\n");
}

//function to delete product from inventory
void deleteProduct(struct Product *p, int *size) {
    int id, index;
    printf("\nEnter the ID of the product to be deleted: ");
    scanf("%d",&id);

    index = searchProduct(p,*size,id);

    if(index == -1) {
        printf("\nProduct not found.\n");
        return;
    }

    for(int i=index; i<(*size)-1; i++) {
        p[i] = p[i+1];
    }

    (*size)--;
    printf("\nProduct Deleted Successfully!\n");
}

//function to display all products in inventory
void displayAllProducts(struct Product *p, int size) {
    printf("\nProduct ID \t Product Name \t Quantity Available \t Price\n");

    for(int i=0; i<size; i++) {
        printf("%d \t\t %s \t\t %d \t\t\t $%.2f\n",p[i].productId,p[i].productName,p[i].quantityAvailable,p[i].price);
    }
}

int main() {
    int option, size = 0;
    struct Product *inventory;

    //allocating memory for inventory
    inventory = (struct Product*) malloc(10 * sizeof(struct Product));

    while(1) {
        printf("\n******** Product Inventory System ********\n");
        printf("1. Add Product\n2. Delete Product\n3. Update Product\n4. Search for a Product\n5. Display All Products\n6. Exit\n");
        printf("Enter your option: ");
        scanf("%d",&option);

        switch(option) {
            case 1:
                //adding new product
                if(size == 10) {
                    printf("\nInventory Full. Cannot add new product.\n");
                    break;
                }
                addProduct(inventory,size);
                size++;
                break;
                
            case 2:
                //deleting a product
                deleteProduct(inventory,&size);
                break;

            case 3:
                //updating a product
                updateProduct(inventory,size);
                break;

            case 4:
                //searching for a product
                {
                    int id, index;
                    printf("\nEnter the ID of the product to be searched: ");
                    scanf("%d",&id);

                    index = searchProduct(inventory,size,id);

                    if(index == -1) {
                        printf("\nProduct not found.\n");
                    } else {
                        printf("\nProduct found!\n");
                        printf("%d \t\t %s \t\t %d \t\t\t $%.2f\n",inventory[index].productId,inventory[index].productName,inventory[index].quantityAvailable,inventory[index].price);
                    }
                }
                break;

            case 5:
                //displaying all products in inventory
                displayAllProducts(inventory,size);
                break;

            case 6:
                //exiting program
                free(inventory);
                exit(0);

            default:
                printf("\nInvalid Input. Please try again.\n");
                break;
        }
    }

    return 0;
}