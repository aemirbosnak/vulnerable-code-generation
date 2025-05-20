//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include<stdio.h>
#include<string.h>

#define max_products 100 //maximum number of products to be stored in the inventory
#define max_name_length 50 //maximum length of product's name

struct product{
    char name[max_name_length];
    int id;
    int quantity;
    float price;
};

int num_products = 0; //number of products currently in the inventory
struct product inventory[max_products]; //array to store products

void add_product(){
    if(num_products < max_products){ //if inventory is not full
        printf("Enter product name: ");
        scanf("%s", inventory[num_products].name);
        printf("Enter product id (integer): ");
        scanf("%d", &inventory[num_products].id);
        printf("Enter product quantity: ");
        scanf("%d", &inventory[num_products].quantity);
        printf("Enter product price: ");
        scanf("%f", &inventory[num_products].price);
        num_products++; //increment number of products in inventory
        printf("Product added successfully!\n");
    }
    else{
        printf("Inventory is full!\n");
    }
}

void display_inventory(){
    printf("Inventory:\n");
    printf("Name\tID\tQuantity\tPrice\n");
    for(int i=0; i<num_products; i++){
        printf("%s\t%d\t%d\t\t%.2f\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
    }
}

void search_product(){
    int id;
    printf("Enter product id to search: ");
    scanf("%d", &id);
    for(int i=0; i<num_products; i++){
        if(inventory[i].id == id){
            printf("Product Found!\n");
            printf("Name: %s\nID: %d\nQuantity: %d\nPrice: %.2f\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found!\n");
}

void sell_product(){
    int id, quantity;
    printf("Enter product id to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    for(int i=0; i<num_products; i++){
        if(inventory[i].id == id){
            if(inventory[i].quantity >= quantity){
                inventory[i].quantity -= quantity;
                printf("%d units of %s sold for %.2f\n", quantity, inventory[i].name, quantity*inventory[i].price);
                if(inventory[i].quantity == 0){
                    printf("WARNING: Product %s is now out of stock!\n", inventory[i].name);
                }
                return;
            }
            else{
                printf("Not enough quantity available to sell!\n");
                return;
            }
        }
    }
    printf("Product not found!\n");
}

int main(){
    int choice;
    do{
        printf("\nMenu:\n1. Add Product\n2. Display Inventory\n3. Search Product\n4. Sell Product\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_product(); break;
            case 2: display_inventory(); break;
            case 3: search_product(); break;
            case 4: sell_product(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    }while(choice != 5);
    return 0;
}