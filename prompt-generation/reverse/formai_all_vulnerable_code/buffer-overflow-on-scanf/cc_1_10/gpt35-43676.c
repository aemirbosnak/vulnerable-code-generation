//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Warehouse{
    int product_id;
    char product_name[100];
    int quantity;
    float price;
    char supplier_name[100];
};

void add_product(struct Warehouse products[], int n){
    printf("Enter the details of the product: \n");
    printf("Product ID: ");
    scanf("%d", &products[n].product_id);
    printf("Product Name: ");
    fflush(stdin);
    gets(products[n].product_name);
    printf("Quantity: ");
    scanf("%d", &products[n].quantity);
    printf("Price: ");
    scanf("%f", &products[n].price);
    printf("Supplier Name: ");
    fflush(stdin);
    gets(products[n].supplier_name);

    printf("\nProduct added successfully!\n");
}

void display_products(struct Warehouse products[], int n){
    printf("Product ID\tProduct Name\tQuantity\tPrice\tSupplier Name\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%s\t\t%d\t\t%.2f\t%s\n", products[i].product_id, products[i].product_name, products[i].quantity, products[i].price, products[i].supplier_name);
    }
}

void search_product(struct Warehouse products[], int n){
    int id;
    printf("Enter the Product ID: ");
    scanf("%d", &id);

    for(int i=0;i<n;i++){
        if(products[i].product_id == id){
            printf("Product Found! Details are: \n");
            printf("Product ID: %d\n Product Name: %s\nQuantity: %d\nPrice: %.2f\nSupplier Name: %s\n", products[i].product_id, products[i].product_name, products[i].quantity, products[i].price, products[i].supplier_name);
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

void update_product(struct Warehouse products[], int n){
    int id;
    printf("Enter the Product ID: ");
    scanf("%d", &id);

    for(int i=0;i<n;i++){
        if(products[i].product_id == id){
            printf("Product Found! Enter the new details: \n");
            printf("Product Name: ");
            fflush(stdin);
            gets(products[i].product_name);
            printf("Quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Price: ");
            scanf("%f", &products[i].price);
            printf("Supplier Name: ");
            fflush(stdin);
            gets(products[i].supplier_name);

            printf("\nProduct Updated Successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

void delete_product(struct Warehouse products[], int n){
    int id;
    printf("Enter the Product ID: ");
    scanf("%d", &id);

    for(int i=0;i<n;i++){
        if(products[i].product_id == id){
            for(int j=i;j<n-1;j++){
                products[j].product_id = products[j+1].product_id;
                strcpy(products[j].product_name, products[j+1].product_name);
                products[j].quantity = products[j+1].quantity;
                products[j].price = products[j+1].price;
                strcpy(products[j].supplier_name, products[j+1].supplier_name);
            }
            printf("\nProduct Deleted Successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

int main(){
    int choice, n = 0;
    struct Warehouse products[100];
    do{
        printf("\n\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Display All Products\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: add_product(products, n); n++; break;
            case 2: search_product(products, n); break;
            case 3: update_product(products, n); break;
            case 4: delete_product(products, n); n--; break;
            case 5: display_products(products, n); break;
            case 0: printf("Thanks for using our system!"); break;
            default: printf("Invalid Choice! Please try again."); break;
        }
    }while(choice!=0);

    return 0;
}